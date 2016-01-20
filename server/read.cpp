#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <iostream>
#include <stdio.h>
#include <sstream>
#include <string.h>
#include <fstream>
#include <dirent.h>
#include <vector>
#include <map>
#include "../common/split.h"
#include "../common/global.h"
#include "../common/log.h"

using namespace::std;
typedef std::vector <std::string> DirListing_t;
int read_file( std::string filename, char *ip, std::string name, std::string type);
int GetDirListing( DirListing_t& result, const std::string& dirpath, char *ip, std::string type );
int string_regex(std::string str, std::string pattern);
bool f_read(const char *filename);
int get_ip(char* iface);
void chomp(const char *s);
string trim(std::string s);

int GetDirListing( DirListing_t& result, const std::string& dirpath, char *ip, std::string type ){
  LOG(vlevel, cout, "Function GetDirListing");
  LOG(vlevel, cout, "dirpath: "<<dirpath);
  LOG(vlevel, cout, "ip: "<<ip);
  LOG(vlevel, cout, "type: "<<type);
  DIR* dir = opendir( dirpath.c_str() );
  if (dir){
    LOG(vlevel, cout, "Looking in path: "<<dirpath);
    struct dirent* entry;
    while ((entry = readdir( dir ))){
      struct stat entryinfo;
      std::string entryname = entry->d_name;
      if (string_regex(entryname, "ifcfg-eth") == 1){
        if(string_regex(entryname, "sav") == 0 && string_regex(entryname, "bak") == 0 && string_regex(entryname, "orig") == 0 && string_regex(entryname, "orig") == 0){
          LOG(vlevel, cout, "Parsing filename: "<<entryname); 
          if(type.compare("list") == 0){
            Splitter split ( entryname, "-");
            char* s_iface;
            strcpy(s_iface, split[1].c_str()); 
            LOG(vlevel, cout, "Getting ip for interface: "<<split[1].c_str());
            if(get_ip(s_iface) == 0){
              all_ip += s_iface;
              all_ip += "\t: ";
              all_ip += iface_ip;
              all_ip += "\n";
              iface_ip = "";
            }else{
              LOG(vlevel,cout, "Failed to get IP for iface: "<<split[1].c_str());
            }
          }else{
            Splitter split ( entryname, ":");
            int size = split.size();
            if (size >= 1){
              std::string entrypath = dirpath + "/" + entryname;
              if (!stat( entrypath.c_str(), &entryinfo )){
                if (S_ISDIR( entryinfo.st_mode )){
                  if      (entryname == ".."){}
                  else if (entryname == "." ){
                    result.push_back( dirpath + "/" );
                  }else{
                    GetDirListing( result, entrypath, ip, type);
                  }
                }else{
                  std::string full_path;
                  std::string cwd = getcwd(NULL, 0);
                  std::string full_path_a;
                  if (entrypath[0] == '.'){
                    full_path_a = cwd + "/" + entrypath;
                  }else if(entrypath[0] == '/'){
                    full_path_a = entrypath;
                  }else{
                    full_path_a = cwd + "/" + entrypath;
                  }
                  full_path = full_path_a;
                  LOG(vlevel, cout, "read_file("<<full_path<<")");
                  if(string_regex(entryname, "sav") == 0 && string_regex(entryname, "bak") == 0 && string_regex(entryname, "orig") == 0 && string_regex(entryname, "orig") == 0){
                    LOG(vlevel,cout,"Reading File: "<<entryname);
                    read_file(full_path_a, ip, entryname, type); 
                    if(found_iface == 1){
LOG(vlevel,cout,"found_iface == "<<found_iface);
LOG(vlevel,cout, "Return: 0");
                      return 0;
                    }
                  }else{
                    LOG(vlevel,cout,"Skipping File: "<<entryname);
                  }
                }
              }
            }
          }
        }
      }
    }
    closedir( dir );
  }
LOG(vlevel,cout, "Return: -1");
  return -1;
}

int read_file( std::string filename, char* ip, std::string name, std::string type){
  LOG(vlevel, cout, "Function read_file");
  LOG(vlevel, cout, "Type: "<<type);
  iface_name="";
  iface_name_short="";
  ifstream inputfile;
  if(sizeof(ip) >= 8 ){
    LOG(vlevel,cout,"Looking for ip: "<<ip);
  }else{
    LOG(vlevel,cout,"Looking for the active NIC");
  }
  inputfile.open(filename.c_str(), ios::in);
  if(f_read(filename.c_str()) == 1){
    LOG(vlevel,cout, "Opening and Reading file: "<<filename);
    while(!inputfile.eof()){
      string line;
      getline(inputfile,line);
      if(!line.empty()){
        if (type.compare("get_iface") == 0){
          Splitter split_n ( line, "=");
          int size_n = split_n.size();
          if (size_n == 2){
            if(trim(split_n[1]).compare(ip) == 0){
              found_iface = true;
              Splitter split_name (name, "-");
              iface_name_short = trim(split_name[1]);
              iface_name = filename;
LOG(vlevel,cout, "Return: 0");
              return 0;
            } 
          }
        }else if (type.compare("find_iface") == 0){
          std::string temp = line.substr(2,4);
          stringstream st;
          std::string ty;
          st << temp[0];
          st >> ty;
          if (ty.compare("e") == 0){
            if (temp == "eth0"){
              is_eth0 = 1;
            }else if (temp == "eth1"){
              is_eth1 = 1;
            }else if (temp == "bond0"){
              is_bond0 = 1;
            }else{}   
          }
        }else if (type.compare("nicroot") == 0){
          Splitter split_r (line, "=");
          if(split_r[0].compare("HWADDR") == 0){
            iface_hwaddr = trim(split_r[1]);
          }
          if(split_r[0].compare("NETMASK") == 0){
            iface_netmask = trim(split_r[1]);
          }
        }else{
          LOG(vlevel, cout, "Type is not recognized: "<<type);
LOG(vlevel,cout, "Return: 10");
          return 10;
        }
      }
    }
  }else{
    LOG(vlevel, cout, "Error Opening file:"<<filename);
LOG(vlevel,cout, "Return: 65");
    return 65;
  }
  if (type.compare("find_iface") == 0){
    if(is_eth0 == 1){
      active="eth0";
    }else{
      if (is_eth1 == 1){
        active="eth1";
      }else{
        if (is_bond0 == 1){
          active="bond0";
        }
      }      
    }
  }
LOG(vlevel,cout, "Return: -1");
  return -1;
}


