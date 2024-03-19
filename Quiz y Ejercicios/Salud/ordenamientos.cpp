#include <iostream>
#include <string>
#include <list>
#include <cmath>

using namespace std;


struct Node {
    string data;
    Node *next;
    Node (string val): data(val), next(nullptr) {};
};

void insertOnInit(Node * &head, string val) {
    Node *newNode = new Node(val);
    newNode->next = head;
    head = newNode;
}

void showList(Node *head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}


int main(int argc, char **argv) {
    Node* head = nullptr;
    insertOnInit(head, "1");
    insertOnInit(head, "3");
    insertOnInit(head, "5");

    
    cout << "Lista Daniel: " << endl;
    showList(head);
}