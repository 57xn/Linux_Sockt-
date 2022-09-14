#pragma once
#include<iostream>
#include<string>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>

class clientInfo
{
private:
     
public:
    //IPv4套接字地址结构
    struct sockaddr_in serveraddr; 
    clientInfo();
    ~clientInfo();
    int clientSocket(int family, int type, int protocol);
    int clientConnect(int sockfd, struct sockaddr *servaddr,socklen_t addrlen);
    int clientClose(int sockfd);
    void clientWrite(int sockfd,const void * buf,size_t byte);
};

// clientInfo::clientInfo(std::string ip, int port)
// {
//     this->clientService.sin_addr.s_addr = inet_addr(ip.c_str());
//     this->clientService.sin_port = htons(port);
//     this->clientService.sin_family = AF_INET;

// }

// clientInfo::~clientInfo()
// {
    
// }