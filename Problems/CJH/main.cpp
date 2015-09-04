#include <iostream>
using namespace std;

struct ZeroOne 
{
	int zeroCount;
	int oneCount;
};

//numbers: 구할 피보나치 수열의 인덱스들 저장할 동적배열의 포인터
//containFibonacci: 피보나치 수열의 0, 1 개수를 저장할 동적배열의 포인터
int* numbers = nullptr; 
ZeroOne* containFibonacci = nullptr;

int main(void)
{
	//cin, cout 객체의 입출력 속도를 향상시키기 위해 호출
	ios_base::sync_with_stdio(false);

	//최대값 저장 변수
	int max = 0;
	int testCount;
	
	cin >> testCount;
	//입력받을 숫자의 수만큼 배열 동적할당
	numbers = new int[testCount]; 
	
	//testCount만큼 반복(테스트 케이스)
	for (int i = 0; i < testCount; i++)
	{
		cin >> numbers[i];
		//구해야할 피보나치 수열의 최대값을 구함.
		if (numbers[i] > max)
			max = numbers[i];
	}

	//동적계획법으로 문제를 풀기위해 피보나치 수열의 값을 저장할 배열을 동적할당
	//0번째와 1번째는 직접 값을 주어야 함.
	containFibonacci = new ZeroOne[max + 1];
	containFibonacci[0] = {1, 0};
	containFibonacci[1] = {0, 1};
	
	//최대값까지 반복하여 인덱스 i를 기준으로 i-1과 i-2의 0, 1 개수를 각각 더함
	for (int i = 2; i <= max; i++)
	{
		containFibonacci[i] = {
			containFibonacci[i - 1].zeroCount + containFibonacci[i - 2].zeroCount,
			containFibonacci[i - 1].oneCount + containFibonacci[i - 2].oneCount
		};
	}

	//테스트 케이스의 수만큼 출력하는 부분
	for (int i = 0; i < testCount; i++)
	{
		//numbers 배열에 저장된 피보나치 수열의 인덱스를 꺼내서 사용
		int current = numbers[i];
		cout << containFibonacci[current].zeroCount << " " 
			<< containFibonacci[current].oneCount << endl;
	}
}

 
