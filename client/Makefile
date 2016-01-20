MAIN     := cipc
LIBS     := -L/usr/lib64 -L/lib64 -lz -lssl -lcrypto
CC       :=g++
CFLAGS   := -g -Wall -DTHREADSAFE=1
INCLUDES := -I/usr/include -I../common
INSTALL  := /usr/bin/install -c
BINDIR   := /usr/bin
.PHONY: default all clean

default: $(MAIN)
all: default

SOURCE = client.cpp ../common/rsa_key.cpp get_uid.cpp ../common/chomp.cpp ../common/help.cpp ip-ping.cpp ip-scan.cpp ../common/regex.cpp

OBJS = $(SOURCE:.c=.o)
.PHONY: depend clean
all:    $(MAIN)
	@echo  ""
	@echo  $(MAIN) has been compiled
	@echo  "******************************************"
	@echo  ""
$(MAIN): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(MAIN) $(OBJS) $(LIBS)
# this is a suffix replacement rule for building .o's from .c's
# it uses automatic variables $<: the name of the prerequisite of
# the rule(a .c file) and $@: the name of the target of the rule (a .o file)
# (see the gnu make manual section about automatic variables)
.c.o:
	$(CC) $(CFLAGS) $(LIBS) -c $<  -o $@
install:
	$(INSTALL) $(MAIN) $(BINDIR)/$(MAIN)

uninstall:
	$(RM) $(BINDIR)/$(MAIN)
	make clean
clean:
	$(RM) *.o *~ $(MAIN)

depend: $(SOURCE)
	makedepend $(INCLUDES) $^

# DO NOT DELETE THIS LINE -- make depend needs it

