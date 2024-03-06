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
        this->p.mostrarPersona();
        if (this->p.mayorEdad())
        {
            cout << "Es mayor de edad" << endl;
        }
        else
        {
            cout << "Es menor de edad" << endl;
        }
        string peso = this->p.calcularIMC();
        if (peso == "PESOBAJO")
        {
            cout << "El peso esta por debajo de lo ideal" << endl;
        }
        else if (peso == "PESOIDEAL")
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