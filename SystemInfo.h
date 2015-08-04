#ifndef SYSTEMINFO_H
#define SYSTEMINFO_H

#include <iostream>
#include <sigar.h>
#include <string>
#include <time.h>
#include <cstdint>

using namespace std;

class SystemInfo
{
public:
    SystemInfo();
    ~SystemInfo();

    string GetSystemDescription();
    string GetSystemArch();

    uint64_t GetTimeGMT();

private:
    string SystemDescription;
    string SystemArch;

};

#endif // SYSTEMINFO_H
