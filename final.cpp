#include "Repeat.h"

int main()
{
	cout << "�ο��� �Է�:";
	int n;
	cin >> n;
	
	cout << "�Ѿ� �Է�:";
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