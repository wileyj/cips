# Process this file with autoconf to produce a configure script.
AC_INIT(server/server.cpp)

### BEGIN RELEASE VARIABLES ############################
CIPS_MAJOR_VERSION=0
CIPS_MINOR_VERSION=0
CIPS_MICRO_VERSION=3

# REL is used for various packaging systems:
REL=1

# DEFINE CIPS_VERSION:
CIPS_VERSION=$CIPS_MAJOR_VERSION.$CIPS_MINOR_VERSION.$CIPS_MICRO_VERSION

AM_INIT_AUTOMAKE(cips, $CIPS_VERSION)
                                                                                                                                                     
AC_SUBST(CIPS_MAJOR_VERSION)                                                                                                                      
AC_SUBST(CIPS_MINOR_VERSION)                                                                                                                      
AC_SUBST(CIPS_MICRO_VERSION)                                                                                                                      
AC_SUBST(CIPS_VERSION)                                                                                                                            
AC_SUBST(REL)

AC_DEFINE_UNQUOTED(CIPS_MAJOR_VERSION, $CIPS_MAJOR_VERSION, CIPS_MAJOR_VERSION)
AC_DEFINE_UNQUOTED(CIPS_MINOR_VERSION, $CIPS_MINOR_VERSION, CIPS_MINOR_VERSION)
AC_DEFINE_UNQUOTED(CIPS_MICRO_VERSION, $CIPS_MICRO_VERSION, CIPS_MICRO_VERSION)

AC_DEFINE_UNQUOTED(REL, $REL, REL)
AC_DEFINE_UNQUOTED(CIPS_VERSION_FULL, "${VERSION}-${REL}", CIPS_VERSION_FULL)

AC_DEFINE_UNQUOTED(HOST_OS, "$host_os", HOST_OS)
AC_DEFINE_UNQUOTED(CPU_VENDOR_OS, "$host", CPU_VENDOR_OS)

AC_PREFIX_DEFAULT([/usr])
AC_LANG([C++])
#AC_CONFIG_SRCDIR([src])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CXX
AC_PROG_CC
AC_PROG_AWK
AC_PROG_INSTALL

# AC_PROG_MKDIR_P
# is a backport of autoconf-2.60's AC_PROG_MKDIR_P.
# Remove this macro when we can assume autoconf >= 2.60.
m4_ifdef([AC_PROG_MKDIR_P], [], [
   AC_DEFUN([AC_PROG_MKDIR_P],
     [AC_REQUIRE([AM_PROG_MKDIR_P])dnl defined by automake
      MKDIR_P='$(mkdir_p)'
      AC_SUBST([MKDIR_P])])])
AC_PROG_MKDIR_P


AM_PROG_CC_C_O
# Checks for libraries.
# FIXME: Replace `main' with a function in `-lssl':
AC_CHECK_LIB([ssl], [main])
AC_CHECK_LIB([crypto], [main])

