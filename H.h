#ifndef H_H
#define H_H
#include <iostream>
#include <vector>

using namespace std;

//·£´ı °õ¼À Ãâ·Â ¹× Á¤´ä ÀúÀå¿ë º¯¼ö

class H {
private:
	int a, b, c; //a´Â ÁÂ°ö, b´Â ¿ì°ö, c´Â a*b
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
