자바8 람다 표현식
================

자바8은 2014년 3월 18일에 최초 릴리즈 되었으며 자체적으로 함수형 프로그래밍이 가능한 **람다 표현식**이 추가 되었다.

람다 표현식은 parameters -> expression 형식을 갖추고 있으며, 이는 그 자체로써 함수의 기능을 하는 것은 아니다.

람다 표현식은 함수형 인터페이스(Functional Interface)에 기반을 두고 있는데, 함수형 인터페이스란, 인터페이스 내부에 메서드가 단 하나 존재하는 것을 칭한다.

가령 Runnable 인터페이스의 경우 **public void run()**메서드 하나만 가지고 있으므로 Runnable인터페이스는 함수형 인터페이스다.

람다 표현식의 사용 방법은 아래와 같다.

```java
public class Java8{
	public static void main(String[] args){
		java.util.Scanner in = new java.util.Scanner(System.in);

		Sum twoElementsSum = (param1, param2)->param1 + param2;

		System.out.println("Input two operands.");
		int s1 = in.nextInt();
		int s2 = in.nextInt();

		System.out.println(operation(s1, s2, twoElementsSum));
	}
	public static int operation(int x1, int x2, Sum sum){
		return sum.getSum(x1, x2);
	}
}

interface Sum{
	public int getSum(int x1, int x2);
}
```

위 코드에서 알 수 있듯이 람다 표현식은 함수 그 자체를 반환하는 것이 아니라, **함수형 인터페이스를 구현하는 방법**일 뿐이다.
