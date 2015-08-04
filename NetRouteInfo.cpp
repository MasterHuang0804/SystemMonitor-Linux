#include "NetRouteInfo.h"

NetRouteInfo::NetRouteInfo()
{
    sigar_t *sigar_route;
    sigar_net_route_list_t route_list;

    sigar_open(&sigar_route);

    int status = sigar_net_route_list_get(sigar_route,&route_list);

    if(status != SIGAR_OK)
        cout<<"Net Route Error: "<<status<<sigar_strerror(sigar_route,status);


    for(int i=0; i<route_list.number; i++)
    {
        sigar_net_route_t route = route_list.data[i];

        cout<<route.mask.addr.in<<endl;
    }

    sigar_net_route_list_destroy(sigar_route,&route_list);

    sigar_close(sigar_route);

}

NetRouteInfo::~NetRouteInfo()
{

}

