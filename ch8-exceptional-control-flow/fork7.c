#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
  if(fork() == 0){
      printf("Terminated Child, PID = %d\n", getpid());
  }else{
      printf("Running Parent, PID = %d\n", getpid());
      while (1)
      {
          /* code */
      }
  }
}