#ifndef WNUM_H
#define WNUM_H

#include <iostream>
#include <vector>
#include <ctime>
using namespace std;
const int s = 2;

class WNum
{
private:
	int n;
	double slowtime;
	int loser;
	int Old;
	int New;
	vector<double>duration;
	int array[s][s];
	int copied[s][s];
	void copy(int arr[s][s], int[s][s]);
	void change(int[s][s]);
	void random(int[s][s]);
	void print(int[s][s]);
public:
	WNum(int);
	void play();
	int getloser();
	void explain();
};

#endif