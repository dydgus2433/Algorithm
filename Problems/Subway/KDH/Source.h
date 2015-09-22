#include<iostream>
#include<string>
#include<cstring>
#include<list>
#include<stack>
#define SIZE 192 // 역 갯수 지정
using namespace std;
string Station[SIZE] = { "NULL","성수","건대입구","구의","강변","잠실나루","잠실","신천","종합운동장","삼성","선릉",
"역삼","강남","교대","서초","방배","사당","낙성대","서울대입구","봉천","신림",
"신대방","구로디지털단지","대림","신도림","문래","영등포구청","당산","합정","홍대입구","신촌",
"이대","아현","충정로","시청","을지로입구","을지로3가","동대문역사문화공원","신당","상왕십리","왕십리",
"한양대","뚝섬","신설동","용두","신답","용답","도림천","양천구청","신정네거리","까치산",
"대화","주엽","정발산","마두","백석","대곡","화정","원당","원흥","삼송",
"지축","구파발","연신내","불광","녹번","홍제","무악재","독립문","경복궁","안국",
"종로3가","을지로3가.","충무로","동대입구","약수","금호","옥수","압구정","신사","잠원",
"고속터미널","교대","남부터미널","양재","매봉","도곡","대치","학여울","대청","일원"
,"수서","가락시장","경찰병원","오금","당고개","상계","노원","창동","쌍문"
,"수유","미아","미아사거리","길음","성신여대입구","한성대입구","혜화","동대문",
"동대문문화역사공원","충무로","명동","회현","서울역","숙대입구","삼각지","신용산",
"이촌","동작","이수","사당","남태령","선바위","경마공원","대공원","과천",
"정부과천청사","인덕원","평촌","범계","금정","산본","수리산","대야미","반월","상록수",
"한대앞","중앙","고잔","초지","안산","신길온천","정왕","오이도",
"방화","개화산","김포공항","송정","마곡","발산","우장산","화곡","까치산","신정",
"목동","오목교","양평","영등포구청","영등포시장","신길","여의도","여의나루","마포","공덕",
"애오개","충정로","서대문","광화문","종로3가.","을지로4가","동대문역사문화공원.","청구","신금호","행당",
"왕십리","장한평","군자","아차산","광나루","천호","강동","길동","굽은다리","명일",
"고덕","상일동","둔촌동","올림픽공원","방이","오금.","개룡","거여","마천"
// 주의 할점 순환선 (0~41) , 5호선 강동 //성수는 42번에 연결 
// 신도림 23번 (46 ~ 49번과 연결) / 49번에 2호선 종료 / 50번부터 3호선 ~93번 / 94번 ~141번 4호선 / 142 ~ 190번 5호선  // 178번 강동 (183/184~)
}; // 역만들기
class Stations
{
public:
	Stations(); // 초기화
	string *STATIONE; // 역이름 저장
	bool **size; // 시작 . 
	void Search(string First, string Last, int Counts); // 검색함수 
};
Stations::Stations() // 일반적인 경우와 예외 처리를 동시에 해야 되서 상당히 많은 양의 코드 발생 
// 이렇게 예외처리를 따로 if문을 둔 이유는 ...(...191개 다적기 귀찮다 ㅜㅜ ) 그래서 일반적인 것을 else로 넣고 예외를 if로...
{
	this->STATIONE = new string[SIZE]; // 역확보. 
	for (int i = 0; i < SIZE; i++)
	{
		this->STATIONE[i] = Station[i];
	}

	this->size = new bool *[SIZE];
	for (int i = 0; i < SIZE; i++)
	{
		this->size[i] = new bool[SIZE]; // 2차원 인접 생성

	}
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			this->size[i][j] = false;

		}
	} // 전부 인접하지 않다로 초기화 

	for (int i = 0; i < SIZE; i++) // 예외처리 
	{
		for (int j = 0; j < SIZE; j++)
		{
			if ((i == j) && ((i == 46) || (i == 50) || (i == 94) || (i == 142) || (i == 184) || (i == 191)))
			{
				this->size[i][j - 1] = true;
				this->size[i][j + 1] = false;
				break;
			}//종착역의 경우 
			else if ((i == j) && (i == 1))
			{
				this->size[i][j - 1] = false;
				this->size[i][j + 1] = true;
				this->size[i][j + 40] = true;
				this->size[i][j + 41] = true;
				break;
			}
			else if ((i == j) && (i == 0))
			{
				this->size[i][j + 1] = false;
				this->size[i][j - 1] = false;
				break;
}
			else if ((i == j) && (i == 51))
			{
				this->size[i][j + 1] = true;
				this->size[i][j - 1] = false;
				break;
			}// 시작역의 경우 
			else if ((i == j) && (i == 143))
			{
				this->size[i][j + 1] = true;
				this->size[i][j - 1] = false;
				break;
			}// 시작역의 경우 
			else if ((i == j) && (i == 95))
			{
				this->size[i][j + 1] = true;
				this->size[i][j - 1] = false;
				break;
			}// 시작역의 경우 
			else if ((i == j) && (i == 24))
			{
				this->size[i][j - 1] = true;
				this->size[i][j + 1] = true;
				this->size[i][j + 23] = true;
				break;
			} // 신도림역의 경우 
			else if ((i == j) && (i == 42))
			{
				this->size[i][j - 1] = true;
				this->size[i][j - 41] = true;
				break;
			} // 뚝섬역의 경우 
			else if ((i == j) && (i == 43))
			{
				this->size[i][j - 42] = true;
				this->size[i][j + 1] = true;
				break;
			} // 신설동역의 경우 
			else if ((i == j) && (i == 47))
			{
				this->size[i][j - 23] = true;
				this->size[i][j + 1] = true;
				break;
			}// 도림천역의 경우
			else if ((i == j) && (i == 179))
			{
				this->size[i][j - 1] = true;
				this->size[i][j + 1] = true;
				this->size[i][j + 6] = true;
				break;
			} // 강동역 ( 상일동 - 마천 방면 )
			else if ((i == j) && (i == 185))
			{
				this->size[i][j + 1] = true;
				this->size[i][j - 6] = true;
				break;
			} // 둔촌동역
			else if (i == j)
			{
				this->size[i][j - 1] = true;
				this->size[i][j + 1] = true;
				break;
			} // 일반적인 경우
		}
	}
	// 여기서 지정해주는 이유는 #define으로 191개의 역을 다 지정해줄수 없어서....(인접..)
}//stations 종료 중괄호


