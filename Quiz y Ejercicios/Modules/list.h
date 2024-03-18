#include <iostream>
#include <string>

using namespace std;

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

    string toString()
    {
        return to_string(this->data);
    }

    friend ostream &operator<<(ostream &os, Node<T> &b)
    {
        return os << b.toString();
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
            while (t->getNext() != NULL)
            {
                t = t->getNext();
            }
            t->setNext(n);
        }
        size++;
    }

    void print()
    {
        Node<T> *t = ptr;
        while (t != NULL)
        {
            cout << (*t) << endl;
            t = t->getNext();
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
    void removeByIndex(int index)
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

    void remove(T value) {
        int index = this->indexOf(value);
        if (index != -1) {
            removeByIndex(index);
        }
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
