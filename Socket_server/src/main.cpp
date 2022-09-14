#include<iostream>
#include<string>
#include<string.h>
#include"servInfo.h"
#define DEFAULT_PORT 8000
int main()
{
    servInfo *server = new servInfo;
    struct sockaddr_in addr = server->clientaddr;
    memset(&addr,0 ,sizeof(addr));
    socklen_t len = sizeof(addr);
    int myAccept;
    char buf[1024];

     //创建套接字
    int sockfd = server->servSocket(AF_INET, SOCK_STREAM, 0);
    //配置服务端信息
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    addr.sin_port = htons(DEFAULT_PORT);
    addr.sin_family = AF_INET;
    
    if(server->servBind(sockfd, (struct sockaddr *)&addr,sizeof(addr)) == 0){
        std::cout<<"套接字绑定成功！"<<std::endl;
    }else{
       std::cout<<"套接字绑定失败！"<<std::endl; 
    }
    //设置套接字为监听状态
    if (server->servListen(sockfd, 5) < 0){
        std::cout<<"设置监听失败！"<<std::endl;
    }else{
        std::cout<<"设置监听成功！"<<std::endl;
    }
    std::cout<<"waiting for client's request-------"<<std::endl;
    //接受连接请求
    while (1)
    {
        int myAccept = server->servAccept(sockfd, (struct sockaddr *)NULL, NULL);
        if(myAccept == -1){
        std::cout<<"连接失败！"<<std::endl;
        return 0;
        }
        std::cout<<"连接建立，准备接受数据"<<std::endl;
       //接收数据
        int myRecv = server->servRecv(myAccept, buf, strlen(buf),0);
        if (myRecv < 0)
        {
            std::cout<<"接受失败!"<<std::endl;
            continue;
        }else{
            std::cout<<"客户信息"<<buf<<std::endl;
        }
        int mySend = server->servSend(myAccept, buf,strlen(buf),0);
        if(mySend == -1){
            std::cout<<"发送失败!"<<std::endl;
        }
        if(mySend == strlen(buf)){
            std::cout<<"发送成功!"<<std::endl;
        }
    }
    close(sockfd);
    return 0;
}
