#pragma once
#include<iostream>
#include<string>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>

class servInfo
{
private:

public:
    //IPv4套接字地址结构
        struct sockaddr_in clientaddr;
        servInfo();
        ~servInfo();
        int servSocket(int family, int type, int protocol);
      // int servConnect(int sockfd, const struct sockaddr *servaddr,socklen_t addrlen);
      // int servClose(int sockfd);
        int servBind(int sockfd, struct sockaddr *myaddr,socklen_t addrlen);
        int servListen(int sockfd, int backlog);
        int servAccept(int sockfd, struct sockaddr *cliaddr, socklen_t *addrlen);
        int servRecv(int sockfd, void *buf, size_t len , int flags);
        int servSend(int accept, const void *buf, size_t len, int flags);

};
      