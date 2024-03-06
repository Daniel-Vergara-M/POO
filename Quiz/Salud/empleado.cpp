#include <iostream>
#include <string>
#include "persona.cpp"

using namespace std;

class Empleado : public Persona
{
private:
    string cargo;
    int valorHora;
    int horasTrabajadas;
    string departamento;

public:
    Empleado(){};
    void pedirDatos()
    {
        Persona::pedirDatos();
        cout << "Ingrese el cargo: ";
        cin >> this->cargo;
        cout << "Ingrese el valor de la hora (En números, sin puntos ni comas): ";
        cin >> this->valorHora;
        cout << "Ingrese las horas trabajadas (Hora completa): ";
        cin >> this->horasTrabajadas;
        cout << "Ingrese el departamento: ";
        cin >> this->departamento;
    }

    void calcularHonorarios() {
        double honorarios = (this->valorHora * this->horasTrabajadas) - (this->valorHora * this->horasTrabajadas) * 0.966;
        cout << "Tipo de documento: " << this->getTipoDoc() << endl
                << "Documento: " << this->getDocumento() << endl
                << "Nombre: " << this->getNombreCompleto() << endl
                << "Cargo: " << this->cargo << endl
                << "Valor por hora: " << this->valorHora << endl
                << "Honorarios: " << honorarios << endl;

    }
};