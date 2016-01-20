//help.cpp 
#include <iostream>
#include <string>
#include "global.h"
//#include "response.h"

using namespace std;

int serverHelp( char binary[] ){
  cout << "usage:\n  " <<  binary <<"                    " << std::endl;
  cout << "\t-v - Enable verbose logging (-vvvv)         " << std::endl;
  cout << "\t-e - Send email of output (Not Implemented) " << std::endl;
  cout << "\t-s - Suppress all output                    " << std::endl;
  cout << "\t-h - Help message                           " << std::endl;
  cout << "\t-r - List of Response Codes                 " << std::endl;
  cout << "\t-d - Run as a Daemon                        " << std::endl;
  cout << std::endl<<std::endl;
  return 0;
}
int clientHelp(char binary[] ){
  cout << "usage:\n  " <<  binary << std::endl;
  cout << "\t-i - IP   (required for type: getnic, setip, delip                 " << std::endl;
  cout << "\t-n - Nic  (required for type getip)                                " << std::endl;
  cout << "\t-H - Host (required for type gethost)                              " << std::endl;
  cout << "\t-t - Type (required, one of: getnic, getip, setip, delip, gethost) " << std::endl;
  cout << "\t-h - Help message                                                  " << std::endl;
  cout << "\t-r - List of Response Codes                                        " << std::endl;
  cout << "\t-s - Silent							" << std::endl;
  cout << "\t-v - Versbosity Level                                              " << std::endl;
  cout << std::endl;

  cout << "Find the Nic for a particular IP:"<<std::endl;
  cout << "\t"<<binary<<" -H <host> -i 10.0.2.15 -t getnic"<<std::endl<<std::endl;

  cout << "Get the IP of a particular NIC"<<std::endl;
  cout << "\t"<<binary<<" -H <host> -n eth0 -t getip"<<std::endl<<std::endl;

  cout << "Add Ip to a host"<<std::endl;
  cout << "\t"<<binary<<" -H <host> -i 10.0.2.25 -t setip"<<std::endl<<std::endl;

  cout << "Delete IP from host"<<std::endl;
  cout << "\t"<<binary<<" -H <host> -i 10.0.2.25 -t delip"<<std::endl<<std::endl;

  cout << "Get the hostname"<<std::endl;
  cout << "  ex: "<<binary<<" -H <host> -t gethost"<<std::endl<<std::endl;

  cout << "Disable an interface"<<std::endl;
  cout << "  ex: "<<binary<<" -H <host> -i 10.0.2.25 -t off"<<std::endl<<std::endl;

  cout << "Activating an interface"<<std::endl;
  cout << "  ex: "<<binary<<" -H <host> -i 10.0.2.25 -t on"<<std::endl<<std::endl;

  cout << "List all ips on a host:"<<std::endl;
  cout << "  ex: "<<binary<<" -H <host> -t list"<<std::endl<<std::endl;

  cout<<std::endl;
  return 0;
}

template <typename T, size_t N>
size_t foo(const T (&buffer)[N])
{
    cout << "size: " << N << endl;
    return N;
}

int showResponse(){
  cout<<std::endl<<"List of Response Codes and Messages:"<<std::endl;
  for (int i=0; i<RESPONSE_SIZE-1; i++){
    cout<<"\t"<<i<<") "<<response[i]<<std::endl;
  }
  return 0;
}
