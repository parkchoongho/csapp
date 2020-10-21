#include <stdio.h>
void f(void);

int x = 0x01234567;
int y = 0x89ABCDEF;

int main(){
  f();
  printf("%x %x\n", x, y);
  return 0;
}
