#include <iostream>
#include <list>

using namespace std;

struct Node
{
    int val;
    string suit;
    Node *next;
    Node() : val(0), suit(""), next(nullptr){};
    Node(int val, string suit) : val(val), suit(suit), next(nullptr){};
};

void insertOnInit(Node *&head, int val, string suit)
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

void bubbleSortSuits(Node* &head) {
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

void bubbleSortValues(Node* &head) {
    if (head == nullptr || head->next == nullptr) return;
    Node *current = head;
    Node *sorted = nullptr;

    while (current != nullptr){
        Node *next = current->next;
        if (sorted == nullptr || sorted->val >= current->val) {
            current->next = sorted;
            sorted = current;
        } else {
            Node *temp = sorted;
            while (temp->next != nullptr && temp->next->val < current->val) {
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
    insertOnInit(head, 5, "Diamantes");
    insertOnInit(head, 2, "Corazones");
    insertOnInit(head, 4, "Picas");
    insertOnInit(head, 3, "Treboles");
    insertOnInit(head, 1, "Corazones");
    insertOnInit(head, 6, "Diamantes");
    insertOnInit(head, 7, "Picas");
    insertOnInit(head, 8, "Treboles");
    insertOnInit(head, 9, "Corazones");


    cout << "Original: " << endl;
    printList(head);
    cout << "Ordenada por traje: " << endl;
    bubbleSortSuits(head);
    printList(head);
    cout << "Ordenada por valor: " << endl;
    bubbleSortValues(head);
    printList(head);
    return 0;
}