#ifndef __GROUND__
#define __GROUND__

class Ground{
private:
    bool **field;   //그라운드객체(밭)에 생성되는 진짜 밭
    int width;      //밭의 너비
    int height;     //밭의 폭
public:
    Ground(int width, int height);  //width, height 크기의 밭을 생성하는 생성자
    ~Ground();                         //밭을 동적으로 생성하므로, 밭을 해제시키는 소멸자
    bool canMove(int x, int y);          //벌레가 이동가능한지 확인하는 함수
    void setBachoo(int x, int y, bool value);   //이곳에 배추가 있으라, 없으라...
    bool getBachoo(int x, int y);                  //이곳에 배추가 있니?
};

#endif
