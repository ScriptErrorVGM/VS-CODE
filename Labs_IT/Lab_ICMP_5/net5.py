import socket
import sys
import struct
import time


def trace(dst):
    hops = 30
    ttl = 1
    port = 33434

    dst_ip = socket.gethostbyname(dst)

    print('traceroute {} ({})'.format(dst, dst_ip))

    while True:
        startTimer = time.time()

        recv_s = socket.socket(socket.AF_INET, socket.SOCK_RAW, socket.IPPROTO_ICMP)
        timeout = struct.pack("ll", 5, 0)
        recv_s.setsockopt(socket.SOL_SOCKET, socket.SO_RCVTIMEO, timeout)
        recv_s.bind(('', port))

        send_s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM, socket.IPPROTO_UDP)
        send_s.setsockopt(socket.SOL_IP, socket.IP_TTL, ttl)

        send_s.sendto(b'', (dst, port))

        addr = None
        try:
            data, addr = recv_s.recvfrom(1024)
            endTimer = time.time()
        except socket.error:
            pass
        finally:
            recv_s.close()
            send_s.close()
        
        if addr:
            timeSpent = round((endTimer - startTimer) * 1000, 2)
            print('{:<4} {} {} ms'.format(ttl, addr[0], timeSpent))
            if addr[0] == dst_ip:
                break
        else:
            print('{:<4} *'.format(ttl))
        
        ttl += 1

        if ttl > hops:
            break
        
if len(sys.argv) < 2:
    print('No domain name provided!')
else:
    dest = sys.argv[1]
    trace(dest)