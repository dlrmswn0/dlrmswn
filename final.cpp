
#include "Repeat.h"

int main()
{
	int p, m, N;

	cout << "�ο��� �Է�:";
	cin >> p;

	cout << "�Ѿ� �Է�:";
	cin >> m;

	cout << "n�� �Ͻðڽ��ϱ�? (1: �Ѵ�, 2: ���Ѵ�)" << endl;
	cin >> N;
	while (N != 1 && N != 2)
	{
		cout << "1�Ǵ� 2�� �Է��ϼ���" << endl;
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