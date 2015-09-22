#ifndef GraphArray_H
#define GraphArray_H

#include <string>
using namespace std;

class Node {
public:
	bool connect;	// Node[i][j]->connect = true면, 역 i와 역 j가 연결되어있단 의미.
};

class GraphbyArray {
private:
	int V;	// 정점
	int E;	// 간선
	string *Name;	// 이름
	bool **Line;	// 노드(역)이 소속한 n호선, 탐색 시에 확인음을 체크하는 변수.
	Node **Q;	// 배열을 가리키는 포인터
public:
	GraphbyArray();	// 초기화. 메모리 할당
	~GraphbyArray();// 소멸자. 메모리 반납
	void InputEdge(string N1, string N2);	// 이름을 통해 간선 추가
	void InputEdge(int V1, int V2);	// 간선 추가
	int FindID(string N);	// 이름을 통해 ID 값 반환
	void RoadCheck(string N1, string N2);	// 경로가 존재하는지 확인 (예외 처리)
	void MetroSetup();	// 지하철 노선도 세팅
	void FindRoad(int V1, int V2, int Num);	// 경로 탐색 및 출력 함수
};

#endif
