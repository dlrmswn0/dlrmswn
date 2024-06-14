#include "Array.h"

Array::Array(int n) :n(n), loser(n) // loser 배열은 생성자를 통해 n개의 인덱스를 가지며 모두 0으로 초기화됨.
{

}


void Array::Count(int m)
{
	loser[m]++; // 입력받은 int 형 변수 m번째 loser 배열 인덱스를 1 더함 . 패배 카운팅
} 

void Array::PrintArray()
{
	for (int i = 0; i < n; i++)
	{
		cout << loser[i];
	}
} // loser 배열 출력