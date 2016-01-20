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
int    del_ip( char* ip, char* user_id, char* timestamp, std::string iface, std::string iface_short);

int parse_deliface(SSL* ssl, char *r_ip, char *r_user, char *r_time){
  if (sizeof(r_ip) >= 8){
    int r_getiface = get_iface(r_ip);
    if (r_getiface == 1){
      LOG(vlevel,cout,"Deleting Interface: "<<iface_name.c_str());
      int returned = del_ip(r_ip, r_user, r_time, iface_name, iface_name_short);
      if (returned == 0){
        if (send_response( ssl, 37, response[37]) == 0){
LOG(vlevel,cout,"send_response 37:"<<response[37]);
          return 0;
        }else{
          return 36;
        }
      }else{
        if (returned == 66){
          if(send_response( ssl, 66, response[66]) == 0){
LOG(vlevel,cout,"send_response 66:"<<response[66]);
            return 0;
          }
        }else{
          LOG(vlevel,cout,"\tdelip size of r_ip: "<<sizeof(r_ip));
          if (send_response( ssl, 60, response[60]) == 0){
LOG(vlevel,cout,"send_response 60:"<<response[60]);
            return 0;
          }
        }
        return 36;
      }
    }else{
      if (send_response( ssl, r_getiface, response[r_getiface]) == 0){
        LOG(vlevel,cout,"send_response "<<r_getiface<<": "<<response[r_getiface]);
        return 0;
      }else{
        return r_getiface;
      }  
    }
  }else{
    LOG(vlevel,cout,"\t deliface size of r_ip: "<<sizeof(r_ip));
    if (send_response( ssl, 61, response[61]) == 0){
LOG(vlevel,cout,"send_response 61:"<<response[61]);
      return 0;
    }else{
      return 36;
    }
  }
  return -1;
}
