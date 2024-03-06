#include <iostream>
#include <string>

using namespace std;

class Persona
{
private:
    string tipoDoc;
    string documento;
    string nombre;
    string apellido;
    float peso;
    float estatura;
    int edad;
    string sexo;

public:
    void pedirDatos()
    {
        cout << "Ingrese su nombre: ";
        cin >> this->nombre;
        cout << "Ingrese su apellido: ";
        cin >> this->apellido;
        cout << "Ingrese su tipo de documento (T.I/C.C): ";
        cin >> this->tipoDoc;
        cout << "Ingrese su documento (En números): ";
        cin >> this->documento;
        cout << "Ingrese su género (Hombre/Mujer): ";
        cin >> this->sexo;
        cout << "Ingrese su edad (En números): ";
        cin >> this->edad;
        cout << "Ingrese su peso (En kilogramos): ";
        cin >> this->peso;
        cout << "Ingrese su estatura (En metros): ";
        cin >> this->estatura;
    }

    void mostrarPersona()
    {
        cout << "Nombre: " << this->nombre << endl;
        cout << "Apellido: " << this->apellido << endl;
        cout << "Tipo de documento: " << this->tipoDoc << endl;
        cout << "Documento: " << this->documento << endl;
        cout << "Género: " << this->sexo << endl;
        cout << "Edad: " << this->edad << endl;
        cout << "Peso: " << this->peso << endl;
        cout << "Estatura: " << this->estatura << endl;
    }
    bool mayorEdad()
    {
        if (this->edad >= 18)
        {
            return true;
        }
        return false;
    }
    void calcularIMC()
    {
        float pesoActual = this->peso / (pow(this->estatura, 2));
        if (pesoActual < 20)
        {
            cout << "El peso está por debajo de lo ideal" << endl;
        }
        else if (pesoActual >= 20 && pesoActual <= 25)
        {
            cout << "El peso es ideal" << endl;
        }
        else
        {
            cout << "El peso está por encima de lo ideal" << endl;
        }
    }
};

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