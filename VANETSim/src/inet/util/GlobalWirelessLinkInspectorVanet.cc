//
// Copyright (C) 2012 Alfonso Ariza Universidad de M�laga
// Copyright (C) 2015 Joanne Skiles
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
//

#include "GlobalWirelessLinkInspectorVanet.h"
GlobalWirelessLinkInspectorVanet::CostMap* GlobalWirelessLinkInspectorVanet::costMap = NULL;
GlobalWirelessLinkInspectorVanet::GlobalRouteMap *GlobalWirelessLinkInspectorVanet::globalRouteMap = NULL;
GlobalWirelessLinkInspectorVanet::LocatorMap *GlobalWirelessLinkInspectorVanet::globalLocatorMap = NULL;
GlobalWirelessLinkInspectorVanet::QueueSize *GlobalWirelessLinkInspectorVanet::queueSize;

Define_Module(GlobalWirelessLinkInspectorVanet);

GlobalWirelessLinkInspectorVanet::GlobalWirelessLinkInspectorVanet()
{
    // TODO Auto-generated constructor stub
    costMap = NULL;
    globalRouteMap = NULL;
    globalLocatorMap = NULL;
    queueSize = NULL;
}

GlobalWirelessLinkInspectorVanet::~GlobalWirelessLinkInspectorVanet()
{
    // TODO Auto-generated destructor stub
    if (costMap != NULL)
    {
        while (!costMap->empty())
        {
            delete costMap->begin()->second;
            costMap->erase(costMap->begin());
        }
        delete costMap;
        costMap = NULL;
    }
    if (globalRouteMap != NULL)
    {
        while (!globalRouteMap->empty())
        {
            ProtocolsRoutes vect = globalRouteMap->begin()->second;
            for (unsigned int i = 0;i < vect.size(); i++)
            {
                delete vect[i].routesVector;
            }
            globalRouteMap->erase(globalRouteMap->begin());
        }
        delete globalRouteMap;
        globalRouteMap = NULL;
    }
    if (globalLocatorMap != NULL)
    {
        delete globalLocatorMap;
        globalLocatorMap = NULL;
    }
}

void GlobalWirelessLinkInspectorVanet::initialize()
{

    if (costMap == NULL)
    {
        costMap = new CostMap;
    }
    else
    {
        opp_error("more that an instance of GlobalWirelessWirelessLinkInspector exist");
    }

    if (globalRouteMap == NULL)
    {
        globalRouteMap = new GlobalRouteMap;
    }
    else
    {
        opp_error("more that an instance of GlobalWirelessWirelessLinkInspector exist");
    }
    if (globalLocatorMap == NULL)
    {
        globalLocatorMap = new LocatorMap;
    }
    else
    {
        opp_error("more that an instance of GlobalWirelessWirelessLinkInspector exist");
    }
    if (queueSize == NULL)
    {
        queueSize = new QueueSize;
    }
    else
    {
        opp_error("more that an instance of GlobalWirelessWirelessLinkInspector exist");
    }
}

void GlobalWirelessLinkInspectorVanet::handleMessage(cMessage *msg)
{
    opp_error ("GlobalWirelessWirelessLinkInspector has received a packet");
}

void GlobalWirelessLinkInspectorVanet::setLinkCost(const VanetAddress& org,const VanetAddress& dest,const Link &link)
{
    if (!costMap)
        return;
    CostMap::iterator it = costMap->find(org);
    if (it != costMap->end())
    {
        NodeLinkCost *nLinkCost = it->second;
        NodeLinkCost::iterator it2 = nLinkCost->find(dest);
        if (it2 != nLinkCost->end())
        {
            it2->second = link;
            return;
        }
        else
        {
            nLinkCost->insert(std::make_pair(dest,link));
        }
    }
    else
    {
        NodeLinkCost *nLinkCost = new NodeLinkCost;
        nLinkCost->insert(std::make_pair(dest,link));
        costMap->insert(std::make_pair(org,nLinkCost));
    }
}