void Stations::Search(string First, string Last, int Counts) // 검색함수 (Counts,Lasts의 구분)
{

	int Data1[50]; // 정방향 저장 인덱스
	int Data2[50]; // 역방향 저장 인덱스 
	for (int i = 0; i < 50; i++)
	{
		Data1[i] = 1500;
		Data2[i] = 1500; // 적당한 큰 숫자로 초기화 
	}
	bool OK1[SIZE] = { false, }; // 방문 했나 
	bool OK2[SIZE] = { false, }; // 방문했는지 
	Data1[0] = Counts;
	Data2[0] = Counts; // 해당하는 출발역 인덱스 저장
	int Count1 = 0; // 정방향 역 이동수
	int Count2 = 0; // 역방향 역 이동수
	OK1[Counts] = true; // 처음 방문 
	OK2[Counts] = true; //처음 방문
	int Dummy1 = 1; // 인덱스의 값을 넣을 변수 1
	int Dummy2 = 1; // 인덱스의 값을 넣을 변수 2
	int Count3 = 0; // 반복문
	int Count4 = 0; //반복문 
	RESTART:
if(Count3==0)
{
	for (int i = Counts; i >= 0; i--) // 역방향 
	{
		for (int j = i; j >= 0; j--)
		{
			if (this->STATIONE[i] == Last)
			{
				Count3 = 1;
				OK1[i] = true; // 해당하는 목적지 방문 
				goto RESTART;
			}

			else if ((j == 0) && (OK1[i] == true)) // 왼쪽항까지 수색했고 OK1[i]가 방문한 상태라면
			{
				for (int k = i; k < SIZE; k++) //거꾸로 시작
				{

					for (j = k; j < SIZE; j++)
					{
						if (this->STATIONE[k] == Last)
						{
							Count3 = 1;
							OK1[i] = true; // 해당하는 목적지 방문 
							goto RESTART;
						} // 거꾸로 하는데 일치한다면.

						else if (this->size[k][j] == true) // 만약에 다시 일치한다면
						{
							if (OK1[j] == true) // 근데 그곳이 방문했던 곳이라면 . 
							{
								Data1[Dummy1] = 1500;
								Dummy1--; // 지나간 역에서 제외
								break;
							}
							else if (OK1[j] == false)
							{
								OK1[j] = true; // 역 지나감(true)
								Data1[Dummy1] = j; // 해당하는 인덱스를 넣음 
								Dummy1++;
								Count1++; // 해당하는 역 지나감
								break;
							}
						}
						else if ((j == SIZE-1) && (OK1[k] == true)) // 만약에 다 해도 발견이 되지 않는다면 . 
						{
							Count1 = 1500; // 경로가 없으므로 
							goto RESTART; 
						}
					}
				}
			}
			else
			{
				if ((this->size[i][j] == true) && (OK1[j] == false)) // 방문하지 않았다 라고 가정한다면 . 
				{
					OK1[j] = true; // 역 지나감(true)
					Data1[Dummy1] = j; // 해당하는 인덱스를 넣음 
					Dummy1++;
					Count1++; // 해당하는 역 지나감
					break;
				}
			}
		}
	}
}
GOTO:
if (Count4 == 0)
{
	for (int i = Counts; i <SIZE; i++) // 정방향 
	{
		for (int j = i; j <SIZE; j++)
		{
			if (this->STATIONE[i] == Last)
			{
				Count4 = 1;
				OK2[i] = true; // 해당하는 목적지 방문 
				goto GOTO;
			}
			else if ((j == SIZE-1) && (OK2[i] == true)) // 왼쪽항까지 수색했고 OK1[i]가 방문한 상태라면
			{
				for (int k = i; k>=0; k--) //거꾸로 시작
				{
					for (j = k; j >=0; j--)
					{
						if (this->STATIONE[k] == Last)
						{
							Count4 = 1;
							OK2[i] = true; // 해당하는 목적지 방문 
							goto GOTO;
						} // 거꾸로 하는데 일치한다면.
						else if (this->size[k][j] == true) // 만약에 다시 일치한다면
						{
							if (OK2[j] == true) // 근데 그곳이 방문했던 곳이라면 . 
							{
								Data2[Dummy2] = 1500;
								Dummy2--; // 지나간 역에서 제외
								break;
							}

							else if (OK2[j] == false)
							{
								OK2[j] = true; // 역 지나감(true)
								Data2[Dummy2] = j; // 해당하는 인덱스를 넣음 
								Dummy2++;
								Count2++; // 해당하는 역 지나감
								break;
							}
						}
						else if ((j == SIZE - 1) && (OK1[k] == true)) // 만약에 다 해도 발견이 되지 않는다면 . 
						{
							Count2 = 1500; // 경로가 없으므로 
							goto RESTART;
						}
					}
				}
			}
			else
			{
				if ((this->size[i][j] == true) && (OK2[j] == false)) // 방문하지 않았다 라고 가정한다면 . 
				{
					OK2[j] = true; // 역 지나감(true)
					Data2[Dummy2] = j; // 해당하는 인덱스를 넣음 
					Dummy2++;
					Count2++; // 해당하는 역 지나감
					break;
				}
			}
		}
	}
}
if (Count1 > Count2)
{
	for (int i = 0; i < Dummy2; i++)
	{
		int n = Data2[i];
		cout << this->STATIONE[n] << endl;
	}
} // 정방향이 더 빠를경우

else
{
	for (int i = 0; i < Dummy1; i++)
	{
		int n = Data1[i];
		cout << this->STATIONE[n] << endl;
	}
} // 역방향이 더 빠를경우 
}
