#include <iostream>
#include <string>
#include "built-in.h"

using namespace std;

/*
 * Database for name, phone number, password and balance
 */
string db[10][4] = {
    {"Daniel", "3125198370", "0505", "100000"},
    {"Katherine", "3106031563", "0505", "200000"},
    {"Juan", "3007464518", "0505", "300000"}};

class Nequi
{
private:
    string phoneNumber;
    string password;
    int balance;

public:
    Nequi(){};
    Nequi(string phoneNumber, string password)
    {
        if (phoneNumber == "" || password == "")
        {
            println("Error: Phone number or password can't be empty");
            return;
        }
        if (phoneNumber.length() != 10 || password.length() != 4)
        {
            println("Error: Phone number must have 10 digits and/or password must have 4 digits");
            return;
        }
        this->phoneNumber = phoneNumber;
        this->password = password;
        this->balance = this->getBalanceByPhone(phoneNumber);
    };

    int getBalanceByPhone(string phoneNumber)
    {
        for (int i = 0; i < db[0]->length(); i++)
        {
            if (db[i][1] == phoneNumber)
            {
                return stoi(db[i][3]);
            }
        }
        println("Error: Phone number not found");
    }
};

int main()
{
    Nequi nequi = Nequi("3125198270", "0505");
    return 0;
}