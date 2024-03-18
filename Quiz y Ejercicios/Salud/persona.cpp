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
    ~Persona(){};
    string getTipoDoc()
    {
        return this->tipoDoc;
    }
    void setTipoDoc(string tipoDoc)
    {
        this->tipoDoc = tipoDoc;
    }
    string getDocumento()
    {
        return this->documento;
    }
    void setDocumento(string documento)
    {
        this->documento = documento;
    }
    string getNombre()
    {
        return this->nombre;
    }
    void setNombre(string nombre)
    {
        this->nombre = nombre;
    }
    string getApellido()
    {
        return this->apellido;
    }
    void setApellido(string apellido)
    {
        this->apellido = apellido;
    }
    string getNombreCompleto()
    {
        return this->nombre + " " + this->apellido;
    }
    int getPeso()
    {
        return this->peso;
    }
    void setPeso(int peso)
    {
        this->peso = peso;
    }
    double getEstatura()
    {
        return this->estatura;
    }
    void setEstatura(double estatura)
    {
        this->estatura = estatura;
    }
    int getEdad()
    {
        return this->edad;
    }
    void setEdad(int edad)
    {
        this->edad = edad;
    }
    string getSexo()
    {
        return this->sexo;
    }
    void setSexo(string sexo)
    {
        this->sexo = sexo;
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

    void mostrarDatos()
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
    double calcularIMC()
    {
        double pesoActual = this->getPeso() / (pow(this->getEstatura(), 2));
        return pesoActual;
    }
};
