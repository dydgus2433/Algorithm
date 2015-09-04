#include <iostream>
using namespace std;

int main() {
	int How_many, num;
	// How_many는 입력받을 num의 갯수
	//num은 피보나치 수열을 계산할 수
	int fibonacci[41][2] = { 0 };
	// 0부터 40까지 41 * 0,과 1의 호출갯수를 기억하는 공간 2개로 2차원 배열 생성
	bool Flag[41] = {false};	// 이전에 계산한 적이 있는지의 Flag 배열 생성. 이 역시 0부터 40까지 41개.
	
	// 초기값 셋팅
	fibonacci[0][0] = 1; fibonacci[1][1] = 1;
	Flag[0] = true; Flag[1] = true;
	//f(0) = (1,0), f(1) = (0,1)이며, 두 수는 이미 계산했음을 셋팅


	cin >> How_many;	// 몇개의 수를 입력할 것인지 입력받음
	for (int i = 0; i < How_many; i++) {
		cin >> num;		// 피보나치 수열을 계산할 수를 입력받음
		
		if (Flag[num] == false) {	// 이전에 계산한 적이 없는 수라면
			for (int j = 2; j <= num; j++) {	// 계산
				fibonacci[j][0] = fibonacci[j - 1][0] + fibonacci[j - 2][0];
				fibonacci[j][1] = fibonacci[j - 1][1] + fibonacci[j - 2][1];
				Flag[j] = true;	// 계산이 끝난 피보나치(j) 대해서는 Flag값을 true로 바꿔줌
			}
		}

		cout << fibonacci[num][0] << ' ' << fibonacci[num][1] << endl;	// 계산된 값 출력
	}

	return 0;
}
