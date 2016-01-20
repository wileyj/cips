//response.h
#ifndef _RESPONSE_H_
#define _RESPONSE_H_

/*       Response Message */					/* return code */
char *response[RESPONSE_SIZE]={
        "Success",                                              /*  00  */  
        "Hostname is NULL",                                     /*  01  */  
        "Connection Error",                                     /*  02  */  
        "Serial Numbers Don't Match...",                        /*  03  */  
        "Execution as 'dba' user is denied",                    /*  04  */  
        "Execution as 'mongodb' user is denied",                /*  05  */  
        "Execution as 'mysql' user is denied",                  /*  06  */  
        "User not in correct group",                            /*  07  */  
        "Error retrieving user id",                             /*  08  */  
        "Invalid IP address",                                   /*  09  */  
        "Missing type argument",                                /*  10  */  
        "Missing host argument",                                /*  11  */  
        "Invalid hostname",                                     /*  12  */  
        "Error verifying keyfiles",                             /*  13  */  
        "Error sending data",                                   /*  14  */  
        "Error reading system() output",                        /*  15  */  
        "ERROR writing to socket",                              /*  16  */  
        "Error opening Keyfile for writing",                    /*  17  */  
        "Error opening Private Output file for writing",        /*  18  */  
        "Error opening Public Output file for writing",         /*  19  */  
        "peminfo: stat()",                                      /*  20  */  
        "Out of Virtual Memory",                                /*  21  */  
        "Error reading keyfile",                                /*  22  */  
        "Error Reading Key info",                               /*  23  */  
        "Can't bind to port",                                   /*  24  */  
        "Can't configure listening port",                       /*  25  */  
        "Error creating Keyfile",                               /*  26  */  
        "Error deleting Private file",                          /*  27  */  
        "Error deleting Public file",                           /*  28  */  
        "Error deleting Keyfile",                               /*  29  */  
        "ERROR on accept",                                      /*  30  */  
        "ERROR on fork",                                        /*  31  */  
        "Error opening NIC file",                               /*  32  */  
        "No Interface to activate",                             /*  33  */  
        "IP does not exist on this host",                       /*  34  */  
        "Error getting NIC",                                    /*  35  */  
        "DELIP ERROR writing to socket",                        /*  36  */  
        "Deleted Interface",                                    /*  37  */  
        "Error Creating NIC",                                   /*  38  */  
        "Error Getting Host",                                   /*  39  */  
        "Error getting ip",                                     /*  40  */  
        "ERROR opening socket",                                 /*  41  */  
        "Error reading from socket",                            /*  42  */  
        "GETIP ERROR writing to socket",                        /*  43  */  
        "GETNIC ERROR writing to socket",                       /*  44  */  
        "SETIP ERROR writing to socket",                        /*  45  */  
        "Activate NIC Error writing to socket",                 /*  46  */  
        "Enable NIC Error writing to socket",                   /*  47  */  
        "Disable NIC Error writing to socket",                  /*  48  */  
        "ERROR writing to socket",                              /*  49  */  
        "GETHOST ERROR writing to socket",                      /*  50  */  
        "GETIFACE ERROR writing to socket",                     /*  51  */  
        "GETIP ERROR writing to socket",                        /*  52  */  
        "Missing ip argument",                                  /*  53  */  
        "SETIP ERROR writing to socket",                        /*  54  */  
        "NIC Not Returned",                                     /*  55  */  
        "Disabled NIC",                                         /*  56  */  
        "IP Not Found",                                         /*  57  */  
        "Activated NIC",                                        /*  58  */  
        "Type option not recognized",                           /*  59  */  
        "NIC not Deleted",                                      /*  60  */  
        "NIC not found",                                        /*  61  */  
        "Created NIC",                                          /*  62  */  
        "IP exists",                                            /*  63  */  
        "Type argument not recognized",                         /*  64  */  
        "Error Opening File",                                   /*  65  */  
        "Refusing to remove Main interface",                    /*  66  */
        "Error Sending List of ips"                             /*  67  */
};
#endif
