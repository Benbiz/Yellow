#ifndef PCAPHEADER_H_
# define PCAPHEADER_H_

namespace Yellow
{
  namespace PCAP
  {
    /*
     * Headers of pcap file format
     * For more informations: https://wiki.wireshark.org/Development/LibpcapFileFormat
     */

    // Global header at the begining of the file
    struct GlobalHeader
    {
      int32_t   magic_number;   /* magic number */
      uint16_t  version_major;  /* major version number */
      uint16_t  version_minor;  /* minor version number */
      int32_t   thiszone;       /* GMT to local correction */
      uint32_t  sigfigs;        /* accuracy of timestamps */
      uint32_t  snaplen;        /* max length of captured packets, in octets */
      uint32_t  network;        /* data link type */
    } __attribute__((packed));

    // Header of each packet
    struct RecordHeader
    {
      uint32_t ts_sec;         /* timestamp seconds */
      uint32_t ts_usec;        /* timestamp microseconds */
      uint32_t incl_len;       /* number of octets of packet saved in file */
      uint32_t orig_len;       /* actual length of packet */
    } __attribute__((packed));
  }
}

#endif /* !PCAPHEADER_H_ */
