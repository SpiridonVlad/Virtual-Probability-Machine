#pragma once
#include"CASINO.h"
class SUPERBET:public CASINO
{
	BankAccount<int>* Casino = new BankAccount <int>("RO263472785", 1000000, "Casino", "BCR", "---");
	BankAccount<int>* User = new BankAccount <int> ("RO26471291",0,"User","BT","---");
	size_t count=0;
public:
	void Add_User(BankAccount<int>* User);
	void Display();
	void Choose_Game();
	void Choose_Sum();
	void Choose_Bet();
	void Choose_Name();
	int Choice();
	void Names();
	void PLAY();
};

