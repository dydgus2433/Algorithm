#include <iostream>
#include "ListP.h"
using namespace std;

listClass::listClass() {		// 생성자
	Count = 0;
	Head = NULL;
}

listClass::listClass(const listClass& L) {	// 복사 생성자
	Count = L.Count;			// 리스트 갯수를 동일하게
	if (L.Head == NULL)			// 넘어온 게 빈 리스트라면
		Head = NULL;		// 자신도 빈 리스트
	else {						// 넘어온 게 빈 리스트가 아니라면
		Head = new node;	// 새 노드 생성
		Nptr Temp1 = Head;	// 사본을 순회하는 포인터 Temp1

		for (Nptr Temp2 = L.Head->Next; Temp2 != NULL; Temp2 = Temp2->Next) {
			Temp1->Next = new node;		// 사본의 현재 노드에 새 노드를 붙임
			Temp1 = Temp1->Next;			// 새 노드로 이동
			Temp1->Data = Temp2->Data;	// 새 노드에 원본 데이터를 복사
		}
		Temp1->Next = NULL;	// 사본의 마지막 노드의 Next에 NULL을 기입
	}
}

listClass::~listClass() {		// 소멸자
	while (!IsEmpty())			// 리스트가 완전히 빌 때까지
		Delete(1);				// 첫번째 노드를 계속 지우기
}

void listClass::Init() {		// 리스트 초기화
	Count = 0;
	Head = NULL;
	// 생성자와 동일한 역할을 하나, 생성자는 객체 생성 시에 1번만 작동하며
	// 사용자가 원할 때 초기화 할 수 없으므로 따로 멤버 함수를 작성
}

int listClass::Length() {		// 데이터 길이
	return Count;
}

bool listClass::IsEmpty() {		// 리스트 안에 데이터 유무 확인
	return (Count == 0);		// 비어있으면 true 반환
}

void listClass::Insert(int Position, int Item) {	// 데이터 삽입
	Nptr p = new node;		// 삽입될 노드의 공간 확보
	if ((Position > (Count + 1)) || (Position < 1)) {
		printf("Position out of Range!\n");	//이격된 삽입위치 불허
		delete(p);
	}
	else {
		p->Data = Item;								// 데이터 값 복사

		if (Position == 1) {						// 첫 위치에 삽입할 경우
			p->Next = Head;							// 삽입노드가 현재 첫 노드를 가리킴
			Head = p;								// 헤드가 삽입노드를 가리키게
		}

		else {										// 첫 위치가 아닐 경우
			Nptr Temp = Head;						// 헤드 포인터를 Temp로 복사
			for (int i = 1; i < (Position - 1); i++)
				Temp = Temp->Next;					// Temp가 삽입직전 노드를 가리키게
			p->Next = Temp->Next;					// 삽입노드의 Next를 설정
			Temp->Next = p;							// 직전노드가 삽입된 노드를 가리키게
		}

		Count += 1;							// 리스트 길이를 늘림
		//cout << "데이터 추가를 완료하였습니다." << endl;
	}
}

void listClass::Delete(int Position) {				// 데이터 삭제
	Nptr Temp;
	Nptr p;

	if (IsEmpty())						// 비어있는지 확인
		cout << "Deletion on Empty List!" << endl << endl;	// 빈 리스트에 삭제 요구는 오류
	else if ((Position > (Count + 1) || (Position < 1)))
		cout << "Position out of Range!" << endl << endl;		// 이격된 삽입위치 불허
	else {
		if (Position == 1) {						// 첫 노드를 삭제하는 경우
			p = Head;								// 삭제될 노드를 가리키는 포인터를 백업
			Head = Head->Next;						// 헤드가 둘째 노드를 가리키게
		}

		else {										// 첫 노드가 아닐 경우
			for (int i = 1; i < (Position - 1); i++)
				Temp = Temp->Next;					// Temp가 삭제 직전 노드를 가리키게
			p = Temp->Next;							// 삭제될 노드를 가리키는 포인터를 백업
			Temp->Next = p->Next;				// 직전노드가 삭제될 노드 다음 노드를 가리키게
		}

		Count -= 1;									// 리스트 길이를 줄임
		delete(p);									// 메모리 공간 반납

		//cout << "데이터 삭제를 완료하였습니다" << endl;
	}
}

void listClass::Retrieve(int Position, int& Item) {	// 데이터 조회
	Nptr Temp = Head;			// 첫번째 노드를 가리키고 있음.

	if ((Position > Count) || (Position < 1))
		cout << "Position out of Range!" << endl << endl;	//이격된 삽입위치 불허

	else if (Position == 1)					// 첫번째 노드이면
		Item = Temp->Data;		// 첫번째 노드의 데이터 값을 참조호출을 이용하여 저장

	else {
		for (int i = 1; i < Position; i++)	// 첫 위치가 아닐 경우
			Temp = Temp->Next;				//Temp가 접근 노드를 가리키게
		Item = Temp->Data;				// 접근 노드의 데이터 값을 참조호출을 이용하여 저장
	}
}
