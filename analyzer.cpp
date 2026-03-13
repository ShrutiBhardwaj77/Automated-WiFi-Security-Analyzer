#include "analyzer.h"
#include "logger.h"
#include "packet_capture.h"
#include <iostream>
#include <cstdlib>

using namespace std;

void Analyzer::detectInterface() {

    Logger::log("Detecting active network interfaces...");

    system("ifconfig | grep 'status: active'");
}

void Analyzer::listDevices() {

    Logger::log("Listing connected devices from ARP table...");

    system("arp -a");
}

void Analyzer::checkOpenPorts() {

    Logger::log("Checking open network ports...");

    system("lsof -i -P -n");
}

void Analyzer::capturePacketsRealTime() {

    Logger::log("Starting real-time packet capture using libpcap...");

    startPacketCapture();
}

void Analyzer::trafficSummary() {

    Logger::log("Generating protocol traffic summary...");

    cout << "\nTCP Connections:\n";
    system("netstat -an | grep tcp | wc -l");

    cout << "\nUDP Connections:\n";
    system("netstat -an | grep udp | wc -l");

    cout << "\nEstablished Connections:\n";
    system("netstat -an | grep ESTABLISHED | wc -l");
}
