#include <iostream>
#include <string>
#include <vector>
using namespace std;
struct Poker
{
    string name;
    string suit;
    Poker(string name, string suit) : name(name), suit(suit) {}
};
void bubbleSort( vector<Poker> deck, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - 1; j++)
        {
            Poker temp = deck[j];
            deck[j] = deck[j + 1];
            deck[j + 1] = temp;
        }
    }
}
void printVector(vector<Poker> deck, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << deck[i].name << " de " << deck[i].suit << endl;
    }
}
void getCards(vector<Poker> &deck, string name, string suit)
{
    deck.push_back(Poker(name, suit));
}
int main()
{
    vector<Poker> deck;
    string val;
    string suit;
    for (int i = 0; i < 13; i++)
    {
        cout << "Ingrese el valor de la carta: ";
        cin >> val;
        cout << "Ingrese el traje de la carta: ";
        cin >> suit;
        getCards(deck, val, suit);
    }
    cout << "Original: " << endl;
    printVector(deck, 13);
    cout << "Ordenado: " << endl;
    bubbleSort(deck, 13);
    printVector(deck, 13);
    return 0;
}