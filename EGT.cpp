#include "EGT.h"

EGT::EGT(BankAccount<int>* User, BankAccount<int>* Casino, int BET)
{
	Table.resize(3);
	for (int i = 0; i < 3; i++)
		Table[i].resize(3);
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			Table[i][j] = '-';
	this->User = User;
	this->Casino = Casino;
	this->BET = BET;
	this->WIN = 100;
}

EGT::~EGT()
{
	this->User = nullptr;
	this->Casino = nullptr;
	this->BET = 0;
	this->WIN = 0;
}

void EGT::Change_Bet(int value)
{
	this->BET = value;
}

void EGT::Change_User(BankAccount<int>* User)
{
	this->User = User;
}

void EGT::Spinning()
{
	string Number1, Number2, Number3;
	string Simbol;
	string Sign1, Sign2, Sign3;
	Symbol_Set(Simbol);
	int index = 0;
	//Beep(1000,1000);
	while (index < 15) {
		Random_Set(Number1, Number2, Number3, Sign1, Sign2, Sign3, Simbol);
		Sleep(125);
		cout << endl;
		//afișăm cartea în consolă
		cout << "$-----------------SPINNING-----------------$" << endl;
		std::cout << "  -----------    -----------    ----------- " << std::endl;
		std::cout << " |" << Number1 << "          |  |" << Number2 << "          |  |" << Number3 << "          |" << std::endl;
		std::cout << " | --------- |  | --------- |  | --------- |" << std::endl;
		std::cout << " | |       | |  | |       | |  | |       | |" << std::endl;
		std::cout << " | |   " << Sign1 << "   | |  | |   " << Sign2 << "   | |  | |   " << Sign3 << "   | |" << std::endl;
		std::cout << " | |       | |  | |       | |  | |       | |" << std::endl;
		std::cout << " | --------- |  | --------- |  | --------- |" << std::endl;
		std::cout << " |          " << Number1 << "|  |          " << Number2 << "|  |          " << Number3 << "|" << std::endl;
		std::cout << "  -----------    -----------    ----------- " << std::endl;
		cout << "$-----------------SPINNING-----------------$" << endl;
		index++;
	}
}

void EGT::Spin()
{

	string Sign;
	Symbol_Set(Sign);
	Sign.resize(6);
	Sign[4] = '7';

	vector<double> Probability;
	Probability.push_back(0.02);
	Probability.push_back(0.018);
	Probability.push_back(0.016);
	Probability.push_back(0.012);
	Probability.push_back(0.003);

	string result = "-";
	int i = 0, j = 0, k = 0;
	int index = 0;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++) {
			while (!Get_values_with_probability(Sign[k], Probability[k], result)) { k++; if (k == 5) k = 0; }
			Table[i][j] = result;
		}
	
	User->Withdraw(BET);
	Casino->Deposit(BET);
}

void EGT::Display()
{
	system("cls");
	string word = "BolfaBet";
	size_t len = word.length();
	std::cout << "      ";
	for (int i = 0; i < len * 4 + 1; i++) {
		std::cout << "-";
	}
	std::cout << " \n";
	std::cout << "  -$-|";
	for (size_t i = 0; i < len / 2; i++) {
		std::cout << " " << word[i] << " |";
	}
	std::cout << " " << word[len / 2] << "  | ";
	for (size_t i = len / 2 + 1; i < len; i++) {
		std::cout << " " << word[i] << " |";
	}
	std::cout << "-$-";
	std::cout << "\n ";
	std::cout << "     ";
	for (size_t i = 0; i < len * 4 + 1; i++) {
		std::cout << "-";
	}


	std::cout << " \n";
	cout << "______________________________________________" << endl;
	cout << endl;
	cout << "  -----------    -----------    ----------- " << endl;
	cout << " | --------- |  | --------- |  | --------- |" << endl;
	for (int i = 0; i < 3; i++) {
		cout << " | |   " << Table[i][0] << "   | |  | |   " << Table[i][1] << "   | |  | |   " << Table[i][2] << "   | |" << endl;
		cout << " | --------- |  | --------- |  | --------- |" << endl;
	}
	cout << "  -----------    -----------    ----------- " << endl;
	cout << "______________________________________________" << endl;
	cout << "["<<User->GetOwner()<<"]"<<"            [" << User->GetBalance() << "]" << "[" << this->BET << "]        ["<<this->WIN<<"]";
	cout << endl;

Sleep(500);
}

