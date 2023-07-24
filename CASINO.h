#pragma once
#include"EGT.h"
#include<algorithm>
class CASINO
{
protected:
	vector<BankAccount<int>*> Users;
	BankAccount<int>* User;
	int BET;
public:
	virtual void Add_User(BankAccount<int>* User)=0;
	//virtual void Choose_Player();
	virtual void Choose_Bet()=0;
	virtual int Choice()=0;
	virtual void Names()=0;
	virtual void PLAY()=0;
};

