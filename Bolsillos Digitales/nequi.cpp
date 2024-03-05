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
    {"3875", "50000"}
};
string movementsTypes[4] = {"recargar", "transferir", "retirar", "guardar"};
class Nequi
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
    Nequi(){};
    Nequi(string phoneNumber, string password)
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
    Nequi account;
    string method;
    int amount;

public:
    Recarga() {}
    Recarga(Nequi account, string method, int amount)
    {
        this->account = account;
        this->method = method;
        this->amount = amount;
    }
};

class Colchon
{
private:
    Nequi account;
    int amount;
    bool locked;

public:
    Colchon() {}
    Colchon(Nequi account, int amount)
    {
        this->account = account;
        this->amount = amount;
        this->locked = false;
    }
};

class Meta
{
private:
    Nequi account;
    int days;
    int amount;

public:
    Meta() {}
    Meta(Nequi account, int amount, int days)
    {
        this->account = account;
        this->amount = amount;
        this->days = days;
    }
};

class Bolsillos
{
private:
    Nequi account;
    int amount;

public:
    Bolsillos() {}
    Bolsillos(Nequi account, int amount)
    {
        this->account = account;
        this->amount = amount;
    }
};

class Retirar
{
private:
    Nequi account;
    int amount;

public:
    Retirar() {}
    Retirar(Nequi account, int amount)
    {
        this->account = account;
        this->amount = amount;
    }
};

class Movimientos
{
private:
    Nequi account;

public:
    Movimientos() {}
    Movimientos(Nequi account)
    {
        this->account = account;
    }
};

int main()
{
    return 0;
}