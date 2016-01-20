//email.cpp
#include <fstream>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <iostream>
#include <stdio.h>
#include <sstream>
#include <string>
#include <fstream>
#include <map>
#include "../common/split.h"
#include "../common/global.h"
#include "../common/log.h"

#define SMTP_SERVER  "localhost.localdomain"
#define SUBJECT      "IP Changed"
#define FROM         "scanner@localhost.localdomain"
#define TO           "wileyj@localhost.localdomain"
#define REPLYTO      ""

using namespace std;
bool f_read(const char *filename);
int send_mail(const char *smtpserver, const char *from, const char *to, const char *subject, const char *replyto, const char *msg);

/*
static std::string delUnnecessary( std::string& str, std::string& key){
  int size = str.length();
  for(int j = 0; j<=size; j++){
    for(int i = 0; i <=j; i++){
      if((str[i] == ' ' && str[i+1] == ' ') || str[i] == '*'){
        str.erase(str.begin() + i);
      }else if(str[0]== ' '){
        str.erase(str.begin());
      }else if(str[i] == '\0' && str[i-1]== ' '){
        str.erase(str.end() - 1);
      }
      if(key != "subject"){
        str[i] = std::tolower(str[i]);
      }
    }
  }
  return str;
}
*/
void send_email(char file[16]){
  std::map<std::string, std::string> options;
  const char* mail_server  = SMTP_SERVER;
  const char* mail_subject = SUBJECT;
  const char* mail_from    = FROM;
  const char* mail_to      = TO;
  const char* mail_replyto = REPLYTO;

  ofstream outputfile;
  std::ifstream read_output;
  int f_length;
  read_output.open(file);
  read_output.seekg(0, std::ios::end);
  f_length = read_output.tellg();
  read_output.seekg(0, std::ios::beg);
  char* buffer = new char[f_length];
  read_output.read(buffer, f_length);
  read_output.close();

  LOG(vlevel,cout,"SMTP Server: "<<mail_server);
  LOG(vlevel,cout,"Subject:     "<<mail_subject);
  LOG(vlevel,cout,"From:        "<<mail_from); 
  LOG(vlevel,cout,"Mail To:     "<<mail_to);
  LOG(vlevel,cout,"ReplyTo:     "<<mail_replyto);
  if (send_mail(mail_server, mail_from, mail_to, mail_subject, mail_replyto, buffer ) != 0){
    LOG(vlevel,cout,"Message send failed!");
  }else{
    LOG(vlevel,cout,"Message sent successfully!");
  }
}
