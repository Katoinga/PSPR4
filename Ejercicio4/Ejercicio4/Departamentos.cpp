
#include "Departamentos.h"
#include <iostream>
using namespace std;
int Departamentos::gethabitantes() {
	return hbt;
}
void Departamentos::setNombreD(std::string n) {
	nombre = n;
}
std::string Departamentos::getNombreD() {
	return nombre;
}
void Departamentos::setHabitantes(int n) {
	hbt = n;
}
void Departamentos::MostrarDepa() {
	cout << nombre << "\tHabitantes: " << hbt << endl;
}
