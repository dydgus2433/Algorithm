#include<iostream>
using namespace std;
class Count
{
public:
	Count();
	int Zero;
	int One;
};

Count::Count()
{
	this->Zero = 0;
	this->One = 0;
}



int main()
{
	int a;

	cout << "피보나치를 측정할 배열을 적어주세요 :";
	cin >>a;

	Count *Counts = new Count[a+1];
	
	if (a == 0)
	{
		Counts[0].Zero++;
	}
	else if (a == 1)
	{
		Counts[1].One++;
	}
	else
	{
		Counts[0].Zero++;
		Counts[1].One++;
		for (int i = 2; i <= a; i++)
		{
		
			Counts[i].Zero = Counts[i - 1].Zero + Counts[i - 2].Zero;
			Counts[i].One = Counts[i - 1].One + Counts[i - 2].One;

		}
	}

	cout << Counts[a].Zero << "  " << Counts[a].One << endl;



	
}
