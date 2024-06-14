#include "Y.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <numeric>
#include <algorithm>
#include <set>

using namespace std;

YahtzeeGame::YahtzeeGame(int n) :n(n), dice(NUM_DICE), rollCount(0), l(0) {
    srand(time(0));
}

int YahtzeeGame::getloser() {
    return l+1;
}

void YahtzeeGame::initializeGame() {
    cout << "Welcome to 야추!!" << endl;
    cout << "게임의 룰은 간단합니다! " << endl;
    cout << "한턴에 주사위를 총 5개를 굴리는데 점수는 주사위 5개의 눈의 총합입니다. (예 :  5 4 3 2 1 = 15점)" << endl;
    cout << "주사위의 눈이 마음에 안든다면 다시 굴릴 기회를 주는데 한 라운드당 2번 주어집니다.  " << endl;
    cout << "주사위를 다시 굴리는 방법은 다시 굴리고 싶지 않은 주사위의 위치를 입력해주시면 됩니다.  " << endl;
    cout << "(예 : 5 5 1 2 3 일때 1 3 을 입력한다면 첫번째 주사위 눈인 5와 세번쨰 주사위 눈인 1을 제외하고 나머지 주사위들이 다시 돌려집니다.)" << endl;
    cout << "특정 조건을 만족하면 보너스 점수를 받을 수 있습니다.(예 : 5개의 주사위 중 같은 눈의 숫자가 4개)" << endl;
    cout << "총 3라운드의 점수를 합산해서 더 높은 점수를 받은 플레이어가 승리합니다! " << endl;
    cout << "참여할 플레이어의 인원 수를 입력하세요: ";
    players.resize(n);
    scores.resize(n, 0);

    for (int i = 0; i < n; ++i) {
        cout << "플레이어 " << (i + 1) << "의 이름을 입력하세요: ";
        cin >> players[i];
    }
}

void YahtzeeGame::rollDice() {
    for (int i = 0; i < NUM_DICE; ++i) {
        dice[i] = rand() % 6 + 1;
    }
}

void YahtzeeGame::rerollDice(const vector<bool>& keep) {
    for (int i = 0; i < NUM_DICE; ++i) {
        if (!keep[i]) {
            dice[i] = rand() % 6 + 1;
        }
    }
}

void YahtzeeGame::printDice() const {
    for (int i = 0; i < NUM_DICE; ++i) {
        cout << dice[i] << " ";
    }
    cout << endl;
}

int YahtzeeGame::calculateScore() {
    int score = accumulate(dice.begin(), dice.end(), 0);
    return score + bonusPoints();
}

int YahtzeeGame::bonusPoints() {
    vector<int> counts(6, 0);
    for (int i = 0; i < NUM_DICE; ++i) {
        counts[dice[i] - 1]++;
    }

    // All Same: 모든 주사위 눈이 같을 때
    if (*max_element(counts.begin(), counts.end()) == 5) {
        cout << "보너스 점수 60점을 획득했습니다! (All Same)" << endl;
        return 60;
    }

    // Full House: 3개와 2개가 같은 눈일 때
    if (find(counts.begin(), counts.end(), 3) != counts.end() && find(counts.begin(), counts.end(), 2) != counts.end()) {
        cout << "보너스 점수 30점을 획득했습니다! (Full House)" << endl;
        return 30;
    }

    // Four of a Kind: 주사위 눈이 4개 같은 경우 (보너스 점수 30점)
    if (*max_element(counts.begin(), counts.end()) >= 4) {
        cout << "보너스 점수 30점을 획득했습니다! (Four of a Kind)" << endl;
        return 30;
    }

    // Three of a Kind: 주사위 눈이 3개 같은 경우 (보너스 점수 15점)
    if (*max_element(counts.begin(), counts.end()) >= 3) {
        cout << "보너스 점수 15점을 획득했습니다! (Three of a Kind)" << endl;
        return 15;
    }

    return 0;
}

void YahtzeeGame::playRound(int playerIndex) {
    rollCount = 0;
    vector<bool> keep(NUM_DICE, false);

    while (rollCount < 3) {
        if (rollCount > 0) {
            rerollDice(keep);
        }
        else {
            rollDice();
        }
        rollCount++;

        cout << "주사위를 굴렸습니다: ";
        printDice();

        if (rollCount < 3) {
            string choice;
            while (true) {
                cout << "주사위를 다시 굴리시겠습니까? (y/n): ";
                cin >> choice;

                if (choice == "y" || choice == "n") {
                    break;
                }
                else {
                    cout << "잘못된 입력입니다. 'y' 또는 'n'을 입력하세요." << endl;
                }
            }

            if (choice == "n") {
                break;
            }

            cout << "다시 굴리지 않을 주사위의 위치를 입력하세요 (예: 1 2 4): ";
            string input;
            cin.ignore();
            getline(cin, input);

            fill(keep.begin(), keep.end(), false);

            for (char ch : input) {
                if (ch >= '1' && ch <= '5') {
                    keep[ch - '1'] = true;
                }
            }
        }
    }

    int score = calculateScore();
    cout << players[playerIndex] << "의 이 턴의 점수: " << score << endl;
    scores[playerIndex] += score;
}

void YahtzeeGame::printScores() const {
    for (size_t i = 0; i < players.size(); ++i) {
        cout << players[i] << "의 현재 점수: " << scores[i] << endl;
    }
}

void YahtzeeGame::playGame() {
    for (int round = 1; round <= NUM_ROUNDS; ++round) {
        for (size_t i = 0; i < players.size(); ++i) {
            cout << "라운드 " << round << " - " << players[i] << "의 차례입니다." << endl;
            playRound(i);
            printScores();
        }
    }

    cout << "최종 점수" << endl;
    printScores();

    // 승자 판별
    int maxScore = *max_element(scores.begin(), scores.end());
    int minScore = *min_element(scores.begin(), scores.end());
    string winner;
    string loser;

    for (size_t i = 0; i < players.size(); ++i) {
        if (scores[i] == maxScore) {
            winner = players[i];
        }
        if (scores[i] == minScore) {
            loser = players[i];
            l = i; //loser~~~~~~~~~~~~~~~~~~~~~~~
        }
    }

    cout << winner << "가 승리했습니다!" << endl;
    cout << loser << "가 패배했습니다." << endl;
}