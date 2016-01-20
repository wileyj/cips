/* OpenSSL Server */
//openssl req -x509 -nodes -days 365 -newkey rsa:1024 -keyout mycert.pem -out mycert.pem

#include <errno.h>
#include <fcntl.h>
#include <fstream>
#include <iostream>
#include <malloc.h>
#include <resolv.h>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <wait.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <openssl/ssl.h>
#include <openssl/err.h>
#include <openssl/x509.h>
#include <openssl/bio.h>
#include <openssl/rsa.h>
#include <openssl/pem.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <vector>
#include <map>
#include "../common/split.h"
#include "../common/global.h"
#include "../common/log.h"
#include "../common/response.h"

using namespace::std;
char   *sslRead (SSL* ssl);
int    rsa_key();
int    serverHelp( char binary[] );
void   parse_client(SSL *ssl, char *buffer);
int    read_file( std::string filename, char *ip, std::string name, std::string type );
int    send_response(SSL* ssl, int returned, char * msg);
char * itoc(int x);
int    find_iface();
int    parse_getnic(SSL* ssl, char *r_ip);
int    parse_getip(SSL* ssl, char *r_nic);
int    parse_setip(SSL* ssl, char *r_ip, char *r_user, char *r_time);
int    parse_deliface(SSL* ssl, char *r_ip, char *r_user, char *r_time);
int    parse_gethost(SSL* ssl);
int    parse_on(SSL* ssl, char *r_ip);
int    parse_off(SSL* ssl, char *r_ip);

typedef std::vector <std::string> DirListing_t;

int GetDirListing( DirListing_t& result, const std::string& dirpath, char *ip, std::string type );

int                   numWarnings;
int                   numErrors;
char*                 output;
ofstream              logfile;
char*                 fname = "/var/tmp/cips.log";
char                  hostname[128];
bool                  email          = false;
bool                  quiet         = false;
bool                  d_mode         = false;
int                   vlevel         = 0;
int                   s_port         = 22500;
bool                  found_iface    = false;
std::string           networkFile    = "/etc/sysconfig/network-scripts";
char                  output_log[25] = "/var/tmp/output_log.txt";
char                * rsa_e          = NULL;
char                * rsa_d          = NULL;
char                * priv_out       = "priv.pem";
char                * pub_out        = "pub.pem";
char                * keyfile        = "key.pem";
std::string           iface_file;
std::string           iface_file_short;
std::string           iface_name;
std::string           iface_name_short;
std::string           iface_root;
std::string           iface_hwaddr;
std::string           iface_netmask;
std::string           iface_ip;
std::string           all_ip;
unsigned char       * buff;
ssize_t               len;
X509                * x;
int                   pos;
unsigned              p_err;
char                  p_errmsg[1024];
const EVP_MD        * digest;
unsigned char         md[EVP_MAX_MD_SIZE];
unsigned int          n;
size_t                pri_len;
size_t                pub_len;
char                * pri_key;
char                * pub_key;
char                * err;
int                   encrypt_len;
BIO                 * bio;
SSL                 * ssl;


bool f_read(const char *filename){
  ifstream ifile(filename);
  return ifile;
}

using namespace::std;
int OpenListener(int port){   
  int sd;
  struct sockaddr_in addr;
  sd = socket(PF_INET, SOCK_STREAM, 0);
int one = 1; 
setsockopt(sd, SOL_SOCKET, SO_REUSEADDR, &one, sizeof(one));


  bzero(&addr, sizeof(addr));
  addr.sin_family = AF_INET;
  addr.sin_port = htons(port);
  addr.sin_addr.s_addr = INADDR_ANY;
  if ( bind(sd, (struct sockaddr*)&addr, sizeof(addr)) != 0 ){
    LOG(vlevel,cout, response[24]);
    if (quiet != 1 && d_mode != 1){
      cout<<response[24]<<": "<<s_port<<std::endl;
    }
    exit(28);
  }
  if ( listen(sd, 10) != 0 ){
    LOG(vlevel,cout, response[29]);
    if (quiet != 1 && d_mode != 1){
      cout<<response[29]<<std::endl;
    }
    exit(29);
  }
  if (d_mode == true){
    LOG(vlevel,cout,"Entering Daemon mode...");
    daemon(1,1);
  }
  return sd;
}

SSL_CTX* InitServerCTX(void){   
  SSL_METHOD *method;
  SSL_CTX *ctx;
  OpenSSL_add_all_algorithms();  /* load & register all cryptos, etc. */
  SSL_load_error_strings();   /* load all error messages */
  method = SSLv2_server_method();  /* create new server-method instance */
  ctx = SSL_CTX_new(method);   /* create new context from method */
  if ( ctx == NULL ){
    ERR_print_errors_fp(stderr);
    abort();
  }
  return ctx;
}