bool EGT::Game()
{
	Display();
	while (User->GetBalance() > BET) 
	{
		if (GetAsyncKeyState(VK_SPACE) & 0x8000 ) {
			Spin();
			Spinning();
			Win();
			Display();
			if(WIN>0)
			Double();
			Display();
		}
		else
			if (GetAsyncKeyState(VK_BACK) & 0x8000) {
				system("cls");
				return false;
		}
	}
	return false;
}

bool EGT::Win()
{
	string Sign;
	Symbol_Set(Sign);
	Sign.resize(6);
	Sign[4] = '7';
	Values.push_back(2);
	Values.push_back(3);
	Values.push_back(4);
	Values.push_back(5);
	Values.push_back(100);
	string copie;
	int index = 0;
	int count = 0;
	bool ok = false;
	this->WIN = 0;
	//------------------------------------------------------------------------------------------
	for (int k = 0; k < 5; k++) {
		for (int i = 0; i < 3; i++)
		{
			count = 0;
			for (int j = 0; j < 3; j++)
			{
				copie.clear();
				copie.push_back(Sign[k]);
				if (Table[i][j] == copie) {
					count++;
				}
			}
			//cout << count << endl;
			if (count == 3)
			{
				this->WIN += Values[k] * BET;
				ok = true;
			}
		}
		//------------------------------------------------------------------------------------------
		for (int i = 0; i < 3; i++) {
			count = 0;
			for (int j = 0; j < 3; j++)
			{
				copie.clear();
				copie.push_back(Sign[k]);
				if (Table[j][i] == copie) {
					count++;
				}
				if (count == 3) {
					this->WIN += Values[k] * BET;
					ok = true;
				}
			}
		}
		//------------------------------------------------------------------------------------------
		count = 0;
		for (int i = 0; i < 3; i++)
		{
			copie.clear();
			copie.push_back(Sign[k]);
			if (Table[i][i] == copie) {
				count++;
			}
			if (count == 3) {
				this->WIN += Values[k] * BET;
				ok = true;
			}
		}
		//------------------------------------------------------------------------------------------
		count = 0;
		index = 0;
		while (index < 3)
			for (int j = 2; j >= 0; j--)
			{
				copie.clear();
				copie.push_back(Sign[k]);
				if (Table[index][j] == copie) {
					count++;
				}
				if (count == 3) {
					this->WIN += Values[k] * BET;
					ok = true;
				}
				index++;
			}
	}
	if (ok == true) {
		system("cls");
		cout << "$----------------------------------------$" << endl;
		std::cout << "                        " << std::endl;
		std::cout << "               ----------- " << std::endl;
		std::cout << "              |           |" << std::endl;
		std::cout << "              | --------- |" << std::endl;
		std::cout << "              | |       | |" << std::endl;
		std::cout << "         ATI  | |   $   | |  Castigat" << std::endl;
		std::cout << "              | |       | |" << std::endl;
		std::cout << "              | --------- |" << std::endl;
		std::cout << "              |           |" << std::endl;
		std::cout << "               ----------- " << std::endl;
		std::cout << "                 WIN:"<<WIN<<"        " << std::endl;
		cout << "$----------------------------------------$" << endl;
		Sleep(1000);
	}
	return ok;
}

