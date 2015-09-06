#include "Ground.h"
#include "Bug.h"

int Bug::count = 0;

Bug::Bug(int x, int y, Ground* ground):pos_x(x), pos_y(y), ground(ground){
    ++count;    //벌레 생성 시 벌레의 수 증가ŝ
    ground->setBachoo(x, y, false); //x, y위치의 배추는 이제 안전하다.
    move(); //또 다른 배추를 찾아서... 상하좌우로 이동시킨다.
}

Bug::~Bug(){
    --count;    //벌레 소멸 시 벌레의 수 감수
}

void Bug::move(){
    if(ground->canMove(pos_x+1, pos_y) == true)
        Bug(pos_x+1, pos_y, ground);
    if(ground->canMove(pos_x-1, pos_y) == true)
        Bug(pos_x-1, pos_y, ground);
    if(ground->canMove(pos_x, pos_y+1) == true)
        Bug(pos_x, pos_y+1, ground);
    if(ground->canMove(pos_x, pos_y-1) == true)
        Bug(pos_x, pos_y-1, ground);
}

int Bug::getCount(){
    return count;
}

void Bug::resetCount(){
    count = 0;
}
