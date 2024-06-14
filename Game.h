#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

const int SIZE = 2;

class Game {
public:
    Game(int players);//�Ű������� �ִ� ������, �ο��� ����.
    void play();
    int getSlowestRun();

private:
    int n;
    double durations[100]; // �ִ� �ο� ���� , 100��
    int slowestRun;
    double slowestTime; //������ ���

    void random_array(int array[SIZE][SIZE], int min_array_index, int max_array_index);
    void print_array(int array[SIZE][SIZE]);
    void copy_array(int source[SIZE][SIZE], int destination[SIZE][SIZE]);
    void change_one_index(int array[SIZE][SIZE], int min_array_index, int max_array_index);// play ��� �Լ����� ����� ���̱� ������ private ���.
    
};

#endif // GAME_H