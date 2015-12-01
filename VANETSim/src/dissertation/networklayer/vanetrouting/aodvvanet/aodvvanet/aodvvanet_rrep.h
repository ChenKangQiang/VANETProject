/*****************************************************************************
 *
 * Copyright (C) 2001 Uppsala University & Ericsson AB.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 * Authors: Erik Nordstr�m, <erik.nordstrom@it.uu.se>
 *
 *
 *****************************************************************************/
#ifndef _AODVVANET_AODVVANETRREP_H
#define _AODVVANET_AODVVANETRREP_H

#ifndef NS_NO_GLOBALS

#ifndef OMNETPP
#ifndef  _WIN32
#include <endian.h>
#else
#ifndef __LITTLE_ENDIAN
#define __LITTLE_ENDIAN
#endif
#endif
#endif

#include "defs_aodvvanet.h"
#include "routing_table_aodvvanet.h"

/* AODVVANETRREP Flags: */

#define AODVVANETRREP_ACK       0x1
#define AODVVANETRREP_REPAIR    0x2

#ifndef OMNETPP
typedef struct
{
    u_int8_t type;
#if defined(__LITTLE_ENDIAN)
    u_int16_t res1:6;
    u_int16_t a:1;
    u_int16_t r:1;
    u_int16_t prefix:5;
    u_int16_t res2:3;
#elif defined(__BIG_ENDIAN)
    u_int16_t r:1;
    u_int16_t a:1;
    u_int16_t res1:6;
    u_int16_t res2:3;
    u_int16_t prefix:5;
#else
#error "Adjust your <bits/endian.h> defines"
#endif
    u_int8_t hcnt;
    u_int32_t dest_addr;
    u_int32_t dest_seqno;
    u_int32_t orig_addr;
    u_int32_t lifetime;
} AODVVANETRREP;

#define AODVVANETRREP_SIZE sizeof(AODVVANETRREP)
typedef struct
{
    u_int8_t type;
    u_int8_t reserved;
} AODVVANETRREP_ack;

#define AODVVANETRREP_ACK_SIZE sizeof(AODVVANETRREP_ack)


#endif


#endif              /* NS_NO_GLOBALS */

#ifndef NS_NO_DECLARATIONS
AODVVANETRREP *rrep_create(u_int8_t flags,
                  u_int8_t prefix,
                  u_int8_t hcnt,
                  struct in_addr dest_addr,
                  u_int32_t dest_seqno,
                  struct in_addr orig_addr, u_int32_t life);

AODVVANETRREP_ack *rrep_ack_create();
AODVVANET_ext *rrep_add_ext(AODVVANETRREP * rrep, int type, unsigned int offset,
                       int len, char *data);
void rrep_send(AODVVANETRREP * rrep, rt_table_t * rev_rt, rt_table_t * fwd_rt, int size, double delay = 0);
void rrep_forward(AODVVANETRREP * rrep, int size, rt_table_t * rev_rt,
                  rt_table_t * fwd_rt, int ttl);
void rrep_process(AODVVANETRREP * rrep, int rreplen, struct in_addr ip_src,
                  struct in_addr ip_dst, int ip_ttl, unsigned int ifindex);
void rrep_ack_process(AODVVANETRREP_ack * rrep_ack, int rreplen, struct in_addr ip_src,
                      struct in_addr ip_dst);
#endif              /* NS_NO_DECLARATIONS */

#endif              /* AODVVANET_AODVVANETRREP_H */

