#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <iostream>
#include <stdio.h>
#include <sstream>
#include <string>
#include <fstream>
#include "../common/split.h"
#include "../common/global.h"
#include "../common/log.h"

using namespace std;
bool f_read(const char *filename);
int disable_nic(std::string iface);

int del_ip(char* ip, char* user_id, char* timestamp, std::string iface, std::string iface_short){
  LOG(vlevel,cout,"Deleting ip: "<<ip<<" on interface "<<iface_name.c_str());
  LOG(vlevel,cout,"Received Options:");
  LOG(vlevel,cout,"\tip:        "<<ip);
  LOG(vlevel,cout,"\tuser:      "<<user_id);
  LOG(vlevel,cout,"\ttimestamp: "<<timestamp);
  LOG(vlevel,cout,"\tinterface: "<<iface.c_str());
  LOG(vlevel,cout,"\tshortname: "<<iface_short.c_str());
  LOG(vlevel,cout,"Trying to Delete interface: "<<iface.c_str());
  LOG(vlevel,cout,"Active: "<<active);
  if (iface_short.compare(active) == 0){
    return 66;
  }
  if(disable_nic(iface) == 0 ){
    if (f_read(iface.c_str()) == 1){
      LOG(vlevel,cout,"Found file: "<<iface.c_str());
      char temp_rm[128];
      sprintf(temp_rm, "rm -f %s", iface.c_str());
      system(temp_rm);  
    }else{
      LOG(vlevel,cout,"Interface file not found: "<<iface.c_str());
      return 20;
    }
  }else{
    LOG(vlevel,cout,"Error disabling ip");
    return 20;
  }
  return 0;
}

int disable_nic(std::string iface){
  Splitter split_name (iface, "-");
  std::string shortname = split_name[2];
  if (strcmp(shortname.c_str(), "") != 0){
    LOG(vlevel,cout,"Shutting down interface: "<<shortname);
    char temp_ifdown[21];
    sprintf(temp_ifdown, "/sbin/ifdown %s", shortname.c_str());
    system(temp_ifdown);
    return 0;
  }else{
    LOG(vlevel,cout,"No Interface to disable");
    return 22;
  }
} 
