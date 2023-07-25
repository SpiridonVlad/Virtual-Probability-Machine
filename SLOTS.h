#pragma once
#include"Bank.h"
#include<chrono>
#include<thread>
#include<time.h>
#include<random>
#include<windows.h>
using namespace std;
class SLOTS
{
protected:
	BankAccount<int>* User;
	BankAccount<int>* Casino;
	vector<vector<string>> Table;
	vector<int> Values;
	int BET;
	int WIN;
public:

	void Symbol_Set(string& Simbol) {
			for (int i = 3; i < 7; i++)
				Simbol.push_back(i);
	}

	void Random_Set(string& Number1, string& Number2, string& Number3, string& Sign1, string& Sign2, string& Sign3, string Simbol) {
		srand(time(0));
		Number1.clear();
		Number2.clear();
		Number3.clear();
		Sign1.clear();
		Sign2.clear();
		Sign3.clear();

		int random_sign;
		int random_num1, random_num2, random_num3;
		do {
			random_num1 = rand() % 4;
			random_num2 = rand() % 4;
			random_num3 = rand() % 4;
		} while (random_num1 == random_num2 || random_num1 == random_num3 || random_num2 == random_num3);

		Number1 = Simbol[random_num1];
		Number2 = Simbol[random_num2];
		Number3 = Simbol[random_num3];

		random_sign = rand() % 4;
		Sign1 = Simbol[random_sign];
		random_sign = rand() % 4;
		Sign2 = Simbol[random_sign];
		random_sign = rand() % 4;
		Sign3 = Simbol[random_sign];
	}

	bool Get_values_with_probability(char Simbol, double probability, string& result) {
		result.clear();
		srand(time(0));
		unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
		default_random_engine generator(seed); // generam numere aleatoare folosind distributia uniforma
		uniform_real_distribution<double> distribution(0.00, 1.00); // distributia uniforma pe intervalul [0,1]
		double rand_num = distribution(generator); // generam un numar aleatoriu intre 0 si 1
		//cout << rand_num<<" ";
		if (rand_num <= probability) { // daca numarul aleatoriu e mai mic decat probabilitatea, adaugam valoarea in vectorul de rezultate
			result = Simbol;
			return true;
		}
		return false;
	}

	virtual void Change_Bet(int value)=0;

	virtual void Change_User(BankAccount<int>* User)=0;

	virtual void Spinning()=0;

	virtual void Spin()=0;

	virtual void Display()=0;

	virtual bool Game()=0;

	virtual bool Win()=0;

	virtual void Double()=0;
};

