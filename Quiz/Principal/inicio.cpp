#include <iostream>
#include <string>
#include "../Salud/persona.cpp"
#include "../Salud/empleado.cpp"

using namespace std;

class Inicio
{
private:
    Persona p;
    Empleado e;
public:
    Inicio(){};
    ~Inicio(){};
    void runPersona()
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
    void runEmpleado()
    {
        this->e.pedirDatos();
        this->e.mostrarDatos();
        if (this->p.mayorEdad())
        {
            cout << "Es mayor de edad" << endl;
        }
        else
        {
            cout << "Es menor de edad" << endl;
        }
        this->e.calcularHonorarios();
        cout << "Los honorarios son: " << this->e.getHonorarios() << endl;
    }
};

int main()
{
    Inicio inicio;
    inicio.runPersona();
    inicio.runEmpleado();
    return 0;
}