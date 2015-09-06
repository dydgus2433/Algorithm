#include <iostream>
using namespace std;

//필드의 가로, 세로 길이 전역변수로 선언
int width, height;

//지렁이가 배추 벌레를 먹는다.
bool DoEat(int field[][50], int x, int y)
{
	//필드의 범위를 벗어났을 경우 false 반환
	if (x < 0 || x >= width || y < 0 || y >= height)
	{
		return false;
	}

	//지정 위치에 배추가 없을 경우 false 반환
	if (field[y][x] == 0)
	{
		return false;
	}

	//배추가 있음을 확인했으므로 없다고 침.
	field[y][x] = 0;

	//아래는 현위치로부터 왼쪽, 오른쪽, 위, 아래를 재귀적으로 탐색
	DoEat(field, x - 1, y);
	DoEat(field, x + 1, y);
	DoEat(field, x, y - 1);
	DoEat(field, x, y + 1);

	//true 반환
	return true;
}

int main(void)
{
	// cin, cout 속도 향상!!
	ios_base::sync_with_stdio(false);

	int testCount;
	//밭의 최대크기가 50, 50이므로 .. 동적할당하기 귀찮아서 잡아줌
	int field[50][50] = { 0, };
	int x, y;
	int countCabbage; // 배추의 수

	cin >> testCount; // 테스트 케이스의 수 입력 받음
	while (testCount-- > 0) // 테스트 케이스 만큼 반복
	{
		// 가로, 세로, 배추 수 입력받음
		cin >> width >> height >> countCabbage; 

		// 배추의 위치를 입력 받음
		for (int i = 0; i < countCabbage; i++)
		{
			cin >> x >> y;
			field[y][x] = 1;
		}

		int countWorms = 0; // 필요한 지렁이 수
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				// 탐색을 시작한 위치에서 true가 반환되면 그 위치에 지렁이 투입
				if (DoEat(field, j, i))
				{
					++countWorms;
				}
			}
		}
		cout << countWorms << '\n'; // 필요한 지렁이의 수 출력
	}
	
	
}
