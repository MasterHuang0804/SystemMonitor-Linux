#ifndef GENERATEJSONDATA_H
#define GENERATEJSONDATA_H

#include <iostream>
#include <json/json.h>
#include <json/value.h>


#include "CpuInfo.h"
#include "MemoryInfo.h"
#include "DiskInfo.h"
#include "SystemInfo.h"
#include "NetInterfaceInfo.h"
#include "NetConnectionInfo.h"
#include "NetRouteInfo.h"

using namespace std;

class GenerateJsonData
{
public:
    GenerateJsonData();
    ~GenerateJsonData();

    Json::Value GetSystemPerformanceInfo();
    Json::Value GetSystemNetInfo();

private:
    SystemInfo  *sys_info;
    CpuInfo     *cpu_info;
    MemoryInfo  *mem_info;
    DiskInfo    *disk_info;
    NetInterfaceInfo *net_info;
};

#endif // GENERATEJSONDATA_H
