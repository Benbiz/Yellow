#ifndef PCAPRECORDER_H_
# define PCAPRECORDER_H_

#include "Packet.h"
#include "PCAPHeader.h"
#include "PCAPRecord.h"

namespace Yellow
{
  namespace PCAP
  {
    class Recorder
    {
    public:
      Recorder();
      ~Recorder();

      const GlobalHeader                          &getGlobalHeader() const;
      const std::vector<std::shared_ptr<Record>>  &getRecords() const;

      std::shared_ptr<Record>                     addRecord(std::shared_ptr<Record>);
      std::shared_ptr<Record>                     addRecord(std::shared_ptr<Yellow::Packet>);

      friend std::ostream                                &operator<<(std::ostream &output, Yellow::PCAP::Recorder &);
      friend std::istream                                &operator>>(std::istream &input, Yellow::PCAP::Recorder &);

    private:
      GlobalHeader                          _gheader;
      std::vector<std::shared_ptr<Record>>  _records;
    };
    std::ostream                                &operator<<(std::ostream &output, const Yellow::PCAP::Recorder &);
    std::istream                                &operator>>(std::istream &input, Yellow::PCAP::Recorder &);
  }
}

#endif /* !PCAPRECORDER */
