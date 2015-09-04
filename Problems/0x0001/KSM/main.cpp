#include<iostream>
using namespace std;

struct z2o{
    long zero;    //피보나치 n번째 요소가 0을 호출하는 횟수
    long one;     //피보나치 n번째 요소가 1을 호출하는 횟수
};

int main()
{
    int repeat;   //입력의 갯수
    cin>>repeat;  //입력의 갯수를 받아 repeat 변수에 저장

    int Max=0;    //입력 받아들일 값의 최대 값을 저장할 변수
    int get;      //입력 값을 받아들일 변수
    int input[repeat];  //입력 값들을 저장할 변수

    for(int i=0; i<repeat; i++) //입력의 갯수만큼 반복
    {
        cin>>get;       //값을 받고
        if(Max < get)   //현재 최대값보다 클 경우
            Max = get;  //최대값으로 지정
        input[i] = get; //입력 값을 배열에 담는다.
    }

    z2o *arr = new z2o[Max+1];      //0부터 입력 값의 최대 값 만큼 배열을 생성
    arr[0] = {0, 1};
    arr[1] = {1, 0};

    for(int i=2; i<=Max; i++)
    {
        arr[i].zero = arr[i-1].zero + arr[i-2].zero;    //반복문으로 피보나치 n번째 요소가  0, 1을 호출하는 횟수를 계산해 저장한다.
        arr[i].one = arr[i-1].one + arr[i-2].one;       
    }

    for(int i=0; i<repeat; i++)
    {
        int column = input[i];      //입력 값이 저장 된 배열에서 값을 하나씩 꺼내 온 후
        cout<<arr[column].one<<" "<<arr[column].zero<<endl;     //해당 입력값에 대응하는 피보나치 요소가 0, 1을 호출하는 횟수를 출력.
    }
}
