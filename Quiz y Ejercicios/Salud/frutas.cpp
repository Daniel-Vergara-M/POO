#include <iostream>
#include <list>

using namespace std;

int main()
{
    list<string> frutas;
    frutas.push_back("Manzana");
    frutas.push_back("Uva");
    frutas.push_back("Melón");
    frutas.push_back("Fresa");
    for (auto &fruta : frutas)
    {
        cout << fruta << endl;
    }
    auto it = next(frutas.begin(), 1);
    frutas.insert(it, "Arandanos");
    for (auto &fruta : frutas)
    {
        cout << fruta << endl;
    }
    frutas.pop_front();
    frutas.erase(next(frutas.begin(), 2));
    frutas.remove("Fresa");
    cout << *next(frutas.begin(), 3) << endl;
    frutas.get_allocator();

    return 0;
}