#include "csapp.h"

int main(){
    int a = 9;
    if(fork() == 0){
        printf("p1: a=%d\n", a--);
    }
    printf("p2: a=%d\n", a++);
    exit(0);
}
