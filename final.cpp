#include "Repeat.h"

int main()
{
	cout << "인원수 입력:";
	int n;
	cin >> n;
	
	cout << "총액 입력:";
	int m;
	cin >> m;

	Repeat repeat(n, m);

	if (n == 2)
	{
		repeat.if_two();
	}
	else
	{
		repeat.all();
	}
}