
/* OpenSSL Client */
#include <fcntl.h>
#include <fstream>
#include <getopt.h>
#include <grp.h>
#include <iostream>
#include <malloc.h>
#include <netdb.h>
#include <ostream>
#include <netdb.h>
#include <resolv.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <openssl/x509.h>
#include <openssl/bio.h>
#include <openssl/rsa.h>
#include <openssl/pem.h>
#include <openssl/ssl.h>
#include <openssl/err.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/uio.h>
#include "../common/global.h"
#include "../common/log.h"
#include "../common/response.h"

using namespace::std;

void free_stuff();
int  rsa_key();
int  clientHelp( char binary[] );
void chomp(const char *s);
int  get_id();
bool validateIpAddress(const string ipAddress);
int check_user(char* id);
int showResponse();
int check_ip(char *arg_1, char *arg_2, char *arg_3);

struct group *grp;

extern int            h_errno;
int                   x2;
char                  g_dba[]  = "dba", **d_grp; // dba group
char                  g_serv[] = "servtech", **s_grp; // servtech group
char*                 euid = NULL; 
char*                 fname    = "/var/tmp/cipc.log";
int                   numWarnings;
int                   numErrors;
char*                 output;
ofstream              logfile;
ssize_t               len;
X509                * x;
unsigned              p_err;
char                  p_errmsg[1024];
unsigned int          n;
unsigned char       * buff;
size_t                pri_len;
size_t                pub_len;
char                * pri_key;
char                * pub_key;
char                * rsa_e = NULL;
char                * err;
int                   encrypt_len;
BIO                 * bio;
char                * priv_out = "priv.pem";
char                * pub_out  = "pub.pem";
char                * keyfile  = "key.pem";
bool                  email; 
bool                  quiet;
bool                  help;
bool                  d_mode;
int                   vlevel;


struct globalArgs_t {
  char* ip;      // -i option
  char* user; 
  char* scan;    // -s option
  char* nic;     // -n option
  char* host;    // -H option
  char* type;    // -t option
  bool  verbose; // -v option
  bool  quiet;   // -q option
} globalArgs;

static const struct option long_options[] = {
  { "ip",      no_argument,       NULL, 'i' },
  { "nic",     no_argument,       NULL, 'n' },
  { "scan",    no_argument,       NULL, 's' },
  { "host",    required_argument, NULL, 'H' },
  { "type",    required_argument, NULL, 't' },
  { "verbose", no_argument,       NULL, 'v' },
  { "quiet  ", no_argument,       NULL, 'q' },
  { "help",    no_argument,       NULL, 'h' },
  { "response",no_argument,       NULL, 'r' },
  { NULL,      no_argument,       NULL, 0   }
};

const std::string currentDateTime() {
  time_t     now = time(0);
  struct tm  tstruct;
  char       buf[80];
  tstruct = *localtime(&now);
  strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);
  return buf;
}