void EGT::Double()
{
	srand(time(0));
	bool Option = rand() % 2;//1 e negru(dreapta) 0 e rosu(stanga);
	while (true) {
		if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
			system("cls");
			cout << "$-----------------DUBLAJ-----------------$" << endl;
			std::cout << "        RED                   BLACK " << std::endl;
			std::cout << "    -----------            ----------- " << std::endl;
			std::cout << "   |J          |          |K          |" << std::endl;
			std::cout << "   | --------- |          | --------- |" << std::endl;
			std::cout << "   | |       | |          | |       | |" << std::endl;
			std::cout << "   | |   $   | |   <-->   | |   $   | |" << std::endl;
			std::cout << "   | |       | |          | |       | |" << std::endl;
			std::cout << "   | --------- |          | --------- |" << std::endl;
			std::cout << "   |          J|          |          K|" << std::endl;
			std::cout << "    -----------            ----------- " << std::endl;
			std::cout << "        RED                   BLACK " << std::endl;
			cout << "$-----------------DUBLAJ-----------------$" << endl;
			cout << "                   [" << WIN << "]";
			cout << endl;
			Sleep(200);

			while (true) {
				if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
					if (Option == 1) {
						WIN *= 2;
						system("cls");
						cout <<      "$-----------------DUBLAJ-----------------$" << endl;
						std::cout << "                  BLACK " << std::endl;
						std::cout << "               ----------- " << std::endl;
						std::cout << "              |K          |" << std::endl;
						std::cout << "              | --------- |" << std::endl;
						std::cout << "              | |       | |" << std::endl;
						std::cout << "  FELICITARI  | |   $   | |  FELICITARI" << std::endl;
						std::cout << "              | |       | |" << std::endl;
						std::cout << "              | --------- |" << std::endl;
						std::cout << "              |          K|" << std::endl;
						std::cout << "               ----------- " << std::endl;
						std::cout << "                  BLACK  " << std::endl;
						cout << "$-----------------DUBLAJ-----------------$" << endl;
						Sleep(500);
						Double();
						return;
					}
					else {
						WIN = 0;
						system("cls");
						cout << "$------------------LOST------------------$" << endl;
						std::cout << "                        " << std::endl;
						std::cout << "               ----------- " << std::endl;
						std::cout << "              |           |" << std::endl;
						std::cout << "              | --------- |" << std::endl;
						std::cout << "              | |       | |" << std::endl;
						std::cout << "         ATI  | |   -   | | PIERDUT" << std::endl;
						std::cout << "              | |       | |" << std::endl;
						std::cout << "              | --------- |" << std::endl;
						std::cout << "              |           |" << std::endl;
						std::cout << "               ----------- " << std::endl;
						std::cout << "                         " << std::endl;
						cout << "$------------------LOST------------------$" << endl;
						Sleep(800);
						return;
					}
				}
				else
					if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
						if (Option == 0) {
							WIN *= 2;
							system("cls");
							cout << "$-----------------DUBLAJ-----------------$" << endl;
							std::cout << "                   RED " << std::endl;
							std::cout << "               ----------- " << std::endl;
							std::cout << "              |K          |" << std::endl;
							std::cout << "              | --------- |" << std::endl;
							std::cout << "              | |       | |" << std::endl;
							std::cout << "  FELICITARI  | |   $   | |  FELICITARI" << std::endl;
							std::cout << "              | |       | |" << std::endl;
							std::cout << "              | --------- |" << std::endl;
							std::cout << "              |          K|" << std::endl;
							std::cout << "               ----------- " << std::endl;
							std::cout << "                   RED  " << std::endl;
							cout << "$-----------------DUBLAJ-----------------$" << endl;
							Sleep(500);
							Double();
							return;
						}
						else {
							this->WIN = 0;
							system("cls");
							cout << "$------------------LOST------------------$" << endl;
							std::cout << "                        " << std::endl;
							std::cout << "               ----------- " << std::endl;
							std::cout << "              |           |" << std::endl;
							std::cout << "              | --------- |" << std::endl;
							std::cout << "              | |       | |" << std::endl;
							std::cout << "         ATI  | |   -   | | PIERDUT" << std::endl;
							std::cout << "              | |       | |" << std::endl;
							std::cout << "              | --------- |" << std::endl;
							std::cout << "              |           |" << std::endl;
							std::cout << "               ----------- " << std::endl;
							std::cout << "                         " << std::endl;
							cout << "$------------------LOST------------------$" << endl;
							Sleep(800);
							return;
						}
					}
					else if (GetAsyncKeyState(VK_SPACE) & 0x8000) {
						User->Deposit(WIN);
						return;
					}
			}

		}
		else
			if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
				system("cls");
				cout << "$-----------------DUBLAJ-----------------$" << endl;
				std::cout << "        RED                   BLACK " << std::endl;
				std::cout << "    -----------            ----------- " << std::endl;
				std::cout << "   |J          |          |K          |" << std::endl;
				std::cout << "   | --------- |          | --------- |" << std::endl;
				std::cout << "   | |       | |          | |       | |" << std::endl;
				std::cout << "   | |   $   | |   <-->   | |   $   | |" << std::endl;
				std::cout << "   | |       | |          | |       | |" << std::endl;
				std::cout << "   | --------- |          | --------- |" << std::endl;
				std::cout << "   |          J|          |          K|" << std::endl;
				std::cout << "    -----------            ----------- " << std::endl;
				std::cout << "        RED                   BLACK " << std::endl;
				cout << "$-----------------DUBLAJ-----------------$" << endl;
				cout << "                   [" << WIN << "]";
				cout << endl;
				Sleep(100);
				while (true) {
					if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
						if (Option == 1) {
							WIN = WIN * 2;
							system("cls");
							cout << "$-----------------DUBLAJ-----------------$" << endl;
							std::cout << "                  BLACK " << std::endl;
							std::cout << "               ----------- " << std::endl;
							std::cout << "              |K          |" << std::endl;
							std::cout << "              | --------- |" << std::endl;
							std::cout << "              | |       | |" << std::endl;
							std::cout << "  FELICITARI  | |   $   | |  FELICITARI" << std::endl;
							std::cout << "              | |       | |" << std::endl;
							std::cout << "              | --------- |" << std::endl;
							std::cout << "              |          K|" << std::endl;
							std::cout << "               ----------- " << std::endl;
							std::cout << "                  BLACK  " << std::endl;
							cout << "$-----------------DUBLAJ-----------------$" << endl;
							Sleep(500);
							Double();
						}
						else {
							WIN = 0;
							system("cls");
							cout << "$------------------LOST------------------$" << endl;
							std::cout << "                        " << std::endl;
							std::cout << "               ----------- " << std::endl;
							std::cout << "              |           |" << std::endl;
							std::cout << "              | --------- |" << std::endl;
							std::cout << "              | |       | |" << std::endl;
							std::cout << "         ATI  | |   -   | | PIERDUT" << std::endl;
							std::cout << "              | |       | |" << std::endl;
							std::cout << "              | --------- |" << std::endl;
							std::cout << "              |           |" << std::endl;
							std::cout << "               ----------- " << std::endl;
							std::cout << "                         " << std::endl;
							cout << "$------------------LOST------------------$" << endl;
							Sleep(800);
							return;
						}
					}
					else
						if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
							if (Option == 0) {
								WIN *= 2;
								system("cls");
								cout << "$-----------------DUBLAJ-----------------$" << endl;
								std::cout << "                   RED " << std::endl;
								std::cout << "               ----------- " << std::endl;
								std::cout << "              |K          |" << std::endl;
								std::cout << "              | --------- |" << std::endl;
								std::cout << "              | |       | |" << std::endl;
								std::cout << "  FELICITARI  | |   $   | |  FELICITARI" << std::endl;
								std::cout << "              | |       | |" << std::endl;
								std::cout << "              | --------- |" << std::endl;
								std::cout << "              |          K|" << std::endl;
								std::cout << "               ----------- " << std::endl;
								std::cout << "                   RED  " << std::endl;
								cout << "$-----------------DUBLAJ-----------------$" << endl;
								Sleep(500);
								Double();
							}
							else {
								this->WIN = 0;
								system("cls");
								cout << "$------------------LOST------------------$" << endl;
								std::cout << "                        " << std::endl;
								std::cout << "               ----------- " << std::endl;
								std::cout << "              |           |" << std::endl;
								std::cout << "              | --------- |" << std::endl;
								std::cout << "              | |       | |" << std::endl;
								std::cout << "         ATI  | |   -   | | PIERDUT" << std::endl;
								std::cout << "              | |       | |" << std::endl;
								std::cout << "              | --------- |" << std::endl;
								std::cout << "              |           |" << std::endl;
								std::cout << "               ----------- " << std::endl;
								std::cout << "                         " << std::endl;
								cout << "$------------------LOST------------------$" << endl;
								Sleep(800);
								return;
							}
						}
						else if (GetAsyncKeyState(VK_SPACE) & 0x8000){
							User->Deposit(WIN);
							Sleep(100);
							return;
						}
				}
			}
			else
				if (GetAsyncKeyState(VK_SPACE) & 0x8000) {
					User->Deposit(WIN);
					Sleep(100);
					return;
				}
	}
	return;
}
