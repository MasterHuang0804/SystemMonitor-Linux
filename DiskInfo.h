#ifndef DISKINFO_H
#define DISKINFO_H

#include <iostream>
#include <sigar.h>
#include <unistd.h>

using namespace std;

class DiskInfo
{
public:
    DiskInfo();
    DiskInfo(const char *ch = "/");
    ~DiskInfo();

    uint64_t GetDiskTotalSize();
    uint64_t GetDiskAvailSize();
    uint64_t GetDiskUsedSize();

    uint64_t GetDiskInSpeed();
    uint64_t GetDiskOutSpeed();

    void 	 CalculateDiskReadWriteSpeed();
    float    GetDiskUsedRate();

private:
    uint64_t totalsize;
    uint64_t availsize;
    uint64_t inspeed;
    uint64_t outspeed;

    float    usedrate;
};

#endif // DISKINFO_H
