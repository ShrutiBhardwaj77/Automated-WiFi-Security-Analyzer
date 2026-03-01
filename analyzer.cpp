#include "analyzer.h"
#include "logger.h"
#include <cstdlib>

void Analyzer::detectInterface() {
    Logger::log("Detecting active network interfaces...");
    system("ifconfig | grep 'status: active'");
}

void Analyzer::listDevices() {
    Logger::log("Listing connected devices (ARP table)...");
    system("arp -a");
}

void Analyzer::checkOpenPorts() {
    Logger::log("Checking open ports...");
    system("lsof -i -P -n");
}

void Analyzer::capturePackets() {
    Logger::log("Capturing 10 live packets...");
    system("sudo tcpdump -i en0 -c 10");
}
