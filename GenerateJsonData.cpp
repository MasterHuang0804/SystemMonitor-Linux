#include "GenerateJsonData.h"

GenerateJsonData::GenerateJsonData()
{
	const char *dirname = "/";

	sys_info = new SystemInfo();
	cpu_info    = new CpuInfo();
	mem_info    = new MemoryInfo();

	disk_info 	= new DiskInfo(dirname);
	disk_info->CalculateDiskReadWriteSpeed();

	net_info = new NetInterfaceInfo();
	net_info->CalculateNetStatIOSpeed();
}

Json::Value GenerateJsonData::GetSystemPerformanceInfo()
{
	Json::Value root;
	Json::Value json_mem;
	Json::Value json_disk;
	Json::Value json_net ;

	root["time"] = Json::Value((Json::Value::UInt64) sys_info->GetTimeGMT());

	root["vmid"] = Json::Value("Linux-vmid") ;

	root["cpu"] = Json::Value(cpu_info->GetCpuTotalUsedRate());;

	json_mem["total"] = Json::Value((Json::Value::UInt64)mem_info->GetTotalMemSize());
	json_mem["used"] = Json::Value((Json::Value::UInt64)mem_info->GetUsedMemSize());
	root["mem"] = json_mem;

	json_disk["total"] = Json::Value((Json::Value::UInt64)disk_info->GetDiskTotalSize());
	json_disk["used"] = Json::Value((Json::Value::UInt64)disk_info->GetDiskUsedSize());
	json_disk["read"] = Json::Value((Json::Value::UInt)disk_info->GetDiskOutSpeed());
	json_disk["write"] = Json::Value((Json::Value::UInt)disk_info->GetDiskInSpeed());
	root["disk"] = json_disk;

	json_net["in"] = Json::Value((Json::Value::UInt)net_info->GetNetStatReceiveSpeed());
	json_net["out"] = Json::Value((Json::Value::UInt)net_info->GetNetStatTransmitSpeed());
	root["net"] = json_net;

	return root;
}

Json::Value GenerateJsonData::GetSystemNetInfo()
{
	Json::Value root;

	return root;
}

GenerateJsonData::~GenerateJsonData()
{

}

