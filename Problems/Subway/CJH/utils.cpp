#include "utils.h"

//문자열을 여러 문자열로 분리하는 함수
vector<string> StringUtil::Split(string source, string token)
{
    int pos = 0; //시작 인덱스 0

    vector<string> vec; //분리된 문자열을 저장할 벡터 자료구조
    //토큰의 첫번째 인덱스를 저장, 문자열내에 토큰이 존재할 경우 반복
    while ((pos = source.find_first_of(token)) != source.npos)
    {
        if (pos > 0)
        { //가장 앞 부분부터 토큰바로 앞까지의 문자열을 벡터에 저장한다.
            vec.push_back(source.substr(0, pos));
        }
        //토큰 뒤의 문자열을 잘라내어 다시 대입한다.
        source = source.substr(pos + 1);
    }

    //문자열내에 토큰은 없으나 잔여 문자열이 있을 경우
    if (source.length() > 0)
    { //문자열 나머지 벡터에 저장
        vec.push_back(source);
    }

    //문자열이 분리되어 저장된 벡터 반환
    return vec;
}

//역명 -> 역번호 매핑 함수
int MapUtil::Mapping(vector<string>& vec, string& station_name)
{
    //벡터 내부를 순회하면서 역명으로 탐색하고, 발견시 인덱스를 반환
    for (unsigned int i = 0; i < vec.size(); i++)
    {
        if (vec[i] == station_name)
        {
            return i;
        }
    }

    //없으면 -1 반환
    return NOT_FOUND;
}

//역번호 -> 역명 매핑 함수
string MapUtil::Mapping(vector<string>& vec, unsigned int station_code)
{
    //인덱스 범위를 벗어났을 시 빈 문자열 반환
    if (station_code < 0 || station_code >= vec.size())
    {
        return "";
    }

    //해당 인덱스의 역명 반환
    return vec[station_code];
}
