#ifndef UTILS_H
#define UTILS_H

#include <vector> //STL 벡터 자료구조 사용
#include <string> 

using namespace std;

class StringUtil
{
public:
    //문자열을 주어진 토큰을 기준으로 여러 문자열로 분리하는 함수
    static vector<string> Split(string source, string token);
};

class MapUtil
{
public:
    //역명 -> 역번호 매핑 함수
    static int Mapping(vector<string>& vec, string& station_name);
    //역번호 -> 역명 매핑 함수
    static string Mapping(vector<string>& vec, unsigned int station_code);
    static const int NOT_FOUND = -1;
};

#endif
