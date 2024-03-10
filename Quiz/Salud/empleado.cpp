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
    double honorarios;

public:
    Empleado() : Persona(){};
    ~Empleado(){};
    string getCargo()
    {
        return this->cargo;
    }
    void setCargo(string cargo) {
        this->cargo = cargo;
    }
    int getValorHora()
    {
        return this->valorHora;
    }
    void setValorHora(int valorHora) {
        this->valorHora = valorHora;
    }
    int getHorasTrabajadas()
    {
        return this->horasTrabajadas;
    }
    void setHorasTrabajadas(int horasTrabajadas) {
        this->horasTrabajadas = horasTrabajadas;
    }
    string getDepartamento()
    {
        return this->departamento;
    }
    void setDepartamento(string departamento) {
        this->departamento = departamento;
    }
    double getHonorarios() {
        return this->honorarios;
    }
    void setHonorarios(double honorarios) {
        this->honorarios = honorarios;
    }
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

    double calcularHonorarios()
    {
        this->setHonorarios((this->valorHora * this->horasTrabajadas) - (this->valorHora * this->horasTrabajadas) * 0.966);
        return this->honorarios;
    }

    void mostrarDatos(){
        Persona::mostrarDatos();
        cout << "Cargo: " << this->cargo << endl;
        cout << "Valor por hora: " << this->valorHora << endl;
        cout << "Horas trabajadas: " << this->horasTrabajadas << endl;
        cout << "Departamento: " << this->departamento << endl;
        cout << "Honorarios: " << this->calcularHonorarios() << endl;
    }
};