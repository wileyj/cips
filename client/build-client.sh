g++ -c -Wall client.cpp ../common/rsa_key.cpp get_uid.cpp ../common/chomp.cpp ../common/help.cpp ip-ping.cpp ip-scan.cpp ../common/regex.cpp
g++ -DTHREADSAFE=1 -L/usr/lib64 -L/lib64 -lz -lssl -lcrypto -o cipc client.o rsa_key.o get_uid.o chomp.o help.o ip-scan.o ip-ping.o regex.o
