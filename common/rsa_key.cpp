/* rsa.cpp */
//gcc -ggdb -Wall -Wextra -o rsa-test rsa-test.c -lcrypto
#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <iostream>
#include <fstream>
#include <unistd.h>
#include <string.h>
#include <openssl/ssl.h>
#include <openssl/err.h>
#include <openssl/x509.h>
#include <openssl/bio.h>
#include <openssl/rsa.h>
#include <openssl/pem.h>
#include "global.h"
#include "log.h"

using namespace::std;
RSA           * keypair;
BIO           * pri;
BIO           * pub;
int rsa_key() {
  struct stat           sb;
  int                   fd;
  char                  priv[1000];
  char                  pub[1000];
  ofstream key_stream;
  ofstream pri_stream;
  ofstream pub_stream;
  key_stream.open(keyfile);
  if (key_stream.fail()){
    LOG(vlevel,cout,"Error opening keyfile: "<<keyfile<<" for writing");
    if (quiet != 1){
      cout<<response[17]<<std::endl;
    }
    exit(17);
  }
  pri_stream.open(priv_out);
  if (pri_stream.fail()){
    LOG(vlevel,cout,"Error opening Output file: "<<priv_out<<" for writing");
    if (quiet != 1){
      cout<<response[18]<<std::endl;
    }
    exit(18);
  } 
  pub_stream.open(pub_out);
  if (pub_stream.fail()){
    LOG(vlevel,cout,"Error opening Output file: "<<pub_out<<" for writing");
    if (quiet != 1){
      cout<<response[19]<<std::endl;
    }
    exit(19);
  }
  strcpy(priv, "-----BEGIN RSA PRIVATE KEY-----\n");
  strcat(priv, "MIICWwIBAAKBgQC6TzDFqIlsfzo2gk6etKFkW3xWPqX9QxnjklpZ51LguNlrD+Ga\n");
  strcat(priv, "zc6t4g2L9/WyTffSU6jBJpM2FDqX89RJcONPF13llc8GR4+rO7d/dXdcXZW6ba76\n");
  strcat(priv, "PhZEiBtiAaMy11dRDbZZHQBYdQ2H/teWcG/TzFDxaQ9rVgg7vn5IYAjG1QIDAQAB\n");
  strcat(priv, "AoGAHbFzV31F8bnRQFDCUP7+3ezKw0AW2mdwX9m6dqushM5RMIQGc9KrRwFJIW6y\n");
  strcat(priv, "hOlyPt5AfhA01CCjOgaNZesM/w9f4tni6oNS/c1ZtC1S/2ELGrazmNTV5OHxkqyz\n");
  strcat(priv, "EekpyJUqdZBxRl+yfikNXeOgmG3+KQZvlu1KeuMs8iljit0CQQDboZFCgoEgFPyG\n");
  strcat(priv, "P3PbXCuQlEO8q4HLC0tqVS5+mS1deNHCvf99v6W7G/3MOmi9y+TZOk93m6omSeQP\n");
  strcat(priv, "x3fdm/OTAkEA2SkSYFf0ydETI8XmB0qAPAuwouN5BuoWp26W9s2RAIGjOYr+/S0r\n");
  strcat(priv, "ML5X5CWMxQj1oE5RPmvBdYL5/eIjg66s9wJARSqhk1+ECLVzPVf4RYnGUnbOyjj8\n");
  strcat(priv, "3BPHgUooJUhaCAjHjlvFfTWAnOdYyxtN5w+yF1MMua81K2+zueBoeErnrwJAGrlM\n");
  strcat(priv, "MqEAVcmt4kwbR7BqYXlKznDR1wD9srMQTuTzQC2z6YPqZzukwgXaiQ/559F3cLfS\n");
  strcat(priv, "lazrDMwGebDXj//x9wJAFym52/MvYVoTnHoafF8MxWedFhnOjAUGKNQwikioe81r\n");
  strcat(priv, "cAxU1mWgEjsTqEaMKgo/ctvVgedRoHr4/XMGWneZoQ==\n");
  strcat(priv, "-----END RSA PRIVATE KEY-----\n");
  pri_stream << priv;
  key_stream << priv;
  pri_stream.close();

  LOG(vlevel,cout,"Generating RSA ("<<KEY_LENGTH<<" bits) keypair...");
  FILE *fp = fopen(priv_out, "r");
  keypair = PEM_read_RSAPrivateKey(fp, NULL, NULL, NULL);
  fclose(fp);
  LOG(vlevel,cout,"RSA keypair...Done");
  

  strcpy(pub, "-----BEGIN CERTIFICATE-----\n");
  strcat(pub, "MIIDvzCCAyigAwIBAgIJANpnw9DXqj8iMA0GCSqGSIb3DQEBBQUAMIGcMQswCQYD\n");
  strcat(pub, "VQQGEwJVUzERMA8GA1UECBMITmV3IFlvcmsxFjAUBgNVBAcTDU5ldyBZb3JrIENp\n");
  strcat(pub, "dHkxEzARBgNVBAoTClZpYWNvbSBJbmMxFTATBgNVBAsTDE1UViBOZXR3b3JrczES\n");
  strcat(pub, "MBAGA1UEAxMJZGJhLWFkbWluMSIwIAYJKoZIhvcNAQkBFhNtYWlsQGRiYS52aWFj\n");
  strcat(pub, "b20uY29tMB4XDTEzMDgyNjE4MzQ0N1oXDTE0MDgyNjE4MzQ0N1owgZwxCzAJBgNV\n");
  strcat(pub, "BAYTAlVTMREwDwYDVQQIEwhOZXcgWW9yazEWMBQGA1UEBxMNTmV3IFlvcmsgQ2l0\n");
  strcat(pub, "eTETMBEGA1UEChMKVmlhY29tIEluYzEVMBMGA1UECxMMTVRWIE5ldHdvcmtzMRIw\n");
  strcat(pub, "EAYDVQQDEwlkYmEtYWRtaW4xIjAgBgkqhkiG9w0BCQEWE21haWxAZGJhLnZpYWNv\n");
  strcat(pub, "bS5jb20wgZ8wDQYJKoZIhvcNAQEBBQADgY0AMIGJAoGBALpPMMWoiWx/OjaCTp60\n");
  strcat(pub, "oWRbfFY+pf1DGeOSWlnnUuC42WsP4ZrNzq3iDYv39bJN99JTqMEmkzYUOpfz1Elw\n");
  strcat(pub, "408XXeWVzwZHj6s7t391d1xdlbptrvo+FkSIG2IBozLXV1ENtlkdAFh1DYf+15Zw\n");
  strcat(pub, "b9PMUPFpD2tWCDu+fkhgCMbVAgMBAAGjggEFMIIBATAdBgNVHQ4EFgQU/KIGsVaG\n");
  strcat(pub, "UJJCinvbTADXM89rK5AwgdEGA1UdIwSByTCBxoAU/KIGsVaGUJJCinvbTADXM89r\n");
  strcat(pub, "K5ChgaKkgZ8wgZwxCzAJBgNVBAYTAlVTMREwDwYDVQQIEwhOZXcgWW9yazEWMBQG\n");
  strcat(pub, "A1UEBxMNTmV3IFlvcmsgQ2l0eTETMBEGA1UEChMKVmlhY29tIEluYzEVMBMGA1UE\n");
  strcat(pub, "CxMMTVRWIE5ldHdvcmtzMRIwEAYDVQQDEwlkYmEtYWRtaW4xIjAgBgkqhkiG9w0B\n");
  strcat(pub, "CQEWE21haWxAZGJhLnZpYWNvbS5jb22CCQDaZ8PQ16o/IjAMBgNVHRMEBTADAQH/\n");
  strcat(pub, "MA0GCSqGSIb3DQEBBQUAA4GBAKOxk1Fe4Y6uq8zs0l46bBPTE3iwwz9/DhbKeXuG\n");
  strcat(pub, "+TJ3PkddYR/h5U/s8ul2wVaBdIwb+JXVk9RXhWuVo0pukNh6GSo908AUtn+mZKcp\n");
  strcat(pub, "QQ9yvdQmwXPVjVr/7NsOqk7BPKwa42zfk4ZJzfhxTr1G9MebLdHMo10uTczztck6\n");
  strcat(pub, "5Mvu\n");
  strcat(pub, "-----END CERTIFICATE-----\n");
  pub_stream << pub;
  key_stream << pub;
  pub_stream.close();

  if ((stat(keyfile, &sb)) == -1){
    LOG(vlevel, cout, response[20]); 
    if (quiet != 1){
      cout<<response[20]<<std::endl;
    }
    exit(20);
  };
  len = (sb.st_size * 2);
  if (!(buff = (unsigned char*)malloc(len))){
    LOG(vlevel, cout, response[21]);
    if (quiet != 1){
      cout<<response[21]<<std::endl;
    }
    exit(21);
  };
  if ((fd = open(keyfile, O_RDONLY)) == -1){
    free(buff);
    LOG(vlevel, cout, response[22]);
    if (quiet != 1){
      cout<<response[22]<<std::endl;
    }
    exit(22);
  };
  if ((len = read(fd, buff, len)) == -1){
    free(buff);
    LOG(vlevel, cout, response[23]);
    if (quiet != 1){
      cout<<response[23]<<std::endl;
    }
    exit(23);
  };
  close(fd);
  return 0;
}

void free_stuff(){
  RSA_free(keypair);
  BIO_free_all(pub);
  BIO_free_all(pri);
  free(pri_key);
  free(pub_key);
  free(err);
}
