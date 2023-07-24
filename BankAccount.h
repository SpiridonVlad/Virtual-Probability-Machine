#pragma once
#include<string>
#include<vector>
#include<iostream>
#include"Exceptions.h"
using namespace std;
template <class T=int>
class BankAccount
{
	string PIN;
	string Bank;
	string	IBAN;
	T Balance;
	string Owner;
public:
	BankAccount(string IBAN,T Balance, string Owner,string Banca,string PIN);
	~BankAccount();
	string GetIban();
	string GetOwner();
	T GetBalance();
	string GetBank();
	void Withdraw(T Amount);
	void SetName(string Name);
	void SetBalance(T Balance);
	void Deposit(T Amount);
	void Print();
};

template<class T>
inline BankAccount<T>::BankAccount(string IBAN, T Balance, string Owner, string Bank,string PIN)
{
	this->Bank = Bank;
	this->Owner = Owner;
	this->Balance = Balance;
	this->IBAN = IBAN;
	this->PIN = PIN;
}

template<class T>
inline BankAccount<T>::~BankAccount()
{
	this->Balance = 0;
	this->Bank.clear();
	this->IBAN.clear();
	this->Owner.clear();
}

template<class T>
inline string BankAccount<T>::GetIban()
{
	return this->IBAN;
}

template<class T>
inline string BankAccount<T>::GetOwner()
{
	return this->Owner;
}

template<class T>
inline T BankAccount<T>::GetBalance()
{
	return this->Balance;
}

template<class T>
inline string BankAccount<T>::GetBank()
{
	return this->Bank;
}

template<class T>
inline void BankAccount<T>::Withdraw(T Amount)
{
	try {
		if (Amount > this->Balance)
			throw Insufficient_funds();
		else
			this->Balance -= Amount;
	}
	catch (exception& e)
	{
		cout <<"Eroare:"<< e.what() << endl;
	}
}

template<class T>
inline void BankAccount<T>::SetName(string Name)
{
	this->Owner = Name;
}

template<class T>
inline void BankAccount<T>::SetBalance(T Balance)
{
	this->Balance = Balance;
}

template<class T>
inline void BankAccount<T>::Deposit(T Amount)
{
	Balance += Amount;
}

template<class T>
inline void BankAccount<T>::Print()
{
	cout <<"$:"<<Owner << " | " << Balance << " | " << IBAN << " | " << Bank <<"|"<< endl;
}
