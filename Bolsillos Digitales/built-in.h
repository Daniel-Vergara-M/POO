#include <iostream>

using namespace std;

/*
 *   Prints a string to the console with a new line at the end.
 *@param message
 *   The string to be printed.
 */
void println(string message)
{
    cout << message << endl;
}
/*
 *   Prints a string to the console.
 *   Used mostly for asking input from the user.
 *@param message
 *   The string to be printed.
 */
void print(string message)
{
    cout << message;
}

/*
 *  Asks the user for input and returns its value.
 *  @param message
 *    The message to be printed before asking for input.
 */
template <typename T>
T input(string message)
{
    T value;
    print(message);
    cin >> value;
    return value;
}
/*
*   Generates a random code of 4 digits.
*/
string generateRandomCode()
{
    string code = "";
    for (int i = 0; i < 4; i++)
    {
        code += to_string(rand() % 10);
    }
    return code;
}
/*
* Converts a given string into lower-case
*/
string toLowerCase(string str)
{
    for (int i = 0; i < str.length(); i++)
    {
        str[i] = tolower(str[i]);
    }
    return str;
}
/*
* Converts a given string into title-case
*/
string toTitleCase(string str)
{
    str[0] = toupper(str[0]);
    for (int i = 1; i < str.length(); i++)
    {
        if (str[i - 1] == ' ')
        {
            str[i] = toupper(str[i]);
        }
    }
    return str;
}
/*
* Converts a given string into upper-case
*/
string toUpperCase(string str)
{
    for (int i = 0; i < str.length(); i++)
    {
        str[i] = toupper(str[i]);
    }
    return str;
}

/*
*  A simple vector class that can store any type of data.
*/
template <typename T>
class Vector
{
private:
    int capacity;
    int size;
    T *v;

public:
    void init(int size)
    {
        v = new T[capacity];
    }
    Vector(int n)
    {
        size = 0;
        capacity = n;
        this->init(n);
    }
    Vector()
    {
        size = 0;
        capacity = 10;
        this->init(capacity);
    }

    int getSize()
    {
        return size;
    }
    int getCapacity()
    {
        return capacity;
    }

    void incrementCapacity()
    {
        capacity *= 2;

        T *current = new T[capacity];
        for (int i = 0; i < this->get_size(); i++)
        {
            current[i] = v[i];
        }
        T *old = v;
        v = current;
        delete[] old;
    }

    void add(T value)
    {
        if (this->getSize() == this->getCapacity())
        {
            this->incrementCapacity();
        }
        v[size++] = value;
    }

    void print()
    {
        for (int i = 0; i < this->get_size(); i++)
        {
            cout << v[i] << " ";
        }
    }
};