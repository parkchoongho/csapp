# 7.1 Compiler Drivers
컴파일 시스템에서는 컴파일 드라이버를 제공합니다. 컴파일 드라이버에는 크게 4가지 preprocessor(전처리기), compiler(컴파일러), assembler(어셈블러), linker(링커)를 포함하고 있습니다.
</br>
main.c
```c
int sum(int *a, int n);
int array[2] = {1, 2};
int main(){
  int val = sum(array, 2);
  return val;
}
```
</br>
sum.c
```c
int sum(int *a, int n){
  int i, s = 0;
  for(i = 0; i < n; i++){
    s += a[i];
  }
  return s;
}
```
위 두 소스 파일을 통해 executable object file을 생성해보도록 하겠습니다.
```shell
linux> gcc -Og -o prog main.c sum.c
```
위 명령어를 사용하면 executable object file을 생성할 수 있습니다. 이 과정은 여러과정을 포함하고 있는데 자세히 알아보겠습니다.</br>
드라이버는 처음에 cpp(C preprocessor - 전처리기)를 동작시켜 main.c를 main.i로 변환시킵니다. 그 다음은 컴파일러를 동작시킵니다. 컴파일러는 main.i를 어셈블리로 구성된 main.s로 변경합니다. 그 다음은 어셈블러의 차례입니다. as(어셈블러)는 어셈블리로 구성된 main.s를  바이트 코드로 구성된 main.o로 변경시킵니다. main.o파일은 *relocatable object file*이라고도 합니다.  이번 챕터에서 중요한 용어니 기억하도록 합시다. sum.c 도 main.c와 동일한 과정을 거쳐 sum.o가 됩니다. 마지막으로 해당 object file들을 링킹해주어야합니다.
```shell
ld -o prog main.o sum.o
```
이렇게 하면 최종적으로 실행할 수 있는 프로그램인 `prog` 파일이 만들어집니다.
```shell
linux> ./prog
```
이와 같이 명령어를 치면 shell이 운영체제를 통해 *loader*를 실행시키고 loader는 prog 파일 안의 code와 data를 메모리에 복사한 후, 프로그램의 시작점에 제어권한을 넘겨줌으로써 프로그램을 실행합니다.