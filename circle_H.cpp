#include "H.h"
#include <ctime>


H::H(int n) :n(n), a(0), b(0), c(0), t(n), loser(0)
{

}

void H::random()
{
    srand(time(0));
    a = 1 + rand() % 9;
    b = 1 + rand() % 9;
    c = a * b;
}

void H::p()
{
    cout << a << "*" << b << "=?";
}

void H::guessnumber()
{
    int g;

    for (int i = 0; i < n; i++)
    {
        clock_t start = clock();
        random();
        do
        {
            p();
            cout << endl;
            cin >> g;

        } while (g != c);
        clock_t end = clock();
        double reactionTime = static_cast<double>(end - start) / CLOCKS_PER_SEC;
        cout << reactionTime << "s" << endl;
        t[i] = reactionTime;

        if (t[i] > t[loser])
        {
            loser = i;
        }
    }


}

int H::getloser() {
    return loser;
}