#include <pcap.h>
#include <iostream>
#include "packet_capture.h"

using namespace std;

void packetHandler(u_char *args,
                   const struct pcap_pkthdr *header,
                   const u_char *packet)
{
    cout << "Packet captured! Length: "
         << header->len << endl;
}

void startPacketCapture()
{
    char errbuf[PCAP_ERRBUF_SIZE];

    pcap_t *handle;

    handle = pcap_open_live("en0",
                            BUFSIZ,
                            1,
                            1000,
                            errbuf);

    if (handle == NULL)
    {
        cout << "Could not open network interface\n";
        return;
    }

    cout << "Starting real-time packet capture...\n";

    pcap_loop(handle, 20, packetHandler, NULL);

    pcap_close(handle);
}
