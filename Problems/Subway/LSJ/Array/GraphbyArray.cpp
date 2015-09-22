#include <iostream>
#include <string>
#include "ListP.h"	// 1학기 때 과제로 사용한 ListP를 사용(경로 탐색의 저장소로 사용)
#include "GraphbyArray.h"
using namespace std;

GraphbyArray::GraphbyArray() {	// 생성자
	V = 183;	// 역의 갯수 195개에서 중복된 정점을 제거하여 183개
	E = 0;		// 간선의 갯수는 처음에 0
	Name = new string[V];	// 역의 이름을 담을 1차원 문자열 배열 생성
	Q = new Node*[V]; // Node* 형태의 1차원 배열을 우선 생성
	
	for (int i = 0; i < V; i++) {
		Q[i] = new Node[V];
	}
	// 그 다음 각각의 Node* 포인터에 V개 만큼의 Node 1차원 배열을 생성
	// 이렇게 하여 V * V개의 2차원 배열을 생성

	for (int i = 0; i < V; i++) {
		for (int j = 0; j < V; j++) {
			Q[i][j].connect = false;	// 간선을 연결하기 전이므로 모두 false
		}
	}

	Line = new bool*[V];	// 각 역의 정보를 담을 2차원 배열
	for (int i = 0; i < V; i++) {
		Line[i] = new bool[6];
		// 0은 탐색할 때 이 역을 지나간 적이 있는지 기억하는 flag
		// 1은 NotUsed. 사용하지 않음
		// 2~5는 역이 어느 호선인지 확인시켜주는 flag.
		// 예를 들어, 동대문역사문화공원역은 2,4,5 호선에 있으므로 2,4,5 = true, 3 = false;
		// Line 2차원 배열은 V(역의 갯수) * 6개로 구현 됨.
		for (int j = 0; j < 6; j++) {
			Line[i][j] = false;	// 이 역시 초기화이므로 false
		}
	}
	MetroSetup();	// 모든 초기화가 끝난 뒤에 지하철 정보 입력
}

GraphbyArray::~GraphbyArray() {	// 소멸자
	for (int i = 0; i < V; i++) {
		delete[]Q[i];
	}
	// 하위 1차원을 우선 반환한 뒤
	delete[]Q;
	// 상위 1차원을 반환

	// 같은 방법으로, flag 용도로 쓰이던 Line[V][6]도 반환
	
	for (int i = 0; i < V; i++) {
		delete[]Line[i];
	}
	delete[]Line;

	delete[]Name;	// 이름 문자열 배열 반환
}

void GraphbyArray::InputEdge(string N1, string N2) {
	int V1, V2;
	V1 = FindID(N1);
	V2 = FindID(N2);
	// 역 이름에 해당하는 ID 값을 찾기

	if (V1 == -1) {	// 역 이름을 잘못 입력했을 경우
		cout << N1 << "역을 찾지 못했습니다." << endl;
		exit(1);	// 찾지 못했음을 출력하고 종료
	}
	else if (V2 == -1) {
		cout << N2 << "역을 찾지 못했습니다." << endl;
		exit(1);
	}

	InputEdge(V1, V2);	// 찾아낸 ID(숫자)를 통해 간선 추가
}

void GraphbyArray::InputEdge(int V1, int V2) {	// 간선 추가
	// 무방향 그래프이므로 양쪽에 경로를 추가
	Q[V1][V2].connect = true;
	Q[V2][V1].connect = true;

	E++; //간선 갯수 증가
}

int GraphbyArray::FindID(string N) {	// 역 이름으로 ID 찾기
	// Name[]과 입력된 문자열을 비교
	for (int i = 0; i < V; i++) {
		if (N == Name[i])
			return i;
	}
	return -1;	// 못찾았을 경우 -1 반환
}

