#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Tic-Tac-Toe 게임을 위한 클래스 정의
class tictactoe {
private:
    char board[3][3]; // 3x3 크기의 게임 보드
    int loser;
public:
    // 생성자: 게임을 초기화
    tictactoe();

    // 보드를 초기 상태로 리셋하는 함수
    void resetboard();

    // 현재 보드 상태를 출력하는 함수
    void displayboard();

    // 게임을 진행하는 메인 함수
    void play();

    // 현재 플레이어가 승리했는지 확인하는 함수
    bool checkwin(char player);

    // 게임이 무승부인지 확인하는 함수
    bool checkdraw();

    int getloses();

    void 설명();
};

#endif // TICTACTOE_H