bool GlobalWirelessLinkInspectorVanet::getLinkCost(const VanetAddress& org,const VanetAddress& dest,Link &link)
{

    if (!costMap)
        return false;
    CostMap::iterator it = costMap->find(org);
    if (it != costMap->end())
    {
        NodeLinkCost *nLinkCost = it->second;
        NodeLinkCost::iterator it2 = nLinkCost->find(dest);
        if (it2 != nLinkCost->end())
        {
            link = it2->second;
            return true;
        }
    }
    return false;
}

bool GlobalWirelessLinkInspectorVanet::getCostPath(const std::vector<VanetAddress>& path, Link &link)
{

    if (!costMap)
        return false;
    link.costEtt = 0;
    link.costEtx = 0;
    for (unsigned int i = 0; i < path.size()-1; i++)
    {
        Link linkAux;
        if (getLinkCost(path[i],path[i+1],linkAux))
        {
            link.costEtt += linkAux.costEtt;
            link.costEtx += linkAux.costEtx;
        }
        else
            return false;
    }
    return true;
}

bool GlobalWirelessLinkInspectorVanet::getWorst(const std::vector<VanetAddress>& path, Link &link)
{

    if (!costMap)
        return false;
    link.costEtt = 0;
    link.costEtx = 0;
    for (unsigned int i = 0; i < path.size()-1; i++)
    {
        Link linkAux;
        if (getLinkCost(path[i],path[i+1],linkAux))
        {
            if (link.costEtx < linkAux.costEtx)
            {
                link.costEtt = linkAux.costEtt;
                link.costEtx = linkAux.costEtx;
            }
        }
        else
            return false;
    }
    return true;
}


bool GlobalWirelessLinkInspectorVanet::setRoute(const cModule* mod,const VanetAddress &orgA, const VanetAddress &dest, const VanetAddress &gw, const bool &erase)
{
    if (globalRouteMap == NULL)
        return false;
    GlobalRouteMap::iterator it = globalRouteMap->find(orgA);
    if (it == globalRouteMap->end())
        return false;
    RouteMap* routesVector = NULL;
    for (unsigned int i = 0; i < it->second.size(); i++)
    {
        if (it->second[i].mod == mod)
        {
            routesVector = it->second[i].routesVector;
            break;
        }
    }
    if (!routesVector)
        return false;
    RouteMap::iterator it2 = routesVector->find(dest);
    if (it2 != routesVector->end())
    {
        if (erase)
            routesVector->erase(it2);
        else
            it2->second = gw;
    }
    else
    {
        if (!erase)
            routesVector->insert(std::make_pair(dest,gw));
    }
    return true;
}

void GlobalWirelessLinkInspectorVanet::initRoutingTables (const cModule* mod,const VanetAddress &orgA, bool isProact)
{
    if (globalRouteMap == NULL)
        return;
    GlobalRouteMap::iterator it = globalRouteMap->find(orgA);
    if (it == globalRouteMap->end())
    {
        ProtocolRoutingData data;
        ProtocolsRoutes vect;
        data.isProactive = isProact;
        data.routesVector = new RouteMap;
        data.mod = const_cast<cModule*> (mod);
        vect.push_back(data);
        globalRouteMap->insert(std::make_pair(orgA,vect));
    }
    else
    {
        ProtocolRoutingData data;
        data.isProactive = isProact;
        data.mod = const_cast<cModule*> (mod);
        data.routesVector = new RouteMap;
        it->second.push_back(data);
    }
}

