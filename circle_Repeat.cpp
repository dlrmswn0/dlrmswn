#include "Repeat.h"

Repeat::Repeat(int n,int r):
	Array(n+1,r),WNum(n),H(n),tictactoe(),YahtzeeGame(n)
{

}

void Repeat::if_two()
{
	cout << "�� ���� �÷��̾�, ��� ���� �÷��̰� �����մϴ�." << endl
		<< "���� ����Ʈ : ƽ����, ���� ���̽�, ���� �׽�Ʈ, Ʋ������ã��" << endl
		<< "ƽ���並 �� ȸ �÷����Ͻðڽ��ϱ�? :";
	int r;
	cin >> r;

	for (int i = 0; i < r; i++)
	{
		tictactoe::play();
		Array::Count(tictactoe::getloses());
	}

	cout << "���� ���̽��� �� ȸ �÷����Ͻðڽ��ϱ�? :";
	cin >> r;

	for (int i = 0; i < r; i++) //���� �ݺ�
	{
		YahtzeeGame::initializeGame();
		YahtzeeGame::playGame();
		Array::Count(YahtzeeGame::getloser());
	}

	cout << "���� �׽�Ʈ�� �� ȸ �÷����Ͻðڽ��ϱ�? :";
	cin >> r;

	for (int i = 0; i < r;i++)
	{
		H::guessnumber();
		Array::Count(H::getloser() + 1);
	}

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

	cout << "���� ���̽��� �� ȸ �÷����Ͻðڽ��ϱ�? :";
	int r;
	cin >> r;

	for (int i = 0; i < r; i++) //���� �ݺ�
	{
		YahtzeeGame::initializeGame();
		YahtzeeGame::playGame();
		Array::Count(YahtzeeGame::getloser());
	}

	cout << "���� �׽�Ʈ�� �� ȸ �÷����Ͻðڽ��ϱ�? :";
	cin >> r;

	for (int i = 0; i < r; i++)
	{
		H::guessnumber();
		Array::Count(H::getloser() + 1);
	}

	cout << "Ʋ������ã�⸦ �� ȸ �÷����Ͻðڽ��ϱ�? :";
	cin >> r;

	for (int i = 0; i < r; i++)
	{
		WNum::play();
		Array::Count(WNum::getloser());
	}
	Array::Calculate();

}

