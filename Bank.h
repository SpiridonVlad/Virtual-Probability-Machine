#pragma once
#include"BankAccount.h"
template<class T>
class Bank
{
	string Name;
	string Address;
	string Country;
	vector<BankAccount<T>*> Accounts;
public:
	Bank(string Name, string Address, string Country);
	~Bank();
	Bank<T>& operator+=(BankAccount<T>* Account);
	Bank<T>& operator-=(BankAccount<T>* Account);
	BankAccount<T>& operator[](string Name);
	void Transfer(BankAccount<T>* From, BankAccount<T>* To, T Amount, T Tax);
	void Print();
};

template<class T>
inline Bank<T>::Bank(string Name, string Address, string Country)
{
	this->Name = Name;
	this->Address = Address;
	this->Country = Country;

}

template<class T>
inline Bank<T>::~Bank()
{
	this->Name.clear();
	this->Address.clear();
	this->Country.clear();
	this->Accounts.clear();
}

template<class T>
inline Bank<T>& Bank<T>::operator+=(BankAccount<T>* Account)
{
	try {
		if (Account->GetBank() != this->Name)
			throw Wrong_Bank();
		Accounts.push_back(Account);
		return *this;
	}
	catch (exception& e) {
		cout <<"Error:"<< e.what() << endl;
		return *this;
	}
}

template<class T>
inline Bank<T>& Bank<T>::operator-=(BankAccount<T>* Account)
{
	this->Accounts.erase(Account);
	return *this;
}

template<class T>
inline BankAccount<T>& Bank<T>::operator[](string Name)
{
	for (auto it : Accounts) {
		if (it->GetName() == Name)
			return it;
	}
}

template<class T>
inline void Bank<T>::Transfer(BankAccount<T>* From, BankAccount<T>* To, T Amount, T Tax)
{
	try {
		if (From->GetBalance() < Amount)
			throw Insufficient_funds();
		if (From->GetBank() == To->GetBank())
			Tax = 0;
		From->Withdraw(Amount + Tax);
		To->Deposit(Amount + Tax);
	}
	catch (exception& e) {
		cout << "Error:" << e.what() << endl;
	}
}

template<class T>
inline void Bank<T>::Print()
{
	cout << Name << "(" << Address << "," << Country << ") :"<<endl;
	cout << "--------------------------------------------------------" << endl;
	for (auto it : Accounts)
	{
		it->Print();
	}
	cout << "--------------------------------------------------------" << endl;
}