void GraphbyArray::RoadCheck(string N1, string N2) {
	int V1, V2;
	int Road = -1;	// V1과 V2가 연결된 호선이 몇호선인지 확인하는 변수.
	// -1은 연결된 호선이 없음을 의미
	
	V1 = FindID(N1);	V2 = FindID(N2);	// 각 역의 ID값 찾기

	if ((V1 == -1) || (V2 == -1)) {
		// 역 이름이 잘못 입력된 경우
		cout << N1 << "역 혹은 " << N2 << "역을 찾지 못했습니다.";
		exit(1);
	}

	else if (V1 == V2) {
		// 출발역과 도착역의 이름이 같은 경우
		cout << "두 역이 같습니다. 경로가 존재하지 않습니다." << endl;
		exit(1);
	}

	for (int i = 2; i < 6; i++) {
		if ((Line[V1][i] == true) && (Line[V2][i] == true)) {
			// 두 역 간의 겹치는 호선을 파악. 저장
			Road = i;
			break;
		}
	}

	switch (Road) {
	case -1:
		// Road가 -1이라는 건, 여기까지 진행되면서
		// Road의 값이 변하지 않았다는 의미이다.
		// 즉, 위의 for문에서 출발역과 도착역 사이의
		// 공통된 n호선을 발견하지 못한 것이다.
		cout << "환승이 필요합니다." << endl;
		exit(0);
		break;
	case 2:
		// 이 부분은 잘못된 Case에서 설명
		if (V1 < V2) {
			int tmp = V1;
			V1 = V2;
			V2 = tmp;
		}
	case 3:
	case 4:
	case 5:
		FindRoad(V1, V2, Road);
		break;
	}
}

void GraphbyArray::FindRoad(int V1, int V2, int Num) {
	listClass Road;	// 경로를 저장할 리스트
	bool End = false;	// 탐색 과정을 종료시키는 flag
	bool Block = false;	// 길이 막혔음을 표시하는 flag
	int SearchNode = V1;// 탐색하고 있는 위치를 나타내는 변수
	Line[V1][0] = true;	// 시작 지점은 이미 지나간 것으로 표시
	int ID;	// 리스트에 저장된 역의 ID를 받을 변수. 이를 이용해 Name을 출력함
	int i;

	while (!End) {
		if (SearchNode == V2) {	// 목적지를 찾았을 경우 (탐색지점 == 도착지)
			for (int j = Road.Length(); j > 0; j--) {
				// 현재까지 리스트에 저장한 경로들을 출력
				Road.Retrieve(j, ID);
				cout << Name[ID] << " - ";
			}
			End = true;	// 탐색 과정 종료
		}

		else if (Block == true) { // 목적지에 도달하지 못하고 길이 막혔다면
			Road.Retrieve(1, SearchNode);	// 가장 최근에 탐색한 곳으로 되돌아감.
				Road.Delete(1);
			Block = false;	// Block 신호를 초기화
		}

		else {
			for (i = 0; i < V; i++) {
				if ((Q[SearchNode][i].connect == true) && (Line[i][Num] == true)) {
					// SearchNode부터 Id가 i인 역으로 가는 경로가 존재하고, 그 경로가 Num호선일 경우
					// (Num은 RoadCheck 함수에서 두 역간의 공통 호선의 값을 가짐)
					if (Line[i][0] == false) {	// 역 i를 지나간 적이 없으면
						Line[i][0] = true;		// 그곳을 지나갔음을 표시하고
						Road.Insert(1, SearchNode);	// 현재 위치를 리스트에 추가그
						SearchNode = i;	// 탐색할 노드를 i로 변경
						break;
					}
				}
			}

			if (i == V) {	// 위의 반복문을 지나 이곳에 도달했다는 것은
							// 다음 경로를 찾지 못해 중간에 break로 탈출하지 못했단 의미이므로
				Block = true;// 길이 막혔단 신호를 보내줌.
			}
		}
	} 
	cout << Name[V2] << "입니다." << endl;
}

