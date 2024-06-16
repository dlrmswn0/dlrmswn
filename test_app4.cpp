//틀린숫자찾기 밑 야추 선택반복
#include "Game.h"
#include "Array.h"
#include <ctime>
#include <vector>
#include "Y.h"

int main() {
	int n;
	cout << "인원수입력:";
	cin >> n;

	int m;
	cout << "금액 입력:";
	cin >> m;

	Array array(n+1,m); // 0번째 배열은 사용x 
	YahtzeeGame game(n);
	Game game1(n); // 객체 생성

	int r;
	cout << endl << "야추 반복수 입력:";
	cin >> r;

	for (int i = 0; i < r; i++) //게임 반복
	{
		game.initializeGame();
		game.playGame();
		array.Count(game.getloser()); //getSlowestRun은 패배자가 몇번째 플레이어인지 반환하는 멤버 함수
	}

	cout << endl << "틀린숫자찾기 반복수 입력:";
	cin >> r;
	for (int i = 0; i < r; i++)
	{
		game1.play();
		array.Count(game1.getSlowestRun());
	}
	cout << "패자 배열 출력" << endl;

	array.PrintArray(); //최종 배열 출력
	array.Calculate(); //낼돈 계산
	array.Nbbang();
}
