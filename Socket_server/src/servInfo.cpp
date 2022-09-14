#include"servInfo.h"

int servInfo::servSocket(int family, int type, int protocol){
    return socket(family, type, protocol);
}
int servInfo::servBind(int sockfd, struct sockaddr *myaddr,socklen_t addrlen){
        return bind(sockfd,myaddr,addrlen);
}
int servInfo::servListen(int sockfd, int backlog){
     return listen(sockfd, backlog);
}
int servInfo::servAccept(int sockfd, struct sockaddr *cliaddr, socklen_t *addrlen){
     return accept(sockfd, cliaddr, addrlen);
}

int servInfo::servRecv(int sockfd, void *buf, size_t len , int flags)
{
    return recv(sockfd, buf, len, flags);
}
int servInfo::servSend(int accept, const void *buf, size_t len, int flags){
    return send(accept,buf,len,flags);
}
servInfo::servInfo()
{
}

servInfo::~servInfo()
{

}
