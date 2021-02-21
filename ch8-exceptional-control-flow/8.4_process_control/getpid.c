#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

pid_t getpid(void);
pid_t getppid(void);

int main(){
    int pid = getpid();
    int ppid = getppid();

    printf("pid는 %d입니다.\n", pid);
    printf("ppid는 %d입니다.", ppid);
}
