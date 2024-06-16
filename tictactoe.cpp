// tictactoe.cpp
#include "Tictactoe.h"

// ������: ������ �ʱ�ȭ
tictactoe::tictactoe() : loser(0)
{
    resetboard();
}

int tictactoe::getloses()
{
    return loser;
}

// ���带 �ʱ� ���·� �����ϴ� �Լ�
void tictactoe::resetboard() {
    int k = 1;
    // ������ �� ��ġ�� 1���� 9���� ���� �Ҵ�
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = '0' + k++; // ������ ���ڷ� ��ȯ
        }
    }
}

// ���� ���� ���¸� ����ϴ� �Լ�
void tictactoe::displayboard() {
    cout << "player 1 [x]  player 2 [o]\n\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << "  " << board[i][j]; // �� ���� ĭ�� ���
            if (j < 2) cout << "  |";  // �� ������ ���м� ���
        }
        cout << endl;
        if (i < 2) cout << "_____|_____|_____\n"; // �� ������ ���м� ���
    }
    cout << endl;
}

// ������ �����ϴ� ���� �Լ�
void tictactoe::play() {
    char turn = 'x'; // ���� ���ʸ� ��Ÿ���� ���� ('x' �Ǵ� 'o')
    int number; // ������ ĭ�� ��ȣ�� ������ ����
    bool draw; // ���� ��� ���θ� Ȯ���ϴ� ����

    
        draw = true; // ó���� ������ ����Ѵٰ� ����
        resetboard(); // ���� ���� �� ���带 �ʱ�ȭ
        while (true) {
            displayboard(); // ���带 ȭ�鿡 ���
            cout << "player " << (turn == 'x' ? '1' : '2') << " [" << turn << "] turn: ";
            cin >> number; // ĭ ��ȣ�� �Է¹���

            // �Է��� ��ȿ���� Ȯ��
            if (number < 1 || number > 9) {
                cout << "invalid move, try again.\n";
                continue;
            }

            number--; // 0���� �����ϴ� �ε����� ��ȯ
            int row = number / 3; // �� �ε��� ���
            int col = number % 3; // �� �ε��� ���

            // ������ ĭ�� �̹� ��������
            if (board[row][col] == 'x' || board[row][col] == 'o') {
                cout << "invalid move, try again.\n";
                continue;
            }

            board[row][col] = turn; // ���� �÷��̾��� ��ȣ�� ���忡 ǥ��
            if (checkwin(turn)) { // ���� �÷��̾ �¸��ߴ��� Ȯ��
                displayboard();
                cout << "player " << (turn == 'x' ? '1' : '2') << " [" << turn << "] wins!\n";
                if (turn == 'x') loser=2; // �÷��̾� 1�� �¸� Ƚ�� ����
                else loser=1; // �÷��̾� 2�� �¸� Ƚ�� ����
                break;
            }

            if (checkdraw()) { // ���º����� Ȯ��
                displayboard();
                cout << "it's a draw!\n";
                break;
            }

            // ���� ����
            turn = (turn == 'x') ? 'o' : 'x';
        }

        
}

// ���� �÷��̾ �¸��ߴ��� Ȯ���ϴ� �Լ�
bool tictactoe::checkwin(char player) {
    // ��� ���� Ȯ��
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) return true;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) return true;
    }
    // �밢���� Ȯ��
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) return true;
    return false;
}

// ������ ���º����� Ȯ���ϴ� �Լ�
bool tictactoe::checkdraw() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'x' && board[i][j] != 'o')
                return false; // ��� �ִ� ĭ�� ������ ���ºΰ� �ƴ�
        }
    }
    return true; // ��� ĭ�� ä������ ���ڰ� ������ ���º�
}

