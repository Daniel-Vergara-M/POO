#include <iostream>
#include <list>

using namespace std;

/* class Poker
{
private:
    string name;
    string suit;
    int value;
    string deck[52];

public:
    Poker(){};
    Poker(string name, string suit, int value, list<string> deck) : name(name), suit(suit), value(value), deck(deck){};
    ~Poker() {
        delete[] deck;
    }
    void initDeck(const char *poker[], list<string> &deck)
    {
        string val = "";
        while (val != "-1") {
            cout << "Ingrese el valor de la carta: ";
            cin >> val;
            if (val != "-1") {
                deck.push_back(val);
            }
        }
    }
    bool isInDeck(const string card)
    {
        for (auto it = this->deck->begin(); it != this->deck->end(); it++)
        {
            if ((string*)*it == &card) return true;
        }
        return false;
    }
    void showCard(const string &card)
    {
        if (isInDeck(card))
        {
            cout << "La carta " << card << " está en el deck" << endl;
        }
        else
        {
            cout << "La carta " << card << " no está en el deck" << endl;
        }
    }

    void bubbleSort()
    {
        deck.sort();
    }

}; */

struct Node
{
    string val;
    string suit;
    Node *next;
    Node() : val(""), suit(""), next(nullptr){};
    Node(string val, string suit) : val(val), suit(suit), next(nullptr){};
};

void insertOnInit(Node *&head, string val, string suit)
{
    Node *newNode = new Node(val, suit);
    newNode->next = head;
    head = newNode;
}

void printList(Node *head)
{
    while (head != nullptr)
    {
        cout << head->val << " de " << head->suit << endl;;
        head = head->next;
    }
}

void bubbleSort(Node* &head) {
    if (head == nullptr || head->next == nullptr) return;
    Node *current = head;
    Node *sorted = nullptr;

    while (current != nullptr){
        Node *next = current->next;
        if (sorted == nullptr || sorted->suit >= current->suit) {
            current->next = sorted;
            sorted = current;
        } else {
            Node *temp = sorted;
            while (temp->next != nullptr && temp->next->suit < current->suit) {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }
        current = next;
    }
    head = sorted;
}

int main()
{
    Node *head = nullptr;
    insertOnInit(head, "5", "Diamantes");
    insertOnInit(head, "2", "Corazones");
    insertOnInit(head, "4", "Picas");
    insertOnInit(head, "3", "Treboles");
    insertOnInit(head, "1", "Corazones");
    insertOnInit(head, "6", "Diamantes");
    insertOnInit(head, "7", "Picas");
    insertOnInit(head, "8", "Treboles");
    insertOnInit(head, "9", "Corazones");


    cout << "Original: " << endl;
    printList(head);
    cout << "Ordenada: " << endl;
    bubbleSort(head);
    printList(head);
    return 0;
}