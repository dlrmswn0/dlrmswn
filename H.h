#ifndef H_H
#define H_H
#include <iostream>
#include <vector>

using namespace std;

//���� ���� ��� �� ���� ����� ����

class H {
private:
	int a, b, c; //a�� �°�, b�� ���, c�� a*b
	int n;
	void p();
	vector<double> t;
	int loser;
	void random();
public:
	H(int);
	int getloser();
	void guessnumber();
};
#endif
