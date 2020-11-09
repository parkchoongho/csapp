# Ch8 Exceptional Control Flow

### Process의 정의는 무엇인가?

- An instance of a program in execution

### Process가 제공하는 2가지 핵심 추상화는?

- 프로그램이 Processor를 exclusive하게 사용하는 것 같은 추상화
- 프로그램이 Memory를 exclusive하게 사용하는 것 같은 추상화

### PCB는 무엇의 약자?

- Process Control Block

### Concurrent vs Parallel

### Context Switch 발생 시 일어나는 흐름 그리기

### Process Fork 코드 짜서 돌려보기

### fork는 한번불리고 두번 리턴하는 함수인데 그 의미는?

### Zombie를 부모가 reap(수확)하지 않으면 어떻게 되는지 실제 예시 만들어보기

- 무한루프로 1초 간격으로 print("Hello World!")코드 만들고 돌림
- 돌리는 쉘(부모)를 죽여버리면? => 자식도 죽나?
- print("Hello World!")하는 프로세스가 어디에 붙는지 확인하기

### Wait을 shell에서도 쓸수 있는 것 확인하기

- Shell 프로그램에서 wait을 써서 동시에 프로그램 4개 돌리기

### Thread의 정의

### Thread와 Process가 Share하는게 무엇이고 Separate하는게 무엇인가

### Micorowebframework를 thread를 사용해 동시에 N명 접속을 처리할 수 있게 바꾸자

### 리눅스에서 Task란?

### htop에서 RES와 VIRTfks?
