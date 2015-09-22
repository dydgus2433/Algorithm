#include <iostream>
#include <string>
#include "GraphbyLinklist.h"
using namespace std;

int main() {
	string start, finish;

	GraphbyLinklist Subway;

	cout << "출발역 : ";
	cin >> start;

	cout << "도착역 : ";
	cin >> finish;

	cout << start << "부터 " << finish << "까지의 경로는..." << endl;

	Subway.RoadCheck(start, finish);

	return 0;
}
