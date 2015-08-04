#include "NetConnectionInfo.h"

NetConnectionInfo::NetConnectionInfo()
{
    sigar_t *sigar_conn;
    sigar_net_connection_list_t conn_list;

    sigar_open(&sigar_conn);

    int flags = SIGAR_NETCONN_SERVER | SIGAR_NETCONN_CLIENT | SIGAR_NETCONN_TCP | SIGAR_NETCONN_UDP ;

    int status = sigar_net_connection_list_get(sigar_conn,&conn_list,flags);

    if(status != SIGAR_OK)
        cout<<"Net Connection Error: "<<status<<sigar_strerror(sigar_conn,status);

    for(int i=0; i<conn_list.number; i++)
    {
        sigar_net_connection_t conn = conn_list.data[i];

    }

    sigar_net_connection_list_destroy(sigar_conn,&conn_list);

    sigar_close(sigar_conn);
}

NetConnectionInfo::~NetConnectionInfo()
{


}

