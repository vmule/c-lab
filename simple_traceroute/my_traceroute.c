#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<string.h>
#include<netinet/ip.h>
#include<netinet/ip_icmp.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<unistd.h>
#include<pthread.h>
#include<poll.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<signal.h>
#include<sys/sem.h>
#include<poll.h>
#include<pthread.h>
#include<sys/select.h>
#include<sys/un.h>
#include<netinet/ip_icmp.h>

unsigned short csum (unsigned short *buf, int nwords) {
  unsigned long sum;
  for (sum = 0; nwords > 0; nwords--)
    sum += *buf++;
  sum = (sum >> 16) + (sum & 0xffff);
  sum += (sum >> 16);
  return ~sum;
}

char buf[4096] = {0};
struct ip *ip_hdr = (struct ip *) buf;

int main (int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s destination\n", argv[0]);
    exit(0);
  }

  int sock = socket(AF_INET,SOCK_RAW,IPPROTO_ICMP);
  if (sock == -1) {
    perror("\nerror opening socket");
    return 1;
    }
  printf("socked fd is: %i.\n", sock);

  struct sockaddr_in sender_address;

  sender_address.sin_family = AF_INET;
  sender_address.sin_port =  htons(7);
  inet_pton(AF_INET, argv[1], &sender_address.sin_addr);

  printf("Destination IP: %s.\n", argv[1]);

  int ttl = 1;
  int one = 1;
  if (setsockopt (sock, IPPROTO_IP, IP_HDRINCL, &one, sizeof(one)) < 0) {
    printf ("Cannot set HDRINCL!\n");
  }

while(1) {

ip_hdr->ip_hl = 5;
ip_hdr->ip_v = 4;
ip_hdr->ip_tos = 0;
ip_hdr->ip_len = 20 + 8;
ip_hdr->ip_id = 10000;
ip_hdr->ip_off = 0;
ip_hdr->ip_ttl = ttl;
ip_hdr->ip_p = IPPROTO_ICMP;
inet_pton (AF_INET, "192.168.1.19", &(ip_hdr->ip_src));
inet_pton (AF_INET, argv[1], &(ip_hdr->ip_dst));

struct icmphdr *icmphd = (struct icmphdr *) (buf + 20);
icmphd->type = ICMP_ECHO;
icmphd->code = 0;
icmphd->checksum = 0;
icmphd->un.echo.id = 0;
icmphd->un.echo.sequence = ttl + 1;
icmphd->checksum = csum ((unsigned short *) (buf + 20), 4);

ssize_t aloha = sendto(sock, buf,  sizeof(struct ip) + sizeof(struct icmphdr),
                       0, (struct sockaddr*)&sender_address,
                       sizeof(sender_address));
if (aloha == -1) {
  perror("error no aloha\n");
  return 1;
}

struct sockaddr_in receiver_address;
socklen_t len = sizeof(receiver_address);

char buf2[4096] = {0};
ssize_t aloha_to_you = recvfrom(sock, buf2, sizeof(buf2), 0, (struct sockaddr*)&receiver_address, &len);
if (aloha_to_you == -1) {
  perror("error no aloha\n");
  return 1;
}


struct icmphdr *icmphd2 = (struct icmphdr *) (buf2 + 20);
if (icmphd2->type != 0) {
  printf ("hop limit:%d Address:%s\n", ttl, inet_ntoa(receiver_address.sin_addr));
  printf ("ICMP type: %d.\n", icmphd2->type);
  printf ("ICMP code: %d.\n", icmphd2->code);
  memset(&receiver_address, 0, sizeof(receiver_address));
}

else {
  printf ("Reached destination:%s with hop limit:%d\n",
          inet_ntoa (receiver_address.sin_addr), ttl);
  printf ("ICMP type: %d.\n", icmphd2->type);
  printf ("ICMP code: %d.\n", icmphd2->code);
  exit (0);
}

ttl++;
}
return 0;
}
