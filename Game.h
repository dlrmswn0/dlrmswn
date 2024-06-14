#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

const int SIZE = 2;

class Game {
public:
    Game(int players);//매개변수가 있는 생성자, 인원을 받음.
    void play();
    int getSlowestRun();

private:
    int n;
    double durations[100]; // 최대 인원 설정 , 100명
    int slowestRun;
    double slowestTime; //데이터 멤버

    void random_array(int array[SIZE][SIZE], int min_array_index, int max_array_index);
    void print_array(int array[SIZE][SIZE]);
    void copy_array(int source[SIZE][SIZE], int destination[SIZE][SIZE]);
    void change_one_index(int array[SIZE][SIZE], int min_array_index, int max_array_index);// play 멤버 함수에서 사용할 것이기 때문에 private 사용.
    
};

#endif // GAME_H