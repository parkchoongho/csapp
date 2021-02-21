#include<unistd.h>
#include<stdio.h>

unsigned int wakeup(unsigned int secs){
    int foo = sleep(secs);
    int wakeup_secs = secs - foo;
    printf("Woke up at %d secs\n", wakeup_secs);
    return foo;
};

int main(){
    int foo = wakeup(2);
    return foo;
}
