#include "Subway.h"

Subway::Subway(std::string fileName){
	//4-5: 파일의 이름을 파싱하여 입력스트림을 엶
	lineNumber = fileName.substr(fileName.find("."));
	fin.open(fileName, std::ifstream::in);
	std::cout<<fileName<<" 로드 됨."<<std::endl;
	//(그래프의 현재 역을 가리키는)커서 초기화
	cursor = 0;
	//[역, 번호]쌍 맵 생성
	stations = new std::map<std::string, int>();
	pool = new std::vector<std::string>();
	//역 이름을 받아들여 전체 역의 갯수를 반환
	size = init();
	makeGraph();
}

Subway::~Subway(){

	fin.close();
	delete stations;
	delete pool;
	for(int i=0; i<size; i++)
		delete graph[i];
	delete graph;
}

int Subway::init(){
	std::string station;
	int tag = 0;
	std::map<std::string, int>::iterator it = stations->begin();
	//exit가 입력될 때까지 역 이름을 받아들인다.
	while(getline(fin, station) && station.compare("exit") != 0)
	{
		//[역, 번호]쌍 벡터에 현재 입력된 역이 없을 경우
		//즉, 입력되었던 역이 중복 입력되는 경우를 막음
		if(stations->find(station) == stations->end())
		{
			//번호를 매기며 [역, 번호] 쌍을 삽입
			stations->insert(it, std::pair<std::string, int>(station, tag++));
			//역 이름을 저장하는 벡터의 마지막에 역 이름을 추가
			pool->push_back(station);
		}
		cursor++;
	}
	return stations->size();	//exit가 입력될 경우 역의 전체 갯수를 반환
}

void Subway::makeGraph(){	//그래프를 만드는 함수
	//51-55: 그래프 초기화
	graph = new bool*[size];
	for(int i=0; i<size; i++)
	{
		graph[i] = new bool[size]{0};
	}

	std::string path;
	std::string first, second;	//string 입력을 위한 string 변수
	int x, y;	//그래프상 위치를 나타내기 위한 변수
	int idx;	//"->"의 위치를 찾기 위한 정수형 변수
	//exit가 입력될 때까지...
	while(getline(fin, path) && path.compare("exit") != 0)
	{
		idx = path.find("->");
		first = path.substr(0, idx);
		second = path.substr(idx+2);
		//맵에 입력되는 pair쌍의 첫 번째 요소는 first
		//두번째 요소는 second로 접근 가능함에 주의!
		/*
		 * 첫번째 역의 변호를 x에 저장, 두번째 역의 변호를 y에 저장
		 */
		x = stations->find(first)->second;
		y = stations->find(second)->second;
		graph[x][y] = graph[y][x] = true;
	}
}

bool Subway::existPath(std::string first, std::string second){
	//두 역이 그래프 상에 모두 존재해야 truef를 반환, 이외 경우 false
	return stations->find(first) != stations->end() && stations->find(second) != stations->end();
}

void Subway::printPath(std::string first, std::string second){
	int x=0, y=0;
	y = stations->find(first)->second;	//탐색 시작위치 지정.
	while(true)
	{
		if(graph[y][x] == 1)	//이전역 혹은 다음 역을 찾을 경우
		{
			//만약 그 역이 출발지일 경우(즉, 원점으로 돌아왔을 경우)
			if(pool->at(y) == first)
				path.clear();	//경로 벡터를 비운다.(뺑뺑이 돌아왔기 때문에...)

			//스택에 값이 있고, 탑이 이전 역일 경우
			//=> A->B->A->B->A->B...의 반복을 막고 A->B->C로 가기 위함
			if(stk.empty() == false && stk.top() == x)
			{
				x++;
				continue;
			}
			//위에서 걸리는 게 없었다면...
			stk.push(y);	//현재 역을 스택에 추가
			path.push_back(pool->at(y));	//경로 벡터에 현재 역을 추가
			y = x;	//다음, 혹은 이전 역으로 이동
			x = 0;	//해당 역에서의 인접 역을 검색하기 위한 x 인덱스
			continue;
		}
		//도착역에 도달했을 경우
		if(pool->at(y) == stations->find(second)->first)
		{
			//경로의 갯수만큼
			for(int i=0; i < path.size(); i++)
			{
				//경로를 출력
				std::cout<<path[i]<<std::endl;
			}
			std::cout<<second<<" 도착!"<<std::endl;
			break;
		}

		//만일, 다음 역을 못 찾고 끝까지 온 경우
		if(x == size-1)
		{
			//124-131: 이전 역으로 복귀
			x = y+1;
			if(stk.empty() == false)
			{
				y = stk.top();
				stk.pop();
				continue;
			}
		}
		x++;
	}
}
