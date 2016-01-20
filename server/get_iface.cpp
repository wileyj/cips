#include <stdio.h>      
#include <ifaddrs.h>
#include <netinet/in.h> 
#include <string.h> 
#include <arpa/inet.h>
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include "../common/split.h"
#include "../common/global.h"
#include "../common/log.h"
#include <sstream>
#include <string>
#include <fstream>


using namespace std;
typedef std::vector <std::string> DirListing_t;
int GetDirListing( DirListing_t& result, const std::string& dirpath, char *ip, std::string type );

using namespace::std;

int get_host(){
  if (gethostname(hostname, sizeof hostname) == 0){
    LOG(vlevel,cout,"Hostname: "<<hostname);
    return 0;
  }else{
    return 10;
  }
}

int get_iface(char* ip){
  //found_iface = 0;
  LOG(vlevel,cout,"Looking for interface of ip: "<<ip);
  DirListing_t dirtree;
  LOG(vlevel, cout, "Looking in /etc/sysconfig/network-scripts for the interface file");
  LOG(vlevel, cout, "FOUND_IFACE: "<<found_iface);
  if(GetDirListing( dirtree, networkFile, ip, "get_iface") == 0){
    LOG(vlevel, cout, "Found Interface: "<<found_iface);
    return found_iface;
  }else{
    LOG(vlevel, cout, "NIC for: "<< ip <<" not found");
    return 61;
  }
}
