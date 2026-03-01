#include "analyzer.h"
#include <iostream>

int main() {

    Analyzer analyzer;
    int choice;

    while (true) {

        std::cout << "\nNetwork Analyzer\n";
        std::cout << "1. Detect Interface\n";
        std::cout << "2. List Devices\n";
        std::cout << "3. Check Open Ports\n";
        std::cout << "4. Capture Packets\n";
        std::cout << "5. Exit\n";
        std::cout << "Choice: ";

        std::cin >> choice;

        switch (choice) {
            case 1: analyzer.detectInterface(); break;
            case 2: analyzer.listDevices(); break;
            case 3: analyzer.checkOpenPorts(); break;
            case 4: analyzer.capturePackets(); break;
            case 5: return 0;
            default: std::cout << "Invalid choice\n";
        }
    }

    return 0;
}
