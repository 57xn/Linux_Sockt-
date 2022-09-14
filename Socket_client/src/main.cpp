#include<iostream>
#include<string>
#include"clientInfo.h"
#include"errno.h"
#define DEFAULT_PORT 8000
int main()
{
    clientInfo *client = new clientInfo;
    struct sockaddr_in addr = client->serveraddr;
    // memset(&addr, 0, sizeof(addr));
    std::string ip;
    std::cout<<"请输入ip地址：";
    std::cin>>ip;
    addr.sin_addr.s_addr = inet_addr(ip.c_str());
    addr.sin_family = AF_INET;
    addr.sin_port = htons(DEFAULT_PORT);
    int sockfd=client->clientSocket(AF_INET,SOCK_STREAM,0);
    if(sockfd != -1){
        std::cout<<"创建套接字成功："<<std::endl;
    }else{
        std::cout<<"失败！"<<std::endl;
    }
  while(1){
    int res=client->clientConnect(sockfd,(struct sockaddr*)&addr,sizeof(addr));
        if(res == -1){
        std::cout<<"创建连接失败："<<std::endl;
         std::cout<<errno<<std::endl;
        return 0;
    }else{
        std::cout<<"成功!"<<std::endl;
        break;
    }
  }

    char buf[1024];
    while(std::cin>>buf){
        if(!strcmp(buf, "exit")){
            break;
        }
        client->clientWrite(sockfd,buf,strlen(buf));
    }

    int Switch=client->clientClose(sockfd);
    if(Switch == 0){
        std::cout<<"关闭套接字成功："<<std::endl;
    }else{
        std::cout<<"失败！"<<std::endl;
    }
    return 0;
}