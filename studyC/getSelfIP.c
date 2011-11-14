#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <linux/types.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <net/if.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/ioctl.h>

int getlocalip(char* outip)
{
    int i=0;
    int sockfd;
    struct ifconf ifconf;
    char buf[512];
    struct ifreq *ifreq;
    char* ip;

    ifconf.ifc_len = 512;
    ifconf.ifc_buf = buf;

    if((sockfd = socket(AF_INET, SOCK_DGRAM, 0))<0)
    {
        return -1;
    }
    ioctl(sockfd, SIOCGIFCONF, &ifconf);
    close(sockfd);
    ifreq = (struct ifreq*)buf;
    for(i = (ifconf.ifc_len / sizeof(struct ifreq)); i > 0; i--)
    {
        ip = inet_ntoa(((struct sockaddr_in*) & (ifreq->ifr_addr))->sin_addr);

        if (strcmp(ip, "127.0.0.1") == 0)
        {
            ifreq++;
            continue;
        }
        strcpy(outip, ip);
        return 0;
    }

    return -1;
}

int main(void)
{
    char ip[20];

    if ( getlocalip( ip ) == 0)
    {
        printf("The myself IP addr is: %s\n", ip);
    }
    else
    {
        printf("Can't get myself IP!\n");
    }

    return 0;
}

