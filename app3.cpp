#include "Game.h"
#include "Array.h"
#include <ctime>
#include <vector>

int main() {
	int n;
	cout << "�ο����Է�:";
	cin >> n;

	Array array(n+1); // 0��° �迭�� ���x 
	Game game(n);
	
	int r;
	cout << endl << "�ݺ��� �Է�";
	cin >> r;

	for (int i = 0; i < r; i++) //���� �ݺ�
	{
		game.play();
		array.Count(game.getSlowestRun()); //getSlowestRun�� �й��ڰ� ���° �÷��̾����� ��ȯ�ϴ� ��� �Լ�
	}
	cout << "���� �迭 ���" << endl;
	array.PrintArray(); //���� �迭 ���
}