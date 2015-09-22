#ifndef GraphLinklist_H
#define GraphLinklist_H

#include <string>
using namespace std;

class Node {
public:
	int Data;	// 노드의 ID 값(역번호)
	Node* Next;	// 다음 노드를 가리키는 포인터
};

class GraphbyLinklist {
private:
	int V;		// 그래프의 정점 갯수
	int E;		// 그래프의 간선 갯수
	Node **Q;	// 경로들을 가리킬 2차원 배열을 가리키는 포인터
	bool **Line;	// 노드(역)이 소속한 n호선, 탐색 시에 확인음을 체크하는 변수.
	string *Name;	// 정점들의 이름(역명)을 담을 배열을 가리키는 포인터
public:
	GraphbyLinklist();	// 초기화. 메모리 할당
	~GraphbyLinklist();// 소멸자. 메모리 반납
	void InputEdge(string N1, string N2);	// 이름을 통해 간선 추가
	void InputEdge(int V1, int V2);	// 간선 추가
	int FindID(string N);	// 이름을 통해 ID 값 반환
	void RoadCheck(string N1, string N2);	// 경로가 존재하는지 확인 (예외 처리)
	void MetroSetup();	// 지하철 노선도 세팅
	void FindRoad(int V1, int V2, int Num);	// 경로 탐색 및 출력 함수
};

#endif
