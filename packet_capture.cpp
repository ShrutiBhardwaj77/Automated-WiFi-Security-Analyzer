#include <pcap.h>
#include <iostream>
#include <arpa/inet.h>
#include <netinet/ip.h>

using namespace std;

int packetCount = 0;

void packetHandler(u_char *args,
                   const struct pcap_pkthdr *header,
                   const u_char *packet)
{
    packetCount++;

    struct ip *ipHeader = (struct ip*)(packet + 14);

    cout << "\nPacket #" << packetCount << endl;

    cout << "Source IP: "
         << inet_ntoa(ipHeader->ip_src)
         << endl;

    cout << "Destination IP: "
         << inet_ntoa(ipHeader->ip_dst)
         << endl;

    cout << "Protocol: ";

    switch(ipHeader->ip_p)
    {
        case 1:
            cout << "ICMP";
            break;

        case 6:
            cout << "TCP";
            break;

        case 17:
            cout << "UDP";
            break;

        default:
            cout << "Other";
    }

    cout << endl;

    cout << "Packet Size: "
         << header->len
         << " bytes"
         << endl;
}

void startPacketCapture()
{
    char errbuf[PCAP_ERRBUF_SIZE];

    pcap_t *handle;

    handle = pcap_open_live(
        "en0",
        BUFSIZ,
        1,
        1000,
        errbuf
    );

    if(handle == NULL)
    {
        cout << "Could not open network interface\n";
        return;
    }

    cout << "Starting real-time packet capture...\n";

    pcap_loop(handle, 20, packetHandler, NULL);

    pcap_close(handle);
}
