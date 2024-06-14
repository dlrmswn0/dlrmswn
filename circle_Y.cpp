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
    cout << "Welcome to ����!!" << endl;
    cout << "������ ���� �����մϴ�! " << endl;
    cout << "���Ͽ� �ֻ����� �� 5���� �����µ� ������ �ֻ��� 5���� ���� �����Դϴ�. (�� :  5 4 3 2 1 = 15��)" << endl;
    cout << "�ֻ����� ���� ������ �ȵ�ٸ� �ٽ� ���� ��ȸ�� �ִµ� �� ����� 2�� �־����ϴ�.  " << endl;
    cout << "�ֻ����� �ٽ� ������ ����� �ٽ� ������ ���� ���� �ֻ����� ��ġ�� �Է����ֽø� �˴ϴ�.  " << endl;
    cout << "(�� : 5 5 1 2 3 �϶� 1 3 �� �Է��Ѵٸ� ù��° �ֻ��� ���� 5�� ������ �ֻ��� ���� 1�� �����ϰ� ������ �ֻ������� �ٽ� �������ϴ�.)" << endl;
    cout << "Ư�� ������ �����ϸ� ���ʽ� ������ ���� �� �ֽ��ϴ�.(�� : 5���� �ֻ��� �� ���� ���� ���ڰ� 4��)" << endl;
    cout << "�� 3������ ������ �ջ��ؼ� �� ���� ������ ���� �÷��̾ �¸��մϴ�! " << endl;
    cout << "������ �÷��̾��� �ο� ���� �Է��ϼ���: ";
    players.resize(n);
    scores.resize(n, 0);

    for (int i = 0; i < n; ++i) {
        cout << "�÷��̾� " << (i + 1) << "�� �̸��� �Է��ϼ���: ";
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

    // All Same: ��� �ֻ��� ���� ���� ��
    if (*max_element(counts.begin(), counts.end()) == 5) {
        cout << "���ʽ� ���� 60���� ȹ���߽��ϴ�! (All Same)" << endl;
        return 60;
    }

    // Full House: 3���� 2���� ���� ���� ��
    if (find(counts.begin(), counts.end(), 3) != counts.end() && find(counts.begin(), counts.end(), 2) != counts.end()) {
        cout << "���ʽ� ���� 30���� ȹ���߽��ϴ�! (Full House)" << endl;
        return 30;
    }

    // Four of a Kind: �ֻ��� ���� 4�� ���� ��� (���ʽ� ���� 30��)
    if (*max_element(counts.begin(), counts.end()) >= 4) {
        cout << "���ʽ� ���� 30���� ȹ���߽��ϴ�! (Four of a Kind)" << endl;
        return 30;
    }

    // Three of a Kind: �ֻ��� ���� 3�� ���� ��� (���ʽ� ���� 15��)
    if (*max_element(counts.begin(), counts.end()) >= 3) {
        cout << "���ʽ� ���� 15���� ȹ���߽��ϴ�! (Three of a Kind)" << endl;
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

        cout << "�ֻ����� ���Ƚ��ϴ�: ";
        printDice();

        if (rollCount < 3) {
            string choice;
            while (true) {
                cout << "�ֻ����� �ٽ� �����ðڽ��ϱ�? (y/n): ";
                cin >> choice;

                if (choice == "y" || choice == "n") {
                    break;
                }
                else {
                    cout << "�߸��� �Է��Դϴ�. 'y' �Ǵ� 'n'�� �Է��ϼ���." << endl;
                }
            }

            if (choice == "n") {
                break;
            }

            cout << "�ٽ� ������ ���� �ֻ����� ��ġ�� �Է��ϼ��� (��: 1 2 4): ";
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
    cout << players[playerIndex] << "�� �� ���� ����: " << score << endl;
    scores[playerIndex] += score;
}

void YahtzeeGame::printScores() const {
    for (size_t i = 0; i < players.size(); ++i) {
        cout << players[i] << "�� ���� ����: " << scores[i] << endl;
    }
}

void YahtzeeGame::playGame() {
    for (int round = 1; round <= NUM_ROUNDS; ++round) {
        for (size_t i = 0; i < players.size(); ++i) {
            cout << "���� " << round << " - " << players[i] << "�� �����Դϴ�." << endl;
            playRound(i);
            printScores();
        }
    }

    cout << "���� ����" << endl;
    printScores();

    // ���� �Ǻ�
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

    cout << winner << "�� �¸��߽��ϴ�!" << endl;
    cout << loser << "�� �й��߽��ϴ�." << endl;
}