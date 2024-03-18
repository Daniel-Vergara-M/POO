#include <iostream>
#include <string>

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

template <typename T>
class Node
{
private:
    T data;
    Node *next;

public:
    Node()
    {
        this->next = NULL;
    }

    Node(T d)
    {
        this->data = d;
        this->next = NULL;
    }

    T getData()
    {
        return this->data;
    }

    void setData(T data)
    {
        this->data = data;
    }

    Node<T> *getNext()
    {
        return this->next;
    }

    void setNext(Node<T> *next)
    {
        this->next = next;
    }

    Node<T> &operator=(const Node<T> &other)
    {
        this->data = other.data;
        this->next = other.next;
        return *this;
    }

    string to_string()
    {
        return to_string(this->data);
    }

    friend ostream &operator<<(ostream &os, Node<T> &b)
    {
        return os << b.to_string();
    }
};

template <typename T>
class List
{
private:
    Node<T> *ptr;
    int size;

public:
    List()
    {
        ptr = NULL;
        size = 0;
    }

    int getSize()
    {
        return this->size;
    }

    void add(T d)
    {
        Node<T> *n = new Node<T>(d);
        if (ptr == NULL)
        {
            ptr = n;
        }
        else
        {
            Node<T> *t = ptr;
            while (t->get_next() != NULL)
            {
                t = t->get_next();
            }
            t->set_next(n);
        }
        size++;
    }

    void print()
    {
        Node<T> *t = ptr;
        while (t != NULL)
        {
            cout << (*t) << endl;
            t = t->get_next();
        }
    }
    void set(int index, T value)
    {
        Node<T> *t = ptr;
        for (int i = 0; i < index; i++)
        {
            t = t->getNext();
        }
        t->setData(value);
    }

    int indexOf(T value)
    {
        Node<T> *t = ptr;
        for (int i = 0; i < size; i++)
        {
            if (t->getData() == value)
            {
                return i;
            }
            t = t->getNext();
        }
        return -1;
    }
    void remove(int index)
    {
        Node<T> *t = ptr;
        if (index == 0)
        {
            ptr = t->getNext();
            delete t;
            size--;
            return;
        }
        for (int i = 0; i < index - 1; i++)
        {
            t = t->getNext();
        }
        Node<T> *temp = t->getNext();
        t->setNext(temp->getNext());
        delete temp;
        size--;
    }

    operator [] (int index)
    {
        Node<T> *t = ptr;
        for (int i = 0; i < index; i++)
        {
            t = t->get_next();
        }
        return t->get_data();
    }
};