# Checks for command line options
# Checks for library functions.
AC_CHECK_FUNCS([ASN1_INTEGER_to_BN])
AC_CHECK_FUNCS([BIO_free]) 
AC_CHECK_FUNCS([BN_bn2hex]) 
AC_CHECK_FUNCS([ERR_error_string]) 
AC_CHECK_FUNCS([ERR_load_crypto_strings]) 
AC_CHECK_FUNCS([ERR_print_errors_fp]) 
AC_CHECK_FUNCS([OpenSSL_add_all_algorithms]) 
AC_CHECK_FUNCS([PEM_read_bio_X509]) 
AC_CHECK_FUNCS([RSA_private_decrypt]) 
AC_CHECK_FUNCS([SSL_CTX_check_private_key]) 
AC_CHECK_FUNCS([SSL_CTX_new]) 
AC_CHECK_FUNCS([SSL_CTX_use_PrivateKey_file]) 
AC_CHECK_FUNCS([SSL_CTX_use_certificate_file]) 
AC_CHECK_FUNCS([SSL_get_peer_certificate]) 
AC_CHECK_FUNCS([SSL_load_error_strings]) 
AC_CHECK_FUNCS([SSL_write]) 
AC_CHECK_FUNCS([SSLv2_client_method]) 
AC_CHECK_FUNCS([X509_NAME_oneline]) 
AC_CHECK_FUNCS([X509_free]) 
AC_CHECK_FUNCS([X509_get_serialNumber]) 
AC_CHECK_FUNCS([X509_issuer_and_serial_hash]) 
AC_CHECK_FUNCS([X509_issuer_name_hash]) 
AC_CHECK_FUNCS([X509_subject_name_hash]) 
AC_CHECK_FUNCS([close]) 
AC_CHECK_FUNCS([closedir]) 
AC_CHECK_FUNCS([fopen]) 
AC_CHECK_FUNCS([fork]) 
AC_CHECK_FUNCS([fread]) 
AC_CHECK_FUNCS([fwrite]) 
AC_CHECK_FUNCS([getgrnam]) 
AC_CHECK_FUNCS([gethostbyname]) 
AC_CHECK_FUNCS([getprotobyname]) 
AC_CHECK_FUNCS([inet_pton]) 
AC_CHECK_FUNCS([malloc])
AC_CHECK_FUNCS([memset]) 
AC_CHECK_FUNCS([opendir]) 
AC_CHECK_FUNCS([popen]) 
AC_CHECK_FUNCS([read]) 
AC_CHECK_FUNCS([realloc]) 
AC_CHECK_FUNCS([recv]) 
AC_CHECK_FUNCS([regcomp]) 
AC_CHECK_FUNCS([regfree]) 
AC_CHECK_FUNCS([snprintf]) 
AC_CHECK_FUNCS([socket]) 
AC_CHECK_FUNCS([sprintf]) 
AC_CHECK_FUNCS([strcat]) 
AC_CHECK_FUNCS([strcmp]) 
AC_CHECK_FUNCS([strcpy]) 
AC_CHECK_FUNCS([strftime]) 
AC_CHECK_FUNCS([strncat]) 
AC_CHECK_FUNCS([strncpy]) 
AC_CHECK_FUNCS([strrchr]) 
AC_CHECK_FUNCS([strstr]) 
AC_CHECK_FUNCS([system]) 
AC_CHECK_FUNCS([time]) 
AC_CHECK_FUNCS([waitpid])
AC_CHECK_FUNCS([bzero]) 
AC_CHECK_FUNCS([getcwd]) 
AC_CHECK_FUNCS([gethostname]) 
AC_CHECK_FUNCS([inet_ntoa])

AC_LANG([C++])
AC_HEADER_STDC
AC_HEADER_SYS_WAIT
AC_HEADER_TIME
#AC_CHECK_HEADER_STDBOOL
AC_TYPE_SIZE_T
AC_FUNC_ERROR_AT_LINE 
AC_FUNC_FORK 
AC_FUNC_MALLOC 
AC_FUNC_REALLOC 
#AC_HEADER_RESOLV 
AC_TYPE_PID_T 
#AC_TYPE_SSIZE_T 

AC_CHECK_HEADERS([arpa/inet.h]) 
AC_CHECK_HEADERS([fcntl.h]) 
AC_CHECK_HEADERS([netdb.h]) 
AC_CHECK_HEADERS([netinet/in.h]) 
AC_CHECK_HEADERS([sys/socket.h]) 
AC_CHECK_HEADERS([malloc.h])

AC_SUBST([AM_CXXFLAGS])
AC_SUBST([AM_LDFLAGS])

# introduce the optional configure parameter for a non-standard install prefix of XXX
AC_ARG_WITH([XXX],
    [AS_HELP_STRING([--with-XXX=prefix],
        [try this for a non-standard install prefix of the XXX library])],
    [XXXPATHSET=1],
    [XXXPATHSET=0])


AC_OUTPUT(Makefile)


echo "Version: $CIPS_VERSION"
echo ""
echo ""
echo "Type \"make\" to compile."

