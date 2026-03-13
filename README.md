# Automated Wi-Fi Security Analyzer (C++)

## Overview
A modular C++ network analysis tool built for Unix-based systems to automate
network diagnostics, inspect open ports, capture live packet flow, and generate structured reports.

## Features
- Detect active network interfaces
- Inspect connected devices using ARP table
- Identify open ports and active sockets
- Capture live packet snapshots
- Timestamp-based structured logging

## Architecture
The project follows a modular design:

- main.cpp → CLI and control flow
- analyzer.cpp → Network analysis logic
- logger.cpp → Structured logging system

## Technologies Used
- C++
- System-level networking utilities (ifconfig, arp, lsof, tcpdump)
- Unix-based OS / macOS / Unix-based systems

## Future Improvements
- Replace system utilities with libpcap for raw packet parsing
- Implement anomaly detection engine
- Add multi-threaded packet processing
- Performance profiling and optimization

## Learning Outcomes
- Practical understanding of TCP/IP stack
- Network interface inspection
- Packet capture workflow
- Modular C++ design principles