void GraphbyArray::MetroSetup() {

	// 2호선 역명 입력
	Name[0] = "까치산"; Name[1] = "신정네거리"; Name[2] = "양천구청"; Name[3] = "도림천"; Name[4] = "신도림"; Name[5] = "문래";
	Name[6] = "영등포구청"; Name[7] = "당산"; Name[8] = "합정"; Name[9] = "홍대입구"; Name[10] = "신촌"; Name[11] = "이대";
	Name[12] = "아현";	Name[13] = "충정로"; Name[14] = "시청"; Name[15] = "을지로입구"; Name[16] = "을지로3가";
	Name[17] = "을지로4가"; Name[18] = "동대문역사문화공원"; Name[19] = "신당"; Name[20] = "상왕십리"; Name[21] = "왕십리";
	Name[22] = "한양대"; Name[23] = "뚝섬";	Name[24] = "성수"; Name[25] = "용답"; Name[26] = "신답"; Name[27] = "용두";
	Name[28] = "신설동"; Name[29] = "건대입구"; Name[30] = "구의"; Name[31] = "강변"; Name[32] = "잠실나루"; Name[33] = "잠실";
	Name[34] = "신천"; Name[35] = "종합운동장"; Name[36] = "삼성";	Name[37] = "선릉"; Name[38] = "역삼"; Name[39] = "강남";
	Name[40] = "교대"; Name[41] = "서초"; Name[42] = "방배";	Name[43] = "사당"; Name[44] = "낙성대"; Name[45] = "서울대입구";
	Name[46] = "봉천"; Name[47] = "신림"; Name[48] = "신대방"; Name[49] = "구로디지털단지"; Name[50] = "대림";

	// 3호선 역명 입력
	Name[51] = "대화"; Name[52] = "주엽";	Name[53] = "정발산";	Name[54] = "마두";	Name[55] = "백석";
	Name[56] = "대곡"; Name[57] = "화정";	Name[58] = "원당";	Name[59] = "원흥";	Name[60] = "삼송";
	Name[61] = "지축"; Name[62] = "구파발";	Name[63] = "연신내";	Name[64] = "불광";	Name[65] = "녹번";
	Name[66] = "홍제"; Name[67] = "무악재";	Name[68] = "독립문";//	Name[69] = "무악재";	Name[70] = "독립문"; 실수
	Name[71] = "경복궁"; Name[72] = "안국";	Name[73] = "종로3가"; /*Name[16] = "을지로3가";*/Name[74] = "충무로";
	Name[75] = "동대입구"; Name[76] = "약수";	Name[77] = "금호";	Name[78] = "옥수";	Name[79] = "압구정";
	Name[80] = "신사";	Name[81] = "잠원";	Name[82] = "고속터미널";	/*Name[40] = "교대";*/ Name[83] = "남부터미널";
	Name[84] = "양재";	Name[85] = "매봉";	Name[86] = "도곡";	Name[87] = "대치";	Name[88] = "학여울";
	Name[89] = "대청";	Name[90] = "일원";	Name[91] = "수서";	Name[92] = "가락시장";	Name[93] = "경찰병원"; Name[94] = "오금";

	// 4호선 역명 입력
	Name[95] = "당고개"; Name[96] = "상계";	Name[97] = "노원";	Name[98] = "창동";	Name[99] = "쌍문";
	Name[100] = "수유";	Name[101] = "미아";	Name[102] = "미아사거리"; Name[103] = "길음"; Name[104] = "성신여대입구";
	Name[105] = "한성대입구"; Name[106] = "혜화"; Name[107] = "동대문";	/*Name[18] = "동대문역사문화공원";*/
	/*Name[74] = "충무로";*/	Name[108] = "명동";	Name[109] = "회현";	Name[110] = "서울역";	Name[111] = "숙대입구";
	Name[112] = "삼각지";	Name[113] = "신용산";	Name[114] = "이촌";	Name[115] = "동작";	Name[116] = "총신대입구";
	/*Name[43] = "사당";*/	Name[117] = "남태령"; Name[118] = "선바위";	Name[119] = "경마공원";	Name[120] = "대공원";
	Name[121] = "과천";	Name[122] = "정부과천청사";	Name[123] = "인덕원"; Name[124] = "평촌";	Name[125] = "범계";
	Name[126] = "금정";	Name[127] = "산본";	Name[128] = "수리산";	Name[129] = "대야미";	Name[130] = "반월";
	Name[131] = "상록수";	Name[132] = "한대앞";	Name[133] = "중앙";	Name[134] = "고잔";	Name[135] = "초지";
	Name[136] = "안산";	Name[137] = "신길온천";	Name[138] = "정왕";	Name[139] = "오이도";

	// 5호선 역명 입력
	Name[140] = "방화";	Name[141] = "개화산"; Name[142] = "김포공항";	Name[143] = "송정"; Name[144] = "마곡";
	Name[145] = "발산";	Name[146] = "우장산"; Name[147] = "화곡";	/*Name[0] = "까치산";*/ Name[148] = "신정";
	Name[149] = "목동";	Name[150] = "오목교"; Name[151] = "양평";	/*Name[6] = "영등포구청";*/ Name[152] = "영등포시장";
	Name[153] = "신길";	Name[154] = "여의도"; Name[155] = "여의나루"; Name[156] = "마포"; Name[157] = "공덕";
	Name[158] = "애오개"; /*Name[13] = "충정로";*/ Name[159] = "서대문"; Name[160] = "광화문"; /*Name[73] = "종로3가";*/
	/*Name[17] = "을지로4가";*/ /*Name[18] = "동대문역사문화공원";*/ Name[161] = "청구"; Name[162] = "신금호";
	Name[163] = "행당"; /*Name[21] = "왕십리";*/ Name[164] = "마장"; Name[165] = "답십리"; Name[166] = "장한평";
	Name[167] = "군자"; Name[168] = "아차산"; Name[169] = "광나루";	Name[170] = "천호";	Name[171] = "강동";	// 171=분기점. 172 or 177
	Name[172] = "길동";	Name[173] = "굽은다리";	Name[174] = "명일";	Name[175] = "고덕";	Name[176] = "상일동";
	Name[177] = "둔촌동"; Name[178] = "올림픽공원"; Name[179] = "방이"; /*Name[94] = "오금";*/ Name[180] = "개롱";
	Name[181] = "거여";	Name[182] = "마천";

	// 역간의 간선 추가
	// 2호선
	InputEdge("까치산", "신정네거리");	InputEdge("신정네거리", "양천구청");	InputEdge("양천구청", "도림천");	InputEdge("도림천", "신도림");
	InputEdge("신도림", "문래");	InputEdge("문래", "영등포구청");	InputEdge("영등포구청", "당산");	InputEdge("당산", "합정");
	InputEdge("합정", "홍대입구");	InputEdge("홍대입구", "신촌");	InputEdge("신촌", "이대");	InputEdge("이대", "아현");
	InputEdge("아현", "충정로");	InputEdge("충정로", "시청");	InputEdge("시청", "을지로입구");	InputEdge("을지로입구", "을지로3가");
	InputEdge("을지로3가", "을지로4가");	InputEdge("을지로4가", "동대문역사문화공원");	InputEdge("동대문역사문화공원", "신당");
	InputEdge("신당", "상왕십리");	InputEdge("상왕십리", "왕십리");	InputEdge("왕십리", "한양대");	InputEdge("한양대", "뚝섬");
	InputEdge("뚝섬", "성수");	InputEdge("성수", "용답");	InputEdge("용답", "신답");	InputEdge("신답", "용두");
	InputEdge("용두", "신설동");	InputEdge("성수", "건대입구");	InputEdge("건대입구", "구의");	InputEdge("구의", "강변");
	InputEdge("강변", "잠실나루");	InputEdge("잠실나루", "잠실");	InputEdge("잠실", "신천");	InputEdge("신천", "종합운동장");
	InputEdge("종합운동장", "삼성");	InputEdge("삼성", "선릉");	InputEdge("선릉", "역삼");	InputEdge("역삼", "강남");
	InputEdge("강남", "교대");	InputEdge("교대", "서초");	InputEdge("서초", "방배");	InputEdge("방배", "사당");
	InputEdge("사당", "낙성대");	InputEdge("낙성대", "서울대입구");	InputEdge("서울대입구", "봉천");	InputEdge("봉천", "신림");
	InputEdge("신림", "신대방");	InputEdge("신대방", "구로디지털단지");	InputEdge("구로디지털단지", "대림");	InputEdge("대림", "신도림");
	// 3호선
	InputEdge("대화", "주엽");	InputEdge("주엽", "정발산");	InputEdge("정발산", "마두");	InputEdge("마두", "백석");
	InputEdge("백석", "대곡");	InputEdge("대곡", "화정");	InputEdge("화정", "원당");	InputEdge("원당", "원흥");
	InputEdge("원흥", "삼송");	InputEdge("삼송", "지축");	InputEdge("지축", "구파발");	InputEdge("구파발", "연신내");
	InputEdge("연신내", "불광");	InputEdge("불광", "녹번");	InputEdge("녹번", "홍제");	InputEdge("홍제", "무악재");
	InputEdge("무악재", "독립문");	InputEdge("독립문", "경복궁");	InputEdge("경복궁", "안국");	InputEdge("안국", "종로3가");
	InputEdge("종로3가", "을지로3가");	InputEdge("을지로3가", "충무로");	InputEdge("충무로", "동대입구");	InputEdge("동대입구", "약수");
	InputEdge("약수", "금호");	InputEdge("금호", "옥수");	InputEdge("옥수", "압구정");	InputEdge("압구정", "신사");
	InputEdge("신사", "잠원");	InputEdge("잠원", "고속터미널");	InputEdge("고속터미널", "교대");	InputEdge("교대", "남부터미널");
	InputEdge("남부터미널", "양재");	InputEdge("양재", "매봉");	InputEdge("매봉", "도곡");	InputEdge("도곡", "대치");
	InputEdge("대치", "학여울");	InputEdge("학여울", "대청");	InputEdge("대청", "일원");	InputEdge("일원", "수서");
	InputEdge("수서", "가락시장");	InputEdge("가락시장", "경찰병원"); InputEdge("경찰병원", "오금");
	// 4호선
	InputEdge("당고개", "상계");	InputEdge("상계", "노원");	InputEdge("노원", "창동");	InputEdge("창동", "쌍문");
	InputEdge("쌍문", "수유");	InputEdge("수유", "미아");	InputEdge("미아", "미아사거리");	InputEdge("미아사거리", "길음");
	InputEdge("길음", "성신여대입구");	InputEdge("성신여대입구", "한성대입구");	InputEdge("한성대입구", "혜화");
	InputEdge("혜화", "동대문");	InputEdge("동대문", "동대문역사문화공원");	InputEdge("동대문역사문화공원", "충무로");
	InputEdge("충무로", "명동");	InputEdge("명동", "회현");	InputEdge("회현", "서울역"); InputEdge("서울역", "숙대입구");
	InputEdge("숙대입구", "삼각지");	InputEdge("삼각지", "신용산");	InputEdge("신용산", "이촌");	InputEdge("이촌", "동작");
	InputEdge("동작", "총신대입구");	InputEdge("총신대입구", "사당"); InputEdge("사당", "남태령");	InputEdge("남태령", "선바위");
	InputEdge("선바위", "경마공원");	InputEdge("경마공원", "대공원");	InputEdge("대공원", "과천");	InputEdge("과천", "정부과천청사");
	InputEdge("정부과천청사", "인덕원"); InputEdge("인덕원", "평촌");	InputEdge("평촌", "범계");	InputEdge("범계", "금정");
	InputEdge("금정", "산본");	InputEdge("산본", "수리산");	InputEdge("수리산", "대야미");	InputEdge("대야미", "반월");
	InputEdge("반월", "상록수");	InputEdge("상록수", "한대앞");	InputEdge("한대앞", "중앙");	InputEdge("중앙", "고잔");
	InputEdge("고잔", "초지");	InputEdge("초지", "안산");	InputEdge("안산", "신길온천");	InputEdge("신길온천", "정왕");
	InputEdge("정왕", "오이도");
	// 5호선
	InputEdge("방화", "개화산");	InputEdge("개화산", "김포공항");	InputEdge("김포공항", "송정");	InputEdge("송정", "마곡");
	InputEdge("마곡", "발산");	InputEdge("발산", "우장산");	InputEdge("우장산", "화곡");	InputEdge("화곡", "까치산");
	InputEdge("까치산", "신정");	InputEdge("신정", "목동");	InputEdge("목동", "오목교");	InputEdge("오목교", "양평");
	InputEdge("양평", "영등포구청");	InputEdge("영등포구청", "영등포시장");	InputEdge("영등포시장", "신길");
	InputEdge("신길", "여의도");	InputEdge("여의도", "여의나루");	InputEdge("여의나루", "마포");	InputEdge("마포", "공덕");
	InputEdge("공덕", "애오개");	InputEdge("애오개", "충정로");	InputEdge("충정로", "서대문");	InputEdge("서대문", "광화문");
	InputEdge("광화문", "종로3가");	InputEdge("종로3가", "을지로4가");	InputEdge("을지로4가", "동대문역사문화공원");
	InputEdge("동대문역사문화공원", "청구");	InputEdge("청구", "신금호");	InputEdge("신금호", "행당");
	InputEdge("행당", "왕십리");	InputEdge("왕십리", "마장"); InputEdge("마장", "답십리");	InputEdge("답십리", "장한평");
	InputEdge("장한평", "군자");	InputEdge("군자", "아차산");	InputEdge("아차산", "광나루");	InputEdge("광나루", "천호");
	InputEdge("천호", "강동");	InputEdge("강동", "길동");	InputEdge("길동", "굽은다리"); InputEdge("굽은다리", "명일");
	InputEdge("명일", "고덕");	InputEdge("고덕", "상일동"); InputEdge("강동", "둔촌동"); InputEdge("둔촌동", "올림픽공원");
	InputEdge("올림픽공원", "방이"); InputEdge("방이", "오금");	InputEdge("오금", "개롱");	InputEdge("개롱", "거여");
	InputEdge("거여", "마천");

	// 각 역의 호선 정보 추가.
	for (int i = 0; i < 51; i++)
		Line[i][2] = true;	// ID 0~50은 2호선
	for (int i = 51; i < 95; i++)
		Line[i][3] = true;	// ID 51~94는 3호선
	for (int i = 95; i < 140; i++)
		Line[i][4] = true;	// ID 95~139는 4호선
	for (int i = 140; i < V; i++)
		Line[i][5] = true;	// ID 139~182는 5호선

	// 위에서 추가하지 못한 환승역의 호선 정보를 추가
	Line[0][5] = true;	// 까치산 = 2,5호선
	Line[6][5] = true;	// 영등포구청 = 2,5호선
	Line[13][5] = true;	// 충정로 = 2,5호선
	Line[16][3] = true;	// 을지로3가 = 2,3호선
	Line[17][5] = true;	// 을지로4가 = 2,5호선
	Line[18][4] = true;	Line[18][5] = true;	// 동대문역사문화공원 = 2,4,5호선
	Line[21][5] = true;	// 왕십리 = 2,5호선
	Line[40][3] = true;	// 교대 = 2,3호선
	Line[43][4] = true;	// 사당 = 2,4호선
	Line[73][5] = true;	// 종로3가 = 4,5호선
	Line[74][4] = true;	// 충무로 = 3,4호선
	Line[94][5] = true;	// 오금 = 3,5호선
}
