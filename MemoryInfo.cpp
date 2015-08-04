#include "MemoryInfo.h"

MemoryInfo::MemoryInfo()
    :TotalMemSize(0),FreeMemSize(0),UsedMemSize(0),
      TotalSwapSize(0),FreeSwapSize(0),UsedSwapSize(0),
      MemUsedRate(0),SwapUsedRate(0)
{
    /*Get Mem Info*/
    sigar_t *sigar_mem;
    sigar_mem_t mem;

    sigar_open(&sigar_mem);
    sigar_mem_get(sigar_mem,&mem);

    TotalMemSize = mem.total;
    FreeMemSize  = mem.free;
    UsedMemSize  = mem.used;
    MemUsedRate = mem.used_percent;

    /*Get Swap Info*/
    sigar_t *sigar_swap;
    sigar_swap_t swap;

    sigar_open(&sigar_swap);
    sigar_swap_get(sigar_swap,&swap);

    TotalSwapSize = swap.total;
    FreeSwapSize  = swap.free;
    UsedSwapSize  = swap.used;

    SwapUsedRate = (double)UsedSwapSize/(double)TotalSwapSize;

    //cout<<TotalSwapSize/1024<<"\t"<<FreeSwapSize/1024<<"\t"<<UsedSwapSize/1024<<endl;

    sigar_close(sigar_mem);
    sigar_close(sigar_swap);
}

__uint64_t MemoryInfo::GetTotalMemSize()
{
    return TotalMemSize / 1024 / 1024;
}

__uint64_t MemoryInfo::GetFreeMemSize()
{
    return FreeMemSize / 1024 / 1024;
}

__uint64_t MemoryInfo::GetUsedMemSize()
{
    return UsedMemSize / 1024 / 1024;
}

float MemoryInfo::GetMemUsedRate()
{
    return MemUsedRate;
}

__uint64_t MemoryInfo::GetTotalSwapSize()
{
    return TotalSwapSize / 1024 / 1024;
}

__uint64_t MemoryInfo::GetFreeSwapSize()
{
    return FreeSwapSize / 1024 / 1024;
}

__uint64_t MemoryInfo::GetUsedSwapSize()
{
    return UsedSwapSize / 1024 / 1024;
}

float MemoryInfo::GetSwapUsedRate()
{
    return SwapUsedRate;
}

MemoryInfo::~MemoryInfo()
{

}

