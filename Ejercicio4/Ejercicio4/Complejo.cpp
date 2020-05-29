
#include <iostream>
#include "Complejo.h"
using namespace std;
void Complejo::llenarTorre() {
	torre = new Torre[7];
	for (int i = 0;i < 1;i++) {
		cout << "Torre" << i + 1 << endl;
		torre[i].llenarTorre();
		// para NO hacer muchas peticiones al usuario
		// decidi copiar 7 veces la primera torree que se introduce
		//aunque se podia pedir completamente normal todos
		// los datos necesarios cambiando enves de 
		// i<1 iria i<7 
	}
	//simplemente creado para septumplicar las torres
	for (int i = 1;i <= 6;i++) {
		torre[i] = torre[0];
	}
}
int Complejo::totalC() {
	int aux = 0;
	for (int i = 0;i < 7;i++) {
		aux += torre[i].totalT();
	}
	return aux;
}
void Complejo::PromPisT() {
	for (int i = 0;i < 7;i++) {
		cout << "Torre: " << (i + 1)<<". Hab:" << torre[i].PromHabitP() << endl;
	}
}
int Complejo::PromHabitT() {
	int aux = 0;
	for (int i = 0;i < 7;i++) {
		aux += torre[i].totalT();
	}
	return aux / 7;
}