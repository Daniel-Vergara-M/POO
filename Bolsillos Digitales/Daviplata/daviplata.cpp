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

string bankList[3] = {"bancolombia", "davivienda", "bbva"};
string validCodes[5][2] = {
    {"1576", "10000"},
    {"9374", "20000"},
    {"7264", "30000"},
    {"2985", "40000"},
    {"3875", "50000"}};
string movementsTypes[4] = {"recargar", "transferir", "retirar", "guardar"};

class Daviplata
{
private:
    string phoneNumber;
    string password;
    int balance;
    Vector<Vector<string>> movements;

    bool isValidPassword(string password)
    {
        return this->password == password;
    }

    int getBalanceByPhone(string phoneNumber)
    {
        for (int i = 0; i < db[0]->length(); i++)
        {
            if (db[i][1] == phoneNumber)
            {
                return stoi(db[i][3]);
            }
        }
        println("\033[31m Error: Phone number not found");
    }

public:
    Daviplata(){};
    Daviplata(string phoneNumber, string password)
    {
        if (phoneNumber == "" || password == "")
        {
            println("\033[31m Error: Phone number or password can't be empty");
            return;
        }
        if (phoneNumber.length() != 10 || password.length() != 4)
        {
            println("\033[31m Error: Phone number must have 10 digits and/or password must have 4 digits");
            return;
        }
        this->phoneNumber = phoneNumber;
        this->password = password;
        this->balance = this->getBalanceByPhone(phoneNumber);
    };
};

class Recarga
{
private:
    Daviplata account;
    string method;
    int amount;

public:
    Recarga(){};
    Recarga(Daviplata account, string method, int amount)
    {
        this->account = account;
        this->method = method;
        this->amount = amount;
    }
};

class Pagar
{
private:
    Daviplata originAccount;
    Daviplata destinationAccount;
    int amount;

public:
    Pagar(){};
    Pagar(Daviplata originAccount, Daviplata destinationAccount, int amount)
    {
        this->originAccount = originAccount;
        this->destinationAccount = destinationAccount;
        this->amount = amount;
    }
};

int main()
{
    return 0;
}