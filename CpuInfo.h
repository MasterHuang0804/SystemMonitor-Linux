#ifndef CPUINFO_H
#define CPUINFO_H

#include <iostream>
#include <unistd.h>
#include <sigar.h>

extern "C"
{
#include <sigar_format.h>
}

using namespace std;

class CpuInfo
{
public:
    CpuInfo();
    ~CpuInfo();

    int     GetCpuNumber();
    int	   	GetCpuTotalUsedRate();
    float   GetCpuIdleRate();

private:
    int     CpuNumber;
    float   CpuTotalUsedRate;
    float   CpuIdleRate;

};

#endif // CPUINFO_H
