
#include "Repeat.h"

Repeat::Repeat(int n, int r) :
	Array(n + 1, r), WNum(n), MulGame(n), tictactoe(), YahtzeeGame(n)
{

}

void Repeat::if_two()
{
	cout << "�� ���� �÷��̾�, ��� ���� �÷��̰� �����մϴ�." << endl
		<< "ƽ����, ���� ���̽�, ���� �׽�Ʈ, Ʋ������ã�� ������ ����˴ϴ�." << endl << endl;
	tictactoe::����();

	cout<< "ƽ���並 �� ȸ �÷����Ͻðڽ��ϱ�? :";
	int r;
	cin >> r;

	for (int i = 0; i < r; i++)
	{
		tictactoe::play();
		Array::Count(tictactoe::getloses());
	}
	cout << endl;
	YahtzeeGame::explain();
	cout << "���� ���̽��� �� ȸ �÷����Ͻðڽ��ϱ�? :";
	cin >> r;

	for (int i = 0; i < r; i++) //���� �ݺ�
	{
		YahtzeeGame::initializeGame();
		YahtzeeGame::playGame();
		Array::Count(YahtzeeGame::getloser());
	}
	cout << endl;
	MulGame::explain();
	cout << "���� �׽�Ʈ�� �� ȸ �÷����Ͻðڽ��ϱ�? :";
	cin >> r;

	for (int i = 0; i < r; i++)
	{
		MulGame::guessnumber();
		Array::Count(MulGame::getloser() + 1);
	}
	cout << endl;
	WNum::explain();
	cout << "Ʋ������ã�⸦ �� ȸ �÷����Ͻðڽ��ϱ�? :";
	cin >> r;

	for (int i = 0; i < r; i++)
	{
		WNum::play();
		cout << endl;
		Array::Count(WNum::getloser());
	}

	cout << "�й� Ƚ��" << endl;

	Array::PrintArray();
	cout << endl;

	Array::Calculate();

}

void Repeat::Else()
{
	cout << "�� �� �̻��� �÷��̾�, ƽ���� ������ �÷��� ���ѵ˴ϴ�.." << endl
		<< "���� ����Ʈ : ���� ���̽�, ���� �׽�Ʈ, Ʋ������ã��" << endl;
	cout << endl;
	YahtzeeGame::explain();
	cout << "���� ���̽��� �� ȸ �÷����Ͻðڽ��ϱ�? :";
	int r;
	cin >> r;

	for (int i = 0; i < r; i++) //���� �ݺ�
	{
		YahtzeeGame::initializeGame();
		YahtzeeGame::playGame();
		Array::Count(YahtzeeGame::getloser());
	}
	cout << endl;
	MulGame::explain();
	cout << "���� �׽�Ʈ�� �� ȸ �÷����Ͻðڽ��ϱ�? :";
	cin >> r;

	for (int i = 0; i < r; i++)
	{
		MulGame::guessnumber();
		Array::Count(MulGame::getloser() + 1);
	}
	cout << endl;
	WNum::explain();
	cout << "Ʋ������ã�⸦ �� ȸ �÷����Ͻðڽ��ϱ�? :";
	cin >> r;

	for (int i = 0; i < r; i++)
	{
		WNum::play();
		Array::Count(WNum::getloser());
	}
	Array::Calculate();

}

