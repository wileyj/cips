#include <stdio.h>
#include <sys/types.h>
#include <string.h>
#include <iostream>
#include <openssl/ssl.h>
#include <openssl/err.h>
#include "../common/split.h"
#include "../common/global.h"
#include "../common/log.h"

using namespace::std;

int send_response(SSL* ssl, int returned, char * msg);
int get_host();

int parse_gethost(SSL* ssl){
  int n;
  if(get_host() == 0){
    LOG(vlevel,cout,"Sending to client: "<<hostname);
    //n = SSL_write(ssl, const_cast<char*>(hostname),sizeof(hostname)/8);
    n = SSL_write(ssl, const_cast<char*>(hostname),sizeof(hostname));
    if (n < 0){  
      LOG(vlevel,cout,response[50]);
      return 50; 
    }else{
      return 0;
    }
  }else{
    LOG(vlevel,cout,response[39]);
    if (send_response( ssl, 39, response[39]) == 0){
LOG(vlevel,cout,"send_response 39:"<<response[39]);
      return 0;
    }else{
LOG(vlevel, cout, "return 50");
      return 50;
    }
  }
LOG(vlevel, cout, "return -1");
  return -1;
}
