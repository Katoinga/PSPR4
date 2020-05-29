
#include <iostream>
#include "Pisos.h"
using namespace std;
void Piso::llenarPiso() {
	dpts = new Departamentos[6];
	for (int i = 0;i < 6;i++) {
		string nm = "Departamento " + to_string(i + 1);
		dpts[i].setNombreD(nm);
		cout << "Habitantes del Departamento: " << i + 1 << ": ";
		int h;
		cin >> h;
		dpts[i].setHabitantes(h);
	}
}

void Piso::setNameP(std::string n) {
	nomPis = n;
}

string Piso::getNameP() {

	return nomPis;
}

int Piso::totalP() {
	int aux = 0;
	for (int i = 0;i < 6;i++) {
		aux += dpts[i].gethabitantes();
	}
	return aux;
}
int Piso::PromHabitD() {
	int aux = 0;
	for (int i = 0;i < 6;i++) {
		aux += dpts[i].gethabitantes();
	}
	// entre 6 porque tienen 6 departamentos
	return  aux / 6;
}