MAIN     := cips
LIBS     := -L/usr/lib64 -L/lib64 -lz -lssl -lcrypto
CC       := g++
CFLAGS   := -g -Wall -DTHREADSAFE=1
INCLUDES := -I/usr/include -I../common
INSTALL  := /usr/bin/install -c
SBINDIR  := /usr/sbin


.PHONY: default all clean

default: $(MAIN)
all: default

SOURCE = server.cpp smtpfuncs.cpp find_iface.cpp get_iface.cpp get_ip.cpp set_ip.cpp del_ip.cpp  read.cpp parse_deliface.cpp parse_gethost.cpp parse_getip.cpp parse_getnic.cpp parse_off.cpp parse_on.cpp parse_setip.cpp ../common/chomp.cpp ../common/itoc.cpp ../common/rsa_key.cpp ../common/help.cpp ../common/regex.cpp email.cpp

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
	$(INSTALL) $(MAIN) $(SBINDIR)/$(MAIN)

uninstall:
	$(RM) $(SBINDIR)/$(MAIN)
	make clean
clean:
	$(RM) *.o *~ $(MAIN)

depend: $(SOURCE)
	makedepend $(INCLUDES) $^

# DO NOT DELETE THIS LINE -- make depend needs it

server.o: /usr/include/errno.h /usr/include/features.h
server.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
server.o: /usr/include/gnu/stubs.h /usr/include/gnu/stubs-64.h
server.o: /usr/include/bits/errno.h /usr/include/linux/errno.h
server.o: /usr/include/asm/errno.h /usr/include/asm-x86_64/errno.h
server.o: /usr/include/asm-generic/errno.h
server.o: /usr/include/asm-generic/errno-base.h /usr/include/fcntl.h
server.o: /usr/include/bits/fcntl.h /usr/include/sys/types.h
server.o: /usr/include/bits/types.h /usr/include/bits/typesizes.h
server.o: /usr/include/time.h /usr/include/endian.h
server.o: /usr/include/bits/endian.h /usr/include/sys/select.h
server.o: /usr/include/bits/select.h /usr/include/bits/sigset.h
server.o: /usr/include/bits/time.h /usr/include/sys/sysmacros.h
server.o: /usr/include/bits/pthreadtypes.h /usr/include/malloc.h
server.o: /usr/include/resolv.h /usr/include/netinet/in.h
server.o: /usr/include/stdint.h /usr/include/bits/wchar.h
server.o: /usr/include/sys/socket.h /usr/include/sys/uio.h
server.o: /usr/include/bits/uio.h /usr/include/bits/socket.h
server.o: /usr/include/limits.h /usr/include/limits.h
server.o: /usr/include/bits/posix1_lim.h /usr/include/bits/local_lim.h
server.o: /usr/include/linux/limits.h /usr/include/bits/posix2_lim.h
server.o: /usr/include/bits/sockaddr.h /usr/include/asm/socket.h
server.o: /usr/include/asm-x86_64/socket.h /usr/include/asm/sockios.h
server.o: /usr/include/asm-x86_64/sockios.h /usr/include/bits/in.h
server.o: /usr/include/bits/byteswap.h /usr/include/sys/param.h
server.o: /usr/include/linux/param.h /usr/include/asm/param.h
server.o: /usr/include/asm-x86_64/param.h /usr/include/stdio.h
server.o: /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h
server.o: /usr/include/gconv.h /usr/include/bits/stdio_lim.h
server.o: /usr/include/bits/sys_errlist.h /usr/include/arpa/nameser.h
server.o: /usr/include/sys/bitypes.h /usr/include/arpa/nameser_compat.h
server.o: /usr/include/stdlib.h /usr/include/alloca.h /usr/include/string.h
server.o: /usr/include/unistd.h /usr/include/bits/posix_opt.h
server.o: /usr/include/bits/confname.h /usr/include/getopt.h
server.o: /usr/include/wait.h /usr/include/sys/wait.h /usr/include/signal.h
server.o: /usr/include/bits/signum.h /usr/include/bits/siginfo.h
server.o: /usr/include/bits/sigaction.h /usr/include/bits/sigcontext.h
server.o: /usr/include/bits/sigstack.h /usr/include/bits/sigthread.h
server.o: /usr/include/sys/resource.h /usr/include/bits/resource.h
server.o: /usr/include/bits/waitflags.h /usr/include/bits/waitstatus.h
server.o: /usr/include/arpa/inet.h /usr/include/openssl/ssl.h
server.o: /usr/include/openssl/e_os2.h /usr/include/openssl/opensslconf.h
server.o: /usr/include/openssl/opensslconf-x86_64.h
server.o: /usr/include/openssl/comp.h /usr/include/openssl/crypto.h
server.o: /usr/include/openssl/stack.h /usr/include/openssl/safestack.h
server.o: /usr/include/openssl/opensslv.h /usr/include/openssl/ossl_typ.h
server.o: /usr/include/openssl/symhacks.h /usr/include/openssl/bio.h
server.o: /usr/include/openssl/x509.h /usr/include/openssl/buffer.h
server.o: /usr/include/openssl/evp.h /usr/include/openssl/fips.h
server.o: /usr/include/openssl/objects.h /usr/include/openssl/obj_mac.h
server.o: /usr/include/openssl/asn1.h /usr/include/openssl/bn.h
server.o: /usr/include/openssl/rsa.h /usr/include/openssl/dsa.h
server.o: /usr/include/openssl/dh.h /usr/include/openssl/sha.h
server.o: /usr/include/openssl/x509_vfy.h /usr/include/openssl/lhash.h
server.o: /usr/include/openssl/pkcs7.h /usr/include/openssl/pem.h
server.o: /usr/include/openssl/pem2.h /usr/include/openssl/hmac.h
server.o: /usr/include/openssl/kssl.h /usr/include/ctype.h
server.o: /usr/include/krb5.h /usr/include/krb5/krb5.h
server.o: /usr/include/et/com_err.h /usr/include/openssl/ssl2.h
server.o: /usr/include/openssl/ssl3.h /usr/include/openssl/pq_compat.h
server.o: /usr/include/openssl/tls1.h /usr/include/openssl/dtls1.h
server.o: /usr/include/openssl/pqueue.h /usr/include/sys/time.h
server.o: /usr/include/openssl/ssl23.h /usr/include/openssl/err.h
server.o: /usr/include/sys/stat.h /usr/include/bits/stat.h ../common/split.h
server.o: ../common/global.h ../common/log.h ../common/response.h
smtpfuncs.o: /usr/include/stdio.h /usr/include/features.h
smtpfuncs.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
smtpfuncs.o: /usr/include/gnu/stubs.h /usr/include/gnu/stubs-64.h
smtpfuncs.o: /usr/include/bits/types.h /usr/include/bits/typesizes.h
smtpfuncs.o: /usr/include/libio.h /usr/include/_G_config.h
smtpfuncs.o: /usr/include/wchar.h /usr/include/bits/wchar.h
smtpfuncs.o: /usr/include/gconv.h /usr/include/bits/stdio_lim.h
smtpfuncs.o: /usr/include/bits/sys_errlist.h /usr/include/string.h
smtpfuncs.o: /usr/include/time.h smtpfuncs.h /usr/include/sys/types.h
smtpfuncs.o: /usr/include/endian.h /usr/include/bits/endian.h
smtpfuncs.o: /usr/include/sys/select.h /usr/include/bits/select.h
smtpfuncs.o: /usr/include/bits/sigset.h /usr/include/bits/time.h
smtpfuncs.o: /usr/include/sys/sysmacros.h /usr/include/bits/pthreadtypes.h
smtpfuncs.o: /usr/include/sys/socket.h /usr/include/sys/uio.h
smtpfuncs.o: /usr/include/bits/uio.h /usr/include/bits/socket.h
smtpfuncs.o: /usr/include/limits.h /usr/include/limits.h
smtpfuncs.o: /usr/include/bits/posix1_lim.h /usr/include/bits/local_lim.h
smtpfuncs.o: /usr/include/linux/limits.h /usr/include/bits/posix2_lim.h
smtpfuncs.o: /usr/include/bits/sockaddr.h /usr/include/asm/socket.h
smtpfuncs.o: /usr/include/asm-x86_64/socket.h /usr/include/asm/sockios.h
smtpfuncs.o: /usr/include/asm-x86_64/sockios.h /usr/include/netinet/in.h
smtpfuncs.o: /usr/include/stdint.h /usr/include/bits/in.h
smtpfuncs.o: /usr/include/bits/byteswap.h /usr/include/arpa/inet.h
smtpfuncs.o: /usr/include/netdb.h /usr/include/rpc/netdb.h
smtpfuncs.o: /usr/include/bits/netdb.h /usr/include/unistd.h
smtpfuncs.o: /usr/include/bits/posix_opt.h /usr/include/bits/confname.h
smtpfuncs.o: /usr/include/getopt.h ../common/split.h ../common/global.h
smtpfuncs.o: ../common/log.h
find_iface.o: /usr/include/unistd.h /usr/include/features.h
find_iface.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
find_iface.o: /usr/include/gnu/stubs.h /usr/include/gnu/stubs-64.h
find_iface.o: /usr/include/bits/posix_opt.h /usr/include/bits/types.h
find_iface.o: /usr/include/bits/typesizes.h /usr/include/bits/confname.h
find_iface.o: /usr/include/getopt.h /usr/include/stdio.h /usr/include/libio.h
find_iface.o: /usr/include/_G_config.h /usr/include/wchar.h
find_iface.o: /usr/include/bits/wchar.h /usr/include/gconv.h
find_iface.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
find_iface.o: ../common/split.h ../common/global.h ../common/log.h
get_iface.o: /usr/include/stdio.h /usr/include/features.h
get_iface.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
get_iface.o: /usr/include/gnu/stubs.h /usr/include/gnu/stubs-64.h
get_iface.o: /usr/include/bits/types.h /usr/include/bits/typesizes.h
get_iface.o: /usr/include/libio.h /usr/include/_G_config.h
get_iface.o: /usr/include/wchar.h /usr/include/bits/wchar.h
get_iface.o: /usr/include/gconv.h /usr/include/bits/stdio_lim.h
get_iface.o: /usr/include/bits/sys_errlist.h /usr/include/ifaddrs.h
get_iface.o: /usr/include/sys/socket.h /usr/include/sys/uio.h
get_iface.o: /usr/include/sys/types.h /usr/include/time.h
get_iface.o: /usr/include/endian.h /usr/include/bits/endian.h
get_iface.o: /usr/include/sys/select.h /usr/include/bits/select.h
get_iface.o: /usr/include/bits/sigset.h /usr/include/bits/time.h
get_iface.o: /usr/include/sys/sysmacros.h /usr/include/bits/pthreadtypes.h
get_iface.o: /usr/include/bits/uio.h /usr/include/bits/socket.h
get_iface.o: /usr/include/limits.h /usr/include/limits.h
get_iface.o: /usr/include/bits/posix1_lim.h /usr/include/bits/local_lim.h
get_iface.o: /usr/include/linux/limits.h /usr/include/bits/posix2_lim.h
get_iface.o: /usr/include/bits/sockaddr.h /usr/include/asm/socket.h
get_iface.o: /usr/include/asm-x86_64/socket.h /usr/include/asm/sockios.h
get_iface.o: /usr/include/asm-x86_64/sockios.h /usr/include/netinet/in.h
get_iface.o: /usr/include/stdint.h /usr/include/bits/in.h
get_iface.o: /usr/include/bits/byteswap.h /usr/include/string.h
get_iface.o: /usr/include/arpa/inet.h ../common/split.h ../common/global.h
get_iface.o: ../common/log.h
get_ip.o: /usr/include/stdio.h /usr/include/features.h
get_ip.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
get_ip.o: /usr/include/gnu/stubs.h /usr/include/gnu/stubs-64.h
get_ip.o: /usr/include/bits/types.h /usr/include/bits/typesizes.h
get_ip.o: /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h
get_ip.o: /usr/include/bits/wchar.h /usr/include/gconv.h
get_ip.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
get_ip.o: /usr/include/sys/types.h /usr/include/time.h /usr/include/endian.h
get_ip.o: /usr/include/bits/endian.h /usr/include/sys/select.h
get_ip.o: /usr/include/bits/select.h /usr/include/bits/sigset.h
get_ip.o: /usr/include/bits/time.h /usr/include/sys/sysmacros.h
get_ip.o: /usr/include/bits/pthreadtypes.h /usr/include/ifaddrs.h
get_ip.o: /usr/include/sys/socket.h /usr/include/sys/uio.h
get_ip.o: /usr/include/bits/uio.h /usr/include/bits/socket.h
get_ip.o: /usr/include/limits.h /usr/include/limits.h
get_ip.o: /usr/include/bits/posix1_lim.h /usr/include/bits/local_lim.h
get_ip.o: /usr/include/linux/limits.h /usr/include/bits/posix2_lim.h
get_ip.o: /usr/include/bits/sockaddr.h /usr/include/asm/socket.h
get_ip.o: /usr/include/asm-x86_64/socket.h /usr/include/asm/sockios.h
get_ip.o: /usr/include/asm-x86_64/sockios.h /usr/include/netinet/in.h
get_ip.o: /usr/include/stdint.h /usr/include/bits/in.h
get_ip.o: /usr/include/bits/byteswap.h /usr/include/string.h
get_ip.o: /usr/include/arpa/inet.h ../common/split.h ../common/global.h
get_ip.o: ../common/log.h
set_ip.o: /usr/include/sys/types.h /usr/include/features.h
set_ip.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
set_ip.o: /usr/include/gnu/stubs.h /usr/include/gnu/stubs-64.h
set_ip.o: /usr/include/bits/types.h /usr/include/bits/typesizes.h
set_ip.o: /usr/include/time.h /usr/include/endian.h
set_ip.o: /usr/include/bits/endian.h /usr/include/sys/select.h
set_ip.o: /usr/include/bits/select.h /usr/include/bits/sigset.h
set_ip.o: /usr/include/bits/time.h /usr/include/sys/sysmacros.h
set_ip.o: /usr/include/bits/pthreadtypes.h /usr/include/sys/stat.h
set_ip.o: /usr/include/bits/stat.h /usr/include/unistd.h
set_ip.o: /usr/include/bits/posix_opt.h /usr/include/bits/confname.h
set_ip.o: /usr/include/getopt.h /usr/include/stdio.h /usr/include/libio.h
set_ip.o: /usr/include/_G_config.h /usr/include/wchar.h
set_ip.o: /usr/include/bits/wchar.h /usr/include/gconv.h
set_ip.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
set_ip.o: ../common/split.h ../common/global.h ../common/log.h
del_ip.o: /usr/include/sys/types.h /usr/include/features.h
del_ip.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
del_ip.o: /usr/include/gnu/stubs.h /usr/include/gnu/stubs-64.h
del_ip.o: /usr/include/bits/types.h /usr/include/bits/typesizes.h
del_ip.o: /usr/include/time.h /usr/include/endian.h
del_ip.o: /usr/include/bits/endian.h /usr/include/sys/select.h
del_ip.o: /usr/include/bits/select.h /usr/include/bits/sigset.h
del_ip.o: /usr/include/bits/time.h /usr/include/sys/sysmacros.h
del_ip.o: /usr/include/bits/pthreadtypes.h /usr/include/sys/stat.h
del_ip.o: /usr/include/bits/stat.h /usr/include/unistd.h
del_ip.o: /usr/include/bits/posix_opt.h /usr/include/bits/confname.h
del_ip.o: /usr/include/getopt.h /usr/include/stdio.h /usr/include/libio.h
del_ip.o: /usr/include/_G_config.h /usr/include/wchar.h
del_ip.o: /usr/include/bits/wchar.h /usr/include/gconv.h
del_ip.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
del_ip.o: ../common/split.h ../common/global.h ../common/log.h
read.o: /usr/include/sys/types.h /usr/include/features.h
read.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
read.o: /usr/include/gnu/stubs.h /usr/include/gnu/stubs-64.h
read.o: /usr/include/bits/types.h /usr/include/bits/typesizes.h
read.o: /usr/include/time.h /usr/include/endian.h /usr/include/bits/endian.h
read.o: /usr/include/sys/select.h /usr/include/bits/select.h
read.o: /usr/include/bits/sigset.h /usr/include/bits/time.h
read.o: /usr/include/sys/sysmacros.h /usr/include/bits/pthreadtypes.h
read.o: /usr/include/sys/stat.h /usr/include/bits/stat.h
read.o: /usr/include/unistd.h /usr/include/bits/posix_opt.h
read.o: /usr/include/bits/confname.h /usr/include/getopt.h
read.o: /usr/include/stdio.h /usr/include/libio.h /usr/include/_G_config.h
read.o: /usr/include/wchar.h /usr/include/bits/wchar.h /usr/include/gconv.h
read.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
read.o: /usr/include/string.h /usr/include/dirent.h
read.o: /usr/include/bits/dirent.h /usr/include/bits/posix1_lim.h
read.o: /usr/include/bits/local_lim.h /usr/include/linux/limits.h
read.o: ../common/split.h ../common/global.h ../common/log.h
parse_deliface.o: /usr/include/stdio.h /usr/include/features.h
parse_deliface.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
parse_deliface.o: /usr/include/gnu/stubs.h /usr/include/gnu/stubs-64.h
parse_deliface.o: /usr/include/bits/types.h /usr/include/bits/typesizes.h
parse_deliface.o: /usr/include/libio.h /usr/include/_G_config.h
parse_deliface.o: /usr/include/wchar.h /usr/include/bits/wchar.h
parse_deliface.o: /usr/include/gconv.h /usr/include/bits/stdio_lim.h
parse_deliface.o: /usr/include/bits/sys_errlist.h /usr/include/sys/types.h
parse_deliface.o: /usr/include/time.h /usr/include/endian.h
parse_deliface.o: /usr/include/bits/endian.h /usr/include/sys/select.h
parse_deliface.o: /usr/include/bits/select.h /usr/include/bits/sigset.h
parse_deliface.o: /usr/include/bits/time.h /usr/include/sys/sysmacros.h
parse_deliface.o: /usr/include/bits/pthreadtypes.h /usr/include/string.h
parse_deliface.o: /usr/include/openssl/ssl.h /usr/include/openssl/e_os2.h
parse_deliface.o: /usr/include/openssl/opensslconf.h
parse_deliface.o: /usr/include/openssl/opensslconf-x86_64.h
parse_deliface.o: /usr/include/openssl/comp.h /usr/include/openssl/crypto.h
parse_deliface.o: /usr/include/stdlib.h /usr/include/alloca.h
parse_deliface.o: /usr/include/openssl/stack.h
parse_deliface.o: /usr/include/openssl/safestack.h
parse_deliface.o: /usr/include/openssl/opensslv.h
parse_deliface.o: /usr/include/openssl/ossl_typ.h
parse_deliface.o: /usr/include/openssl/symhacks.h /usr/include/openssl/bio.h
parse_deliface.o: /usr/include/openssl/x509.h /usr/include/openssl/buffer.h
parse_deliface.o: /usr/include/openssl/evp.h /usr/include/openssl/fips.h
parse_deliface.o: /usr/include/openssl/objects.h
parse_deliface.o: /usr/include/openssl/obj_mac.h /usr/include/openssl/asn1.h
parse_deliface.o: /usr/include/openssl/bn.h /usr/include/openssl/rsa.h
parse_deliface.o: /usr/include/openssl/dsa.h /usr/include/openssl/dh.h
parse_deliface.o: /usr/include/openssl/sha.h /usr/include/openssl/x509_vfy.h
parse_deliface.o: /usr/include/openssl/lhash.h /usr/include/openssl/pkcs7.h
parse_deliface.o: /usr/include/openssl/pem.h /usr/include/openssl/pem2.h
parse_deliface.o: /usr/include/openssl/hmac.h /usr/include/openssl/kssl.h
parse_deliface.o: /usr/include/ctype.h /usr/include/krb5.h
parse_deliface.o: /usr/include/krb5/krb5.h /usr/include/limits.h
parse_deliface.o: /usr/include/limits.h /usr/include/bits/posix1_lim.h
parse_deliface.o: /usr/include/bits/local_lim.h /usr/include/linux/limits.h
parse_deliface.o: /usr/include/bits/posix2_lim.h /usr/include/et/com_err.h
parse_deliface.o: /usr/include/openssl/ssl2.h /usr/include/openssl/ssl3.h
parse_deliface.o: /usr/include/openssl/pq_compat.h
parse_deliface.o: /usr/include/openssl/tls1.h /usr/include/openssl/dtls1.h
parse_deliface.o: /usr/include/openssl/pqueue.h /usr/include/sys/time.h
parse_deliface.o: /usr/include/openssl/ssl23.h /usr/include/openssl/err.h
parse_deliface.o: /usr/include/errno.h /usr/include/bits/errno.h
parse_deliface.o: /usr/include/linux/errno.h /usr/include/asm/errno.h
parse_deliface.o: /usr/include/asm-x86_64/errno.h
parse_deliface.o: /usr/include/asm-generic/errno.h
parse_deliface.o: /usr/include/asm-generic/errno-base.h ../common/split.h
parse_deliface.o: ../common/global.h ../common/log.h
parse_gethost.o: /usr/include/stdio.h /usr/include/features.h
parse_gethost.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
parse_gethost.o: /usr/include/gnu/stubs.h /usr/include/gnu/stubs-64.h
parse_gethost.o: /usr/include/bits/types.h /usr/include/bits/typesizes.h
parse_gethost.o: /usr/include/libio.h /usr/include/_G_config.h
parse_gethost.o: /usr/include/wchar.h /usr/include/bits/wchar.h
parse_gethost.o: /usr/include/gconv.h /usr/include/bits/stdio_lim.h
parse_gethost.o: /usr/include/bits/sys_errlist.h /usr/include/sys/types.h
parse_gethost.o: /usr/include/time.h /usr/include/endian.h
parse_gethost.o: /usr/include/bits/endian.h /usr/include/sys/select.h
parse_gethost.o: /usr/include/bits/select.h /usr/include/bits/sigset.h
parse_gethost.o: /usr/include/bits/time.h /usr/include/sys/sysmacros.h
parse_gethost.o: /usr/include/bits/pthreadtypes.h /usr/include/string.h
parse_gethost.o: /usr/include/openssl/ssl.h /usr/include/openssl/e_os2.h
parse_gethost.o: /usr/include/openssl/opensslconf.h
parse_gethost.o: /usr/include/openssl/opensslconf-x86_64.h
parse_gethost.o: /usr/include/openssl/comp.h /usr/include/openssl/crypto.h
parse_gethost.o: /usr/include/stdlib.h /usr/include/alloca.h
parse_gethost.o: /usr/include/openssl/stack.h
parse_gethost.o: /usr/include/openssl/safestack.h
parse_gethost.o: /usr/include/openssl/opensslv.h
parse_gethost.o: /usr/include/openssl/ossl_typ.h
parse_gethost.o: /usr/include/openssl/symhacks.h /usr/include/openssl/bio.h
parse_gethost.o: /usr/include/openssl/x509.h /usr/include/openssl/buffer.h
parse_gethost.o: /usr/include/openssl/evp.h /usr/include/openssl/fips.h
parse_gethost.o: /usr/include/openssl/objects.h
parse_gethost.o: /usr/include/openssl/obj_mac.h /usr/include/openssl/asn1.h
parse_gethost.o: /usr/include/openssl/bn.h /usr/include/openssl/rsa.h
parse_gethost.o: /usr/include/openssl/dsa.h /usr/include/openssl/dh.h
parse_gethost.o: /usr/include/openssl/sha.h /usr/include/openssl/x509_vfy.h
parse_gethost.o: /usr/include/openssl/lhash.h /usr/include/openssl/pkcs7.h
parse_gethost.o: /usr/include/openssl/pem.h /usr/include/openssl/pem2.h
parse_gethost.o: /usr/include/openssl/hmac.h /usr/include/openssl/kssl.h
parse_gethost.o: /usr/include/ctype.h /usr/include/krb5.h
parse_gethost.o: /usr/include/krb5/krb5.h /usr/include/limits.h
parse_gethost.o: /usr/include/limits.h /usr/include/bits/posix1_lim.h
parse_gethost.o: /usr/include/bits/local_lim.h /usr/include/linux/limits.h
parse_gethost.o: /usr/include/bits/posix2_lim.h /usr/include/et/com_err.h
parse_gethost.o: /usr/include/openssl/ssl2.h /usr/include/openssl/ssl3.h
parse_gethost.o: /usr/include/openssl/pq_compat.h /usr/include/openssl/tls1.h
parse_gethost.o: /usr/include/openssl/dtls1.h /usr/include/openssl/pqueue.h
parse_gethost.o: /usr/include/sys/time.h /usr/include/openssl/ssl23.h
parse_gethost.o: /usr/include/openssl/err.h /usr/include/errno.h
parse_gethost.o: /usr/include/bits/errno.h /usr/include/linux/errno.h
parse_gethost.o: /usr/include/asm/errno.h /usr/include/asm-x86_64/errno.h
parse_gethost.o: /usr/include/asm-generic/errno.h
parse_gethost.o: /usr/include/asm-generic/errno-base.h ../common/split.h
parse_gethost.o: ../common/global.h ../common/log.h
parse_getip.o: /usr/include/stdio.h /usr/include/features.h
parse_getip.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
parse_getip.o: /usr/include/gnu/stubs.h /usr/include/gnu/stubs-64.h
parse_getip.o: /usr/include/bits/types.h /usr/include/bits/typesizes.h
parse_getip.o: /usr/include/libio.h /usr/include/_G_config.h
parse_getip.o: /usr/include/wchar.h /usr/include/bits/wchar.h
parse_getip.o: /usr/include/gconv.h /usr/include/bits/stdio_lim.h
parse_getip.o: /usr/include/bits/sys_errlist.h /usr/include/sys/types.h
parse_getip.o: /usr/include/time.h /usr/include/endian.h
parse_getip.o: /usr/include/bits/endian.h /usr/include/sys/select.h
parse_getip.o: /usr/include/bits/select.h /usr/include/bits/sigset.h
parse_getip.o: /usr/include/bits/time.h /usr/include/sys/sysmacros.h
parse_getip.o: /usr/include/bits/pthreadtypes.h /usr/include/string.h
parse_getip.o: /usr/include/openssl/ssl.h /usr/include/openssl/e_os2.h
parse_getip.o: /usr/include/openssl/opensslconf.h
parse_getip.o: /usr/include/openssl/opensslconf-x86_64.h
parse_getip.o: /usr/include/openssl/comp.h /usr/include/openssl/crypto.h
parse_getip.o: /usr/include/stdlib.h /usr/include/alloca.h
parse_getip.o: /usr/include/openssl/stack.h /usr/include/openssl/safestack.h
parse_getip.o: /usr/include/openssl/opensslv.h
parse_getip.o: /usr/include/openssl/ossl_typ.h
parse_getip.o: /usr/include/openssl/symhacks.h /usr/include/openssl/bio.h
parse_getip.o: /usr/include/openssl/x509.h /usr/include/openssl/buffer.h
parse_getip.o: /usr/include/openssl/evp.h /usr/include/openssl/fips.h
parse_getip.o: /usr/include/openssl/objects.h /usr/include/openssl/obj_mac.h
parse_getip.o: /usr/include/openssl/asn1.h /usr/include/openssl/bn.h
parse_getip.o: /usr/include/openssl/rsa.h /usr/include/openssl/dsa.h
parse_getip.o: /usr/include/openssl/dh.h /usr/include/openssl/sha.h
parse_getip.o: /usr/include/openssl/x509_vfy.h /usr/include/openssl/lhash.h
parse_getip.o: /usr/include/openssl/pkcs7.h /usr/include/openssl/pem.h
parse_getip.o: /usr/include/openssl/pem2.h /usr/include/openssl/hmac.h
parse_getip.o: /usr/include/openssl/kssl.h /usr/include/ctype.h
parse_getip.o: /usr/include/krb5.h /usr/include/krb5/krb5.h
parse_getip.o: /usr/include/limits.h /usr/include/limits.h
parse_getip.o: /usr/include/bits/posix1_lim.h /usr/include/bits/local_lim.h
parse_getip.o: /usr/include/linux/limits.h /usr/include/bits/posix2_lim.h
parse_getip.o: /usr/include/et/com_err.h /usr/include/openssl/ssl2.h
parse_getip.o: /usr/include/openssl/ssl3.h /usr/include/openssl/pq_compat.h
parse_getip.o: /usr/include/openssl/tls1.h /usr/include/openssl/dtls1.h
parse_getip.o: /usr/include/openssl/pqueue.h /usr/include/sys/time.h
parse_getip.o: /usr/include/openssl/ssl23.h /usr/include/openssl/err.h
parse_getip.o: /usr/include/errno.h /usr/include/bits/errno.h
parse_getip.o: /usr/include/linux/errno.h /usr/include/asm/errno.h
parse_getip.o: /usr/include/asm-x86_64/errno.h
parse_getip.o: /usr/include/asm-generic/errno.h
parse_getip.o: /usr/include/asm-generic/errno-base.h ../common/split.h
parse_getip.o: ../common/global.h ../common/log.h
parse_getnic.o: /usr/include/stdio.h /usr/include/features.h
parse_getnic.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
parse_getnic.o: /usr/include/gnu/stubs.h /usr/include/gnu/stubs-64.h
parse_getnic.o: /usr/include/bits/types.h /usr/include/bits/typesizes.h
parse_getnic.o: /usr/include/libio.h /usr/include/_G_config.h
parse_getnic.o: /usr/include/wchar.h /usr/include/bits/wchar.h
parse_getnic.o: /usr/include/gconv.h /usr/include/bits/stdio_lim.h
parse_getnic.o: /usr/include/bits/sys_errlist.h /usr/include/sys/types.h
parse_getnic.o: /usr/include/time.h /usr/include/endian.h
parse_getnic.o: /usr/include/bits/endian.h /usr/include/sys/select.h
parse_getnic.o: /usr/include/bits/select.h /usr/include/bits/sigset.h
parse_getnic.o: /usr/include/bits/time.h /usr/include/sys/sysmacros.h
parse_getnic.o: /usr/include/bits/pthreadtypes.h /usr/include/string.h
parse_getnic.o: /usr/include/openssl/ssl.h /usr/include/openssl/e_os2.h
parse_getnic.o: /usr/include/openssl/opensslconf.h
parse_getnic.o: /usr/include/openssl/opensslconf-x86_64.h
parse_getnic.o: /usr/include/openssl/comp.h /usr/include/openssl/crypto.h
parse_getnic.o: /usr/include/stdlib.h /usr/include/alloca.h
parse_getnic.o: /usr/include/openssl/stack.h /usr/include/openssl/safestack.h
parse_getnic.o: /usr/include/openssl/opensslv.h
parse_getnic.o: /usr/include/openssl/ossl_typ.h
parse_getnic.o: /usr/include/openssl/symhacks.h /usr/include/openssl/bio.h
parse_getnic.o: /usr/include/openssl/x509.h /usr/include/openssl/buffer.h
parse_getnic.o: /usr/include/openssl/evp.h /usr/include/openssl/fips.h
parse_getnic.o: /usr/include/openssl/objects.h /usr/include/openssl/obj_mac.h
parse_getnic.o: /usr/include/openssl/asn1.h /usr/include/openssl/bn.h
parse_getnic.o: /usr/include/openssl/rsa.h /usr/include/openssl/dsa.h
parse_getnic.o: /usr/include/openssl/dh.h /usr/include/openssl/sha.h
parse_getnic.o: /usr/include/openssl/x509_vfy.h /usr/include/openssl/lhash.h
parse_getnic.o: /usr/include/openssl/pkcs7.h /usr/include/openssl/pem.h
parse_getnic.o: /usr/include/openssl/pem2.h /usr/include/openssl/hmac.h
parse_getnic.o: /usr/include/openssl/kssl.h /usr/include/ctype.h
parse_getnic.o: /usr/include/krb5.h /usr/include/krb5/krb5.h
parse_getnic.o: /usr/include/limits.h /usr/include/limits.h
parse_getnic.o: /usr/include/bits/posix1_lim.h /usr/include/bits/local_lim.h
parse_getnic.o: /usr/include/linux/limits.h /usr/include/bits/posix2_lim.h
parse_getnic.o: /usr/include/et/com_err.h /usr/include/openssl/ssl2.h
parse_getnic.o: /usr/include/openssl/ssl3.h /usr/include/openssl/pq_compat.h
parse_getnic.o: /usr/include/openssl/tls1.h /usr/include/openssl/dtls1.h
parse_getnic.o: /usr/include/openssl/pqueue.h /usr/include/sys/time.h
parse_getnic.o: /usr/include/openssl/ssl23.h /usr/include/openssl/err.h
parse_getnic.o: /usr/include/errno.h /usr/include/bits/errno.h
parse_getnic.o: /usr/include/linux/errno.h /usr/include/asm/errno.h
parse_getnic.o: /usr/include/asm-x86_64/errno.h
parse_getnic.o: /usr/include/asm-generic/errno.h
parse_getnic.o: /usr/include/asm-generic/errno-base.h ../common/split.h
parse_getnic.o: ../common/global.h ../common/log.h
parse_off.o: /usr/include/stdio.h /usr/include/features.h
parse_off.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
parse_off.o: /usr/include/gnu/stubs.h /usr/include/gnu/stubs-64.h
parse_off.o: /usr/include/bits/types.h /usr/include/bits/typesizes.h
parse_off.o: /usr/include/libio.h /usr/include/_G_config.h
parse_off.o: /usr/include/wchar.h /usr/include/bits/wchar.h
parse_off.o: /usr/include/gconv.h /usr/include/bits/stdio_lim.h
parse_off.o: /usr/include/bits/sys_errlist.h /usr/include/sys/types.h
parse_off.o: /usr/include/time.h /usr/include/endian.h
parse_off.o: /usr/include/bits/endian.h /usr/include/sys/select.h
parse_off.o: /usr/include/bits/select.h /usr/include/bits/sigset.h
parse_off.o: /usr/include/bits/time.h /usr/include/sys/sysmacros.h
parse_off.o: /usr/include/bits/pthreadtypes.h /usr/include/string.h
parse_off.o: /usr/include/openssl/ssl.h /usr/include/openssl/e_os2.h
parse_off.o: /usr/include/openssl/opensslconf.h
parse_off.o: /usr/include/openssl/opensslconf-x86_64.h
parse_off.o: /usr/include/openssl/comp.h /usr/include/openssl/crypto.h
parse_off.o: /usr/include/stdlib.h /usr/include/alloca.h
parse_off.o: /usr/include/openssl/stack.h /usr/include/openssl/safestack.h
parse_off.o: /usr/include/openssl/opensslv.h /usr/include/openssl/ossl_typ.h
parse_off.o: /usr/include/openssl/symhacks.h /usr/include/openssl/bio.h
parse_off.o: /usr/include/openssl/x509.h /usr/include/openssl/buffer.h
parse_off.o: /usr/include/openssl/evp.h /usr/include/openssl/fips.h
parse_off.o: /usr/include/openssl/objects.h /usr/include/openssl/obj_mac.h
parse_off.o: /usr/include/openssl/asn1.h /usr/include/openssl/bn.h
parse_off.o: /usr/include/openssl/rsa.h /usr/include/openssl/dsa.h
parse_off.o: /usr/include/openssl/dh.h /usr/include/openssl/sha.h
parse_off.o: /usr/include/openssl/x509_vfy.h /usr/include/openssl/lhash.h
parse_off.o: /usr/include/openssl/pkcs7.h /usr/include/openssl/pem.h
parse_off.o: /usr/include/openssl/pem2.h /usr/include/openssl/hmac.h
parse_off.o: /usr/include/openssl/kssl.h /usr/include/ctype.h
parse_off.o: /usr/include/krb5.h /usr/include/krb5/krb5.h
parse_off.o: /usr/include/limits.h /usr/include/limits.h
parse_off.o: /usr/include/bits/posix1_lim.h /usr/include/bits/local_lim.h
parse_off.o: /usr/include/linux/limits.h /usr/include/bits/posix2_lim.h
parse_off.o: /usr/include/et/com_err.h /usr/include/openssl/ssl2.h
parse_off.o: /usr/include/openssl/ssl3.h /usr/include/openssl/pq_compat.h
parse_off.o: /usr/include/openssl/tls1.h /usr/include/openssl/dtls1.h
parse_off.o: /usr/include/openssl/pqueue.h /usr/include/sys/time.h
parse_off.o: /usr/include/openssl/ssl23.h /usr/include/openssl/err.h
parse_off.o: /usr/include/errno.h /usr/include/bits/errno.h
parse_off.o: /usr/include/linux/errno.h /usr/include/asm/errno.h
parse_off.o: /usr/include/asm-x86_64/errno.h /usr/include/asm-generic/errno.h
parse_off.o: /usr/include/asm-generic/errno-base.h ../common/split.h
parse_off.o: ../common/global.h ../common/log.h
parse_on.o: /usr/include/stdio.h /usr/include/features.h
parse_on.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
parse_on.o: /usr/include/gnu/stubs.h /usr/include/gnu/stubs-64.h
parse_on.o: /usr/include/bits/types.h /usr/include/bits/typesizes.h
parse_on.o: /usr/include/libio.h /usr/include/_G_config.h
parse_on.o: /usr/include/wchar.h /usr/include/bits/wchar.h
parse_on.o: /usr/include/gconv.h /usr/include/bits/stdio_lim.h
parse_on.o: /usr/include/bits/sys_errlist.h /usr/include/sys/types.h
parse_on.o: /usr/include/time.h /usr/include/endian.h
parse_on.o: /usr/include/bits/endian.h /usr/include/sys/select.h
parse_on.o: /usr/include/bits/select.h /usr/include/bits/sigset.h
parse_on.o: /usr/include/bits/time.h /usr/include/sys/sysmacros.h
parse_on.o: /usr/include/bits/pthreadtypes.h /usr/include/string.h
parse_on.o: /usr/include/openssl/ssl.h /usr/include/openssl/e_os2.h
parse_on.o: /usr/include/openssl/opensslconf.h
parse_on.o: /usr/include/openssl/opensslconf-x86_64.h
parse_on.o: /usr/include/openssl/comp.h /usr/include/openssl/crypto.h
parse_on.o: /usr/include/stdlib.h /usr/include/alloca.h
parse_on.o: /usr/include/openssl/stack.h /usr/include/openssl/safestack.h
parse_on.o: /usr/include/openssl/opensslv.h /usr/include/openssl/ossl_typ.h
parse_on.o: /usr/include/openssl/symhacks.h /usr/include/openssl/bio.h
parse_on.o: /usr/include/openssl/x509.h /usr/include/openssl/buffer.h
parse_on.o: /usr/include/openssl/evp.h /usr/include/openssl/fips.h
parse_on.o: /usr/include/openssl/objects.h /usr/include/openssl/obj_mac.h
parse_on.o: /usr/include/openssl/asn1.h /usr/include/openssl/bn.h
parse_on.o: /usr/include/openssl/rsa.h /usr/include/openssl/dsa.h
parse_on.o: /usr/include/openssl/dh.h /usr/include/openssl/sha.h
parse_on.o: /usr/include/openssl/x509_vfy.h /usr/include/openssl/lhash.h
parse_on.o: /usr/include/openssl/pkcs7.h /usr/include/openssl/pem.h
parse_on.o: /usr/include/openssl/pem2.h /usr/include/openssl/hmac.h
parse_on.o: /usr/include/openssl/kssl.h /usr/include/ctype.h
parse_on.o: /usr/include/krb5.h /usr/include/krb5/krb5.h
parse_on.o: /usr/include/limits.h /usr/include/limits.h
parse_on.o: /usr/include/bits/posix1_lim.h /usr/include/bits/local_lim.h
parse_on.o: /usr/include/linux/limits.h /usr/include/bits/posix2_lim.h
parse_on.o: /usr/include/et/com_err.h /usr/include/openssl/ssl2.h
parse_on.o: /usr/include/openssl/ssl3.h /usr/include/openssl/pq_compat.h
parse_on.o: /usr/include/openssl/tls1.h /usr/include/openssl/dtls1.h
parse_on.o: /usr/include/openssl/pqueue.h /usr/include/sys/time.h
parse_on.o: /usr/include/openssl/ssl23.h /usr/include/openssl/err.h
parse_on.o: /usr/include/errno.h /usr/include/bits/errno.h
parse_on.o: /usr/include/linux/errno.h /usr/include/asm/errno.h
parse_on.o: /usr/include/asm-x86_64/errno.h /usr/include/asm-generic/errno.h
parse_on.o: /usr/include/asm-generic/errno-base.h ../common/split.h
parse_on.o: ../common/global.h ../common/log.h
parse_setip.o: /usr/include/stdio.h /usr/include/features.h
parse_setip.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
parse_setip.o: /usr/include/gnu/stubs.h /usr/include/gnu/stubs-64.h
parse_setip.o: /usr/include/bits/types.h /usr/include/bits/typesizes.h
parse_setip.o: /usr/include/libio.h /usr/include/_G_config.h
parse_setip.o: /usr/include/wchar.h /usr/include/bits/wchar.h
parse_setip.o: /usr/include/gconv.h /usr/include/bits/stdio_lim.h
parse_setip.o: /usr/include/bits/sys_errlist.h /usr/include/sys/types.h
parse_setip.o: /usr/include/time.h /usr/include/endian.h
parse_setip.o: /usr/include/bits/endian.h /usr/include/sys/select.h
parse_setip.o: /usr/include/bits/select.h /usr/include/bits/sigset.h
parse_setip.o: /usr/include/bits/time.h /usr/include/sys/sysmacros.h
parse_setip.o: /usr/include/bits/pthreadtypes.h /usr/include/string.h
parse_setip.o: /usr/include/openssl/ssl.h /usr/include/openssl/e_os2.h
parse_setip.o: /usr/include/openssl/opensslconf.h
parse_setip.o: /usr/include/openssl/opensslconf-x86_64.h
parse_setip.o: /usr/include/openssl/comp.h /usr/include/openssl/crypto.h
parse_setip.o: /usr/include/stdlib.h /usr/include/alloca.h
parse_setip.o: /usr/include/openssl/stack.h /usr/include/openssl/safestack.h
parse_setip.o: /usr/include/openssl/opensslv.h
parse_setip.o: /usr/include/openssl/ossl_typ.h
parse_setip.o: /usr/include/openssl/symhacks.h /usr/include/openssl/bio.h
parse_setip.o: /usr/include/openssl/x509.h /usr/include/openssl/buffer.h
parse_setip.o: /usr/include/openssl/evp.h /usr/include/openssl/fips.h
parse_setip.o: /usr/include/openssl/objects.h /usr/include/openssl/obj_mac.h
parse_setip.o: /usr/include/openssl/asn1.h /usr/include/openssl/bn.h
parse_setip.o: /usr/include/openssl/rsa.h /usr/include/openssl/dsa.h
parse_setip.o: /usr/include/openssl/dh.h /usr/include/openssl/sha.h
parse_setip.o: /usr/include/openssl/x509_vfy.h /usr/include/openssl/lhash.h
parse_setip.o: /usr/include/openssl/pkcs7.h /usr/include/openssl/pem.h
parse_setip.o: /usr/include/openssl/pem2.h /usr/include/openssl/hmac.h
parse_setip.o: /usr/include/openssl/kssl.h /usr/include/ctype.h
parse_setip.o: /usr/include/krb5.h /usr/include/krb5/krb5.h
parse_setip.o: /usr/include/limits.h /usr/include/limits.h
parse_setip.o: /usr/include/bits/posix1_lim.h /usr/include/bits/local_lim.h
parse_setip.o: /usr/include/linux/limits.h /usr/include/bits/posix2_lim.h
parse_setip.o: /usr/include/et/com_err.h /usr/include/openssl/ssl2.h
parse_setip.o: /usr/include/openssl/ssl3.h /usr/include/openssl/pq_compat.h
parse_setip.o: /usr/include/openssl/tls1.h /usr/include/openssl/dtls1.h
parse_setip.o: /usr/include/openssl/pqueue.h /usr/include/sys/time.h
parse_setip.o: /usr/include/openssl/ssl23.h /usr/include/openssl/err.h
parse_setip.o: /usr/include/errno.h /usr/include/bits/errno.h
parse_setip.o: /usr/include/linux/errno.h /usr/include/asm/errno.h
parse_setip.o: /usr/include/asm-x86_64/errno.h
parse_setip.o: /usr/include/asm-generic/errno.h
parse_setip.o: /usr/include/asm-generic/errno-base.h ../common/split.h
parse_setip.o: ../common/global.h ../common/log.h
../common/chomp.o: /usr/include/stdio.h /usr/include/features.h
../common/chomp.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
../common/chomp.o: /usr/include/gnu/stubs.h /usr/include/gnu/stubs-64.h
../common/chomp.o: /usr/include/bits/types.h /usr/include/bits/typesizes.h
../common/chomp.o: /usr/include/libio.h /usr/include/_G_config.h
../common/chomp.o: /usr/include/wchar.h /usr/include/bits/wchar.h
../common/chomp.o: /usr/include/gconv.h /usr/include/bits/stdio_lim.h
../common/chomp.o: /usr/include/bits/sys_errlist.h /usr/include/stdlib.h
../common/chomp.o: /usr/include/sys/types.h /usr/include/time.h
../common/chomp.o: /usr/include/endian.h /usr/include/bits/endian.h
../common/chomp.o: /usr/include/sys/select.h /usr/include/bits/select.h
../common/chomp.o: /usr/include/bits/sigset.h /usr/include/bits/time.h
../common/chomp.o: /usr/include/sys/sysmacros.h
../common/chomp.o: /usr/include/bits/pthreadtypes.h /usr/include/alloca.h
../common/chomp.o: /usr/include/string.h
../common/itoc.o: /usr/include/stdio.h /usr/include/features.h
../common/itoc.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
../common/itoc.o: /usr/include/gnu/stubs.h /usr/include/gnu/stubs-64.h
../common/itoc.o: /usr/include/bits/types.h /usr/include/bits/typesizes.h
../common/itoc.o: /usr/include/libio.h /usr/include/_G_config.h
../common/itoc.o: /usr/include/wchar.h /usr/include/bits/wchar.h
../common/itoc.o: /usr/include/gconv.h /usr/include/bits/stdio_lim.h
../common/itoc.o: /usr/include/bits/sys_errlist.h
../common/rsa_key.o: /usr/include/stdio.h /usr/include/features.h
../common/rsa_key.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
../common/rsa_key.o: /usr/include/gnu/stubs.h /usr/include/gnu/stubs-64.h
../common/rsa_key.o: /usr/include/bits/types.h /usr/include/bits/typesizes.h
../common/rsa_key.o: /usr/include/libio.h /usr/include/_G_config.h
../common/rsa_key.o: /usr/include/wchar.h /usr/include/bits/wchar.h
../common/rsa_key.o: /usr/include/gconv.h /usr/include/bits/stdio_lim.h
../common/rsa_key.o: /usr/include/bits/sys_errlist.h /usr/include/sys/stat.h
../common/rsa_key.o: /usr/include/time.h /usr/include/bits/stat.h
../common/rsa_key.o: /usr/include/stdlib.h /usr/include/sys/types.h
../common/rsa_key.o: /usr/include/endian.h /usr/include/bits/endian.h
../common/rsa_key.o: /usr/include/sys/select.h /usr/include/bits/select.h
../common/rsa_key.o: /usr/include/bits/sigset.h /usr/include/bits/time.h
../common/rsa_key.o: /usr/include/sys/sysmacros.h
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
../common/help.o: ../common/global.h
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
email.o: /usr/include/sys/types.h /usr/include/features.h
email.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
email.o: /usr/include/gnu/stubs.h /usr/include/gnu/stubs-64.h
email.o: /usr/include/bits/types.h /usr/include/bits/typesizes.h
email.o: /usr/include/time.h /usr/include/endian.h /usr/include/bits/endian.h
email.o: /usr/include/sys/select.h /usr/include/bits/select.h
email.o: /usr/include/bits/sigset.h /usr/include/bits/time.h
email.o: /usr/include/sys/sysmacros.h /usr/include/bits/pthreadtypes.h
email.o: /usr/include/sys/stat.h /usr/include/bits/stat.h
email.o: /usr/include/unistd.h /usr/include/bits/posix_opt.h
email.o: /usr/include/bits/confname.h /usr/include/getopt.h
email.o: /usr/include/stdio.h /usr/include/libio.h /usr/include/_G_config.h
email.o: /usr/include/wchar.h /usr/include/bits/wchar.h /usr/include/gconv.h
email.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
email.o: ../common/split.h ../common/global.h ../common/log.h
