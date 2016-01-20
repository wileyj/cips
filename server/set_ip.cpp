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
int activate_nic(std::string iface);

int set_ip(char* ip, char* user_id, char* timestamp, std::string netmask, std::string hwaddr, std::string iface, std::string iface_name){
  LOG(vlevel,cout,"Adding ip: "<<ip<<" To interface: "<<iface_file_short.c_str());
  LOG(vlevel,cout,"Received Options:");
  LOG(vlevel,cout,"\tip:         "<<ip);
  LOG(vlevel,cout,"\tuser:       "<<user_id);
  LOG(vlevel,cout,"\ttime:       "<<timestamp);
  LOG(vlevel,cout,"\tmask:       "<<netmask.c_str());
  LOG(vlevel,cout,"\thwaddr:     "<<hwaddr.c_str());
  LOG(vlevel,cout,"\tinterface:  "<<iface.c_str());
  LOG(vlevel,cout,"\tshortname:  "<<iface_name.c_str());
  LOG(vlevel,cout,"Interface file: "<<iface_file.c_str());

  ofstream ifcfg_out;
  LOG(vlevel,cout,"Opening NIC file: "<<iface_file.c_str());
  ifcfg_out.open(iface_file.c_str());
  if (ifcfg_out.fail()){
    LOG(vlevel,cout,"Error opening Interface file: "<<iface_file.c_str());
    exit(65);
  } 
  LOG(vlevel,cout,"Writing values to NIC file: "<<iface_file.c_str());
  ifcfg_out << "# Created by: "<<user_id<<std::endl;
  ifcfg_out << "# Created on: "<<timestamp<<std::endl;
  ifcfg_out << "DEVICE="<<iface_name<<std::endl;
  ifcfg_out << "HWADDR="<<hwaddr<<std::endl;
  ifcfg_out << "IPADDR="<<ip<<std::endl;
  ifcfg_out << "NETMASK="<<netmask<<std::endl;
  ifcfg_out << "ONBOOT=yes";
  
  LOG(vlevel,cout,"Closing NIC file: "<<iface_file.c_str());
  ifcfg_out.close();

  if(f_read(iface_file.c_str()) == 1){
    LOG(vlevel,cout,"Created file: "<<iface_file.c_str());
  }else{
    LOG(vlevel,cout,"Error creating file: "<<iface_file.c_str());
  }
  if(activate_nic(iface_name) == 0 ){
    LOG(vlevel,cout,"Nic "<<iface_name.c_str()<<" was activated");
  }else{
    LOG(vlevel,cout,"Nic was not activated");
  }
  return 0;
}

int activate_nic(std::string iface){
  Splitter split_name (iface, "-");
  std::string shortname;
  if (split_name.size() > 2){
    shortname = split_name[2];
  }else{
    shortname = iface;
  }
  if (strcmp(shortname.c_str(), "") != 0){
    LOG(vlevel,cout,"Activating interface: "<<shortname);
    char temp_ifup[21];
    sprintf(temp_ifup, "/sbin/ifup %s", shortname.c_str());
    system(temp_ifup);
    return 0;
  }else{
    LOG(vlevel,cout,"No Interface to activate");
    if (quiet != 1){
      cout<<response[33]<<std::endl;
    }
    exit(33);
  }
  return 0;
}
