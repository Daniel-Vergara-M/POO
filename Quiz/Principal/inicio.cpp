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
    persona1.calcularIMC();
    return 0;
}