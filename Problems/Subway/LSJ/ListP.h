#ifndef listP_H
#define listP_H

typedef struct nodeRecord {
// C++에선 구조체와 Class가 Default 접근 권한을 제외하고 동일함
public:	// Default 접근 권한이 public이지만 가독성을 위해 기입
	int Data;
	struct nodeRecord* Next;
} node;

typedef node* Nptr;

class listClass {
private:
	int Count;
	Nptr Head;
public:
	listClass();								// 생성자
	listClass(const listClass& L);				// 복사 생성자
	~listClass();								// 소멸자

	void Init();								// 리스트 초기화
	int Length();								// 데이터 길이
	bool IsEmpty();								// 리스트 안에 데이터 유무 확인
	void Insert(int Position, int Item);		// 데이터 삽입
	void Delete(int Position);					// 데이터 삭제
	void Retrieve(int Position, int& Item);		// 데이터 조회
};

#endif
