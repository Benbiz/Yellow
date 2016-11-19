#ifndef STDAFX_H_
# define STDAFX_H_

// System
#include <memory>
#include <iostream>
#include <exception>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/ip_icmp.h>   //Provides declarations for icmp header
#include <netinet/udp.h>   //Provides declarations for udp header
#include <netinet/tcp.h>   //Provides declarations for tcp header
#include <netinet/ip.h>    //Provides declarations for ip header
#include <netinet/if_ether.h>  //For ETH_P_ALL
#include <sys/ioctl.h>
#include <net/if.h>
#include <net/ethernet.h>  //For ether_header
#include <linux/if_packet.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <cstring>
#include <cstdint>
#include <string>
#include <unistd.h>
#include <ctime>
#include <ratio>
#include <chrono>
#include <vector>
#include <fstream>

#endif /* !STDAFX_H_ */
