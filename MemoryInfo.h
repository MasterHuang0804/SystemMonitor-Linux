#ifndef MEMORYINFO_H
#define MEMORYINFO_H

#include <iostream>
#include <sigar.h>

using namespace std;

class MemoryInfo
{
public:
    MemoryInfo();
    ~MemoryInfo();

    __uint64_t GetTotalMemSize();
    __uint64_t GetFreeMemSize();
    __uint64_t GetUsedMemSize();
    __uint64_t GetTotalSwapSize();
    __uint64_t GetFreeSwapSize();
    __uint64_t GetUsedSwapSize();

    float GetMemUsedRate();
    float GetSwapUsedRate();

private:
    __uint64_t TotalMemSize;
    __uint64_t FreeMemSize;
    __uint64_t UsedMemSize;

    __uint64_t TotalSwapSize;
    __uint64_t FreeSwapSize;
    __uint64_t UsedSwapSize;

    float MemUsedRate,SwapUsedRate;
};

#endif // MEMORYINFO_H
