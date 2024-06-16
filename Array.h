#ifndef Array_H // 반복시 패배자를 저장할 배열 관리 헤더
#define Array_H
#include <iostream>
#include <vector>
using namespace std;

class Array {
private:
	int n;
	vector<int> loser;
	double money;
	vector<double> pay;
public:
	Array(int, int); //인원수를 입력받음, 이후 구현 파일에서 n 크기 loser 배열 초기화
	void Count(int);
	void PrintArray();
	void Calculate();
	void Nbbang();
};
#endif