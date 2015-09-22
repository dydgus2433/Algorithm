Enter file contents here#include"stack.h"
// 왜 메인이 기냐고 물어보면 리스트를 여기다 구현했음 . 
int main()
{
	Stations Go;
	Stack P;
	string z;
	string First, Last;
	int Lasts;
	int GOTO =0;
	bool IsVIsit[SIZE] = { false, };// 방문한 노드 
	cout << "출발역을 입력하세요 :";
	cin >> First;
	cout << "도착역을 입력하세요 :";
	cin >> Last;
		
	for (int i = 0; i < SIZE; i++)
	{
		if (Go.STATIONE[i] == First)
		{
			cout << "인접 행렬로 할 경우"<<endl;
			Go.Search(First, Last, i);
			break;
		}
	} // 행렬을 통해 찾는법

	// 인접 리스트로 찾는법
	// 이차원 배열...
	RES:
	if (GOTO == 0)
	{
		for (int i = 0; i < SIZE; i++)
		{
			for (int j = 0; j < SIZE; j++)
			{
				if (Station[j] == First)
				{
					P.Push(j); //입력
					IsVIsit[j] = true; // 처음 시작하는 곳에 우선 들어감.
				}
				else if (Station[j] == Last)
				{
					Lasts = j;
				}

			} //시작 카운트 입력 
			if (First == Last)
			{
				cout << "잘못 입력하셨습니다." << endl;
				break;
			}
			else
			{
				for (int j = 0; j < SIZE; j++)
				{
					if (P.sizes[P.gettop()][j] == true) // 해당하는 길에 장소가 있다면. 
					{
						if (Lasts == j)  // 그 열중에서 경로가 있다면 . 
						{
							P.Push(j); //목적지를 넣어놓음 
							IsVIsit[j] = true;
							cout << "경로가 있습니다." << endl;
							GOTO = 1;
							goto RES;
						}
						else //해당했는데 하고
						{
							if (IsVIsit[j] == true)
							{
								continue; // 만약에 목적지가 아니인데 , 방문했다면 건너뛰자.
							}
							else
							{
								IsVIsit[j] = true; // 그곳에 방문했다고 적는다.
								P.Push(j); // 새로 쌓는다.
								continue;

							}
						}
					}
					if ((j == SIZE - 1) && (P.sizes[P.gettop()][j] == false)) //끝까지 검사를 하고 .
					{
						if (!P.Isempty())
						{ // 만약에 비어있지 않다면
							P.Pop(); // 한번 비게 하고
							j = 0;// 해당하는 곳으로 ㄱㄱ
							continue;
						}
						else
						{
							cout << "길이 없습니다." << endl;
							break;
						}
					}
				}
			}
		}
	}
	cout << "인접 리스트로 할 경우 "<<endl;
	for (int i=P.Length(); i >=0; i--)
	{
		if (P.Length()>0)
		{
			string R = Station[P.gettop()];
			cout << R << endl;
			P.Pop();
		}
	}
}
