#include "DiskInfo.h"

DiskInfo::DiskInfo()
    :totalsize(0),availsize(0),usedrate(0),
	 inspeed(0),outspeed(0)
{

}

DiskInfo::DiskInfo(const char *dirname)
    :totalsize(0),availsize(0),usedrate(0),
	 inspeed(0),outspeed(0)
{
    sigar_t *sigar_disk;
    sigar_file_system_usage_t filesystem;
//    sigar_proc_disk_io_t io;
//    sigar_pid_t pid;

    sigar_open(&sigar_disk);

    sigar_file_system_usage_get(sigar_disk,dirname,&filesystem);
    //sigar_proc_disk_io_get(sigar_disk,pid,&io);

    totalsize = filesystem.total;
    availsize = filesystem.avail;
    usedrate  = filesystem.use_percent;

    //cout<<"ProcRead"<<io.bytes_read<<"\tProcWrite: "<<io.bytes_total<<endl;

    sigar_close(sigar_disk);
}

void DiskInfo::CalculateDiskReadWriteSpeed()
{
	sigar_t *sigar_disk;
	sigar_disk_usage_t disk;

	sigar_open(&sigar_disk);

	const char *name = "sda";

	sigar_disk_usage_get(sigar_disk,name,&disk);

	uint64_t rbyte1 = disk.read_bytes;
	uint64_t wbyte1 = disk.write_bytes;

	sleep(1);

	sigar_disk_usage_get(sigar_disk,name,&disk);

	uint64_t rbyte2 = disk.read_bytes;
	uint64_t wbyte2 = disk.write_bytes;

	outspeed = (rbyte2 - rbyte1) / 1024 ;
	inspeed  = (wbyte2 - wbyte1) / 1024 ;

	cout<<"In: "<<inspeed<<"\tOut"<<outspeed<<endl;

	sigar_close(sigar_disk);
}

uint64_t DiskInfo::GetDiskInSpeed()
{
	return inspeed ;
}

uint64_t DiskInfo::GetDiskOutSpeed()
{
	return outspeed;
}

uint64_t DiskInfo::GetDiskTotalSize()
{
    return totalsize / 1024 ;           //"Unit: MB"
}

uint64_t DiskInfo::GetDiskAvailSize()
{
    return availsize / 1024 ;           //"Unit: MB"
}

uint64_t DiskInfo::GetDiskUsedSize()
{
	return (totalsize - availsize) / 1024 ; //"Unit: MB"
}

float DiskInfo::GetDiskUsedRate()
{
    return usedrate ;
}

DiskInfo::~DiskInfo()
{

}

