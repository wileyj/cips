#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>

using namespace::std;

void chomp(const char *s){
  char *p;
  while (NULL != s && NULL != (p = strrchr(s, '\n'))){
    *p = '\0';
  }
}

std::string trim(std::string s){
  size_t endpos = s.find_last_not_of(" \t");
  if( string::npos != endpos ){
    s = s.substr( 0, endpos+1 );
  }
  return s;
}

