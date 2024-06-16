// tictactoe.cpp
#include "Tictactoe.h"

// 생성자: 게임을 초기화
tictactoe::tictactoe() : loser(0)
{
    resetboard();
}

int tictactoe::getloses()
{
    return loser;
}

// 보드를 초기 상태로 리셋하는 함수
void tictactoe::resetboard() {
    int k = 1;
    // 보드의 각 위치에 1부터 9까지 숫자 할당
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = '0' + k++; // 정수를 문자로 변환
        }
    }
}

// 현재 보드 상태를 출력하는 함수
void tictactoe::displayboard() {
    cout << "player 1 [x]  player 2 [o]\n\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << "  " << board[i][j]; // 각 보드 칸을 출력
            if (j < 2) cout << "  |";  // 열 사이의 구분선 출력
        }
        cout << endl;
        if (i < 2) cout << "_____|_____|_____\n"; // 행 사이의 구분선 출력
    }
    cout << endl;
}

// 게임을 진행하는 메인 함수
void tictactoe::play() {
    char turn = 'x'; // 현재 차례를 나타내는 변수 ('x' 또는 'o')
    int number; // 선택한 칸의 번호를 저장할 변수
    bool draw; // 게임 계속 여부를 확인하는 변수

    
        draw = true; // 처음엔 게임을 계속한다고 가정
        resetboard(); // 게임 시작 시 보드를 초기화
        while (true) {
            displayboard(); // 보드를 화면에 출력
            cout << "player " << (turn == 'x' ? '1' : '2') << " [" << turn << "] turn: ";
            cin >> number; // 칸 번호를 입력받음

            // 입력이 유효한지 확인
            if (number < 1 || number > 9) {
                cout << "invalid move, try again.\n";
                continue;
            }

            number--; // 0부터 시작하는 인덱스로 변환
            int row = number / 3; // 행 인덱스 계산
            int col = number % 3; // 열 인덱스 계산

            // 선택한 칸이 이미 차있으면
            if (board[row][col] == 'x' || board[row][col] == 'o') {
                cout << "invalid move, try again.\n";
                continue;
            }

            board[row][col] = turn; // 현재 플레이어의 기호로 보드에 표시
            if (checkwin(turn)) { // 현재 플레이어가 승리했는지 확인
                displayboard();
                cout << "player " << (turn == 'x' ? '1' : '2') << " [" << turn << "] wins!\n";
                if (turn == 'x') loser=2; // 플레이어 1의 승리 횟수 증가
                else loser=1; // 플레이어 2의 승리 횟수 증가
                break;
            }

            if (checkdraw()) { // 무승부인지 확인
                displayboard();
                cout << "it's a draw!\n";
                break;
            }

            // 차례 변경
            turn = (turn == 'x') ? 'o' : 'x';
        }

        
}

// 현재 플레이어가 승리했는지 확인하는 함수
bool tictactoe::checkwin(char player) {
    // 행과 열을 확인
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) return true;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) return true;
    }
    // 대각선을 확인
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) return true;
    return false;
}

// 게임이 무승부인지 확인하는 함수
bool tictactoe::checkdraw() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'x' && board[i][j] != 'o')
                return false; // 비어 있는 칸이 있으면 무승부가 아님
        }
    }
    return true; // 모든 칸이 채워지고 승자가 없으면 무승부
}

