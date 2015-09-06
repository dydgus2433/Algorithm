#ifndef __BUG__
#define __BUG__

class Bug{      //벌레
private:
    int pos_x;  //벌레의 x 위치
    int pos_y;  //벌레의 y 위치
    Ground *ground;  //벌레가 밭의 멤버함수 호출을 할 수 있도록...
    static int count;   //밭에 존재하는 벌레의 총 마리수 생성자에서 증가, 소멸자에서 감소시킨다. 정적 필드임에 주의
public:
    Bug(int x, int y, Ground* ground);  //지정된 위치에 벌레를 생성
    ~Bug();
    static int getCount();  //지금 벌레가 몇 마리 있죠??
    static void resetCount();   //count가 정적멤버변수니까, 초기화를 해줄 것.
    void move();    //벌레 이동한다.
};

#endif
