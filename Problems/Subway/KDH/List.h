//STL을 못써서 리스트를 다시 만들었다 ㄱ- 
//개인적으로 가장 낭비같았던 헤더파일이다.
#include"Source.h"
typedef struct Node
{
	int Number; // 역 인덱스 번호
	string Station; // 역이름
	Node *Nptr; // Node형태를 가리키는 포인터
}Nodes;
typedef Nodes* NodeTo;//Nodes형태의 포인터
class Lists
{
public:
	int Count;
	NodeTo Head;
	void Init();
	int Length();//길이
	void Insert(int Numbers,int Item);//삽입
	void Delete(int Numbers); //삭제
	int Retrieve(int Numberss); //검색
	bool IsEmpty(); //0인지 아닌지확인
};
void Lists::Init()
{	this->Count = 0;
	this->Head = NULL;
	cout << "초기화 되었습니다." << endl;
} // 초기화
bool Lists::IsEmpty() {
	return (this->Count == 0);
}
int Lists::Length()
{
	cout << "길이 :" << this->Count << endl;
	return this->Count;
} // 길이
void Lists::Insert(int Numbers,int Item)
{
	if ((Numbers > this->Count + 1) || (Numbers < 1))
		cout << "이격되어있습니다." << endl;
	else {
		NodeTo S = new Nodes; // 동적할당
		S->Number = Item;
		S->Nptr = NULL;
		if (Numbers == 1) { // 만약에 내가 넣어야하는게 처음이라면 
			S->Nptr = Head; // 새 노드는 이전 헤드 노드를 가리킴
			Head = S; // 헤드는 새 노드를 가리킴
		}
		else {
			NodeTo Temp = Head;
			for (int i = 0; i < (Numbers - 1); i++)
			{
				Temp = Temp->Nptr;
				S->Nptr = Temp;
				Temp->Nptr = S;
			}
		}
		Count++; // 리스트 길이 증가
	}

}
void Lists::Delete(int Mumbers)
{
	if (this->Count == 0)
	{
		cout << "리스트가 비어있습니다." << endl;
	}
	else if ((Mumbers > this->Count) || (Mumbers < 1)) {
		cout << "이격되어있습니다." << endl;
	}
	else {
		NodeTo S = Head; // node 포인터 p가 첫노드를 가리킴
		if (Mumbers == 1) { // 첫 노드 제거
			Head = S->Nptr; // 헤드가 p의 Next필드 값(두 번째 노드)를 가리킴
			delete S;
		}
		else {
			NodeTo Temp = Head;
			for (int i = 1; i < (Mumbers - 1); i++)
				Temp = Temp->Nptr;
			S = Temp->Nptr;
			Temp->Nptr = S->Nptr;
			delete S;
		}
		Count--; // 리스트 길이 감소
	}
} // 삭제

int Lists::Retrieve(int Numberss) //검색
{
	if ((Numberss > Count) || (Numberss < 1)) // 범위 밖의 데이터 검색 금지
		cout << "범위에 없습니다." << endl;
	else {
		NodeTo Temp = Head; // 임시 노드 포인터가 헤드 노드 지칭
		for (int i = 1; i < Numberss; i++)
			Temp = Temp->Nptr; // 노드 포인터가 Position 위치의 노드까지 이동
		return Temp->Number; // 해당 노드의 데이터를 Item 변수에 저장
	}
} // 검색 
