#ifndef MULGAME_H
#define MULGAME_H
#include <iostream>
#include <vector>

using namespace std;

//·£´ý °õ¼À Ãâ·Â ¹× Á¤´ä ÀúÀå¿ë º¯¼ö

class MulGame {
private:
	int a, b, c; //a´Â ÁÂ°ö, b´Â ¿ì°ö, c´Â a*b
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