bool GlobalWirelessLinkInspectorVanet::getRoute(const VanetAddress &src, const VanetAddress &dest, std::vector<VanetAddress> &route)
{
    if (globalRouteMap == NULL)
        return false;
    VanetAddress next = src;
    route.clear();
    route.push_back(src);
    if (src == dest)
        return true;
    while (1)
    {
        GlobalRouteMap::iterator it = globalRouteMap->find(next);
        if (it == globalRouteMap->end())
            return false;
        if (it->second.empty())
            return false;

        if (it->second.size() == 1)
        {
            RouteMap * rt = it->second[0].routesVector;
            RouteMap::iterator it2 = rt->find(dest);
            if (it2 == rt->end())
                return false;
            if (it2->second == dest)
            {
                route.push_back(dest);
                return true;
            }
            else
            {
                route.push_back(it2->second);
                next = it2->second;
            }
        }
        else
        {
            if (it->second.size() > 2)
                throw cRuntimeError("Number of routing protocols bigger that 2");
            // if several protocols, search before in the proactive
            RouteMap * rt;
            if (it->second[0].isProactive)
                rt = it->second[0].routesVector;
            else
                rt = it->second[1].routesVector;
            RouteMap::iterator it2 = rt->find(dest);
            if (it2 == rt->end())
            {
                // search in the reactive

                if (it->second[0].isProactive)
                    rt = it->second[1].routesVector;
                else
                    rt = it->second[0].routesVector;
                it2 = rt->find(dest);
                if (it2 == rt->end())
                    return false;
            }
            if (it2->second == dest)
            {
                route.push_back(dest);
                return true;
            }
            else
            {
                route.push_back(it2->second);
                next = it2->second;
            }
        }
    }
    return false;
}


bool GlobalWirelessLinkInspectorVanet::getRouteWithLocator(const VanetAddress &src, const VanetAddress &dest, std::vector<VanetAddress> &route)
{
    if (globalRouteMap == NULL)
        return false;
    // search in the locator tables
    //
    VanetAddress origin;
    VanetAddress destination;
    if (!getLocatorInfo(src, origin))
    {
        origin = src;
    }
    if (!getLocatorInfo(dest, destination))
    {
        destination = dest;
    }
    return getRoute(origin,destination,route);
}



void GlobalWirelessLinkInspectorVanet::setLocatorInfo(VanetAddress node, VanetAddress ap)
{
    if (globalLocatorMap == NULL)
        return;
    if (!ap.isUnspecified())
        (*globalLocatorMap)[node] = ap;
    else
    {
        LocatorIteartor it =  globalLocatorMap->find(node);
        if (it != globalLocatorMap->end())
            globalLocatorMap->erase(it);
    }
}

bool GlobalWirelessLinkInspectorVanet::getLocatorInfo(VanetAddress node, VanetAddress &ap)
{
    if (globalLocatorMap == NULL)
        return false;
    LocatorIteartor it =  globalLocatorMap->find(node);
    if (it == globalLocatorMap->end())
        return false;
    ap = it->second;
    return true;
}


bool GlobalWirelessLinkInspectorVanet::getNumNodes(VanetAddress node, int &cont)
{
    cont = 0;
    if (globalLocatorMap == NULL)
        return false;
    LocatorIteartor it =  globalLocatorMap->find(node);
    if (it == globalLocatorMap->end())
        return false;
    VanetAddress ap = it->second;
    for (it = globalLocatorMap->begin();it != globalLocatorMap->end();it++)
    {
        if (it->second == ap && it->first != node)
            cont++;
    }
    return true;
}

bool GlobalWirelessLinkInspectorVanet::areNeighbour(const VanetAddress &node1, const VanetAddress &node2,bool &areNei)
{
    areNei = false;
    if (globalLocatorMap == NULL)
        return false;
    LocatorIteartor it1 =  globalLocatorMap->find(node1);
    if (it1 == globalLocatorMap->end())
        return false;
    LocatorIteartor it2 =  globalLocatorMap->find(node2);
    if (it2 == globalLocatorMap->end())
        return false;
    VanetAddress ap1 = it1->second;
    VanetAddress ap2 = it2->second;
    if (ap1 == ap2)
        areNei = true;
    return true;
}


bool GlobalWirelessLinkInspectorVanet::setQueueSize(const VanetAddress &node, const uint64_t &val)
{
    if (queueSize == NULL)
        return false;
    (*queueSize)[node] = val;
    return true;
}

bool GlobalWirelessLinkInspectorVanet::getQueueSize(const VanetAddress &node, uint64_t & val)
{
    if (queueSize == NULL)
        return false;
    QueueSize::iterator it = queueSize->find(node);
    if (it == queueSize->end())
        return false;
    val = it->second;
    return true;
}

