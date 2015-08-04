#include "SystemInfo.h"

SystemInfo::SystemInfo()
    :SystemDescription("CentOS"),SystemArch("x86_64")
{
    sigar_t *sigar_sysinfo ;
    sigar_sys_info_t sysinfo;

    sigar_open(&sigar_sysinfo);

    sigar_sys_info_get(sigar_sysinfo,&sysinfo);

    SystemDescription   = sysinfo.description ;
    SystemArch          = sysinfo.arch ;

    sigar_close(sigar_sysinfo);

}

uint64_t SystemInfo::GetTimeGMT()
{
	const time_t t = time(NULL);

	return (uint64_t)t;
}

string SystemInfo::GetSystemDescription()
{
    return SystemDescription;
}

string SystemInfo::GetSystemArch()
{
    return SystemArch;
}

SystemInfo::~SystemInfo()
{

}

