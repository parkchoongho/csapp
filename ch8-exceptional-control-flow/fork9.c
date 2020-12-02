#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
  int child_status;

  if(fork() == 0){
      printf("HC: hello from child\n");
  }else{
      printf("HP: hello from parent\n");
      wait(&child_status);
      printf("CT: child has terminated\n");
  }
  printf("Bye\n");
  exit(0);
}