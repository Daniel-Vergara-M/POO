#include <iostream>
#include <string>
#include "../Salud/persona.cpp"

using namespace std;

int main()
{
    Persona persona1;
    persona1.pedirDatos();
    persona1.mostrarPersona();
    if (persona1.mayorEdad())
    {
        cout << "Es mayor de edad" << endl;
    }
    else
    {
        cout << "Es menor de edad" << endl;
    }
    string peso = persona1.calcularIMC();
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
    return 0;
}