#include <iostream>
using namespace std;

int main() {
	int Page;
	int Num[10] = { 0 };

	cin >> Page;	// 페이지의 끝인 'N'을 입력 받는다.

	//계산
	int Q, R;	// quotient : 몫 , remainder : 나머지
	for (int i = 1; i <= Page; i++) {
		Q = i;
		while (1) {
			// 1부터 N까지 한자리씩 추출하여 센다.
			R = Q % 10;	// 나머지부터 계산함에 주의.
			Q = Q / 10;	// Q부터 계산할 시 Q 값이 변하므로 올바른 R값을 구할 수 없게 됨.

			Num[R]++;  // 한자리의 숫자를 더하고
			if (Q == 0)  // 만약 방금이 마지막 자리였다면
				break;  // While문을 정지하고 다음 숫자 계산
		}
	}

	// 출력
	for (int i = 0; i < 10; i++) {
		cout << Num[i] << ' ';
	}
	cout << endl;

	return 0;
}
