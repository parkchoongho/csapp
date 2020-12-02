#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void cleanup(void){
    printf("cleaning up\n");
}

int main(){
  atexit(cleanup);
  fork();
  exit(0);
}
