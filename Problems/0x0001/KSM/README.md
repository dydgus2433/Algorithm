풀이 방법
========

처음엔 재귀함수를 이용하여 풀려 했으나,
비교적 큰 수의 피보나치 배열의 원소를 출력하려 하면 시간이 아주 오래 걸린다.

그래서 배열을 이용한 풀이를 생각해냈다.

```cpp
#include<iostream>
using namespace std;

struct z2o{
    long zero;
    long one;
};

int main()
{
    int repeat;
    cin>>repeat;

    z2o *arr = new z2o[5000];
    arr[0] = {0, 1};
    arr[1] = {1, 0};

    for(int i=2; i<5000; i++)
    {
        arr[i].zero = arr[i-1].zero + arr[i-2].zero;
        arr[i].one = arr[i-1].one + arr[i-2].one;
    }

    for(int i=0; i<repeat; i++)
    {
        int col;
        cin>>col;
        cout<<arr[col].one<<" "<<arr[col].zero<<endl;
    }

}
```

위와 같이 작성했을 경우  배열의 크기를 고려하지 않은, 말 그대로 메모리에 비 효율적인 풀이 방법이 된다.

그래서 입력 값을 한번에 모아, 계산할 수 있다는 말을 듣고 최대값에 따른 배열의 크기를 지정하기로 했다.  
가령, 최대 값이 100이라면 피보나치 0에서부터 피보나치 100까지 저장할 수 있는 101개의 배열을 만들기로 한 것이다.

```cpp
#include<iostream>
using namespace std;

struct z2o{
    long zero;
    long one;
};

int main()
{
    int repeat;
    cin>>repeat;

    int Max=0;
    int get;
    int input[repeat];

    for(int i=0; i<repeat; i++)
    {
        cin>>get;
        if(Max < get)
            Max = get;
        input[i] = get;
    }

    z2o *arr = new z2o[Max+1];
    arr[0] = {0, 1};
    arr[1] = {1, 0};

    for(int i=2; i<=Max; i++)
    {
        arr[i].zero = arr[i-1].zero + arr[i-2].zero;
        arr[i].one = arr[i-1].one + arr[i-2].one;       
    }

    for(int i=0; i<repeat; i++)
    {
        int column = input[i];
        cout<<arr[column].one<<" "<<arr[column].zero<<endl;
    }
}

```

위 코드에서
```cpp
int Max=0;
int get;
int input[repeat];

for(int i=0; i<repeat; i++)
{
    cin>>get;
    if(Max < get)
        Max = get;
    input[i] = get;
}
```
위와 같이 Max 변수를 이용해 최대 값을 처리한 후

```cpp
z2o *arr = new z2o[Max+1];
```
위와 같이 Max + 1 개의 배열을 생성했다.

이때 Max+1개의 배열을 생성한 이유는 최대 값이 100일 경우
배열을 101개 만들어야 100번째 배열을 사용할 수 있기 때문이다.  
만약 100개의 배열을 만들면 배열 인덱스의 최대 값이 99이기 때문에  
100번째 배열에 도달하지 못하고 반드시 실패하게 된다.
