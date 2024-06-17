#include "WNum.h"


WNum::WNum(int n) :n(n), duration(n), loser(0), slowtime(0), New(0), Old(0)
{
	for (int i = 0; i < s; i++)
	{
		for (int j = 0; j < s; j++)
		{
			array[i][j] = 0;
			copied[i][j] = 0;
		}
	}

	srand(static_cast<unsigned int>(time(0))); // �õ� ����
}

void WNum::random(int a[s][s])
{
	for (int i = 0; i < s; i++)
	{
		for (int j = 0; j < s; j++)
		{
			array[i][j] = rand() % 100;
		}
	}
}

void WNum::copy(int a[s][s], int b[s][s])
{
	for (int i = 0; i < s; i++)
	{
		for (int j = 0; j < s; j++)
		{
			b[i][j] = a[i][j];
		}
	}
}

void WNum::print(int a[s][s])
{
	for (int i = 0; i < s; i++)
	{
		for (int j = 0; j < s; j++)
		{
			cout << a[i][j] << "\t";
		}

		cout << endl << endl;

	}
}

void WNum::change(int a[s][s])
{
	int r = rand() % s;
	int c = rand() % s;
	Old = a[r][c];
	New = a[r][c];

	do
	{
		New = rand() % 100;
	} while (Old == New);

	a[r][c] = New;

}


void WNum::play()
{
	slowtime = 0;

	for (int i = 0; i < n; i++)
	{
		random(array);
		copy(array, copied);
		change(copied);

		cout << i + 1 << "�� �÷��̾� �����Դϴ�!" << endl << "���� �� �迭 �� �ٸ� ���� ���� ��� ���� ������� �Է��ϼ���." << endl << endl;

		print(array);
		cout << endl;
		print(copied);

		int row, col;

		clock_t start = clock();

		do {
			cout << "��� ���� ���ʴ�� �Է��ϼ��� (1���� 4 ������ ��):" << endl;

			cin >> row >> col;
			while (row < 1 || row > 4 || col < 1 || col > 4) {
				cout << "1���� 4 ������ ���� �Է��ϼ���." << endl;
				cin >> row;
				cin >> col;
			}

			if (array[row - 1][col - 1] == copied[row - 1][col - 1]) {
				cout << "Ʋ�Ƚ��ϴ�! �ٽ� �Է��ϼ���" << endl;
			}
		} while (array[row - 1][col - 1] == copied[row - 1][col - 1]);

		clock_t end = clock();
		duration[i] = static_cast<double>(end - start) / CLOCKS_PER_SEC;

		cout << "�����Դϴ�!" << endl;
		cout << "�ҿ� �ð�:" << duration[i] << "��" << endl;

		if (duration[i] > slowtime)
		{
			loser = i;
			slowtime = duration[i];
		}
		
	}

	cout << "�й��ڴ�" " " << loser + 1 << "�� �÷��̾��Դϴ�!" << endl;

}

int WNum::getloser()
{
	return loser + 1;
}

void WNum::explain()
{
	cout << "Ʋ������ ã�Ⱑ ���۵Ǹ� �� �迭�� �־����ϴ�!" << endl
		<< "�� �迭 �� �ٸ� ���ڰ� �ϳ� �ֽ��ϴ�!" << endl
		<< "� ���ڰ� �ٲ������ ã���ּ���!" << endl;
}