void LoadCertificates(SSL_CTX* ctx, char* CertFile, char* KeyFile){
 /* set the local certificate from CertFile */
 if ( SSL_CTX_use_certificate_file(ctx, CertFile, SSL_FILETYPE_PEM) <= 0 ){
   ERR_print_errors_fp(stderr);
   abort();
 }
 /* set the private key from KeyFile (may be the same as CertFile) */
 if ( SSL_CTX_use_PrivateKey_file(ctx, KeyFile, SSL_FILETYPE_PEM) <= 0 ){
    ERR_print_errors_fp(stderr);
    abort();
  }
  /* verify private key */
  if ( !SSL_CTX_check_private_key(ctx) ){
    fprintf(stderr, "Private key does not match the public certificate\n");
    abort();
  }
}

void ShowCerts(SSL* ssl){   
  X509 *cert;
  char *line;
  cert = SSL_get_peer_certificate(ssl); /* Get certificates (if available) */
  if ( cert != NULL ){
    line = X509_NAME_oneline(X509_get_subject_name(cert), 0, 0);
    LOG(vlevel,cout,"Subject:");
    LOG(vlevel,cout,"\t"<<line);
    free(line);
    line = X509_NAME_oneline(X509_get_issuer_name(cert), 0, 0);
    LOG(vlevel,cout,"Issuer:"); 
    LOG(vlevel,cout,"\t"<<line);
    free(line);
    X509_free(cert);
  }
}

void Servlet(SSL* ssl) /* Serve the connection -- threadable */{   
  char buf[1024];
  char reply[1024];
  int sd, bytes;
  const char* recv="%s";
  if ( SSL_accept(ssl) == FAIL ){     /* do SSL-protocol accept */
    ERR_print_errors_fp(stderr);
  }else{
    ShowCerts(ssl);        /* get any certificates */
    bytes = SSL_read(ssl, buf, sizeof(buf)); 
    if ( bytes > 0 ){
      buf[bytes] = 0;
      sprintf(reply, recv, buf);   
      LOG(vlevel,cout,"Received: "<<reply);
      parse_client(ssl, buf);
    }else{
      ERR_print_errors_fp(stderr);
    }
    sd = SSL_get_fd(ssl);       
    SSL_free(ssl);         
    close(sd);          
    sslRead(ssl);
  }
}
char *sslRead (SSL* ssl){
  const int readSize = 1024;
  char *rc = NULL;
  int received, count = 0;
  char buffer[1024];
  if (ssl){
    while (1){
      if (!rc){
        rc = (char*)malloc(readSize * sizeof (char) + 1);
      }else{
        rc = (char*)realloc(rc, (count + 1) * readSize * sizeof (char) + 1);
      }
      received = SSL_read (ssl, buffer, readSize);
      buffer[received] = '\0';
      if (received > 0){
        strcat (rc, buffer);
        buffer[received] = 0;
        //printf("%i Received: %s", __LINE__, buffer);
        LOG(vlevel, cout, "Received: "<<buffer);
      }else{
        ERR_print_errors_fp(stderr);
      }
      if (received < readSize){
        break;
      }
      count++;
    }
  }
  return rc;
}


