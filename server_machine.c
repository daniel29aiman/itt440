#include<stdio.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<unistd.h>

int main(int argc, char*argv[])
{
    int socket_dscr, new_socket,s;
    struct sockaddr_in server, client;
    int random_number;srand(time(0));


    socket_dscr=socket(AF_INET, SOCK_STREAM,0);
    if(socket_dscr==-1){

    printf(" COULD NOT CREATE SOCKET ");
    }


    server.sin_family=AF_INET;
    server.sin_addr.s_addr=INADDR_ANY;
    server.sin_port=htons(4203);


    bind(socket_dscr,(struct sockaddr*)&server,sizeof(server));

    listen(socket_dscr,3);

    puts(" WAITING FOR INCOMING CONNECTIONS ....... ");
    s=sizeof(struct sockaddr_in);
    new_socket=accept(socket_dscr, (struct sockaddr*)&client, (socklen_t*)&s);
    if(new_socket<0){

    perror("accept failed");

    }

    puts("Connection accepted");


    random_number=(rand()%(999-100+1)+100);

    write(new_socket,&random_number,sizeof(random_number));

    close(new_socket);
    close(socket_dscr);
    return 0;
    }



