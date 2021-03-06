$NetBSD: patch-unix-socket.cxx,v 1.3 2017/09/16 15:13:10 tnn Exp $

- Add DragonFly support
- NetBSD no longer has RTF_LLINFO, RTF_CLONED, etc since net/route.h r1.98.

--- src/ptlib/unix/socket.cxx.orig	2012-08-23 02:12:27.000000000 +0000
+++ src/ptlib/unix/socket.cxx
@@ -54,7 +54,7 @@
 #define  ifr_macaddr         ifr_hwaddr.sa_data
 #endif
 
-#if defined(P_FREEBSD) || defined(P_OPENBSD) || defined(P_NETBSD) || defined(P_SOLARIS) || defined(P_MACOSX) || defined(P_MACOS) || defined(P_IRIX) || defined(P_VXWORKS) || defined(P_RTEMS) || defined(P_QNX)
+#if defined(P_FREEBSD) || defined(P_OPENBSD) || defined(P_NETBSD) || defined(P_SOLARIS) || defined(P_MACOSX) || defined(P_MACOS) || defined(P_IRIX) || defined(P_VXWORKS) || defined(P_RTEMS) || defined(P_QNX) || defined(P_DRAGONFLY)
 #define ifr_netmask ifr_addr
 
 #include <net/if_dl.h>
@@ -78,7 +78,7 @@
 
 #endif
 
-#if defined(P_FREEBSD) || defined(P_OPENBSD) || defined(P_NETBSD) || defined(P_MACOSX) || defined(P_MACOS) || defined(P_QNX)
+#if defined(P_FREEBSD) || defined(P_OPENBSD) || defined(P_NETBSD) || defined(P_MACOSX) || defined(P_MACOS) || defined(P_QNX) || defined(P_DRAGONFLY)
 #include <sys/sysctl.h>
 #endif
 
@@ -92,7 +92,7 @@
 #include <be/bone/sys/sockio.h> // for SIOCGI*
 #endif
 
-#if defined(P_FREEBSD) || defined(P_OPENBSD) || defined(P_NETBSD) || defined(P_MACOSX) || defined(P_VXWORKS) || defined(P_RTEMS) || defined(P_QNX)
+#if defined(P_FREEBSD) || defined(P_OPENBSD) || defined(P_NETBSD) || defined(P_MACOSX) || defined(P_VXWORKS) || defined(P_RTEMS) || defined(P_QNX) || defined(P_DRAGONFLY)
 // Define _SIZEOF_IFREQ for platforms (eg OpenBSD) which do not have it.
 #ifndef _SIZEOF_ADDR_IFREQ
 #define _SIZEOF_ADDR_IFREQ(ifr) \
@@ -526,7 +526,7 @@ PBoolean PIPSocket::IsLocalHost(const PS
         }
       }
       
-#if defined(P_FREEBSD) || defined(P_OPENBSD) || defined(P_MACOSX) || defined(P_VXWORKS) || defined(P_RTEMS) || defined(P_QNX)
+#if defined(P_FREEBSD) || defined(P_OPENBSD) || defined(P_MACOSX) || defined(P_VXWORKS) || defined(P_RTEMS) || defined(P_QNX) || defined(P_DRAGONFLY)
       // move the ifName pointer along to the next ifreq entry
       ifName = (struct ifreq *)((char *)ifName + _SIZEOF_ADDR_IFREQ(*ifName));
 #elif !defined(P_NETBSD)
@@ -1100,7 +1100,7 @@ PBoolean PIPSocket::GetRouteTable(RouteT
   return !table.IsEmpty();
 }
 
-#elif (defined(P_FREEBSD) || defined(P_OPENBSD) || defined(P_NETBSD) || defined(P_MACOSX) || defined(P_QNX)) && !defined(P_IPHONEOS)
+#elif (defined(P_FREEBSD) || defined(P_OPENBSD) || defined(P_NETBSD) || defined(P_MACOSX) || defined(P_QNX)) && !defined(P_IPHONEOS) || defined(P_DRAGONFLY)
 
 PBoolean process_rtentry(struct rt_msghdr *rtm, char *ptr, unsigned long *p_net_addr,
                      unsigned long *p_net_mask, unsigned long *p_dest_addr, int *p_metric);
@@ -1194,10 +1194,15 @@ PBoolean process_rtentry(struct rt_msghd
     return PFalse;
   }
 
-  if ((~rtm->rtm_flags&RTF_LLINFO)
-#if defined(P_NETBSD) || defined(P_QNX)
+  if (
+#if defined(RTF_LLINFO)
+           (~rtm->rtm_flags&RTF_LLINFO)
+#else
+	1
+#endif
+#if defined(RTF_CLONED)
         && (~rtm->rtm_flags&RTF_CLONED)     // Net BSD has flag one way
-#elif !defined(P_OPENBSD) && !defined(P_FREEBSD)
+#elif defined(RTF_WASCLONED)
         && (~rtm->rtm_flags&RTF_WASCLONED)  // MAC has it another
 #else
                                             // Open/Free BSD does not have it at all!
@@ -1966,7 +1971,7 @@ PBoolean PIPSocket::GetInterfaceTable(In
         }
       }
 
-#if defined(P_FREEBSD) || defined(P_OPENBSD) || defined(P_MACOSX) || defined(P_VXWORKS) || defined(P_RTEMS) || defined(P_QNX)
+#if defined(P_FREEBSD) || defined(P_OPENBSD) || defined(P_MACOSX) || defined(P_VXWORKS) || defined(P_RTEMS) || defined(P_QNX) || defined(P_DRAGONFLY)
       // move the ifName pointer along to the next ifreq entry
       ifName = (struct ifreq *)((char *)ifName + _SIZEOF_ADDR_IFREQ(*ifName));
 #elif !defined(P_NETBSD)
