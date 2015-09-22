# 알고리즘 1차 과제

**주제** : 서울시 지하철 2,3,4,5호선 노선도를 인접행렬과 인접리스트 방식으로 구현

**구연 세부사항**
- 인접행렬로 구현하고 인접리스트로도 구현할 것
- 지하철역 사이 거리에 대한 가주이는 없음 : 가중치가 없는 그래프
- 지하철력 사이에 방향은 없음 : 무방향 그래프
- 지하철 노선 환승은 구현에 반영하지 않아도 무방

**제공 기능**
- 그래프 구축 : 인접한 2개 역을 입력하면 이를 인접행렬과 인접리스트에 저장함
  * 예 : '서울역'역에 인접한 '숙대입구'역과 '회현'역을 입력하면 이러한 인접사항이
 인접행렬과 인접리스트에 저장되어야 함. '숙대입구'역에 인접한 '서울역'역과 '삼각지'역을
 입력하면 이러한 사항이 인접행렬과 인접리스트에 저장되어야 함
- 경로 출력 : 동일한 노선에 있는 출발역과 도착역을 입력하면 2개역 사이에 있는 (해당
  노선 상의) 모든 역들을 출력하여야 함
  * 예 : 출발역으로 '길음'역, 도착역으로 '서울역'역을 입력하면  <U>'길음',  '성신여대입구', '한성대입구', '혜화', '동대문', '동대문역사문화공원', '충무로', '명동', '회현', '서울역'</U>을 출력하여야 함. 단, 노선을 환승하여야 하는 경우는 구현하지 않아도 됨. 즉, 출발역을 '길음'역으로 도착역을 '을지로3가'역으로 하는 경우 '동대문역사문화공원'역에서 2호선으로 환승하여야 하는데 이번 구현에서는 이러한 환승은 구현에서 제외함
**구현 시 고민하여야 할 내용**
- 입력된 역명을 인접행렬과 인접리스트에 있는 배열의 인덱스와 어떤 방식으로 매핑 시켜야 할 것인가?
- 도착역으로 가는 과정에서 환승역을 지나갈 경우
지금까지 오고 있던 노선과 다른 노선으로 가지 않도록 하기 위해서는 어떻게 하여야 할 것인가?
- 환승을 하지 않는 상황에서 도착역까지 갈 수 있는 경로가 존재하지 않는다는 사실을 보다 일찍 알 수 잇는 방법은 없는가?
**구현 언어** : C 혹은 Cpp
**제출일자** : 9월 21일 (월요일 강의시간)
**제출내용**
- 표지
- 소스코드 : Comment 문이 적절하게 기술되어 있을 것
- 상기 "구현 시 고민하여야 할 내용"을 어떻게 해결하엿는지를 기술할 것
- 실행과정 화면
  * 인접행렬 상에서 실행되는 경우와 인접리스트에서 실행되는 경우를 보일 것
  * 각각의 경우에 대하여 10가지 정상적인 실행 예를 보일 것
  * 각각의 경우에 대하여 5가지 비정상적인 실행 예를 보일 것