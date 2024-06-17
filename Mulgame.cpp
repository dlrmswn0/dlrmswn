

#include "Mulgame.h"
#include <ctime>


MulGame::MulGame(int n) :n(n), a(0), b(0), c(0), t(n), loser(0)
{

}

void MulGame::explain() {
    cout << "======���� ����======" << endl;
    cout << "�� ������ ������ ������ ����� ������ �¸��մϴ�!" << endl;
}

void MulGame::random()
{
    srand(time(0));
    a = 1 + rand() % 9;
    b = 1 + rand() % 9;
    c = a * b;
}

void MulGame::p()
{
    cout << "����: " << a << "*" << b << "= ";
}
void MulGame::guessnumber()
{

    int g;

    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << "�� ° �÷��̾� �����Դϴ�." << endl;
        random();
        bool correct = false;
        double totalReactionTime = 0.0;

        cout << "������ �����Ϸ��� Enter Ű�� ��������." << endl;
        cin.ignore(100, '\n'); // �Է� ���۸� ���
        cin.get(); // Enter Ű �Է��� ��ٸ�

        while (!correct)
        {
            clock_t start = clock();
            p();
            cin >> g;
            clock_t end = clock();

            double reactionTime = static_cast<double>(end - start) / CLOCKS_PER_SEC;
            t[i] = reactionTime;
            totalReactionTime += reactionTime;

            if (c == g) {
                correct = true;
                t[i] = totalReactionTime;
                cout << "����! " << " �ɸ� �ð�: " << totalReactionTime << " ��" << endl;
                cout << endl;
            }
            else {
                cout << "Ʋ�Ƚ��ϴ�. �ٽ� �õ��ϼ���." << endl;
            }

        }
        if (t[i] > t[loser])
        {
            loser = i;
        }
    } // �ݺ�����
    cout << "�й��ڴ� " << loser + 1 << " �� ° �÷��̾��Դϴ�!" << endl; //�߰�
}

int MulGame::getloser() {
    return loser;
}