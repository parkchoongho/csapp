#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main(){
  printf("L0\n");
  fork();
  printf("L1\n");
  fork();
  printf("Bye\n");
}
