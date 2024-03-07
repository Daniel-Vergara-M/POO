#include <iostream>
#include <string>
#include "built-in.h"

using namespace std;

class BolsilloDigital
{
private:
    string name;
    string phoneNumber;
    string password;
    int balance;

public:
    BolsilloDigital(){};
    BolsilloDigital(string name, string phoneNumber, string password, int balance)
    {
        this->name = name;
        this->phoneNumber = phoneNumber;
        this->password = password;
        this->balance = balance;
    }

    string getName()
    {
        return this->name;
    }

    string getPhoneNumber()
    {
        return this->phoneNumber;
    }

    string getPassword()
    {
        return this->password;
    }

    void setBalance(int balance)
    {
        this->balance = balance;
    }

    void addToBalance(int amount)
    {
        this->balance += amount;
    }
    void subtractFromBalance(int amount)
    {
        this->balance -= amount;
    }

    ~BolsilloDigital(){};
};