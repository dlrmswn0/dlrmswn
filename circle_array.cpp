#include "Array.h"

Array::Array(int n,int i) 
:n(n), loser(n),pay(n),money(i) // loser, pay �迭�� �����ڸ� ���� n���� �ε����� ������ ��� 0���� �ʱ�ȭ��.
{

}


void Array::Count(int m)
{
	loser[m]++; // �Է¹��� int �� ���� m��° loser �迭 �ε����� 1 ���� . �й� ī����
} 

void Array::PrintArray()
{
	for (int i = 1; i < n; i++)
	{
		cout << loser[i] << " ";
	}
} // loser �迭 ���

void Array::Calculate()
{
	double total=0;
	for (int i = 1; i < n; i++)
	{
		total += loser[i];
	}
	
	for (int i = 1; i < n; i++)
	{
		pay[i] = (loser[i] / total) * money;
	} //pay ���

	for (int i = 1; i < n; i++)
	{
		cout << endl << i << "��° �÷��̾ �� �ݾ�:" << pay[i] << "��";
	}//pay ���

	
}

void Array::Nbbang()
{
	cout <<endl<< "n�� �ݾ�:" << money / (n-1) << "�� �Դϴ�.";
}