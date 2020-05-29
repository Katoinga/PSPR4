#include "iostream"
#include "string.h"
#include "stdlib.h"
using namespace std;

void funcionamiento(string letra, string palabra, string palabraGuiones, bool acierto, bool fin, int vidas, int intentos);
int main() {
	// definiendo variables
	string palabraGuiones = " ";
	string palabra = " ";
	int vidas=0;	
	int categoria = 0;
	int dificultad = 0;
	int intentos = 0;
	string letra = " ";
	bool fin = false;
	int indice=0;
	bool acierto = false;
	string animales[] = { "perro","abeja","burro","hiena","erizo" };
	string nombres[] = { "emilio","brayan","aldair","ximena","dorian" };
	string paises[] = { "peru","iran","irak","cuba"};

	// menu del ahorcado
	cout << "Bienvenidos el Ahorcado" << endl;
	cout << endl;
	cout << "Este juego consiste en poder adivinar toda la palabra, letra por letra." << endl;
	cout << "Seleccione la categoria de palabras " << endl;
	cout << "1. Animales, 2. Nombres, 3. Paises" << endl;
	cout << "Ingresa la categoria: ";
	cin >> categoria;
	//se selecciona la categoria
	switch (categoria) {
	case 1:
		//saco uno aleatorio
		indice = rand() %5;
		palabra = animales[indice];
		palabraGuiones = "_____";
		fin = false;
		intentos = 0;

		break;
	case 2:
		//saco uno aleatorio
		indice = rand() % 5;
		palabra = nombres[indice];
		palabraGuiones = "______";
		fin = false;
		intentos = 0;

		break;
	case 3:
		//saco uno aleatorio
		indice = rand() % 4;
		palabra = paises[indice];
		palabraGuiones = "____";
		fin = false;
		intentos = 0;
		break;
	default:
		cout << "escribe una categoria entre 1 y 3" << endl;
		break;
	}
	cout << "1. Facil, 2. Medio,3.Dificil: ";
	cout << "Ingresa la dificultad: ";
	cin >> dificultad;
	// seleccionamos la dificultad
	switch (dificultad) {
	case 1:
		vidas = 8;		break;
	case 2:
		vidas = 4;		break;
	case 3:
		vidas = 2;		break;
	default:
		cout << "escribe una dificultad entre 1 y 3" << endl;

		break;
	}
	cout << "===================================================================================\n";
	cout << "El Ahorcado" << endl;
	cout << "Intentos:" << intentos << "\tVidas: " << vidas << endl;
	cout << "palabra: " << palabraGuiones << endl;
	cout << endl;
	funcionamiento(letra, palabra, palabraGuiones, acierto, fin, vidas, intentos);
	return 0;
}
//funcionamiento del problema
void funcionamiento( string letra, string palabra, string palabraGuiones,bool acierto, bool fin, int vidas, int intentos) {
	while (fin == false) {
		cout << "ingresa solo UNA letra: ";
		cin >> letra;
		cout << endl;
		if (letra.size() == 0) {
			cout << "ingresa una letra" << endl;
		}
		else
			if (letra.size() == 1) {
				for (int i = 0; i < palabra.size(); i++) {
					if (letra[0] == palabra[i]) {
						palabraGuiones[i] = palabra[i];
						acierto = true;
					}
				}
				if (acierto == false) {
					vidas--;
				}
				intentos++;
				acierto = false;
			}
			else {
				cout << "ingresa solo una letra" << endl;
			}
		if (palabraGuiones == palabra) {
			cout << "El Ahorcado" << endl;
			cout << "Intentos:" << intentos << "\tVidas: " << vidas << endl;
			cout << "Palabra: " << palabra << endl;
			cout << endl;
			cout << "HAZ GANADO" << endl;
			cout << "Winner!!!" << endl;
			cout << "===================================================================================" << endl;
			break;

		}
		if (vidas == 0) {
			fin = true;
		}
		letra = " ";
		cout << "El Ahorcado" << endl;
		cout << "Intentos:" << intentos << "\tVidas: " << vidas << endl;
		cout << endl;
		cout << "palabra: " << palabraGuiones << endl;
		cout << endl;

		if (fin == true) {
			cout << " El Ahorcado" << endl;
			cout << "Intentos:" << intentos << "\tVidas: " << vidas << endl;
			cout << endl;
			cout << "GAME OVER" << endl;
			cout << "Has perdido!!!" << endl;
			cout << "===================================================================================" << endl;

		}
	}
	cout << "Se ejecuto correctamente";

}