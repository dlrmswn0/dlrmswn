#ifndef REPEAT_H
#define REPEAT_H
#include "Array.h"
#include "Game.h"
#include "Tictactoe.h"
#include "Y.h"
#include "H.h"

class Repeat:public Array,public Game,public H,public tictactoe,public YahtzeeGame
{
private:
	
public:
	Repeat(int,int);
	void if_two();
	void all();
};










#endif