#include "Array.h"

Array::Array(int n) :n(n), loser(n) // loser �迭�� �����ڸ� ���� n���� �ε����� ������ ��� 0���� �ʱ�ȭ��.
{

}


void Array::Count(int m)
{
	loser[m]++; // �Է¹��� int �� ���� m��° loser �迭 �ε����� 1 ���� . �й� ī����
} 

void Array::PrintArray()
{
	for (int i = 0; i < n; i++)
	{
		cout << loser[i];
	}
} // loser �迭 ���