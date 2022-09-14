#include "clientInfo.h"

int clientInfo::clientSocket(int family, int type, int protocol){
    return socket(family, type, protocol);
}
int clientInfo::clientConnect(int sockfd, struct sockaddr *servaddr,socklen_t addrlen){
    return connect(sockfd, servaddr, addrlen);
}

int clientInfo::clientClose(int sockfd){
    return close(sockfd);
}
void clientInfo::clientWrite(int sockfd,const void * buf,size_t byte){
    write(sockfd,buf,byte);
}
clientInfo::clientInfo()
{
}

clientInfo::~clientInfo()
{
    
}
