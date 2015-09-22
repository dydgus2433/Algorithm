#ifndef GRAPH_H
#define GRAPH_H

#include <stack> //STL 스택 자료구조 사용

using namespace std;

class GraphArr //인접행렬 클래스
{
private:
    int _vertex; //역 개수
    int _edge; //간선 수
    int** _graph; //인접행렬
    bool* _isVisit; //방문 여부 행렬
public:
    GraphArr(int vertex); //인접행렬 생성자 함수
    void InsertEdge(int src, int dest); //역간 간선 삽입 함수
    stack<int> FindPath(int src, int dest); //경로 찾기 함수
};

struct Vertex //리스트에 사용할 역 구조체
{
    int _key; //역 번호
    Vertex* _adjVertex; //인접 역
};

class GraphList //인접리스트 클래스
{
private:
    int _vertex; //역 개수
    int _edge; //간선 수
    Vertex** _list; //인접리스트
    bool* _isVisit; //방문 여부 행렬
    bool Insert(int src, int dest); //역간 간선 삽입 함수(2)
public:
    GraphList(int vertex); //인접리스트 생성자 함수
    void InsertEdge(int src, int dest); //역간 간선 삽입 함수
    bool IsMoveable(int src, int dest); //역 연결 여부 확인 함수
    stack<int> FindPath(int src, int dest); //경로 찾기 함수
};

#endif
