#include <iostream>
#include <string>
#include "GraphbyArray.h"
using namespace std;

int main() {
	string start, finish;	// 출발역과 도착역의 이름을 저장하는 문자열
	GraphbyArray Subway;	// 그래프 생성

	// 출발역과 도착역의 이름을 입력받음
	cout << "출발역 : ";	cin >> start;
	cout << "도착역 : ";	cin >> finish;
	
	cout << start << "부터 " << finish << "까지의 경로는..." << endl;
	Subway.RoadCheck(start, finish);	// 경로 탐색

	return 0;
}
