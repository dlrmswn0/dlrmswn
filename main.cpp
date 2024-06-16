#include "Repeat.h"

int main()
{
	cout << "ÀÎ¿ø¼ö ÀÔ·Â:";
	int n;
	cin >> n;
	
	cout << "ÃÑ¾× ÀÔ·Â:";
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
