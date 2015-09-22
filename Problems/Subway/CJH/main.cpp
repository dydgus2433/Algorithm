#include <fstream>
#include <iostream>
#include "graph.h"
#include "utils.h"

using namespace std;

int main(void)
{
    ifstream fs; //입력 파일 스트림 객체
    char fileName[20]; //역 이름이 저장된 파일이름
    char buff[4096] = ""; //역을 읽어들일 버퍼

    vector<string> listMap; //매핑에 사용할 벡터

    cout << "노선 파일: ";
    cin.getline(fileName, 20, '\n');
    fs.open(fileName, fs.in); //파일 스트림을 입력모드로 연다
    fs.read(buff, 4096); //파일내용을 버퍼로 읽어들임
    //공백문자를 기준으로 역들을 분리하여 벡터 맵에 저장
    listMap = StringUtil::Split(buff, " ");
    fs.close(); //파일 스트림을 닫는다

    cout << "불러온 역 개수: " << listMap.size() << endl;

    GraphList gList(listMap.size()); //역 개수 만큼의 인접행렬 생성
    GraphArr gArray(listMap.size()); //역 개수 만큼의 인접리스트 생성

    cout << "1. 그래프 구축" << endl
        << "2. 경로 출력" << endl
        << "0. 종료" << endl;

    int sel;
    char station[50], station2[50];

    while (true)
    {
        cout << "명령>> ";
        cin >> sel;
        cin.ignore(); //입력버퍼에 남아있는 줄바꿈 문자 제거
        switch (sel)
        {
        case 1:
        {
            cout << "역 이름: ";
            cin.getline(station, 50, '\n'); //시작하는 역 입력

            //벡터 맵에 해당하는 역이 없을 경우 취소
            if (MapUtil::Mapping(listMap, string(station)) == MapUtil::NOT_FOUND)
            {
                cout << "해당 역은 노선 상에 존재하지 않습니다." << endl;
                break;
            }

            cout << station << "와(과) 인접한 역들 이름(공백으로 구분): ";
            cin.getline(station2, 50, '\n');
            {
                //연결할 역들을 역단위로 분리하여 저장
                vector<string> stations = StringUtil::Split(string(station2), " ");
                //연결할 역들을 노선에 있는지 확인하여 연결시킴
                for (vector<string>::iterator target = stations.begin(); target != stations.end(); target++)
                {
                    int src = MapUtil::Mapping(listMap, string(station));
                    int dest = MapUtil::Mapping(listMap, *target);

                    //도착지가 노선에 없을 경우 다음 연결할 역 확인
                    if (dest == MapUtil::NOT_FOUND)
                    {
                        cout << *target << "은 존재하지 않습니다." << endl;
                        continue;
                    }

                    gList.InsertEdge(src, dest); //인접리스트 간선 삽입
                    gArray.InsertEdge(src, dest); //인접행렬 간선 삽입
                }
            }
            break;
        }
        case 2:
        {
            cout << "출발 역: ";
            cin.getline(station, 50, '\n');
            cout << "도착 역: ";
            cin.getline(station2, 50, '\n');

            cout << endl;

            //출발지와 도착지를 역명->역번호 매핑
            int src = MapUtil::Mapping(listMap, string(station));
            int dest = MapUtil::Mapping(listMap, string(station2));

            stack<int> path; //경로를 저장할 스택

            //출발지나 도착지가 노선에 없을 경우 취소
            if (src == MapUtil::NOT_FOUND || dest == MapUtil::NOT_FOUND)
            {
                cout << "* 노선 상에 존재하지 않는 역입니다." << endl;
                break;
            }

            //인접리스트로 경로를 찾는다
            path = gList.FindPath(src, dest);
            if (path.top() == -1) //경로가 없을 경우
            {
                cout << "* 경로가 없습니다." << endl;
                break;
            }

            cout << "= 인접 리스트에 의한 경로 출력 =" << endl;
            //스택에 저장된 경로를 출력(인접리스트)
            while (true)
            {
                //역번호 -> 역명 매핑하여 출력
                cout << MapUtil::Mapping(listMap, path.top());
                path.pop();
                if (path.empty())
                {
                    break;
                }
                else
                {
                    cout << " -> ";
                }
            }

            cout << endl << endl;

            //인접행렬로 경로를 찾는다
            path = gArray.FindPath(src, dest);

            cout << "= 인접 행렬에 의한 경로 출력 =" << endl;
            //스택에 저장된 경로를 출력(인접행렬)
            while (true)
            {
                //역번호 -> 역명 매핑하여 출력
                cout << MapUtil::Mapping(listMap, path.top());
                path.pop();

                if (path.empty())
                {
                    break;
                }
                else
                {
                    cout << " -> ";
                }
            }

            cout << endl << endl;

            break;
        }
        case 0:
        default:
            return 0;
        }
    }
}
