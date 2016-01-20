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
int    disable_nic(std::string iface);
 
int parse_off(SSL* ssl, char *r_ip){
  if (sizeof(r_ip) >= 8){
    if(get_iface(r_ip) == 1){
      LOG(vlevel,cout,"Disabling Interface: "<<iface_name.c_str());
      if(disable_nic(iface_name) == 0 ){
        if (send_response( ssl, 56, response[56]) == 0){
LOG(vlevel,cout,"send_response 56:"<<response[56]);
          return 0;
        }else{
          return 48;
        }
      }
    }else{
      if (send_response( ssl, 34, response[34]) == 0){
LOG(vlevel,cout,"send_response 34:"<<response[34]);
        return 0;
      }else{
        return 48;
      }
    }
  }else{
    LOG(vlevel,cout,"\t setip size of r_ipc: "<<sizeof(r_ip));
    if (send_response( ssl, 60, response[60]) == 0){
LOG(vlevel,cout,"send_response 60:"<<response[60]);
      return 0;
    }else{
      return 48;
    }
  }
  return -1;
} 
  
