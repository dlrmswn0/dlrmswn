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

	srand(static_cast<unsigned int>(time(0))); // 시드 설정
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

		cout << i + 1 << "번 플레이어 차례입니다!" << endl << "다음 두 배열 중 다른 값을 가진 행과 열을 순서대로 입력하세요." << endl << endl;

		print(array);
		cout << endl;
		print(copied);

		int row, col;

		clock_t start = clock();

		do {
			cout << "행과 열을 차례대로 입력하세요 (1에서 4 사이의 값):" << endl;

			cin >> row >> col;
			while (row < 1 || row > 4 || col < 1 || col > 4) {
				cout << "1에서 4 사이의 값을 입력하세요." << endl;
				cin >> row;
				cin >> col;
			}

			if (array[row - 1][col - 1] == copied[row - 1][col - 1]) {
				cout << "틀렸습니다! 다시 입력하세요" << endl;
			}
		} while (array[row - 1][col - 1] == copied[row - 1][col - 1]);

		clock_t end = clock();
		duration[i] = static_cast<double>(end - start) / CLOCKS_PER_SEC;

		cout << "정답입니다!" << endl;
		cout << "소요 시간:" << duration[i] << "초" << endl;

		if (duration[i] > slowtime)
		{
			loser = i;
			slowtime = duration[i];
		}
		
	}

	cout << "패배자는" " " << loser + 1 << "번 플레이어입니다!" << endl;

}

int WNum::getloser()
{
	return loser + 1;
}

void WNum::explain()
{
	cout << "틀린숫자 찾기가 시작되면 두 배열이 주어집니다!" << endl
		<< "두 배열 중 다른 숫자가 하나 있습니다!" << endl
		<< "어떤 숫자가 바뀌었는지 찾아주세요!" << endl;
}