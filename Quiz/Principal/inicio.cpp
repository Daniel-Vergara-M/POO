#include <iostream>
#include <string>
#include "../Salud/persona.cpp"

using namespace std;

class Inicio
{
private:
    Persona p;
public:
    Inicio(){};
    void run()
    {
        this->p.pedirDatos();
        this->p.mostrarDatos();
        if (this->p.mayorEdad())
        {
            cout << "Es mayor de edad" << endl;
        }
        else
        {
            cout << "Es menor de edad" << endl;
        }
        double peso = this->p.calcularIMC();
        if (peso < 20)
        {
            cout << "El peso esta por debajo de lo ideal" << endl;
        }
        else if (peso >= 20 && peso <= 25)
        {
            cout << "El peso es ideal" << endl;
        }
        else
        {
            cout << "El peso esta por encima de lo ideal" << endl;
        }
    }
};

int main()
{
    Inicio inicio;
    inicio.run();
    return 0;
}