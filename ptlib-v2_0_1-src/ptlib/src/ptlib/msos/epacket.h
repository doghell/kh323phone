/*
 * epacket.h
 *
 * Ethernet Packet Interface to NDIS drivers.
 *
 * Copyright 1998 Equivalence Pty. Ltd.
 *
 * Original code by William Ingle (address unknown)
 *
 * $Log: epacket.h,v $
 * Revision 1.4  1998/10/23 04:09:07  robertj
 * Fixes for NT support.
 * Allowed both old and new driver by compilation option.
 *
 * Revision 1.3  1998/10/06 10:24:40  robertj
 * Fixed hang when using reset command, removed the command!
 *
 * Revision 1.2  1998/10/01 09:06:29  robertj
 * NT driver compatibility.
 *
 * Revision 1.1  1998/09/28 08:10:33  robertj
 * Initial revision
 *
 */

#ifndef __EPACKET_H
#define __EPACKET_H

#ifndef CTL_CODE
#include <winioctl.h>
#endif

#ifdef USE_VPACKET

#define FILE_DEVICE_EPACKET 0x8000

#define IOCTL_EPACKET_QUERY_OID  (UINT)CTL_CODE(FILE_DEVICE_EPACKET, 0, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_EPACKET_SET_OID    (UINT)CTL_CODE(FILE_DEVICE_EPACKET, 1, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_EPACKET_STATISTICS (UINT)CTL_CODE(FILE_DEVICE_EPACKET, 2, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_EPACKET_READ       (UINT)CTL_CODE(FILE_DEVICE_EPACKET, 4, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_EPACKET_WRITE      (UINT)CTL_CODE(FILE_DEVICE_EPACKET, 5, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_EPACKET_BIND       (UINT)CTL_CODE(FILE_DEVICE_EPACKET, 7, METHOD_BUFFERED, FILE_ANY_ACCESS)

#else

#define FILE_DEVICE_EPACKET 0x1000

#define IOCTL_EPACKET_VERSION   CTL_CODE(FILE_DEVICE_EPACKET, 0, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_EPACKET_BIND      CTL_CODE(FILE_DEVICE_EPACKET, 1, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_EPACKET_QUERY_OID CTL_CODE(FILE_DEVICE_EPACKET, 2, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_EPACKET_SET_OID   CTL_CODE(FILE_DEVICE_EPACKET, 3, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_EPACKET_READ      CTL_CODE(FILE_DEVICE_EPACKET, 4, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_EPACKET_WRITE     CTL_CODE(FILE_DEVICE_EPACKET, 5, METHOD_BUFFERED, FILE_ANY_ACCESS)

#endif


#pragma pack(1)

typedef struct _EPACKET_OID {
  ULONG Oid;
  ULONG Length;
  UCHAR Data[1];
} EPACKET_OID;

#pragma pack()


#endif // __EPACKET_H


// End of File ////////////////////////////////////////////////////////////////
