#ifndef __SUBWAY__
#define __SUBWAY__

#include<map>
#include<vector>
#include<stack>
#include<string>
#include<iostream>
#include<fstream>

class Subway{
	private:
		int cursor;	// 현재 탐색 중인 역을 가리킴
		std::lineNumber;	//노선의 번호
		std::ifstream fin;	//파일을 입력받기 위한 입력 스트림
		std::map<std::string, int>* stations;	//[역,번호]쌍을 저장할 맵
		std::vector<std::string>* pool;	//번호를 이용해 역명을 참조할 벡터
		std::vector<std::string> path;	//경로를 저장 하기 위한 벡터
		std::stack<int> stk;	//깊이우선탐색에 사용할 스택
		bool** graph;	//그래프를 가리키는 포인터
		int size;	//역의 전체 갯수
	public:
		Subway(std::string fileName);	//filename을 넘겨 입력스트림을 엶
		~Subway();	//모든 할당 해제를 담당하는 소멸자
		int init();	//노선에 대한 정보를 초기화
		void makeGraph();	//그래프(인접행렬)를 만드는 함수
		//두 역이 존재하는지 검사하는 함수
		bool existPath(std::string first, std::string second);
		//두 역 사이의 경로를 출력하는 함수
		void printPath(std::string first, std::string second);
};

#endif
