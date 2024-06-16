//1È¸ ½ÇÇà
#include "Game.h"
#include "Array.h"
#include <ctime>
#include <vector>
int main() {
    int n = 0;
    cin >> n;
    Array array1(n+1);
    Game game1(n);
    game1.play();
    array1.Count(game1.getSlowestRun());
    array1.PrintArray();
    return 0;
}
