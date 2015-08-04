#include "CpuInfo.h"

CpuInfo::CpuInfo()
    :CpuNumber(0),CpuTotalUsedRate(0),CpuIdleRate(0)
{
    sigar_t *sigar_cpu;
    sigar_open(&sigar_cpu);

    /*Get cpu list info,such as number...*/
    sigar_cpu_list_t cpu_list;

    int status = sigar_cpu_list_get(sigar_cpu,&cpu_list);

    if(status != SIGAR_OK)
        cout<<"CPU LIST ERROR:"<<status<<sigar_strerror(sigar_cpu,status);

    CpuNumber = cpu_list.number;

    /*Get cpu used rate,idle rate...*/
    sigar_cpu_t cpu_old;
    sigar_cpu_t cpu_current;

    sigar_cpu_get(sigar_cpu,&cpu_old);
    sigar_cpu_perc_t perc;

    sleep(1);

    sigar_cpu_get(sigar_cpu,&cpu_current);

    sigar_cpu_perc_calculate(&cpu_old,&cpu_current,&perc);

    CpuTotalUsedRate = perc.combined;
    CpuIdleRate = perc.idle;

    cpu_old = cpu_current;

    /*Do something of destory and close*/

    sigar_cpu_list_destroy(sigar_cpu,&cpu_list);

    sigar_close(sigar_cpu);
}

int CpuInfo::GetCpuNumber()
{
    return CpuNumber;
}

int CpuInfo::GetCpuTotalUsedRate()
{
    return CpuTotalUsedRate * 100;
}

float CpuInfo::GetCpuIdleRate()
{
    return CpuIdleRate * 100 ;
}

CpuInfo::~CpuInfo()
{

}

