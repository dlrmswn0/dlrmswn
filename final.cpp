
#include "Repeat.h"

int main()
{
	int p, m, N;

	cout << "인원수 입력:";
	cin >> p;

	cout << "총액 입력:";
	cin >> m;

	cout << "n빵 하시겠습니까? (1: 한다, 2: 안한다)" << endl;
	cin >> N;
	while (N != 1 && N != 2)
	{
		cout << "1또는 2만 입력하세요" << endl;
		cin >> N;
	}

	if (N == 1)
	{
		Array array(p + 1, m);
		array.Nbbang();
		return 0;
	}

	Repeat repeat(p, m);

	if (p == 2)
	{
		repeat.if_two();
	}
	else
	{
		repeat.Else();
	}
}