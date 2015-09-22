#include "graph.h"

//인접행렬 생성자 함수
GraphArr::GraphArr(int vertex)
{
    //인접행렬 멤버 초기화
    this->_vertex = vertex;
    this->_edge = 0;
    this->_isVisit = new bool[_vertex];

    //인접행렬 동적할당 부분
    //int 포인터 배열 동적할당
    _graph = new int*[_vertex];
    for (int i = 0; i < _vertex; i++)
    {//int 배열 동적할당과 동시에 요소를 0으로 초기화
        _graph[i] = new int[_vertex] { 0, };
    }
}

//인접행렬 간선 삽입 함수
void GraphArr::InsertEdge(int src, int dest)
{
    //간선이 없을 경우
    if (_graph[src][dest] == 0)
    {
        //src->dest, dest->src 두 간선을 삽입한다
        _graph[src][dest] = 1;
        _graph[dest][src] = 1;
        ++_edge;
    }
}

//인접행렬 경로 찾기 함수
stack<int> GraphArr::FindPath(int src, int dest)
{
    stack<int> path; //경로를 저장할 스택

    //방문 여부 모두 false로 초기화
    for (int i = 0; i < _vertex; i++)
    {
        _isVisit[i] = false;
    }

    int current = src; //현재위치 = 시작위치
    path.push(current); //시작위치를 스택에 푸시
    _isVisit[current] = true; //시작위치 방문 표시

    //스택이 비어있지 않을 경우 반복
    for (int i = 0; !path.empty(); i++)
    {
        //최근 방문지가 도착지일 경우
        if (path.top() == dest)
        {
            //스택에 담긴 경로는 순서가 반대이므로 새로운 스택으로 순서를 뒤집는다
            stack<int> reverse_stack;
            for (; !path.empty(); path.pop())
            {
                reverse_stack.push(path.top());
            }

            //경로(스택) 반환
            return reverse_stack;
        }

        //마지막 지점까지 탐색하였을 경우 백트래킹
        if (i == _vertex)
        {
            path.pop();
            current = path.top();
            i = -1;
            continue;
        }
        //갈 수 있고 아직 방문하지 않았을 경우 경로에 추가
        if (_graph[current][i] == 1 && !_isVisit[i])
        {
            current = i;
            path.push(current);
            _isVisit[current] = true;
            i = -1;
        }
    }

    //경로가 없다는 의미로 -1을 담은 스택 반환
    path.push(-1);
    return path;
}

//인접리스트 생성자 함수
GraphList::GraphList(int vertex)
{
    //인접리스트 멤버 초기화
    this->_vertex = vertex;
    this->_edge = 0;
    this->_list = new Vertex*[_vertex];
    this->_isVisit = new bool[_vertex] { 0 };

    //모든 역의 출발지 노드 생성
    for (int i = 0; i < _vertex; i++)
    {
        _list[i] = new Vertex;
        _list[i]->_adjVertex = NULL;
        _list[i]->_key = i;
    }
}

//인접리스트 간선 삽입 함수(2)
bool GraphList::Insert(int src, int dest)
{
    //간선이 없을 경우에만 간선 삽입
    if (!IsMoveable(src, dest))
    {
        //역을 동적할당으로 생성하고 출발역과 연결한다
        Vertex* newVertex = new Vertex;
        newVertex->_adjVertex = _list[src]->_adjVertex;
        newVertex->_key = dest;
        _list[src]->_adjVertex = newVertex;

        return true;
    }

    //간선이 이미 존재할 경우 false 반환
    return false;
}

//인접리스트 간선 삽입 함수
void GraphList::InsertEdge(int src, int dest)
{
    bool inserted = false; //간선 삽입 성공 여부
    inserted = Insert(src, dest);
    Insert(dest, src);

    //간선 삽입을 성공했을 경우 간선 수 증가
    if (inserted)
    {
        ++_edge;
    }
}

//역 연결 여부 확인 함수
bool GraphList::IsMoveable(int src, int dest)
{
    bool found = false; //연결 여부 확인

    for (Vertex* current = _list[src]; current != NULL; current = current->_adjVertex)
    {
        //연결된 역을 모두 순회하며 연결되어 있는지 확인
        //연결되어 있을 경우 true 대입
        if (found = (current->_key == dest))
            break;
    }

    //연결되어 있으면 true, 반대의 경우 false 반환
    return found;
}

//인접리스트 경로 찾기 함수
stack<int> GraphList::FindPath(int src, int dest)
{
    //방문 여부 모두 false로 초기화
    for (int i = 0; i < _vertex; i++)
    {
        _isVisit[i] = false;
    }

    stack<int> path; //경로를 저장할 스택

    path.push(src); //시작위치를 스택에 푸시
    Vertex* pV = _list[path.top()]; //포인터로 시작위치를 가리킴
    _isVisit[path.top()] = true; //시작위치 방문 표시

    while (!path.empty()) //스택이 비어있지 않을 경우 반복
    {
        //최근 방문지가 도착지일 경우
        if (path.top() == dest)
        {
            //스택에 담긴 경로는 순서가 반대이므로 새로운 스택으로 순서를 뒤집는다
            stack<int> reverse_stack;
            for (; !path.empty(); path.pop())
            {
                reverse_stack.push(path.top());
            }

            //경로 스택 반환
            return reverse_stack;
        }

        //현재 가리키는 위치를 이미 방문했을 경우
        if (_isVisit[pV->_key])
        {
            //연결된 다음 위치를 가리킴
            pV = pV->_adjVertex;
            //더이상 연결된 곳이 없을 경우 백트래킹
            if (pV == NULL)
            {
                path.pop();
                if (path.empty())
                    break;
                pV = _list[path.top()];
            }
        }
        //현재 가리키는 위치를 아직 방문하지 않았을 경우
        else
        {
            //경로에 추가하고 방문 표시
            path.push(pV->_key);
            _isVisit[path.top()] = true;
            pV = _list[path.top()];
        }
    }

    //경로가 없다는 의미로 -1을 담은 스택 반환
    path.push(-1);
    return path;
}
