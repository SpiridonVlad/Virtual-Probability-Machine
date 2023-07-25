#pragma once
#include"SLOTS.h"

class EGT :public SLOTS {
public:
	
	EGT(BankAccount<int>* User, BankAccount<int>* Casino, int BET);
	
	~EGT();	
	
	void Change_Bet(int value);
	
	void Change_User(BankAccount<int>* User);
	
	void Spinning();

	void Spin();

	void Display();

	bool Game();
	
	bool Win();
	
	void Double();
};
