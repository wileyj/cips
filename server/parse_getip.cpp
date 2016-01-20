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

int    send_response(SSL* ssl, int returned, char * msg);
int    get_ip( char* iface );

int parse_getip(SSL* ssl, char *r_nic){
  int n;
  if (sizeof(r_nic) >= 8){
    LOG(vlevel,cout,"Getting IP of NIC: "<<r_nic);
    if (get_ip(r_nic) == 0){
      LOG(vlevel,cout,"Interface: "<<r_nic<<" IP:"<<iface_ip.c_str());
      LOG(vlevel,cout,"Sending to client: "<<iface_ip.c_str());
      n = SSL_write(ssl,const_cast<char*>(iface_ip.data()),iface_ip.length());
      if (n < 0){ 
        LOG(vlevel,cout,response[43]); 
        return 43;
      }else{
        return 0;
      }
    }else{
      if (send_response(ssl, 40, response[40]) == 0){
LOG(vlevel,cout,"send_response 40:"<<response[40]);
        return 0;
      }else{
        return 43;
      }
    }
  }else{
    LOG(vlevel,cout,"\t getip size of r_nic: "<<sizeof(r_nic));
    if (send_response(ssl, 53, response[53]) == 0){
LOG(vlevel,cout,"send_response 53:"<<response[53]);
      return 0;
    }else{
      return 43;
    }
  }
  return -1;
}
