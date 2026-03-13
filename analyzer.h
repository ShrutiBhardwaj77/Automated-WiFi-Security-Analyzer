#ifndef ANALYZER_H
#define ANALYZER_H

class Analyzer {
public:
    void detectInterface();
    void listDevices();
    void checkOpenPorts();
    void capturePackets();
    void capturePacketsRealTime();
void trafficSummary();
};

#endif
