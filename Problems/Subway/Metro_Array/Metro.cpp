#include "Metro.h"
Metro::Metro(int argc, char** argv){
	lines = argc-1;	//노선의 갯수
	subway = new Subway*[argc-1];	//포인터의 배열 생성
	for(int i=0; i<argc-1; i++)
	{
		subway[i] = new Subway(*(argv+1+i));	//각 배열마다 객체를 생성
	}
}

Metro::~Metro()
{
	for(int i=0; i<lines; i++)	//모든 객체 할당 해제
		delete subway[i];	
	delete subway;	//포인터 배열도 해제
}

//findPath는 사실 Subway객체의 existPath함수에 대한 인터페이스
bool Metro::findPath(int line, std::string first, std::string second){
	return subway[line]->existPath(first, second);
}

//printPath 역시 Subwayr개체의 printPath함수에 대한 인터페이스
void Metro::printPath(int line, std::string first, std::string second){
	subway[line]->printPath(first, second);
}

