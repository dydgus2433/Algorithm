#include <iostream>
#define NotFound -1	// 빈 땅임을 의미할 때.
#define Kimchi 10000// 김치(...) 배추가 이 땅에 있다는 의미의 임의의 값
using namespace std;

int main() {
	int X, Y, B;	// X는 가로, Y는 세로, B는 배추의 B.
	int x, y;	// 좌표를 가리킬 때 사용할 변수 (x,y)

	int how_many;
	cin >> how_many;
	for (int a = 0; a < how_many; a++) {
		cin >> X >> Y >> B;

		// 동적으로 입력받은 밭의 크기만큼 동적할당. 2차원배열을 동적으로 생성한다.
		// 참고 사이트 : http://gshan85.tistory.com/34.
		// 1차원 배열을 가리키는 이중 포인터를 생성한 후, 생성된 포인터들로 다시 1차원 배열을 가리킨다.
		int **field = new int*[X];	// 밭을 가리킬 포인터 field. 가로 세로의 크기는 각각 1~50 제한
		for (int i = 0; i < X; i++) {
			field[i] = new int[Y];
		}


		/****** 밭의 초기화 밑 배추 심기 ******/

		for (int i = 0; i < X; i++) {
			for (int j = 0; j < Y; j++) {
				field[i][j] = NotFound;	// 밭의 모든 자리를 배추가 없다(404)로 초기화
			}
		}

		int c = 0;	// 심은 배추의 갯수를 세기 위해 사용할 변수.
					// 배추의 개수만큼, (x,y) 좌표를 뽑아내어 심는다.
		while (c < B) {
			cin >> x >> y;
			if (field[x][y] == NotFound) {	// (x,y)가 빈 땅이라면 (배추를 심지 않은 곳이라면)
				field[x][y] = Kimchi;	// 배추를 심고
				c++;	// 심은 갯수(변수 c)를 올려요.
			}
		}

		/****** 배추의 위치 파악 및 벌레 투입 ******/
		int bread = 1;	// 빵. 돌아올 길에 뿌려둘 변수(...)
		int worm = 0;	// 지렁이의 갯수.

		for (int i = 0; i < X; i++) {
			for (int j = 0; j < Y; j++) {
				if (field[i][j] >= Kimchi) {
					// 배추를 찾았을 경우
					worm++;	// 우선 벌레 갯수를 1개 증가
					field[i][j] += worm;	// 해당 배추에 벌레가 있음을 표시.

					if ((i != 0) && (field[i - 1][j] > Kimchi)) {
						// 찝은 지역의 좌측이 배추가 있는 지역이라면
						// 더 먼저 벌레를 넣은 쪽이 움직일 수 있는 곳임. 고로 넣은 벌레를 다시 빼줌
						if (field[i][j] > field[i - 1][j]) {
							field[i][j] = field[i - 1][j];
							worm--;
						}

						else {
							field[i - 1][j] = field[i][j];
						}
					}

					if (((i + 1) != X) && (field[i + 1][j] > Kimchi)) {
						// 찝은 지역의 우측이 배추가 있는 지역이라면
						// 더 먼저 벌레를 넣은 쪽이 움직일 수 있는 곳임. 고로 넣은 벌레를 다시 빼줌
						if (field[i][j] > field[i + 1][j]) {
							field[i][j] = field[i + 1][j];
							worm--;
						}

						else {
							field[i + 1][j] = field[i][j];
						}
					}

					if ((j != 0) && (field[i][j - 1] > Kimchi)) {
						// 찝은 지역의 윗측이 배추가 있는 지역이라면
						// 더 먼저 벌레를 넣은 쪽이 움직일 수 있는 곳임. 고로 넣은 벌레를 다시 빼줌
						if (field[i][j] > field[i][j - 1]) {
							field[i][j] = field[i][j - 1];
							worm--;
						}

						else {
							field[i][j - 1] = field[i][j];
						}
					}

					if (((j + 1) != 0) && (field[i][j + 1] > Kimchi)) {
						// 찝은 지역의 아랫측이 배추가 있는 지역이라면
						// 더 먼저 벌레를 넣은 쪽이 움직일 수 있는 곳임. 고로 넣은 벌레를 다시 빼줌
						if (field[i][j] > field[i][j + 1]) {
							field[i][j] = field[i][j + 1];
							worm--;
						}

						else {
							field[i][j] = field[i][j + 1];
						}
					}
				}
			}
		}

		int final_worm = 0;	// 초기값. 딱히 의미 없음

		for (int i = 0; i < X; i++) {
			for (int j = 0; j < Y; j++) {
				if ((field[i][j] != NotFound) && ((field[i][j] - Kimchi) > final_worm)) {
					// 빈 땅이 아니고, 배추 벌레의 번호가 가장 큰 것을 찾아냄
					final_worm = field[i][j] - Kimchi;
				}
			}
		}

		cout << final_worm << endl;	// 최종 벌레 수를 출력


									// 동적으로 할당한 2차원 배열(밭)을 반환. 삭제는 생성의 역순으로.
		for (int i = 0; i < X; i++) {
			delete[] field[i];
		}
		delete[] field;
	}

	return 0;
}
