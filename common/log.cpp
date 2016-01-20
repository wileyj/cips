
#include <fstream>
#include <iostream>
#include <ostream>
#include <sstream>
#include <string>
#include <stdarg.h>
#include <cxxabi.h>
#include <typeinfo>
#include "global.h"
#include "log.h"

using namespace::std;

void do_log(const char *fmt, va_list args);
char *loglevel;

void logit(const char *fmt,...){
  va_list args;
  va_start(args, fmt);
  if (vlevel == 1){ 
    loglevel = "INFO "; 
  }else if (vlevel == 2){ 
    loglevel = "WARN "; 
  }else if (vlevel == 3){ 
    loglevel = "ERROR"; 
  }else if (vlevel == 4){ 
    loglevel = "DEBUG"; 
  }else{
    loglevel = "DEFAULT";
  }
  do_log(fmt, args);
  va_end(args);
}

void do_log(const char *fmt, va_list args){
  char msgbuf[MSGBUFSIZ];
  char fmtbuf[MSGBUFSIZ];
  char *txt = NULL;
  if (vlevel > 0){
    if(vlevel == 2){numWarnings++;}
    if(vlevel == 3){numErrors++;}
  }
  snprintf(fmtbuf, sizeof(fmtbuf), "%s: %s", txt, fmt);
  vsnprintf(msgbuf, sizeof(msgbuf), fmt, args);
  if (strcmp(loglevel, "DEFAULT") == 0){
    quiet ? cout<<"" : cout << msgbuf << std::endl;
    if(logfile.is_open()){
      logfile << msgbuf << std::endl;
    }
  }else{
    quiet ? cout<<"" : cout<<"["<<loglevel<<"] "<< msgbuf << std::endl;
    if(logfile.is_open()){
      logfile << "["<<loglevel<<"] "<< msgbuf << std::endl;
    }
  }
}

void log_open(const char *timestamp, const char *fname) { 
  logfile.open (fname);
  if (logfile.is_open()) {
    logfile << "Created on " << timestamp << std::endl;
    logfile << "_____________________________________________________________________" << std::endl << std::endl;
    quiet ? cout<<"" : cout << "Logging to: "<< fname << std::endl;
    quiet ? cout<<"" : cout << "Timestamp:  "<< timestamp << std::endl<<std::endl;
  }
}

void log_close(const char *fname) { 
  if (logfile.is_open()) {
    logfile << std::endl;
    logfile << "Warnings: " << numWarnings << std::endl;
    logfile << "Errors:   " << numErrors << std::endl;
    logfile << "_____________________________________________________________________" << std::endl << std::endl;
    logfile.close();
  }
}
void error(const char *msg, int r_code){
    perror(msg);
    exit(r_code);
}


//#endif