int main(int argc, char *argv[]){   
  int c;
  while ( (c = getopt(argc, argv, "veqd")) != -1) {
    switch (c) {
      case 'v':
        vlevel++;
        break;
      case 'e':
        email = true;
        break;
      case 'q':
        quiet = true;
        break;
      case 'd':
        d_mode = true;
        break;
      case '?':
        serverHelp(argv[0]);
        exit(0);
        break;
      default:
        serverHelp(argv[0]);
        exit(0);
        break;
    }
  }
  if(vlevel > 4){
    vlevel = 4;
  }
  char date[80];
  strcpy(date, __DATE__);
  strcat(date, ", ");
  strcat(date, __TIME__);
  //log_open(date, fname);
  if (vlevel > 0 && quiet == 1){
    LOG(vlevel,cout,"Verbosity enabled with quiet mode. Verbosity overrides quiet");
  }
  LOG(vlevel,cout,"Verbosity Level:    "<<vlevel);
  LOG(vlevel,cout,"Silent enabled:     "<<quiet);
  LOG(vlevel,cout,"Email  enabled:     "<<email);
  LOG(vlevel,cout,"Daemon enabled:     "<<d_mode);

  find_iface();
  LOG(vlevel,cout,"Using interface: "<<iface_root.c_str()<<" as interface template");
  read_file(iface_root, "", "", "nicroot");
  SSL_CTX *ctx;
  int server;
  if (rsa_key() != 0){
    LOG(vlevel, cout, "Error with rsa_key");
    LOG(vlevel,cout, response[26]);
    if (quiet != 1 && d_mode != 1){
      cout<<response[26]<<std::endl;
    }
    exit(26);
  }
  SSL_library_init();
  ctx = InitServerCTX();        /* initialize SSL */
  bio = BIO_new_mem_buf(buff, len);
  if (!(x = PEM_read_bio_X509(bio, NULL, 0L, NULL))){
    while((p_err = ERR_get_error())){
      p_errmsg[1023] = '\0';
      ERR_error_string_n(p_err, p_errmsg, 1023);
      fprintf(stderr, "peminfo: %s\n", p_errmsg);
    };
    BIO_free(bio);
    free(buff);
    return(1);
  };

  // prints x509 info
  if(quiet != 1 && d_mode != 1 ){
    LOG(vlevel,cout,"Name: "<<x->name);
    if (vlevel == 1){ cout << "INFO:  " << "("<<__TIME__<<")  " << " Serial: "; }
    else if (vlevel == 2){ cout << "WARN:  " << "("<<__TIME__<<") (" <<__FILE__<< ") Serial: ";  }
    else if (vlevel == 3){ cout << "ERROR: " << "("<<__TIME__<<") (" <<__FILE__<< "  @" << __LINE__<< ") Serial: "; }
    else if (vlevel == 4){ cout << "DEBUG: " << "("<<__DATE__<<" " <<__TIME__<< ") (" <<__FILE__<<  " @" << __LINE__<<") Serial: "; }
    else{ cout<<"Serial: ";}
    printf("\t%02X", x->cert_info->serialNumber->data[0]);
    for(pos = 1; pos < x->cert_info->serialNumber->length; pos++){
      printf(":%02X", x->cert_info->serialNumber->data[pos]);
    }
    LOG(vlevel,cout,"");

    // calculate & print fingerprint
    digest = EVP_get_digestbyname("sha1");
    X509_digest(x, digest, md, &n);
    if (vlevel == 1){ cout << "INFO:  " << "("<<__TIME__<<") " << " Fingerprint: "; }
    else if (vlevel == 2){ cout << "WARN:  " << "("<<__TIME__<<") (" <<__FILE__<< ") Fingerprint: ";  }
    else if (vlevel == 3){ cout << "ERROR: " << "("<<__TIME__<<") (" <<__FILE__<< " @" << __LINE__<<") Fingerprint: "; }
    else if (vlevel == 4){ cout << "DEBUG: " << "("<<__DATE__<<" "<<__TIME__<<") (" <<__FILE__<< " @" << __LINE__<<") Fingerprint: "; }
    else{ cout<<"Fingerprint: ";}
    for(pos = 0; pos < 19; pos++){
      printf("%02x:", md[pos]);
    }
    printf("%02x\n", md[19]);
  }
  LOG(vlevel,cout,""); 
  LoadCertificates(ctx, keyfile, keyfile);                      /* load certs */
  if( remove( priv_out ) != 0 ){
    LOG(vlevel, cout, response[27]);
    if (quiet != 1 && d_mode != 1){
      cout<<response[27]<<std::endl;
    }
    exit(27);
  }else if( remove( pub_out) != 0 ){
    LOG(vlevel, cout, response[28]);
    if (quiet != 1 && d_mode != 1){
      cout<<response[28]<<std::endl;
    }
    exit(28);
  }else if( remove( keyfile) != 0){
    LOG(vlevel, cout, response[29]);
    if (quiet != 1 && d_mode != 1){
      cout<<response[29]<<std::endl;
    }
    exit(20);
  }else{
    LOG(vlevel,cout,"Files successfully deleted");
  }
  server = OpenListener(s_port);                          /* create server socket */
  while (1){   
    struct sockaddr_in addr;
    socklen_t len = sizeof(addr);
    SSL *ssl;
    int client = accept(server, (struct sockaddr*)&addr, &len);  /* accept connection as usual */
    if (client < 0){
      LOG(vlevel, cout, response[30]);
      if (quiet != 1 && d_mode != 1){
        cout<<response[30]<<std::endl;
      }
      exit(30);
    }
    pid_t pid = fork();
    if( pid == 0 ) {
      // Child context here
      LOG(vlevel,cout,"Connection: "<<inet_ntoa(addr.sin_addr)<<ntohs(addr.sin_port));
      ssl = SSL_new(ctx);                                          /* get new SSL state with context */
      SSL_set_fd(ssl, client);                                     /* set connection socket to SSL state */
      Servlet(ssl);                                               /* service connection */
      close(client);
    } else if( pid > 0 ) {
      // Parent context here
      int status = 0;
      waitpid( pid, &status, 0 );
      close(client);
    }else if (pid < 0){
      LOG(vlevel, cout, response[31]);  
      if (quiet != 1 && d_mode != 1){
        cout<<response[31]<<std::endl;
      }
      exit(31);
    }
  }                                               
  close(server);  /* close server socket */
  SSL_CTX_free(ctx); /* release context */
  //log_close(fname);
  return 0;
}

