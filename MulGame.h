#ifndef MULGAME_H
#define MULGAME_H
#include <iostream>
#include <vector>

using namespace std;

//���� ���� ��� �� ���� ����� ����

class MulGame {
private:
	int a, b, c; //a�� �°�, b�� ���, c�� a*b
	int n;
	void p();
	vector<double> t;
	int loser;

public:
	void explain();
	void random();
	MulGame(int);
	int getloser();
	void guessnumber();
};
#endif
