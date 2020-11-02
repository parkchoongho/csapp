## 7.10 Dynamic Linking with Shared Libraries

지금까지 static libraries를 활용해 linking하는 과정을 살펴보았습니다. 이런 링킹 방법은 몇가지 단점을 가지고 있습니다.

1. Static 라이브러리의 경우에는 지속적으로 유지보수 및 업데이트가 이루어져야합니다. 만약 특정 static 라이브러리를 사용하는 유저가 가장 최신 버전을 사용하고 싶다면, 라이브러리가 업데이트 됐다는 사실을 알고 업데이트된 라이브러리로 다시 링킹 작업을 해주어야합니다.
2. 다른 문제점은 C Program이 여러 standard I/O function들을 사용한다는 점입니다. 런타임 상에서 이 함수들을 위한 코드들은 중복해서 text segment를 차지하게 될 것 입니다. 이는 여러 프로세스를 핸들링하는 시스템 입장에서는 자원의 낭비를 초래합니다.

Shard Libraries는 이러한 static libraries의 문제점을 해결하기 위해 나왔습니다. shard Library는 메모리 주소에 런타임 또는 로드타임에 올라갈 수 있고 프로그램과 링킹됩니다. 이러한 과정을 dynamic linking이라하고 이는 dynamic linker라는 프로그램에 의해 수행됩니다. 리눅스 시스템상 `.so` 라는 접미사가 붙습니다.

Shared Libraries는 크게 2가지 방식으로 "shared"됩니다.
1. 하나는 특정 라이브러리에 하나의 `.so` file이 있는 방식입니다.
2. 다른 하나는 shared library의 .text 부분만 공유되는 것 입니다.

Shared Library를 만드는 명령어에 대해 알아보겠습니다.
```shell
linux> gcc -shared -fpic -o libvector.so addvec.c multvec.c
```
-fpic은 컴파일러에게 position-independent code를 생성하라고 지시하는 flag입니다. -shared flag는 링커에게 shared object file을 만들라고 지시합니다.
```shell
linux> gcc -o prog21 main2.c ./libvector.so
```
dynamic liking과 static linking의 가장 큰 차이점은 dynamic linking에서는 `libvector.so` 의 code와 data가 executable object file에 들어가지 않는다는 것입니다. 대시넹 링커는 relocation과 symbol table 정보를 복사해서 `libvector.so` 안의 code와 data 관련된 referenc를 가능하게 해줍니다.

