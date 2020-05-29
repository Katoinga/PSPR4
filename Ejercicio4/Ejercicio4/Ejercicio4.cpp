#include <iostream>
#include "Complejo.h"
using namespace std;

int main() {
	int opcion;
	Complejo* complejo = new Complejo[1];
	cout << "==Complejo de Vivienda===" << endl;
	cout << "Introduzca informacion del Complejo" << endl;
	complejo[0].llenarTorre();
	cout<< "1: Total de habitantes del Complejo\n2: Promedio de habitantes por piso de cada Torre"<<
		"\n3: Promedio de habitantes por Torre\n4: Salir\n\n";
	cin >> opcion;
	while (opcion != 4) {
		if (opcion == 1) {
			cout << "\nEl total de Habitantes del Complejo es: " << complejo[0].totalC() << endl;
		}
		else if (opcion == 2) {
			complejo[0].PromPisT();
		}
		else if (opcion == 3) {
			cout << "\nEl Promedio de Habitantes por Torre es: " << complejo[0].PromHabitT() << endl;
		}
		cout
			<< "\n1: Total de habitantes del Complejo\n2: Promedio de habitantes por piso de cada Torre\n" <<
			"\n3: Promedio de habitantes por Torre\n4: Salir\n\n";
		cin >> opcion;
	}

}
