#include <iostream>
#include <string>
#include "built-in.h"

using namespace std;

class BolsilloDigital
{
private:
    string name;
    string phoneNumber;
    int balance;

    virtual void addToBalance(int amount) = 0;
    virtual void subtractFromBalance(int amount) = 0;

protected:
    string password;
public:
    BolsilloDigital(){};
    BolsilloDigital(string name, string phoneNumber, string password, int balance)
    {
        this->name = name;
        this->phoneNumber = phoneNumber;
        this->password = password;
        this->balance = balance;
    }
    ~BolsilloDigital(){};

    string getName()
    {
        return this->name;
    }
    string setName(string name)
    {
        this->name = name;
    }

    string getPhoneNumber()
    {
        return this->phoneNumber;
    }

    string setPhoneNumber(string phoneNumber)
    {
        this->phoneNumber = phoneNumber;
    }

    string getPassword()
    {
        return this->password;
    }

    void addToBalance(int amount)
    {
        this->balance += amount;
    }
    void subtractFromBalance(int amount)
    {
        this->balance -= amount;
    }
};