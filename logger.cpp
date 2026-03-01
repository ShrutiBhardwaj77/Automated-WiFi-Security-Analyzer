#include "logger.h"
#include <iostream>
#include <fstream>
#include <ctime>

void Logger::log(const std::string &message) {

    std::ofstream file("report.txt", std::ios::app);

    time_t now = time(0);

    file << "---------------------------------\n";
    file << "Time: " << ctime(&now);
    file << message << "\n";

    file.close();

    std::cout << message << std::endl;
}
