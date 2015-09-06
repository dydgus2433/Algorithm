#include<iostream>
#include<assert.h>
#include"Ground.h"
#include"Bug.h"

using namespace std;

int main(int argc, char* argv[]){
    int fields; //밭의 갯수
    cin>>fields;

    int needBugs = 0;   //밭 하나당 필요한 벌레의 마릿수

    int width, height, bachoo;  //밭의 너비, 폭, 배추의 갯수.

    for(int repeater=0; repeater < fields; repeater++)  //초기 입력값 field. 나중에 i, j를 쓰기 위해 repeater라는 임시변수 사용
    {
        cin>>width>>height>>bachoo; //밭의 너비, 폭, 배추의 갯수

        int bachoo_x, bachoo_y; //입력값(배추의 위치)를 받기 위한 임시 변수

        Ground *ground = new Ground(width, height); //밭 생성

        for(int locator=0; locator<bachoo; locator++)
        {
            cin>>bachoo_x>>bachoo_y;
            ground->setBachoo(bachoo_x, bachoo_y, true);    //배추밭의 x, y위치에 배추를 표시
        }

        for(int i=0; i<height; i++)
        {
            for(int j=0; j<width; j++)
            {
                if(ground->getBachoo(j, i) == true)
                {
                    Bug(j, i, ground);  //벌레를 그냥 임시변수로 만들어도, 생성자 내 move함수를 호출하기 때문에 문제 없다.
                    needBugs++; //생성자와 move가 반복해서 호출되기 때문에 인접한 trues는 모두 처리된다.
                                //그래서 한 구역이 완료되면 필요한 벌레의 수를 증가.
                }
            }
        }
        cout<<needBugs<<endl;
        Bug::resetCount();      //Bug내의 count변수는 static이기 때문에 초기화가 필요하다.
        needBugs = 0;   //또 한복할 것이기 때문에 needBugs를 0으로 초기화
    }
}
