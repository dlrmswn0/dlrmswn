#include "Game.h"
#include "Array.h"
#include <ctime>
#include <vector>
#include "Y.h"

int main() {
	int n;
	cout << "�ο����Է�:";
	cin >> n;

	Array array(n+1); // 0��° �迭�� ���x 
	YahtzeeGame game(n);
	
	int r;
	cout << endl << "�ݺ��� �Է�";
	cin >> r;

	for (int i = 0; i < r; i++) //���� �ݺ�
	{
		game.initializeGame();
		game.playGame();
		array.Count(game.getloser()); //getSlowestRun�� �й��ڰ� ���° �÷��̾����� ��ȯ�ϴ� ��� �Լ�
	}
	cout << "���� �迭 ���" << endl;
	array.PrintArray(); //���� �迭 ���
}