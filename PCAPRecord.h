#ifndef PCAPRECORD
# define PCAPRECORD

namespace Yellow
{
  namespace PCAP
  {
    class Record
    {
    public:
      Record(std::shared_ptr<Yellow::Packet> packet);
      Record();
      ~Record();

      const RecordHeader                    &getHeader() const;
      const std::shared_ptr<Yellow::Packet> getPacket() const;

    private:
      friend std::ostream &operator<<(std::ostream &output, Yellow::PCAP::Record &user);
      friend std::istream &operator>>(std::istream &input, Yellow::PCAP::Record &user);

      RecordHeader                    _hdr;
      std::shared_ptr<Yellow::Packet> _packet;
    };

    std::ostream &operator<<(std::ostream &output, Yellow::PCAP::Record &user);
    std::istream &operator>>(std::istream &input, Yellow::PCAP::Record &user);
  }
}

#endif /* !PCAPRECORD */
