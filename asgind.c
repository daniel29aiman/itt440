#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<errno.h>
#include<string.h>
#include<signal.h>

void cTask(){
     printf("Hiiiiiii, i am the child as you can seee \n");
     }

void pTask(){
      printf("As you know i am the father \n");
      }


int main(void){

    int child;

    char k[50];

    printf("How much present did you want?\n");
    scanf("%s",k);

    int pipefds[2];
    int buffer;
    void int_handler(int sig);
    void tstp_handler(int sig);
    void quit_handler(int sig);

    if(signal(SIGINT ,int_handler) == SIG_ERR){
        perror("signal SIGINT");
     }

    else if(signal(SIGTSTP, tstp_handler) == SIG_ERR){
         perror("signal SIGTSTP");
     }

    else if(signal(SIGQUIT, quit_handler) == SIG_ERR){
         perror("signal SIGQUIT");
         exit(1);

     }


    if(pipe(pipefds) == -1){
      perror("pipe");
      exit(EXIT_FAILURE);
      }

    pipe(pipefds);

    pid_t  parentId = fork();


      if(parentId == 0){
         pTask();
         printf("Giving the present to child ....\n");
         close(pipefds[0]);
         write(pipefds[1], k, sizeof(k));

         printf("Successful.\n\n");
         exit(EXIT_SUCCESS);
        }

       else if(parentId > 0){
         wait(NULL);
         cTask();
         printf("Present being received by child.....\n");
         close(pipefds[1]);
         read(pipefds[0], k, sizeof(k));
         close(pipefds[0]);

         printf("Successful.\n\n");
        }

       else {
         printf("  ERROR : Unable to create the child process. ");
       }

       printf("How many child that should received present? :");
       scanf("%d", &child);

       if(child < 1){
           perror("Looping input error detected ");
       }

       else{
           printf("You entered %d\n\n", child);
      }

       for(int i=0 ; i <("%d", child ) ; i++) ;{
           pid_t parentId = fork();


           if(parentId == 0){
                   printf("This child receive %s present from parent\n",k);
                   exit(0);
             }


            else{
               printf("Waiting for the received to finish.....\n");
               wait(NULL);
               close(pipefds[1]);
               close(pipefds[0]);
               printf(" Present received process for all child has finished.\n\n");

               }


        
       }

}

void int_handler(int sig){

     printf("Ctrl+ C Captured \n");
}

void tstp_handler(int sig){
      printf("Ctrl+ Z Captured \n");
}

void quit_handler(int sig){
      printf("Ctrl+ Backspace Captured \n");
}
