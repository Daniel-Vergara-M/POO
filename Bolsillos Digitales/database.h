#include <iostream>
#include <string>
#include "built-in.h"

using namespace std;

class Database
{
private:
    List<string> users;
    List<string> passwords;
    List<int> balances;
    List<string> phoneNumbers;
    bool userExists(const string &user) { return (this->users.indexOf(user) != -1); }

public:
    /* Constructores   */
    Database()
    {
        this->users = List<string>();
        this->passwords = List<string>();
        this->balances = List<int>();
        this->phoneNumbers = List<string>();
    }
    ~Database()
    {
        this->users.~List();
        this->passwords.~List();
        this->balances.~List();
        this->phoneNumbers.~List();
    }
    string getUser(const string &user)
    {
        int index = this->users.indexOf(user);
        if (!this->userExists(user))
        {
            println("User not found");
            return "";
        }
        return to_string(this->users[index]);
    }
    void setUser(const string &user, const string &newUser)
    {
        int index = this->users.indexOf(user);
        if (!this->userExists(user))
            return;
        this->users.set(index, newUser);
    }
    int getBalance(const string &user)
    {
        int index = this->users.indexOf(user);
        if (!this->userExists(user))
            return -1;
        return this->balances[index];
    }
    void setBalance(const string &user, const int &balance)
    {
        int index = this->users.indexOf(user);
        if (!this->userExists(user))
            return;
        this->balances.set(index, balance);
    }
    string getPassword(const string &user)
    {
        int index = this->users.indexOf(user);
        if (!this->userExists(user))
            return "";
        return to_string(this->passwords[index]);
    }
    void setPassword(const string &user, const string &password)
    {
        int index = this->users.indexOf(user);
        if (!this->userExists(user))
            return;
        this->passwords.set(index, password);
    }
    string getPhoneNumber(const string &user)
    {
        int index = this->users.indexOf(user);
        if (!this->userExists(user))
            return "";
        return to_string(this->phoneNumbers[index]);
    }
    void setPhoneNumber(const string &user, const string &phoneNumber)
    {
        int index = this->users.indexOf(user);
        if (!this->userExists(user))
            return;
        this->phoneNumbers.set(index, phoneNumber);
    }
    void addUser(const string &user, const string &password, const int &balance, const string &phoneNumber)
    {
        if (this->userExists(user))
        {
            println("User already exists");
            return;
        }
        this->users.add(user);
        this->passwords.add(password);
        this->balances.add(balance);
        this->phoneNumbers.add(phoneNumber);
    }
    void removeUser(const string &user)
    {
        int index = this->users.indexOf(user);
        if (!this->userExists(user))
        {
            println("User not found");
            return;
        }
        this->users.remove(index);
        this->passwords.remove(index);
        this->balances.remove(index);
        this->phoneNumbers.remove(index);
    }
};

int main()
{
    return 0;
}