client.o: /usr/include/fcntl.h /usr/include/features.h
client.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
client.o: /usr/include/gnu/stubs.h /usr/include/gnu/stubs-64.h
client.o: /usr/include/bits/fcntl.h /usr/include/sys/types.h
client.o: /usr/include/bits/types.h /usr/include/bits/typesizes.h
client.o: /usr/include/time.h /usr/include/endian.h
client.o: /usr/include/bits/endian.h /usr/include/sys/select.h
client.o: /usr/include/bits/select.h /usr/include/bits/sigset.h
client.o: /usr/include/bits/time.h /usr/include/sys/sysmacros.h
client.o: /usr/include/bits/pthreadtypes.h /usr/include/getopt.h
client.o: /usr/include/grp.h /usr/include/stdio.h /usr/include/malloc.h
client.o: /usr/include/netdb.h /usr/include/netinet/in.h
client.o: /usr/include/stdint.h /usr/include/bits/wchar.h
client.o: /usr/include/sys/socket.h /usr/include/sys/uio.h
client.o: /usr/include/bits/uio.h /usr/include/bits/socket.h
client.o: /usr/include/limits.h /usr/include/limits.h
client.o: /usr/include/bits/posix1_lim.h /usr/include/bits/local_lim.h
client.o: /usr/include/linux/limits.h /usr/include/bits/posix2_lim.h
client.o: /usr/include/bits/sockaddr.h /usr/include/asm/socket.h
client.o: /usr/include/asm-x86_64/socket.h /usr/include/asm/sockios.h
client.o: /usr/include/asm-x86_64/sockios.h /usr/include/bits/in.h
client.o: /usr/include/bits/byteswap.h /usr/include/rpc/netdb.h
client.o: /usr/include/bits/netdb.h /usr/include/resolv.h
client.o: /usr/include/sys/param.h /usr/include/linux/param.h
client.o: /usr/include/asm/param.h /usr/include/asm-x86_64/param.h
client.o: /usr/include/arpa/nameser.h /usr/include/sys/bitypes.h
client.o: /usr/include/arpa/nameser_compat.h /usr/include/stdlib.h
client.o: /usr/include/alloca.h /usr/include/string.h /usr/include/unistd.h
client.o: /usr/include/bits/posix_opt.h /usr/include/bits/confname.h
client.o: /usr/include/arpa/inet.h /usr/include/openssl/x509.h
client.o: /usr/include/openssl/e_os2.h /usr/include/openssl/opensslconf.h
client.o: /usr/include/openssl/opensslconf-x86_64.h
client.o: /usr/include/openssl/symhacks.h /usr/include/openssl/buffer.h
client.o: /usr/include/openssl/ossl_typ.h /usr/include/openssl/evp.h
client.o: /usr/include/openssl/bio.h /usr/include/openssl/crypto.h
client.o: /usr/include/openssl/stack.h /usr/include/openssl/safestack.h
client.o: /usr/include/openssl/opensslv.h /usr/include/openssl/fips.h
client.o: /usr/include/openssl/objects.h /usr/include/openssl/obj_mac.h
client.o: /usr/include/openssl/asn1.h /usr/include/openssl/bn.h
client.o: /usr/include/openssl/rsa.h /usr/include/openssl/dsa.h
client.o: /usr/include/openssl/dh.h /usr/include/openssl/sha.h
client.o: /usr/include/openssl/x509_vfy.h /usr/include/openssl/lhash.h
client.o: /usr/include/openssl/pkcs7.h /usr/include/openssl/pem.h
client.o: /usr/include/openssl/pem2.h /usr/include/openssl/ssl.h
client.o: /usr/include/openssl/comp.h /usr/include/openssl/hmac.h
client.o: /usr/include/openssl/kssl.h /usr/include/ctype.h
client.o: /usr/include/krb5.h /usr/include/krb5/krb5.h
client.o: /usr/include/et/com_err.h /usr/include/openssl/ssl2.h
client.o: /usr/include/openssl/ssl3.h /usr/include/openssl/pq_compat.h
client.o: /usr/include/openssl/tls1.h /usr/include/openssl/dtls1.h
client.o: /usr/include/openssl/pqueue.h /usr/include/sys/time.h
client.o: /usr/include/openssl/ssl23.h /usr/include/openssl/err.h
client.o: /usr/include/errno.h /usr/include/bits/errno.h
client.o: /usr/include/linux/errno.h /usr/include/asm/errno.h
client.o: /usr/include/asm-x86_64/errno.h /usr/include/asm-generic/errno.h
client.o: /usr/include/asm-generic/errno-base.h /usr/include/sys/stat.h
client.o: /usr/include/bits/stat.h ../common/global.h ../common/log.h
client.o: ../common/response.h
../common/rsa_key.o: /usr/include/stdio.h /usr/include/sys/stat.h
../common/rsa_key.o: /usr/include/features.h /usr/include/sys/cdefs.h
../common/rsa_key.o: /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h
../common/rsa_key.o: /usr/include/gnu/stubs-64.h /usr/include/bits/types.h
../common/rsa_key.o: /usr/include/bits/typesizes.h /usr/include/time.h
../common/rsa_key.o: /usr/include/bits/stat.h /usr/include/stdlib.h
../common/rsa_key.o: /usr/include/sys/types.h /usr/include/endian.h
../common/rsa_key.o: /usr/include/bits/endian.h /usr/include/sys/select.h
../common/rsa_key.o: /usr/include/bits/select.h /usr/include/bits/sigset.h
../common/rsa_key.o: /usr/include/bits/time.h /usr/include/sys/sysmacros.h
../common/rsa_key.o: /usr/include/bits/pthreadtypes.h /usr/include/alloca.h
../common/rsa_key.o: /usr/include/fcntl.h /usr/include/bits/fcntl.h
../common/rsa_key.o: /usr/include/sys/uio.h /usr/include/bits/uio.h
../common/rsa_key.o: /usr/include/unistd.h /usr/include/bits/posix_opt.h
../common/rsa_key.o: /usr/include/bits/confname.h /usr/include/getopt.h
../common/rsa_key.o: /usr/include/string.h /usr/include/openssl/ssl.h
../common/rsa_key.o: /usr/include/openssl/e_os2.h
../common/rsa_key.o: /usr/include/openssl/opensslconf.h
../common/rsa_key.o: /usr/include/openssl/opensslconf-x86_64.h
../common/rsa_key.o: /usr/include/openssl/comp.h
../common/rsa_key.o: /usr/include/openssl/crypto.h
../common/rsa_key.o: /usr/include/openssl/stack.h
../common/rsa_key.o: /usr/include/openssl/safestack.h
../common/rsa_key.o: /usr/include/openssl/opensslv.h
../common/rsa_key.o: /usr/include/openssl/ossl_typ.h
../common/rsa_key.o: /usr/include/openssl/symhacks.h
../common/rsa_key.o: /usr/include/openssl/bio.h /usr/include/openssl/x509.h
../common/rsa_key.o: /usr/include/openssl/buffer.h /usr/include/openssl/evp.h
../common/rsa_key.o: /usr/include/openssl/fips.h
../common/rsa_key.o: /usr/include/openssl/objects.h
../common/rsa_key.o: /usr/include/openssl/obj_mac.h
../common/rsa_key.o: /usr/include/openssl/asn1.h /usr/include/openssl/bn.h
../common/rsa_key.o: /usr/include/openssl/rsa.h /usr/include/openssl/dsa.h
../common/rsa_key.o: /usr/include/openssl/dh.h /usr/include/openssl/sha.h
../common/rsa_key.o: /usr/include/openssl/x509_vfy.h
../common/rsa_key.o: /usr/include/openssl/lhash.h
../common/rsa_key.o: /usr/include/openssl/pkcs7.h /usr/include/openssl/pem.h
../common/rsa_key.o: /usr/include/openssl/pem2.h /usr/include/openssl/hmac.h
../common/rsa_key.o: /usr/include/openssl/kssl.h /usr/include/ctype.h
../common/rsa_key.o: /usr/include/krb5.h /usr/include/krb5/krb5.h
../common/rsa_key.o: /usr/include/limits.h /usr/include/limits.h
../common/rsa_key.o: /usr/include/bits/posix1_lim.h
../common/rsa_key.o: /usr/include/bits/local_lim.h
../common/rsa_key.o: /usr/include/linux/limits.h
../common/rsa_key.o: /usr/include/bits/posix2_lim.h /usr/include/et/com_err.h
../common/rsa_key.o: /usr/include/openssl/ssl2.h /usr/include/openssl/ssl3.h
../common/rsa_key.o: /usr/include/openssl/pq_compat.h
../common/rsa_key.o: /usr/include/openssl/tls1.h /usr/include/openssl/dtls1.h
../common/rsa_key.o: /usr/include/openssl/pqueue.h /usr/include/sys/time.h
../common/rsa_key.o: /usr/include/openssl/ssl23.h /usr/include/openssl/err.h
../common/rsa_key.o: /usr/include/errno.h /usr/include/bits/errno.h
../common/rsa_key.o: /usr/include/linux/errno.h /usr/include/asm/errno.h
../common/rsa_key.o: /usr/include/asm-x86_64/errno.h
../common/rsa_key.o: /usr/include/asm-generic/errno.h
../common/rsa_key.o: /usr/include/asm-generic/errno-base.h ../common/global.h
../common/rsa_key.o: ../common/log.h
get_uid.o: /usr/include/stdlib.h /usr/include/features.h
get_uid.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
get_uid.o: /usr/include/gnu/stubs.h /usr/include/gnu/stubs-64.h
get_uid.o: /usr/include/sys/types.h /usr/include/bits/types.h
get_uid.o: /usr/include/bits/typesizes.h /usr/include/time.h
get_uid.o: /usr/include/endian.h /usr/include/bits/endian.h
get_uid.o: /usr/include/sys/select.h /usr/include/bits/select.h
get_uid.o: /usr/include/bits/sigset.h /usr/include/bits/time.h
get_uid.o: /usr/include/sys/sysmacros.h /usr/include/bits/pthreadtypes.h
get_uid.o: /usr/include/alloca.h /usr/include/string.h client.h
get_uid.o: ../common/global.h ../common/log.h
../common/chomp.o: /usr/include/stdio.h /usr/include/stdlib.h
../common/chomp.o: /usr/include/features.h /usr/include/sys/cdefs.h
../common/chomp.o: /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h
../common/chomp.o: /usr/include/gnu/stubs-64.h /usr/include/sys/types.h
../common/chomp.o: /usr/include/bits/types.h /usr/include/bits/typesizes.h
../common/chomp.o: /usr/include/time.h /usr/include/endian.h
../common/chomp.o: /usr/include/bits/endian.h /usr/include/sys/select.h
../common/chomp.o: /usr/include/bits/select.h /usr/include/bits/sigset.h
../common/chomp.o: /usr/include/bits/time.h /usr/include/sys/sysmacros.h
../common/chomp.o: /usr/include/bits/pthreadtypes.h /usr/include/alloca.h
../common/chomp.o: /usr/include/string.h
../common/help.o: ../common/global.h
ip-ping.o: /usr/include/arpa/inet.h /usr/include/features.h
ip-ping.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
ip-ping.o: /usr/include/gnu/stubs.h /usr/include/gnu/stubs-64.h
ip-ping.o: /usr/include/netinet/in.h /usr/include/stdint.h
ip-ping.o: /usr/include/bits/wchar.h /usr/include/sys/socket.h
ip-ping.o: /usr/include/sys/uio.h /usr/include/sys/types.h
ip-ping.o: /usr/include/bits/types.h /usr/include/bits/typesizes.h
ip-ping.o: /usr/include/time.h /usr/include/endian.h
ip-ping.o: /usr/include/bits/endian.h /usr/include/sys/select.h
ip-ping.o: /usr/include/bits/select.h /usr/include/bits/sigset.h
ip-ping.o: /usr/include/bits/time.h /usr/include/sys/sysmacros.h
ip-ping.o: /usr/include/bits/pthreadtypes.h /usr/include/bits/uio.h
ip-ping.o: /usr/include/bits/socket.h /usr/include/limits.h
ip-ping.o: /usr/include/limits.h /usr/include/bits/posix1_lim.h
ip-ping.o: /usr/include/bits/local_lim.h /usr/include/linux/limits.h
ip-ping.o: /usr/include/bits/posix2_lim.h /usr/include/bits/sockaddr.h
ip-ping.o: /usr/include/asm/socket.h /usr/include/asm-x86_64/socket.h
ip-ping.o: /usr/include/asm/sockios.h /usr/include/asm-x86_64/sockios.h
ip-ping.o: /usr/include/bits/in.h /usr/include/bits/byteswap.h
ip-ping.o: /usr/include/sys/param.h /usr/include/linux/param.h
ip-ping.o: /usr/include/asm/param.h /usr/include/asm-x86_64/param.h
ip-ping.o: /usr/include/sys/file.h /usr/include/fcntl.h
ip-ping.o: /usr/include/bits/fcntl.h /usr/include/sys/time.h
ip-ping.o: /usr/include/netinet/in_systm.h /usr/include/netinet/ip.h
ip-ping.o: /usr/include/netinet/ip_icmp.h /usr/include/netdb.h
ip-ping.o: /usr/include/rpc/netdb.h /usr/include/bits/netdb.h
ip-ping.o: /usr/include/unistd.h /usr/include/bits/posix_opt.h
ip-ping.o: /usr/include/bits/confname.h /usr/include/getopt.h
ip-ping.o: /usr/include/stdio.h /usr/include/ctype.h /usr/include/string.h
ip-ping.o: /usr/include/stdlib.h /usr/include/alloca.h /usr/include/regex.h
ip-scan.o: /usr/include/stdlib.h /usr/include/features.h
ip-scan.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
ip-scan.o: /usr/include/gnu/stubs.h /usr/include/gnu/stubs-64.h
ip-scan.o: /usr/include/sys/types.h /usr/include/bits/types.h
ip-scan.o: /usr/include/bits/typesizes.h /usr/include/time.h
ip-scan.o: /usr/include/endian.h /usr/include/bits/endian.h
ip-scan.o: /usr/include/sys/select.h /usr/include/bits/select.h
ip-scan.o: /usr/include/bits/sigset.h /usr/include/bits/time.h
ip-scan.o: /usr/include/sys/sysmacros.h /usr/include/bits/pthreadtypes.h
ip-scan.o: /usr/include/alloca.h /usr/include/string.h /usr/include/stdio.h
ip-scan.o: /usr/include/errno.h /usr/include/bits/errno.h
ip-scan.o: /usr/include/linux/errno.h /usr/include/asm/errno.h
ip-scan.o: /usr/include/asm-x86_64/errno.h /usr/include/asm-generic/errno.h
ip-scan.o: /usr/include/asm-generic/errno-base.h /usr/include/netdb.h
ip-scan.o: /usr/include/netinet/in.h /usr/include/stdint.h
ip-scan.o: /usr/include/bits/wchar.h /usr/include/sys/socket.h
ip-scan.o: /usr/include/sys/uio.h /usr/include/bits/uio.h
ip-scan.o: /usr/include/bits/socket.h /usr/include/limits.h
ip-scan.o: /usr/include/limits.h /usr/include/bits/posix1_lim.h
ip-scan.o: /usr/include/bits/local_lim.h /usr/include/linux/limits.h
ip-scan.o: /usr/include/bits/posix2_lim.h /usr/include/bits/sockaddr.h
ip-scan.o: /usr/include/asm/socket.h /usr/include/asm-x86_64/socket.h
ip-scan.o: /usr/include/asm/sockios.h /usr/include/asm-x86_64/sockios.h
ip-scan.o: /usr/include/bits/in.h /usr/include/bits/byteswap.h
ip-scan.o: /usr/include/rpc/netdb.h /usr/include/bits/netdb.h
ip-scan.o: /usr/include/arpa/inet.h /usr/include/arpa/nameser.h
ip-scan.o: /usr/include/sys/param.h /usr/include/linux/param.h
ip-scan.o: /usr/include/asm/param.h /usr/include/asm-x86_64/param.h
ip-scan.o: /usr/include/sys/bitypes.h /usr/include/arpa/nameser_compat.h
ip-scan.o: /usr/include/resolv.h ../common/split.h
../common/regex.o: /usr/include/unistd.h /usr/include/features.h
../common/regex.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
../common/regex.o: /usr/include/gnu/stubs.h /usr/include/gnu/stubs-64.h
../common/regex.o: /usr/include/bits/posix_opt.h /usr/include/bits/types.h
../common/regex.o: /usr/include/bits/typesizes.h /usr/include/bits/confname.h
../common/regex.o: /usr/include/getopt.h /usr/include/sys/types.h
../common/regex.o: /usr/include/time.h /usr/include/endian.h
../common/regex.o: /usr/include/bits/endian.h /usr/include/sys/select.h
../common/regex.o: /usr/include/bits/select.h /usr/include/bits/sigset.h
../common/regex.o: /usr/include/bits/time.h /usr/include/sys/sysmacros.h
../common/regex.o: /usr/include/bits/pthreadtypes.h /usr/include/sys/stat.h
../common/regex.o: /usr/include/bits/stat.h /usr/include/regex.h
../common/regex.o: ../common/global.h
