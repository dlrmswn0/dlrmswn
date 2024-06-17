

#include "Mulgame.h"
#include <ctime>


MulGame::MulGame(int n) :n(n), a(0), b(0), c(0), t(n), loser(0)
{

}

void MulGame::explain() {
    cout << "======능지 차이======" << endl;
    cout << "더 빠르게 곱셈을 수행한 사람이 게임을 승리합니다!" << endl;
}

void MulGame::random()
{
    srand(time(0));
    a = 1 + rand() % 9;
    b = 1 + rand() % 9;
    c = a * b;
}

void MulGame::p()
{
    cout << "문제: " << a << "*" << b << "= ";
}
void MulGame::guessnumber()
{

    int g;

    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << "번 째 플레이어 차례입니다." << endl;
        random();
        bool correct = false;
        double totalReactionTime = 0.0;

        cout << "게임을 시작하려면 Enter 키를 누르세요." << endl;
        cin.ignore(100, '\n'); // 입력 버퍼를 비움
        cin.get(); // Enter 키 입력을 기다림

        while (!correct)
        {
            clock_t start = clock();
            p();
            cin >> g;
            clock_t end = clock();

            double reactionTime = static_cast<double>(end - start) / CLOCKS_PER_SEC;
            t[i] = reactionTime;
            totalReactionTime += reactionTime;

            if (c == g) {
                correct = true;
                t[i] = totalReactionTime;
                cout << "정답! " << " 걸린 시간: " << totalReactionTime << " 초" << endl;
                cout << endl;
            }
            else {
                cout << "틀렸습니다. 다시 시도하세요." << endl;
            }

        }
        if (t[i] > t[loser])
        {
            loser = i;
        }
    } // 반복문끝
    cout << "패배자는 " << loser + 1 << " 번 째 플레이어입니다!" << endl; //추가
}

int MulGame::getloser() {
    return loser;
}