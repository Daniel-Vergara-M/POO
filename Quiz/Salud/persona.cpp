#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Persona
{
private:
    string tipoDoc;
    string documento;
    string nombre;
    string apellido;
    int peso;
    double estatura;
    int edad;
    string sexo;

public:
    Persona(){};
    string getTipoDoc()
    {
        return this->tipoDoc;
    }
    string getDocumento()
    {
        return this->documento;
    }
    string getNombre()
    {
        return this->nombre;
    }
    string getApellido()
    {
        return this->apellido;
    }
    string getNombreCompleto()
    {
        return this->getNombre() + " " + this->getApellido();
    }
    int getPeso()
    {
        return this->peso;
    }
    double getEstatura()
    {
        return this->estatura;
    }
    int getEdad()
    {
        return this->edad;
    }
    string getSexo()
    {
        return this->sexo;
    }
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
        cout << "Nombre: " << this->getNombre() << endl;
        cout << "Apellido: " << this->getApellido() << endl;
        cout << "Tipo de documento: " << this->getTipoDoc() << endl;
        cout << "Documento: " << this->getDocumento() << endl;
        cout << "Género: " << this->getSexo() << endl;
        cout << "Edad: " << this->getEdad() << endl;
        cout << "Peso: " << this->getPeso() << " Kg" << endl;
        cout << "Estatura: " << this->getEstatura() << endl;
    }
    bool mayorEdad()
    {
        if (this->edad >= 18)
        {
            return true;
        }
        return false;
    }
    string calcularIMC()
    {
        float pesoActual = this->getPeso() / (pow(this->getEstatura(), 2));
        if (pesoActual < 20)
        {
           return "PESOBAJO";
        }
        else if (pesoActual >= 20 && pesoActual <= 25)
        {
            return "PESOIDEAL";
        }
        else
        {
           return "SOBREPESO";
        }
    }
};
