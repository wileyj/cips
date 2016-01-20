#ifndef _RSA_H_ 
#define _RSA_H_

#define KEY_LENGTH  2048
#define PUB_EXP     3
#define PRINT_KEYS
#define WRITE_TO_FILE
#define FAIL    -1

extern size_t          pri_len;
extern size_t          pub_len;
extern char          * pri_key;
extern char          * pub_key;
extern char            msg[KEY_LENGTH/8]; 
extern char          * rsa_e;
extern char          * rsa_d;
extern char          * err;
extern int             encrypt_len;
extern RSA           * keypair;
extern BIO           * pri;
extern BIO           * pub;
extern SSL_CTX       * ctx;
extern int             server;
extern char          * portnum;
extern char            buf[1024];
extern char            reply[1024];
extern X509          * cert;
extern char          * line;
extern unsigned char * buff;
extern ssize_t         len;
extern char          * priv_out;
extern char          * pub_out;
extern char          * keyfile;

#endif
