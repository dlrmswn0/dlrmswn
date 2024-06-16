#include "game.h"

Game::Game(int players) : n(players),slowestRun(0),slowestTime(0.0) {
    for (int i = 0; i < 100; ++i) {
        durations[i] = 0.0; // 배열 초기화, duration의 인덱스는 최대 100명의 플레이어의 플레이 시간을 기록함
    }//생성자로 n명의 플레이어를 받고, slowestRun, slowestTime, durations의 인덱스를 0으로 초기화한다.
}

void Game::random_array(int array[SIZE][SIZE], int min_array_index, int max_array_index) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            array[i][j] = rand() % (max_array_index - min_array_index + 1) + min_array_index;
        }
    }
}

void Game::print_array(int array[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            cout << array[i][j] << "\t";
        }
        cout << endl;
    }
}

void Game::copy_array(int source[SIZE][SIZE], int destination[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            destination[i][j] = source[i][j];
        }
    }
}

void Game::change_one_index(int array[SIZE][SIZE], int min_array_index, int max_array_index) {
    int row = rand() % SIZE;
    int col = rand() % SIZE;
    int oldValue = array[row][col];
    int newValue = oldValue;
    while (newValue == oldValue) {
        newValue = rand() % (max_array_index - min_array_index + 1) + min_array_index;
    }
    array[row][col] = newValue;
}

void Game::play() {
    slowestTime = 0.0;
    slowestRun = 0;

    for (int run = 0; run < n; ++run) {
        int originalArray[SIZE][SIZE];
        int modifiedArray[SIZE][SIZE];

        random_array(originalArray, 1, 100);
        copy_array(originalArray, modifiedArray);
        change_one_index(modifiedArray,1,100);

        cout << "Player #" << run + 1 << ": Find the changed number." << endl;

        cout << "Original Array:" << endl;
        print_array(originalArray);

        cout << "\nModified Array (with one number changed):" << endl;
        print_array(modifiedArray);

        auto start = chrono::high_resolution_clock::now(); //현재 시간 측정

        bool found = false;
        while (!found) {
            int guessRow, guessCol;
            cout << "Enter the position of the changed number (row and column, 0-based index): ";
            cin >> guessRow >> guessCol;

            if (guessRow < 0 || guessRow >= SIZE+1 || guessCol < 0 || guessCol >= SIZE+1) {
                cout << "Invalid input. Please try again." << endl;
            }
            else if (originalArray[guessRow-1][guessCol-1] != modifiedArray[guessRow-1][guessCol-1]) {
                cout << "Correct! The changed number is at (" << guessRow << ", " << guessCol << ")." << endl;
                found = true;
            }
            else {
                cout << "Incorrect. Try again." << endl;
            }
        }

        auto end = chrono::high_resolution_clock::now(); // 게임 플레이 후 시간 측정
        chrono::duration<double> elapsedTime = end - start;
        durations[run] = elapsedTime.count();

        if (durations[run] > slowestTime) {
            slowestTime = durations[run];
            slowestRun = run + 1;
        }

        cout << "Time taken for player #" << run + 1 << ": " << durations[run] << " seconds." << endl;
    }

    cout << "\nPlayer #" << slowestRun << " was the slowest with a time of " << slowestTime << " seconds." << endl;
}

int Game::getSlowestRun() {
    return slowestRun; // 게임에서 진 사람을 반환하기 위한 함수, slowestRun을 반환함.
}