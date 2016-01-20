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
int    find_iface();
int    set_ip(char* ip, char* user_id, char* timestamp, std::string netmask, std::string hwaddr, std::string iface, std::string iface_name);

int parse_setip(SSL* ssl, char *r_ip, char *r_user, char *r_time){
  if (sizeof(r_ip) >= 8){
    LOG(vlevel, cout, "sizof(r_ip):"<<sizeof(r_ip));
    if (get_iface(r_ip) == 61 && find_iface() == 0){
      LOG(vlevel,cout,"Setting ip ("<<r_ip<<") to interface: "<<iface_file_short.c_str());
      LOG(vlevel,cout,"Using interface: "<<iface_root.c_str()<<" as interface template");
      LOG(vlevel,cout,"Interface file: "<<iface_file.c_str());
      if(set_ip(r_ip, r_user, r_time, iface_netmask, iface_hwaddr, iface_file, iface_file_short) == 0){
        if (send_response( ssl, 62, response[62]) == 0){
          return 0;
        }else{
          return 54;
        }
      }else{
        if (send_response( ssl, 38, response[38]) == 0){
          return 0;
        }else{
          return 54;
        }
      }
    }else{
     LOG(vlevel, cout, "Found Existing interface for ip: "<<r_ip);
     if (send_response( ssl, 63, response[63]) == 0){
       return 0;
     }else{
       return 54;
     }
   } 
  }else{
    LOG(vlevel,cout,"\t setip size of r_ipc: "<<sizeof(r_ip));
    if (send_response( ssl, 40, response[40]) == 0){
      return 0;
    }else{
      return 54;
    }
  }
  return -1;
}
