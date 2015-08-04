#include "NetInterfaceInfo.h"

NetInterfaceInfo::NetInterfaceInfo()
	:transmit_speed(0),receive_speed(0)
{
    sigar_t *sigar_netinfo;

    sigar_net_interface_list_t iflist;

    sigar_open(&sigar_netinfo);

    int status = sigar_net_interface_list_get(sigar_netinfo,&iflist);

    if(status != SIGAR_OK)
        cout<<"Net Interface Error: "<<sigar_strerror(sigar_netinfo,status);

    for(int i=0; i<iflist.number; i++)
    {
        char *ifname = iflist.data[i] ;

        IfConfigName.push_back(ifname);

        sigar_net_interface_stat_t      ifstat;
        sigar_net_interface_config_t    ifconfig;

        int status2 = sigar_net_interface_config_get(sigar_netinfo,ifname,&ifconfig);

        if(status2 != SIGAR_OK)
            cout<<"Net Interface Config Error: "<<sigar_strerror(sigar_netinfo,status2);

    }

    sigar_net_interface_list_destroy(sigar_netinfo,&iflist);

    sigar_close(sigar_netinfo);

}

void NetInterfaceInfo::CalculateNetStatIOSpeed()
{
	sigar_t *net;
	sigar_net_interface_stat_t netstat;

	sigar_open(&net);

	const char *name = "eth0";

	sigar_net_interface_stat_get(net,name,&netstat);

	uint64_t tx1 = netstat.tx_bytes;
	uint64_t rx1 = netstat.rx_bytes;

	sleep(1);

	sigar_net_interface_stat_get(net,name,&netstat);

	uint64_t tx2 = netstat.tx_bytes;
	uint64_t rx2 = netstat.rx_bytes;

	transmit_speed = tx2 - tx1;
	receive_speed = rx2 - rx1;

	sigar_close(net);
}

uint64_t NetInterfaceInfo::GetNetStatReceiveSpeed()
{
	return receive_speed;
}

uint64_t NetInterfaceInfo::GetNetStatTransmitSpeed()
{
	return transmit_speed;
}
NetInterfaceInfo::~NetInterfaceInfo()
{

}

