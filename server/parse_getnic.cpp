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
int    get_iface( char* ip );

int parse_getnic(SSL* ssl, char *r_ip){
  int n;
  if (sizeof(r_ip) >= 8){
    LOG(vlevel,cout,"Getting the NIC for ip: "<<r_ip);
    if(get_iface(r_ip) == 1){
      if (strcmp(iface_name_short.c_str(), "") != 0){
        LOG(vlevel,cout,"\tInterface: "<<iface_name_short.c_str()<<":");
        LOG(vlevel,cout,"Sending to client: "<<iface_name_short.c_str()<<":");
        n = SSL_write(ssl, const_cast<char*>(iface_name_short.data()),iface_name_short.length());
        if (n < 0){ 
          LOG(vlevel,cout,response[44]); 
          return 44;
        }else{
          return 0;
        }
      }
    }else{
      if (send_response( ssl, 55, response[55]) == 0){
        LOG(vlevel,cout, "send_response(55) returned 0");
        return 0;
      }else{
        return 44 ;
      }
    }
  }else{
    LOG(vlevel,cout,"\t getnic size of r_ip: "<<sizeof(r_ip));
    if (send_response( ssl, 53, response[53]) == 0){
      return 0;
    }else{
      return 44 ;
    }
  }
LOG(vlevel, cout, "This shouldn't be reached");
  return -1;
}
