#include <stdio.h>      
#include <sys/types.h>
#include <ifaddrs.h>
#include <netinet/in.h> 
#include <string.h> 
#include <arpa/inet.h>
#include <iostream>
#include "../common/split.h"
#include "../common/global.h"
#include "../common/log.h"

using namespace::std;

int get_ip(char* iface){
  LOG(vlevel,cout,"Looking for ip of interface: "<<iface);
  struct ifaddrs * ifAddrStruct=NULL;
  struct ifaddrs * ifa=NULL;
  void * tmpAddrPtr=NULL;
  getifaddrs(&ifAddrStruct);
  for (ifa = ifAddrStruct; ifa != NULL; ifa = ifa->ifa_next) {
    if (ifa ->ifa_addr->sa_family==AF_INET) {
      char *interface = ifa->ifa_name;
      if (strcmp(interface, iface) == 0){
        tmpAddrPtr=&((struct sockaddr_in *)ifa->ifa_addr)->sin_addr;
        char addressBuffer[INET_ADDRSTRLEN];
        inet_ntop(AF_INET, tmpAddrPtr, addressBuffer, INET_ADDRSTRLEN);
        iface_ip += addressBuffer;
        LOG(vlevel,cout,"Returning IP: "<<iface_ip.c_str());
        if (strcmp(iface_ip.c_str(), "") == 0){
          LOG(vlevel,cout,"IP is NULL");
          return 19;
        }
      }
    }
  }
  if (ifAddrStruct!=NULL){
    freeifaddrs(ifAddrStruct);
  }
  if (strcmp(iface_ip.c_str(), "") == 0){
    LOG(vlevel,cout,"IP is NULL");
    return 19;
  }else{
    return 0;
  }
}
