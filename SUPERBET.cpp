#include "SUPERBET.h"

void SUPERBET::Choose_Sum()
{
    Display();
    int value;
    cout << "             |----------------|" << std::endl;
    cout << "              |--------------|" << std::endl;
    cout << "                    [SUM]:";cin >> value;
    this->User->SetBalance(this->User->GetBalance()+value);
}

void SUPERBET::Choose_Bet()
{
    system("cls");
    Display();
    int value;
    cout << "             |----------------|" << std::endl;
    cout << "              |--------------| " << std::endl;
    cout << "                    [BET]:"; cin >> value;
    this->BET = value;
}

void SUPERBET::Choose_Name()
{
    system("cls");
    Display();
    string value;
    cout << "             |----------------|" << std::endl;
    cout << "              |--------------| " << std::endl;
    cout << "                   [NAME]:"; cin >> value;
    User->SetName(value);
}

int SUPERBET::Choice()
{
    int val = 0;
    bool validInput = false;
    Names();
    while (!validInput)
    {
        if (GetAsyncKeyState('1') & 0x8000) // Verifică dacă a fost apăsată tasta 1
        {
            val = 1;
            validInput = true;
        }
        else if (GetAsyncKeyState('2') & 0x8000) // Verifică dacă a fost apăsată tasta 2
        {
            val = 2;
            validInput = true;
        }
        else if (GetAsyncKeyState('3') & 0x8000) // Verifică dacă a fost apăsată tasta 3
        {
            val = 3;
            validInput = true;
        }
        else if (GetAsyncKeyState('4') & 0x8000) // Verifică dacă a fost apăsată tasta 4
        {
            val = 4;
            validInput = true;
        }
        else if (GetAsyncKeyState('5') & 0x8000) // Verifică dacă a fost apăsată tasta 5
        {
            val = 5;
            validInput = true;
        }
        else if (GetAsyncKeyState('6') & 0x8000) // Verifică dacă a fost apăsată tasta 6
        {
            val = 6;
            validInput = true;
        }
        else if (GetAsyncKeyState('7') & 0x8000) // Verifică dacă a fost apăsată tasta 7
        {
            val = 7;
            validInput = true;
        }
        else if (GetAsyncKeyState('8') & 0x8000) // Verifică dacă a fost apăsată tasta 8
        {
            val = 8;
            validInput = true;
        }
        else if (GetAsyncKeyState('9') & 0x8000) // Verifică dacă a fost apăsată tasta 9
        {
            val = 9;
            validInput = true;
        }

        Sleep(100); // Așteaptă 10 milisecunde pentru a evita supraîncărcarea procesorului
    }
    return val;
}

void SUPERBET::Names()
{
    std::vector<std::string> table = { "", "", "", "", "", "", "", "", "" };
    std::string input;
    string aux;
    // Citim 9 string-uri de la tastatură
    for (int i = 0; i < 9; i++) {
        aux.clear();
        aux += '[';
        aux += (i+1) + '0';
        aux += ']';
        aux += Users[i]->GetOwner();
        table[i] = aux;
    }

    // Aflam lungimea maxima a string-urilor
    int max_length = 0;
    for (const auto& str : table) {
        max_length = max(max_length, static_cast<int>(str.length()));
    }

    // Afisam tabela
    std::cout << "$";
    for (int i = 0; i < max_length *3+8; i++) {
        std::cout << "-";
    }
    std::cout << "$" << std::endl;

    for (int i = 0; i < 3; i++) {
        std::cout << "| ";
        for (int j = 0; j < 3; j++) {
            const auto& str = table[i * 3 + j];
            std::cout << str;
            for (int k = str.length(); k < max_length; k++) {
                std::cout << " ";
            }
            std::cout << " | ";
        }
        std::cout << std::endl;
    }

    std::cout << "$";
    for (int i = 0; i < max_length * 3 + 8; i++) {
        std::cout << "-";
    }
    std::cout << "$" << std::endl;
    cout << "       (1-9)[CHOOSE YOUR PLAYER](1-9)" << endl;
}

void SUPERBET::PLAY()
{
    //Choose_Player();
    Choose_Name();
    Choose_Sum();
    Choose_Bet();
    EGT Slot(User, Casino, BET);
	while (!Slot.Game())
    {
        system("cls");
        Sleep(100);
        Choose_Sum();
        Choose_Bet();
		Slot.Change_Bet(BET);
        Sleep(100);
        Slot.Game();
    }
}

void SUPERBET::Add_User(BankAccount<int>* User)
{
    Users.push_back(User);
}

void SUPERBET::Display()
{
    int value;
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
    cout << " |           |  |           |  |           |    " << endl;
    cout << " | --------- |  | --------- |  | --------- |" << endl;
    cout << " |           |  |           |  |           |    " << endl;
    cout << " |           |  |           |  |           |    " << endl;
    cout << " |           |  |           |  |           |    " << endl;
    cout << " | --------- |  | --------- |  | --------- |" << endl;
    cout << " |           |  |           |  |           |    " << endl;
    cout << "  -----------    -----------    ----------- " << endl;
    cout << "______________________________________________" << endl;
}

void SUPERBET::Choose_Game()
{
    cout << "Choose game mode";
}
