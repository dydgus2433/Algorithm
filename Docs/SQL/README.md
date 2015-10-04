SQLite
======

#### 쿼리 문법

##### 테이블 생성
> **create table board(id integer, name text, age integer);**  
> 
> > id|name|age
> > :-:|:-:|:-:
> 
> **create table:** 새로운 테이블을 생성한다.  
> **board:** 테이블의 이름  
> **id, name, age**   
> **integer, text, real**: 정수형, 문자형, 실수형  

##### 테이블에 레코드 추가
> **insert into** board **values (1, "Kim", 23);**  
> **insert into** board **values (2, "Park", 23);**  
> **insert into** board(id, name, age) **values (3, "Choi", 23);**  
> > id|name|age
> > :-:|:-:|:-:
> > 1|Kim|23
> > 2|Park|23
> > 3|Choi|23
> > *테이블이 DB에 생성된 상태*
>  
> **insert into:** 테이블에 레코드(row) 추가  
> **board:** 테이블의 이름  
> *테이블의 이름과, 필드(column) 이름을 지정할 수 있다.  
> **values:** 테이블에 추가할 각 레코드의 값.  

##### 테이블의 레코드 쿼리
> **select \* from board;**  
> > id|name|age  
> > :-:|:-:|:-:
> > 1|Kim|23
> > 2|Park|23
> > 3|Choi|23
> > *DB에 생성된 데이터를 가져온 결과*  
> 
> **select:** 쿼리할 데이터  
> **from:** 데이터를 가져올 테이블  
> 
> ---
> **\*필드 지정 방법**  
> **select name, agd** from board;  
> > name|age  
> > :-:|:-:
> > Kim|23
> > Park|23
> > Choi|23


##### 테이블 필드(column) 추가
> **alter table** board **add column e_mail text;**  
> select * from board;  
> > id|name|age|e_mail  
> > :-:|:-:|:-:|:-:
> > 1|Kim|23
> > 2|Park|23
> > 3|Choi|23
> 
> insert into board values(4, "Wang", 27, "Wang123@gmail.com");  
> select * from board;  
> > id|name|age|e_mail
> > :-:|:-:|:-:|:-:
> > 1|Kim|23
> > 2|Park|23
> > 3|Choi|23
> > 4|Wang|27|Wang123@gmail.com

##### 조건 추가하기
> Select \* from board **where name is "Choi"**;  
> > id|name|age|e_mail
> > :-:|:-:|:-:|:-:
> > 3|Choi|23
> 
> **where:** 필드 명, 조건 식, 값, [관계 식, 필드 명, 조건 식, 값], [...]  
> *조건식* : **=(is), !=(is not), >, <, >=, >=**   
> 
> ---
> Select \* from board **where age >= 24**;  
> > id|name|age|e_mail
> > :-:|:-:|:-:|:-:
> > 4|Wang|27|Wnag123@gmail.com
> 
> ---
> Select \* from board **where e_mail is not NULL**;  
> > id|name|age|e_mail
> > :-:|:-:|:-:|:-:
> > 1|Kim|23
> > 2|Park|23
> > 3|Choi|23
> 
> ---
> Select \* from board **where e_mail is NULL**;  
> > id|name|age|e_mail
> > :-:|:-:|:-:|:-:
> > 4|Wang|27|Wang123@gmail.com

##### select 중복 값 필터링 distinct
> insert board values(5, "Kim", 24, NULL);  
> insert board values(6, "Park", 22, NULL);  
> select **distinct name** from board;  
> > name|
> > :-:|
> > Kim|
> > Park|
> > Choi|
> > Wang|
> 
> distinct 뒤에서 comma(,)로 구분하면 모두 필터링 된다.  

##### 레코드 삭제하기
> **delete from** board where e_mail is not NULL;  
> select \* from board;  
> > id|name|age|e_mail
> > :-:|:-:|:-:|:-:
> > 4|Wang|27|Wang123@gmail.com
> 

##### where 강화, like
> insert into board values (1, "Kim", 23, NULL);  
> insert into board values (2, "Kang", 23, NULL);  
> insert into board values (3, "Choi", 23, NULL);  
> 
> select \* from board where name **like "K%"**;  
> > id|name|age|e_mail
> > :-:|:-:|:-:|:-:
> > 1|Kim|23
> > 2|Kang|23
> 
> select \* from board where name **like "__ng"**;  
> > id|name|age|e_mail
> > :-:|:-:|:-:|:-:
> > 4|Wang|27|Wang123@gmail.com
> > 2|Kang|23
> 
> **like:** where 문 뒤에 위치한다.    
> > **k%:** k로 시작하는 문자  
> > **%k:** k로 끝나는 문자  
> > **%k%:** k가 포함된 문자(K로 시작, k로 종결 포함)  
> > **_k:** 와일드 카드 문자 1개를 포함하며 k로 끝나는 두 글자 문자  

##### where 강화, between
> update board  
> set age = 24  
> where id between 2 and 4;  
> 
> > id|name|age|e_mail
> > :-:|:-:|:-:|:-:
> > 4|Wnag|27|Wang123@gmail.com
> > 1|Kim|23
> > 2|Kang|24
> > 3|Choi|24
> 
> **between** SRC **and** DES: **SRC <= values <= Des**  

##### where 복합
> select \* from board **where age between 23 and 24 and name is "Kang"**;  
> > id|name|age|e_mail
> > :-:|:-:|:-:|:-:
> > 2|Kang|24
> 
> ---
> select \* from board **where age between 23 and 24 or name is "Wang"**;  
> > id|name|age|e_mail
> > :-:|:-:|:-:|:-:
> > 4|Wnag|27|Wang123@gmail.com
> > 1|Kim|23
> > 2|Kang|24
> > 3|Choi|24

##### 정렬
> select * from board **order by id asc**;  
>
> > id|name|age|e_mail
> > :-:|:-:|:-:|:-:
> > 1|Kim|23
> > 2|Kang|24
> > 3|Choi|24
> > 4|Wnag|27|Wang123@gmail.com
> 
> **desc:** 오름차순 정렬 
> ---
> select * from board **order by id desc**;  
> > id|name|age|e_mail
> > :-:|:-:|:-:|:-:
> > 4|Wnag|27|Wang123@gmail.com
> > 3|Choi|24
> > 2|Kang|24
> > 1|Kim|23
> **asc: ** 내림차순 정렬  

##### 쿼리 갯수 제한
> select * from board  
> order by id asc  
> **limit 2**;
> > id|name|age|e_mail
> > :-:|:-:|:-:|:-:
> > 1|Kim|23
> > 2|Kang|24
