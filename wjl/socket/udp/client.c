#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <strings.h>
#include <string.h>
#include "wrap.h"

#define MAXLINE 80
#define SERV_PORT 8000

int main(int argc, const char *argv[])
{
    int sockfd;
    struct sockaddr_in servaddr;
    char buf[MAXLINE];
    int n;

    sockfd = my_socket(AF_INET, SOCK_DGRAM, 0);

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    inet_pton(AF_INET, "127.0.0.1", &servaddr.sin_addr);
    servaddr.sin_port = htons(SERV_PORT);

    while (fgets(buf, MAXLINE, stdin) != NULL) 
    {
        n = sendto(sockfd, buf, strlen(buf), 0, (struct sockaddr *)&servaddr, sizeof(servaddr));
        if (n == -1) 
        {
            perr_exit("sendto error");
        }

        n = recvfrom(sockfd, buf, MAXLINE, 0, NULL, 0);
        if (n == -1) 
        {
            perr_exit("recvfrom error");
        }
        my_write(STDOUT_FILENO, buf, n);
    }
    
    my_close(sockfd);
    return 0;
}
