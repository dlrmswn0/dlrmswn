#include "Game.h"
#include "Array.h"
#include <ctime>
#include <vector>

int main() {
	int n;
	cout << "인원수입력:";
	cin >> n;

	Array array(n+1); // 0번째 배열은 사용x 
	Game game(n);
	
	int r;
	cout << endl << "반복수 입력";
	cin >> r;

	for (int i = 0; i < r; i++) //게임 반복
	{
		game.play();
		array.Count(game.getSlowestRun()); //getSlowestRun은 패배자가 몇번째 플레이어인지 반환하는 멤버 함수
	}
	cout << "패자 배열 출력" << endl;
	array.PrintArray(); //최종 배열 출력
}