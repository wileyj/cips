#include <string>
#include <iostream>
#include <stdio.h>

char * itoc(int x){
  int y = x;
  int end = 0;
  while(x >= 1) {
    x = x/10;
    end++;
  }
  char* cstr = NULL;
  cstr = new char [end+1];
  sprintf(cstr, "%i", y);
  return cstr;
}

