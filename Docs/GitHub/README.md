GitHub 사용 설명서
=================

최근들어 초, 중, 고등학교 S/W 교육의 의무화에 따라 IT산업에 바람이 불고 있습니다. 제가 아는 선배도 경영학을 전공하고 미국 보스턴의 대학으로 2년 반동안 공부하고 와서는, IT업계에서 MFC를 이용한 제어 관련 업무를 맡고 있는데, 그만큼 IT업계에서는 수요가 부족하다는 의미입니다.

그렇다고 우리 실력으로 어디 이력서를 내놓을 수 있을까요. IT업계의 인사과에서 한 자리를 차지하는 채용 담당자로서 "수요가 부족하니, 여러분을 대거 채용하겠다"라는 말을 할 것이라고 생각하나요?

아마 그들도 어느정도 판단을 하고 채용을 결정할 것입니다. **간단하게** 이런 조건을 따져 봅시다.

>1. 지금까지 작성한 코드를 확인할 수 있는 개발자 or 없는 개발자
>2. 최신 소프트웨어를 잘 알고 있느 개발자 or 잘 모르는 개발자
>3. 프로그래밍 언어 또는 소프트웨어 세계의 다양한 문화를 이해하고 있는 개발자 or 이해하지 못하는 개발자

여러분이 3년간 모아온 자금으로 스타트업을 시작했다고 가정하고 위 리스트의 후자에 해당하는 사람을 뽑을 의향이 있나요?

저런 사람을 뽑지 않기 위해서, 아니 후자에 해당하는 경우가 되지 않으려면 다른 사람의 코드를 읽고, 공동작업을 하는 소셜코딩 또는 **GitHub**가 중요한 디딤돌이 될 것입니다.

---
**우물 밖으로...**

대학교, 학원에서 교수님, 그리고 선생님들이 알려주는 지식의 정수는 어디 비교할 수 없는 최고의 가이드라인입니다. 그리고 우리는 그 속에서 치열하게 치고 박고 다투며 학점의 노예가 되어 공부를 하죠. 그리고 그 안에서 뭔가를 건진다면 그나마 본전이라도 뽑은 셈입니다.

그렇다면 우리가 도대체 뭘 해야 경쟁력을 갖춰 앞으로 나아갈 수 있을까요?

바로 우물 안에서 벌레들을 잡아먹으며 호화로운 삶을 살고 있다고 생각하는 개구리와 같은 생각을 버리고 우물 밖으로 뛰쳐나가는 것입니다.

8월 29일 **강남역 메리츠 타워 네이버 D2 스타트업 팩토리**에 참여했다가 알고리즘 문제를 제대로 풀어내지 못하고 무거운 발걸음으로 집에 돌아 왔습니다. 그때까지 우리들은 모두 학교에서 알려준 것만 알고 있는 상태였고, 그래도 알고리즘은 자신있다고 생각했는데, 다른 사람들과 비교한 우리가 초라해 보였습니다. 학교에서는 그나마 자신있다고 생각했는데, 막상 밖에서 부딪히니 어찌 손도 못 대보고 끝나고 말았죠.

때문에, 우리는 더 **치밀하게** 준비해야 할 필요가 있습니다.
남들이 모르는 기술이 있다면 알려고 힘쓰고, 남들이 알고있는 기술은 배워서 더더욱 발전시켜야죠.

그러기 위해서 다른 사람들의 방법을 모방을 해야할 필요가 있습니다.(비 상업적으로요.) 그래서 우리는 GitHub를 통해 우리의 코드를 세계에 공유하고, 다른 사람들의 코드를 읽기 위해 Git을 배우고자 합니다.

여기까지 읽으셨다면 아마 Git을 배울 의향이 있는 분이라 생각합니다.
Git에 대한 포스트는 빠르게 진행하진 않습니다.
우선 [CLI환경(Command Line Interface)](https://ko.wikipedia.org/wiki/%EB%AA%85%EB%A0%B9_%EC%A4%84_%EC%9D%B8%ED%84%B0%ED%8E%98%EC%9D%B4%EC%8A%A4)상에서  사용하는 방법을 먼저 작성한 후, [GUI(Graphic User Interface)](https://ko.wikipedia.org/wiki/%EA%B7%B8%EB%9E%98%ED%94%BD_%EC%82%AC%EC%9A%A9%EC%9E%90_%EC%9D%B8%ED%84%B0%ED%8E%98%EC%9D%B4%EC%8A%A4)환경에 대한 설명을 이어나가겠습니다.