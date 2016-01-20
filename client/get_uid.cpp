#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <sstream>
#include "client.h"
#include "../common/global.h"
#include "../common/log.h"

using namespace::std;
void chomp(const char *s);

int get_id(){
  LOG(vlevel,cout,"Getting Effective uid");
  FILE *inpipe;
  char inbuf[1000];
  unsigned int i;
  int inchar;
  char *command = "who -m | awk {'print $1'}";
  inpipe = popen(command, "r");
  if (!inpipe) {
    LOG(vlevel,cout,"Error reading system() output");
    LOG(vlevel, cout, response[15]);
    if (quiet!= 1){
      cout<<response[15]<<std::endl;
    }
    exit(15);
  }
  for (i = 0; i < sizeof(inbuf) - 1; i++) {
    inchar = fgetc(inpipe);
    if (inchar == EOF) {
      break;
    }
    inbuf[i] = inchar;
  }
  inbuf[i] = 0;
  chomp(inbuf);
  LOG(vlevel,cout,"Number of chars read = "<<i); 
  LOG(vlevel,cout,"Buffer: <"<<inbuf<<">");
  pclose(inpipe);
  chomp(inbuf);
  euid = inbuf;
  return 0;
}   