int OpenConnection(const char *hostname, int port){   
  int sd;
  struct hostent *host;
  struct sockaddr_in addr;
  if ( (host = gethostbyname(hostname)) == NULL ){
    LOG(vlevel,cout,"Hostname is NULL");
    if(quiet != 1){
      cout<<response[1]<<std::endl;
    }
    exit(1);
  }
  sd = socket(PF_INET, SOCK_STREAM, 0);
  bzero(&addr, sizeof(addr));
  addr.sin_family = AF_INET;
  addr.sin_port = htons(port);
  addr.sin_addr.s_addr = *(long*)(host->h_addr);
  if ( connect(sd, (struct sockaddr*)&addr, sizeof(addr)) != 0 ){
    close(sd);
    LOG(vlevel,cout,"Connection Error");
    if(quiet != 1){
      cout<<response[2]<<std::endl;
    }
    exit(2);
  }
  return sd;
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

SSL_CTX* InitCTX(void){   
  SSL_METHOD *method;
  SSL_CTX *ctx;
  OpenSSL_add_all_algorithms();  /* Load cryptos, et.al. */
  SSL_load_error_strings();   /* Bring in and register error messages */
  method = SSLv2_client_method();  /* Create new client-method instance */
  ctx = SSL_CTX_new(method);   /* Create new context */
  LoadCertificates(ctx, keyfile, keyfile);
  if( remove( priv_out ) != 0 ){
    LOG(vlevel,cout,"Error deleting private file");
  }else if( remove( pub_out) != 0 ){
    LOG(vlevel,cout,"Error deleting public file");
  }else if( remove( keyfile) != 0){
    LOG(vlevel,cout,"Error deleting keyfile");
  }else{
    LOG(vlevel,cout,"Files successfully deleted");
  }
  if ( ctx == NULL ){
    ERR_print_errors_fp(stderr);
    abort();
  }
  return ctx;
}

void ShowCerts(SSL* ssl){   
  X509 *cert;
  char *line;
  cert = SSL_get_peer_certificate(ssl); /* get the server's certificate */
  if ( cert != NULL ){
    LOG(vlevel,cout,"Received Server certificates:");

    line = X509_NAME_oneline(X509_get_subject_name(cert), 0, 0);
    LOG(vlevel,cout,"\t"<<line);
    free(line);       /* free the malloc'ed string */

    line = X509_NAME_oneline(X509_get_issuer_name(cert), 0, 0);
    chomp (line);
    LOG(vlevel,cout,"Issuer: "<<line);
    free(line);       /* free the malloc'ed string */
    ASN1_INTEGER *serial = X509_get_serialNumber(cert);
    BIGNUM *bnser        = ASN1_INTEGER_to_BN(serial, NULL);
    char * asciiHex       = BN_bn2hex(bnser);
    //int x_issuer_serial  = X509_issuer_and_serial_hash(cert);
    //int x_issuer = X509_issuer_name_hash(cert);
    //int x_hash = X509_subject_name_hash(cert);
    //logit("X509 Issuer & Serial: "<<x_issuer_serial);
    //logit("X509 Issuer:          "<<x_issuer);
    //logit("X509 Subject:         "<<x_hash);
    if(strcmp(asciiHex, "DA67C3D0D7AA3F22") == 0){
      LOG(vlevel,cout,"Serial: ");
      LOG(vlevel,cout,"\t"<<asciiHex);
    }else{
      LOG(vlevel,cout,"Server-Client Cert. Serial Numbers Don't Match...");
      if(quiet != 1){
        cout<<response[1]<<std::endl;
      }
      exit(3);
    }
    X509_free(cert);     /* free the malloc'ed certificate copy */
  }
}

int main(int argc, char *argv[]){   

  int sockfd, portnum, n;
  portnum = 22500;
  std::string timestamp = currentDateTime();
  SSL_CTX *ctx;
  int d_server;
  SSL *ssl;
  int r;
  char date[80];
  strcpy(date, __DATE__);
  strcat(date, ", ");
  strcat(date, __TIME__);
  int c;
  while(1){
    int option_index = 0;
    c = getopt_long (argc, argv, "i:n:H:t:s:vhrq?", long_options, &option_index);
    if (c == -1)
      break;
    switch(c){
      case 'i' :
        globalArgs.ip = optarg;
        break;
      case 'n' :
        globalArgs.nic = optarg;
        break;
      case 'H' :
        globalArgs.host = optarg;
        break;
      case 't' :
        globalArgs.type = optarg;
        break;
      case 's' :
	globalArgs.scan = optarg;
	break;
      case 'v' :
        globalArgs.verbose = true;
        vlevel++;
        break;
      case 'h':
        clientHelp(argv[0]);
        exit(0);
        break;
      case 'r':
        showResponse();
        return 1;
        break;
      case 'q':
        quiet = true;
        break;
      case '?':
        clientHelp(argv[0]);
        exit(0);
        break;
      default:
        clientHelp(argv[0]);
        exit(0);
        break;
    }
  }
  if (vlevel > 0 && quiet == 1){
    LOG(vlevel,cout,"Verbosity enabled with quiet mode. Verbosity overrides quiet");
  }
  //log_open(date, fname);
  if (get_id() == 0){
    LOG(vlevel,cout,"Returning id: "<<euid); 
    if ( strcmp(euid, "dba") == 0 ){
      LOG(vlevel,cout,"Execution as user '"<<euid<<"' is not allowed");
      LOG(vlevel,cout,"Execution as \"dba\" user is denied");
      LOG(vlevel, cout, response[4]);
      if (quiet != 1){ 
        cout<<response[4]<<std::endl; 
      }
      exit(4);
    }
    if( strcmp(euid, "mongodb") == 0 ){
      LOG(vlevel,cout,"Execution as user '"<<euid<<"' is not allowed");
      LOG(vlevel,cout,"Execution as \"mongodb\" user is denied");
      LOG(vlevel, cout, response[5]);
      if (quiet != 1){
        cout<<response[5]<<std::endl;
      }
      exit(5);
    }
    if ( strcmp(euid, "mysql") == 0){
      LOG(vlevel,cout,"Execution as user '"<<euid<<"' is not allowed");
      LOG(vlevel,cout,"Execution as \"mysql\" user is denied");
      LOG(vlevel, cout, response[6]);
      if (quiet != 1){
        cout<<response[6]<<std::endl;
      }
      exit(6);
    }
    if (check_user(euid) == 0){
      LOG(vlevel,cout,"Running as user: "<<globalArgs.user);
    }else{
      LOG(vlevel,cout,"User not in correct group");
      LOG(vlevel, cout, response[7]);
      if (quiet != 1){
        cout<<response[7]<<std::endl;
      }
      exit(7);
    }    
  }else{
    LOG(vlevel,cout,"Error retrieving the actual user id");
    LOG(vlevel,cout,"Error retrieving user id");
    LOG(vlevel, cout, response[8]);
    if (quiet != 1){
      cout<<response[8]<<std::endl;
    }
    exit(8);
  }
  if (argc < 2 || (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0)){
    clientHelp(argv[0]);
    exit(0);
  }
  if (globalArgs.ip){ 
    if(validateIpAddress(globalArgs.ip) == 1){
      LOG(vlevel,cout,"\tIP:      "<<globalArgs.ip);      
    }else{
      LOG(vlevel,cout,"Invalid ip address: "<<globalArgs.ip);
      LOG(vlevel,cout,"Invalid IP address");
      LOG(vlevel, cout, response[9]);
      if (quiet != 1){
        cout<<response[9]<<std::endl;
      }
      exit(9);
    }
  } 
  if (globalArgs.nic    ){ LOG(vlevel,cout,"\tNIC:     "<<globalArgs.nic);     }
  if (globalArgs.user   ){ LOG(vlevel,cout,"\tUser:    "<<globalArgs.user);    }
  if (globalArgs.host   ){ LOG(vlevel,cout,"\tHost:    "<<globalArgs.host);    }
  if (globalArgs.type   ){ LOG(vlevel,cout,"\tType:    "<<globalArgs.type);    }
  if (globalArgs.quiet  ){ LOG(vlevel,cout,"\tQuiet:   "<<globalArgs.quiet);   }
  if (globalArgs.scan   ){ LOG(vlevel,cout,"\tScan:    "<<globalArgs.scan);    }
  if (globalArgs.verbose){ LOG(vlevel,cout,"\tVerbose: "<<globalArgs.verbose); }
 

  if (globalArgs.scan){
    // ip/netmask to scan is in globalArgs.scan
    // need to find how to get verbose and number

    char* arg_1 = NULL;
    char* arg_2 = NULL;
    char* arg_3 = NULL;
    for (int j; j<argc; j++){
      if (strcmp (argv[j], globalArgs.scan) == 0){
	arg_1 = globalArgs.scan;
        if (argv[j+1] != NULL){
	        arg_2 = argv[j+1];
	}
	if (argv[j+2] != NULL){
      		arg_3 = argv[j+2];
	}
      }
    }
    LOG(vlevel,cout,"Calling ip scan function with args:"<<globalArgs.scan<<","<<arg_2<<","<<arg_3);
    int do_ipscan = check_ip(arg_1, arg_2, arg_3);
    cout<<"do_ipscan returned:"<<do_ipscan<<std::endl;
    return 0;
  }

 
  if (globalArgs.type == NULL){
    cout<<"Error: Required -t (type) option is missing"<<std::endl<<std::endl;
    LOG(vlevel,cout,"Missing type argument");
    LOG(vlevel, cout, response[10]);
    if (quiet != 1){ 
      cout<<response[10]<<std::endl; 
    }
    clientHelp(argv[0]);
    exit(10);
  }
  if (globalArgs.host == NULL){
    cout<<"Error: Required -H (host) option is missing"<<std::endl<<std::endl;
    LOG(vlevel,cout,"Missing host argument");
    LOG(vlevel, cout, response[11]);
    if(quiet != 1){
      cout<<response[11]<<std::endl;
    }
    exit(11);
  }

  char query[256]; 
  strcpy(query, "");

  globalArgs.ip   ? strcat(query, globalArgs.ip)   : strcat(query, ""); 
  strcat(query, "|");

  globalArgs.user ? strcat(query, globalArgs.user) : strcat(query, "");
  strcat(query, "|");

  globalArgs.nic  ? strcat(query, globalArgs.nic)  : strcat(query, "");
  strcat(query, "|");

  globalArgs.type ? strcat(query, globalArgs.type) : strcat(query, "");
  strcat(query, "|");

  strcat(query, timestamp.c_str());
  if (globalArgs.verbose){
    LOG(vlevel,cout,"Query: "<<query); 
  }

  struct sockaddr_in;
  struct hostent *server;
  server = gethostbyname(globalArgs.host);
  
  if ( !server ) { 
    LOG(vlevel,cout, hstrerror(h_errno)<<": host '"<<globalArgs.host<<"'");
    LOG(vlevel,cout,"Invalid hostname");
    LOG(vlevel, cout, response[12]);
    if(quiet != 1){
      cout<<response[12]<<std::endl;
    }
    exit(12);
  }else{
    LOG(vlevel,cout,"\tHost: "<<globalArgs.host);
    LOG(vlevel,cout,"\tOfficially: "<<server->h_name);
    for ( x2=0; server->h_aliases[x2]; ++x2 ) {
      LOG(vlevel,cout,"\tAliases: "<<server->h_aliases[x2]);
    }
    if ( server->h_addrtype == AF_INET ) {
      for ( x2=0; server->h_addr_list[x2]; ++x2 ) {
        LOG(vlevel,cout,"\tAddress: "<<inet_ntoa( *(struct in_addr *) server->h_addr_list[x2]));
      }
    }
    LOG(vlevel,cout,"");
  }

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0){
    LOG(vlevel,cout,"ERROR opening socket");
    LOG(vlevel, cout, response[41]);
    if(quiet != 1){
      cout<<response[41]<<std::endl;
    }
    exit(41);
  }

  if (rsa_key() != 0){
    LOG(vlevel,cout,"Error verifying the keyfiles");
    LOG(vlevel,cout,"Error verifying keyfiles");
    LOG(vlevel, cout, response[13]);
    if(quiet != 1){
      cout<<response[13]<<std::endl;
    }
    exit(13);
  }
  SSL_library_init();
  ctx = InitCTX();
  d_server = OpenConnection(globalArgs.host, portnum);
  ssl = SSL_new(ctx);      /* create new SSL connection state */
  SSL_set_fd(ssl, d_server);    /* attach the socket descriptor */
  
  if ( SSL_connect(ssl) == FAIL ){   /* perform the connection */
    ERR_print_errors_fp(stderr);
  }else{
    /*  Write Process */
    LOG(vlevel,cout,"Connected to "<<globalArgs.host<<" with "<<SSL_get_cipher(ssl)<<" encryption");
    ShowCerts(ssl);        /* get any certs */
    int s = SSL_write(ssl, query, strlen(query));   /* encrypt & send message */
    if(s < 0){
      LOG(vlevel,cout,"Error Sending data to server on host "<<globalArgs.host);
      LOG(vlevel,cout,"Error sending data");
      LOG(vlevel, cout, response[14]);
      if(quiet != 1){
        cout<<response[14]<<std::endl;
      }
      exit(14);
    }

    /* Read Process */
    bzero(query, 256);
    n = SSL_read(ssl, query, 256);
    char data[256];
    if (n < 0){
      LOG(vlevel,cout,"ERROR reading from socket");
      LOG(vlevel,cout,"Error reading from socket");
      LOG(vlevel, cout, response[42]);
      if(quiet != 1){
        cout<<response[42]<<std::endl;
      }
      exit(42);
    }
    sprintf(data, "%s", query);
    LOG(vlevel, cout, "Parsing output( " << data << " )");
    if (isdigit(data[0]) == 1 && validateIpAddress(data) == 0){
      r = atoi(data);
      if (!quiet){
        cout<<response[r]<<std::endl;
      }
    }else{
      r = 0; 
      if(!quiet){
        cout<<data<<std::endl;
      }
    }
    SSL_free(ssl);        /* release connection state */
  }
  LOG(vlevel, cout, "Closing client connection\n");
  close(d_server);         /* close socket */
  SSL_CTX_free(ctx);        /* release context */
  return r;
}

bool validateIpAddress(const string ipAddress){
  struct sockaddr_in sa;
  int result = inet_pton(AF_INET, ipAddress.c_str(), &(sa.sin_addr));
  return result != 0;
}
int check_user(char* id){
  char uid[sizeof(id)];
  strcpy(uid,id);
  grp = getgrnam(g_dba);
  for (d_grp=grp->gr_mem; (*d_grp) != NULL; d_grp++){
    if(strcmp(*d_grp, uid) == 0){
      LOG(vlevel,cout,"Matched user "<<*d_grp<<" from group: "<<g_dba);
      globalArgs.user = uid;
      return 0;
    }
  }

  //check the servtech group for id
  grp = getgrnam(g_serv);
  for (s_grp=grp->gr_mem; (*s_grp) != NULL; s_grp++){
    if(strcmp(*s_grp, uid) == 0){
      LOG(vlevel,cout,"Matched user "<<*s_grp<<" from group: "<<g_serv);
      globalArgs.user = *s_grp;
      return 0;
    }
  }
  LOG(vlevel,cout,"User "<<uid<<" is not in the correct group (dba/servtech");
  return -1;
}
