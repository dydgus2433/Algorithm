Enter file contents here#include"Listclass.h"
class Stack
{
public:
	Lists L;
	bool **sizes;
	Stack();
	void Init();
	void Push(int Item);
	void Pop();
	int Length();
	bool Isempty();
	int gettop();
};
int Stack::Length()
{return L.Count;
}
Stack::Stack()
{
	L.Init();
	this->sizes = new bool *[SIZE];
	for (int i = 0; i < SIZE; i++)
	{
		this->sizes[i] = new bool[SIZE]; // 2차원 인접 생성
	}
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			this->sizes[i][j] = false;
		}
	} // 전부 인접하지 않다로 초기화 
	for (int i = 0; i < SIZE; i++) // 예외처리 
	{
		for (int j = 0; j < SIZE; j++)
		{
			if ((i == j) && ((i == 46) || (i == 50) || (i == 94) || (i == 142) || (i == 184) || (i == 191)))
			{
				this->sizes[i][j - 1] = true;
				this->sizes[i][j + 1] = false;
				break;
			}//종착역의 경우 
			else if ((i == j) && (i == 1))
			{
				this->sizes[i][j - 1] = false;
				this->sizes[i][j + 1] = true;
				this->sizes[i][j + 40] = true;
				this->sizes[i][j + 41] = true;
				break;
			}
			else if ((i == j) && (i == 0))
			{
				this->sizes[i][j + 1] = false;
				this->sizes[i][j - 1] = false;
				break;

			}
			else if ((i == j) && (i == 51))
			{
				this->sizes[i][j + 1] = true;
				this->sizes[i][j - 1] = false;
				break;

			}// 시작역의 경우 
			else if ((i == j) && (i == 143))
			{
				this->sizes[i][j + 1] = true;
				this->sizes[i][j - 1] = false;
				break;

			}// 시작역의 경우 
			else if ((i == j) && (i == 95))
			{
				this->sizes[i][j + 1] = true;
				this->sizes[i][j - 1] = false;
				break;

			}// 시작역의 경우 
			else if ((i == j) && (i == 24))
			{
				this->sizes[i][j - 1] = true;
				this->sizes[i][j + 1] = true;
				this->sizes[i][j + 23] = true;
				break;
			} // 신도림역의 경우 
			else if ((i == j) && (i == 42))
			{
				this->sizes[i][j - 1] = true;
				this->sizes[i][j - 41] = true;
				break;
			} // 뚝섬역의 경우 
			else if ((i == j) && (i == 43))
			{
				this->sizes[i][j - 42] = true;
				this->sizes[i][j + 1] = true;
				break;
			} // 신설동역의 경우 
			else if ((i == j) && (i == 47))
			{
				this->sizes[i][j - 23] = true;
				this->sizes[i][j + 1] = true;
				break;
			}// 도림천역의 경우
			else if ((i == j) && (i == 179))
			{
				this->sizes[i][j - 1] = true;
				this->sizes[i][j + 1] = true;
				this->sizes[i][j + 6] = true;
				break;
			} // 강동역 ( 상일동 - 마천 방면 )
			else if ((i == j) && (i == 185))
			{
				this->sizes[i][j + 1] = true;
				this->sizes[i][j - 6] = true;
				break;
			} // 둔촌동역
			else if (i == j)
			{
				this->sizes[i][j - 1] = true;
				this->sizes[i][j + 1] = true;
				break;
			} // 일반적인 경우
		}
	}
}
void Stack::Init()
{
	L.Init();
} // 스택 초기화

void Stack::Push(int Item)
{
	L.Insert(1,Item);
} // 스택 삽입
void Stack::Pop()
{
	L.Delete(1);
} // 스택 제거
int Stack::gettop()
{
	return L.Retrieve(1);
} // 스택 찾기

bool Stack::Isempty()
{
	return L.IsEmpty();
} // 스택 비어있는지 확인
