#include <iostream>
#include "Metro.h"
using namespace std;

int main(int argc, char** argv)
{
	string first, second;	//출발역과 도착역
	Metro* metro = new Metro(argc, argv);	//main함수의 파라미터를 넘긴다.

	cout<<"출발역: ";
	getline(cin, first);
	cout<<"도착역: ";
	getline(cin, second);

	for(int i=0; i<argc-1; i++){	//입력된 모든 노선에 대하여
		if(metro->findPath(i, first, second))	//두 경로가 동시에 존재할 경우
			metro->printPath(i, first, second);	//경로를 출력한다.
	}
	delete metro;
}

