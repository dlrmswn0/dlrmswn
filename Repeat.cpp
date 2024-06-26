
#include "Repeat.h"

Repeat::Repeat(int n, int r) :
	Array(n + 1, r), WNum(n), MulGame(n), tictactoe(), YahtzeeGame(n)
{

}

void Repeat::if_two()
{
	cout << "두 명의 플레이어, 모든 게임 플레이가 가능합니다." << endl
		<< "틱택토, 야추 다이스, 지능 테스트, 틀린숫자찾기 순서로 실행됩니다." << endl << endl;
	tictactoe::설명();

	cout<< "틱택토를 몇 회 플레이하시겠습니까? :";
	int r;
	cin >> r;

	for (int i = 0; i < r; i++)
	{
		tictactoe::play();
		Array::Count(tictactoe::getloses());
	}
	cout << endl;
	YahtzeeGame::explain();
	cout << "야추 다이스를 몇 회 플레이하시겠습니까? :";
	cin >> r;

	for (int i = 0; i < r; i++) //게임 반복
	{
		YahtzeeGame::initializeGame();
		YahtzeeGame::playGame();
		Array::Count(YahtzeeGame::getloser());
	}
	cout << endl;
	MulGame::explain();
	cout << "지능 테스트를 몇 회 플레이하시겠습니까? :";
	cin >> r;

	for (int i = 0; i < r; i++)
	{
		MulGame::guessnumber();
		Array::Count(MulGame::getloser() + 1);
	}
	cout << endl;
	WNum::explain();
	cout << "틀린숫자찾기를 몇 회 플레이하시겠습니까? :";
	cin >> r;

	for (int i = 0; i < r; i++)
	{
		WNum::play();
		cout << endl;
		Array::Count(WNum::getloser());
	}

	cout << "패배 횟수" << endl;

	Array::PrintArray();
	cout << endl;

	Array::Calculate();

}

void Repeat::Else()
{
	cout << "두 명 이상의 플레이어, 틱택토 게임은 플레이 제한됩니다.." << endl
		<< "게임 리스트 : 야추 다이스, 지능 테스트, 틀린숫자찾기" << endl;
	cout << endl;
	YahtzeeGame::explain();
	cout << "야추 다이스를 몇 회 플레이하시겠습니까? :";
	int r;
	cin >> r;

	for (int i = 0; i < r; i++) //게임 반복
	{
		YahtzeeGame::initializeGame();
		YahtzeeGame::playGame();
		Array::Count(YahtzeeGame::getloser());
	}
	cout << endl;
	MulGame::explain();
	cout << "지능 테스트를 몇 회 플레이하시겠습니까? :";
	cin >> r;

	for (int i = 0; i < r; i++)
	{
		MulGame::guessnumber();
		Array::Count(MulGame::getloser() + 1);
	}
	cout << endl;
	WNum::explain();
	cout << "틀린숫자찾기를 몇 회 플레이하시겠습니까? :";
	cin >> r;

	for (int i = 0; i < r; i++)
	{
		WNum::play();
		Array::Count(WNum::getloser());
	}
	Array::Calculate();

}

