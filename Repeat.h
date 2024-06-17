#ifndef REPEAT_H
#define REPEAT_H
#include "Array.h"
#include "WNum.h"
#include "Tictactoe.h"
#include "YACHT_DICE.h"
#include "Mulgame.h"

class Repeat:public Array,public WNum,public MulGame,public tictactoe,public YahtzeeGame
{
private:
	
public:
	Repeat(int,int);
	void if_two();
	void Else();
};










#endif