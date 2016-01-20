#include <unistd.h>
#include <iostream>
#include <stdio.h>
#include <sstream>
#include <string>
#include <fstream>
#include "../common/split.h"
#include "../common/global.h"
#include "../common/log.h"
#define routefile "/proc/net/dev"

char *active;
int is_eth0;
int is_eth1;
int is_bond0;
using namespace std;
bool f_read(const char *filename);
int read_file( std::string filename, char* ip, std::string name, std::string type);

char * itoc(int x);

int find_iface(){
  read_file(routefile, "", "", "find_iface");
  iface_file = "";
  iface_file_short="";
  LOG(vlevel,cout,"\tActive Interface: "<<active);
  iface_file += networkFile;
  iface_file += "/";
  iface_file += "ifcfg-";
  iface_file += active;
  iface_file_short += active;
  iface_root = iface_file;
  iface_file_short += ":";
  iface_file += ":";
  int found = 0;
  int num = 0;
  while(found != 1){
    num++;
    std::string temp = iface_file;
    temp += itoc(num);
    if (f_read(temp.c_str()) != 1){
      found = 1;
      iface_file = temp;
      iface_file_short += itoc(num);
    }
  } 
  iface_hwaddr="";
  iface_netmask="";
  read_file(iface_root, "", "", "nicroot");
  LOG(vlevel,cout,"\tCreate new interface as: "<<iface_file.c_str());
  return 0;
}
