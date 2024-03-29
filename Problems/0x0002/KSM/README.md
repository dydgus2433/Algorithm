유기농 배추 문제 풀이
===================

배추 밭이  10x6의 크기이며, 배추가 14개 있다고 가정한다.
> 1|1|0|0|0|0|0|0|0|0
> :-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:
> 0|1|0|0|0|0|0|0|0|0
> 0|0|0|0|1|0|0|0|0|0
> 0|0|0|0|1|0|0|0|0|0
> 0|0|1|1|0|0|0|1|1|1
> 0|0|0|0|1|0|0|1|1|1

각 배추가 인접한 영역을 하나의 영역, 즉 Area라고 하자
위 그림에서 (0, 0), (1,0), (1,1)가 군집한 Area에 벌레 한 마리를,  
(4, 2), (4, 3)가 군집한 Area에 벌레 한 마리를,  
(2, 4), (3, 4)가 군집한 Area에 벌레 한 마리를,  
(4, 5)가 홀로 있는 Area에 벌레 한 마리,  
그리고 (7, 4), (7, 5), (8, 4), (8, 5), (9, 7), (9, 5)가 군집한 영역에 벌레 한 마리를 놓을 수 있다.

이 풀이의 방식은 간단하다.

가장 먼저 (0, 0) 위치부터 가로로 이동하며 (9, 5)위치까지 도달할 때까지 배추의 존재 여부를 확인한다.

단, (0, 0)에 배추가 있다고 가정할 때 (0, 1)을 검사하기까지 **많은 작업**이 일어난다.

> 먼저 (0, 0)위치에 벌레를 놓고나면, 벌레는 그 자리의 값 1을 0으로 바꾼다.  >
> 그리고 사방으로 이동하는데, (-1, 0), (0, -1)은 이동이 아예 불가능하고, (0, 1)은 배추가 없다. 그러므로 이동 가능한 영역임과 동시에 배추가 존재하는 (1, 0)에 또 벌레를 생성한다.(벌레를 생성한 후, 벌레는 소멸된다...ㅠ)  

>(1, 0)에 놓인 벌레는 (1, 0)위치의 값 1을 0으로 바꾸고 사방으로 움직일 텐데 (0, -1)은 이동이 아예 되는 위치가 아니고, (0, 0)은 이미 왔던 곳이기 때문에 값이 0이다.(배추가 없다고 가정하는 것이다.)  
>그리고 (2, 1)은 배추가 없고, 유일하게 (1, 1)위치에 배추가 있다.  
>벌레는 (1, 1)위치에 벌레를 생성하고 또 소멸한다.)
>위 과정을 반복하여 (1, 1)위치의 벌레는 더이상 이동할 곳이 없다.  

>다시 메인 함수의 루프로 돌아와서 (0, 0)위치에 벌레를 놓는 과정은 끝이나고 필요한 벌레의 수를 1 증가시킨다.

>그 다음으로 검사기는 (1, 0)위치를 검사할 텐데, 이미(0, 0)위치에 벌레를 놨을 때 벌레가 (1, 0), (1, 1)위치의 배추에 도달했기 때문에 (1, 0) 위치의 배추는 검사 대상이 아니다. (1, 1)위치 역시 무시되고, 위와 같은 과정이 한 Area마다 수행된다.

끝으로 (9, 5)위치에 도달하여 모든 배추에 대한 검사가 끝이난 후 필요한 벌레의 수가 출력된다.
