#ifndef Array_H // �ݺ��� �й��ڸ� ������ �迭 ���� ���
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
	Array(int, int); //�ο����� �Է¹���, ���� ���� ���Ͽ��� n ũ�� loser �迭 �ʱ�ȭ
	void Count(int);
	void PrintArray();
	void Calculate();
	void Nbbang();
};
#endif