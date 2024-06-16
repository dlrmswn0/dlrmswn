#include "Array.h"

Array::Array(int n,int i) 
:n(n), loser(n),pay(n),money(i) // loser, pay 배열은 생성자를 통해 n개의 인덱스를 가지며 모두 0으로 초기화됨.
{

}


void Array::Count(int m)
{
	loser[m]++; // 입력받은 int 형 변수 m번째 loser 배열 인덱스를 1 더함 . 패배 카운팅
} 

void Array::PrintArray()
{
	for (int i = 1; i < n; i++)
	{
		cout << loser[i] << " ";
	}
} // loser 배열 출력

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
	} //pay 계산

	for (int i = 1; i < n; i++)
	{
		cout << endl << i << "번째 플레이어가 낼 금액:" << pay[i] << "원";
	}//pay 출력

	
}

void Array::Nbbang()
{
	cout <<endl<< "n빵 금액:" << money / (n-1) << "원 입니다.";
}