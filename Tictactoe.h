#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Tic-Tac-Toe ������ ���� Ŭ���� ����
class tictactoe {
private:
    char board[3][3]; // 3x3 ũ���� ���� ����
    int loser;
public:
    // ������: ������ �ʱ�ȭ
    tictactoe();

    // ���带 �ʱ� ���·� �����ϴ� �Լ�
    void resetboard();

    // ���� ���� ���¸� ����ϴ� �Լ�
    void displayboard();

    // ������ �����ϴ� ���� �Լ�
    void play();

    // ���� �÷��̾ �¸��ߴ��� Ȯ���ϴ� �Լ�
    bool checkwin(char player);

    // ������ ���º����� Ȯ���ϴ� �Լ�
    bool checkdraw();

    int getloses();

    void ����();
};

#endif // TICTACTOE_H