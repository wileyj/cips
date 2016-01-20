// log.h
#define LOG(vlevel,out, msg)\
do {\
  if (vlevel == 0){ }\
  if (vlevel == 1){ \
    out << "INFO: " << "("<<__TIME__<<") " << " " <<msg << std::endl; \
  }\
  if (vlevel == 2){ \
    out << "WARN: " << "("<<__TIME__<<") (" <<__FILE__<< ") " <<msg << std::endl; \
  }\
  if (vlevel == 3){ \
    out << "ERROR: " << "("<<__TIME__<<") (" <<__FILE__<< " @" << __LINE__<<") "<<msg << std::endl; \
  }\
  if (vlevel == 4){ \
    out << "DEBUG: " << "("<<__DATE__<<" "<<__TIME__<<") (" <<__FILE__<< " @" << __LINE__<<") "<<msg << std::endl; \
  }\
} while(0)
