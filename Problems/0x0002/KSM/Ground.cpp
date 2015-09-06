#include "Ground.h"

Ground::Ground(const int width, const int height):width(width), height(height){
    field = new bool*[height];      //매개변수로 2차원 배열 동적 생성 불가.
    for(int i=0; i<height; i++){        //포인터의 배열 생성 후
        field[i] = new bool[width]{false};  //bool 배열 생성
    }
}

Ground::~Ground(){
    delete []field; //밭을 없앤다...  가 아니라, 동적으로 할당된 bool 배열(필드)를 제거한다.
}

bool Ground::canMove(int x, int y){
    //x, y가 밭의 범위 내에 있으며, 해당 위치에 배추가 있을 경우
    if((x>=0 && x<width) && (y>=0 && y<height) && field[y][x] == true)
    {
        return true;
    }
    return false;
}

void Ground::setBachoo(int x, int y, bool value){
    field[y][x] = value;    //x, y위치에 배추가 있기로 한다.
}

bool Ground::getBachoo(int x, int y){
    return field[y][x] == true;     //x, y위치에 배추가 있나 확인한다.
}
