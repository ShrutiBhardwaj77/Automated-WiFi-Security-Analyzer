#include "analyzer.h"
#include <iostream>

using namespace std;

int main() {

    Analyzer analyzer;
    int choice;

    while (true) {

        cout << "\n===== Network Traffic Analyzer =====\n";
        cout << "1. Detect Interface\n";
        cout << "2. List Devices\n";
        cout << "3. Check Open Ports\n";
        cout << "4. Capture Packets (Real Time)\n";
        cout << "5. Traffic Summary\n";
        cout << "6. Exit\n";
        cout << "Choice: ";

        cin >> choice;

        switch (choice) {

            case 1:
                analyzer.detectInterface();
                break;

            case 2:
                analyzer.listDevices();
                break;

            case 3:
                analyzer.checkOpenPorts();
                break;

            case 4:
                analyzer.capturePacketsRealTime();
                break;

            case 5:
                analyzer.trafficSummary();
                break;

            case 6:
                return 0;

            default:
                cout << "Invalid choice\n";
        }
    }

    return 0;
}
