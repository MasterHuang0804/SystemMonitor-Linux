#ifndef NETINTERFACEINFO_H
#define NETINTERFACEINFO_H

#include <iostream>
#include <sigar.h>
#include <cstring>
#include <vector>
#include <unistd.h>

using namespace  std;

class NetInterfaceInfo
{
public:
    NetInterfaceInfo();
    ~NetInterfaceInfo();
    uint64_t GetNetStatTransmitSpeed();
    uint64_t GetNetStatReceiveSpeed();

    void CalculateNetStatIOSpeed();

private:
    vector<char *> IfConfigName;
    uint64_t  transmit_speed;
    uint64_t  receive_speed;

};

#endif // NETINTERFACEINFO_H
