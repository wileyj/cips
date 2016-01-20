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
int    activate_nic(std::string iface);
 
int parse_on(SSL* ssl, char *r_ip){
  if (sizeof(r_ip) >= 8){
    if(get_iface(r_ip) == 1){
      if(activate_nic(iface_name) == 0 ){
        if (send_response( ssl, 58, response[58]) == 0){
LOG(vlevel,cout,"send_response 58:"<<response[58]);
          return 0;
        }else{
          return 47;
        }
      }else{
        if (send_response( ssl, 34, response[34]) == 0){
LOG(vlevel,cout,"send_response 34:"<<response[34]);
          return 0;
        }else{
          return 47;
        }
      }
    }else{
      if (send_response( ssl, 35, response[35]) == 0){
LOG(vlevel,cout,"send_response 35:"<<response[35]);
        return 0;
      }else{
        return 47;
      }
    }
  }else{
    LOG(vlevel,cout,"\t setip size of r_ipc: "<<sizeof(r_ip));
    if (send_response( ssl, 34, response[34]) == 0){
LOG(vlevel,cout,"send_response 34:"<<response[34]);
      return 0;
    }else{
      return 42;
    }
  }
  return -1;
}