void parse_client(SSL *ssl, char *buffer){
  //int n;
  Splitter received ( buffer, "|");
  char *r_ip     = (char*)received[0].c_str();
  char *r_user   = (char*)received[1].c_str();
  char *r_nic    = (char*)received[2].c_str();
  char *r_type   = (char*)received[3].c_str();
  char *r_time   = (char*)received[4].c_str();
  /* soon: an item for a deferred change, setup an at job or something to modify the file at __time__ */
  if (received.size() > 0){
    LOG(vlevel,cout,"Received "<<received.size()<<" values");
    LOG(vlevel,cout,"\tIP   :"<<r_ip);
    LOG(vlevel,cout,"\tUser :"<<r_user);
    LOG(vlevel,cout,"\tNic  :"<<r_nic);
    LOG(vlevel,cout,"\tType :"<<r_type);
    LOG(vlevel,cout,"\tTime :"<<r_time);

    if (strcmp(r_type, "getnic") == 0){
      LOG(vlevel,cout,"Calling Function: parse_getnic");
      int returned = parse_getnic(ssl, r_ip);
      send_response(ssl, returned, response[returned]);
    }else if(strcmp(r_type,"getip") == 0){
      LOG(vlevel,cout,"Calling Function: parse_getip");
      int returned = parse_getip(ssl, r_nic);
      send_response(ssl, returned, response[returned]);
    }else if(strcmp(r_type,"setip") == 0){
      LOG(vlevel,cout,"Calling Function: parse_setip");
      int returned = parse_setip(ssl, r_ip, r_user, r_time);
      send_response(ssl, returned, response[returned]);
    }else if(strcmp(r_type,"delip") == 0){
      LOG(vlevel,cout,"Calling Function: parse_deliface");
      int returned = parse_deliface(ssl, r_ip, r_user, r_time);
      send_response(ssl, returned, response[returned]);
    }else if(strcmp(r_type,"gethost") == 0){
      LOG(vlevel,cout,"Calling Function: parse_gethost");
      int returned = parse_gethost(ssl);
      send_response(ssl, returned, response[returned]);
    }else if (strcmp(r_type, "on") == 0){
      LOG(vlevel,cout,"Calling Function: parse_on");
      int returned = parse_on(ssl, r_ip);
      send_response(ssl, returned, response[returned]);
    }else if (strcmp(r_type, "off") == 0){
      LOG(vlevel,cout,"Calling Function: parse_off");
      int returned = parse_off(ssl, r_ip);
      send_response(ssl, returned, response[returned]);
    }else if (strcmp(r_type, "list") == 0){
      LOG(vlevel,cout, "Calling function read for type: "<<r_type);
      all_ip = "";
      DirListing_t dirtree;
      GetDirListing( dirtree, networkFile, "", "list");
      LOG(vlevel,cout,"Sending to client: "<<std::endl<<all_ip.c_str());
      n = SSL_write(ssl,const_cast<char*>(all_ip.data()),all_ip.length());
      if (n < 0){
        LOG(vlevel,cout,response[67]);
        LOG(vlevel,cout,"send_response 67:"<<response[67]);
        send_response(ssl, 67, response[67]);
      }
    }else{
        LOG(vlevel,cout,"Type: "<<r_type<<" Not Recognized");
        send_response(ssl, 59, response[59]);
    }

  }
}
int send_response(SSL* ssl, int returned, char * msg){
  LOG(vlevel,cout,"Sending message: "<<msg);
  LOG(vlevel,cout,"Returning: "<<returned);
  char* c_reply = itoc(returned);
  SSL_free(ssl);
  if (n < 0){
    LOG(vlevel,cout,"Error Sending Response code:"<<returned<<":");
    return -1;
  }else{
    LOG(vlevel,cout,"c_reply: "<<c_reply<<") "<<msg);
    return 0;
  }
}
