#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<sys/socket.h>

int main(int argc,char*argv[])
{
   int soc;
   struct sockaddr_in server;
   int ran_num;

   soc=socket(AF_INET,SOCK_STREAM,0);

   if(soc==-1)
   {
     printf(" COULD NOT CREATE SOCKET");
     return 1;
   }
 puts(" SOCKET CREATED ");

    server.sin_addr.s_addr=inet_addr("192.168.126.128");
    server.sin_family=AF_INET;
    server.sin_port=htons(4203);

    if(connect(soc,(struct sockaddr*)&server,sizeof(server))<0)
    {
       perror(" connect failed, ERROR ");
       return 1;
    }

     puts(" CONNECTED\n");

     if(recv(soc,&ran_num,sizeof(ran_num),0)<0)
     {

         puts(" RECV FAILED ");
         return 0;
     }
 printf("RANDOM NUMBER FROM SERVER: %d\n",ran_num);

     close(soc);
     return 0;
    }
