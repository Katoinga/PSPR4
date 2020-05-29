#include <iostream>
#include <fstream>

using namespace std;

void multmat(int** A, int** B, int** C);
void imprimirMatriz(int** m);
int main() {
	// primero definimos bien los punteros
	int** A, ** B, ** C;
	A = new int* [3], B = new int* [3], C = new int* [3];
	for (int j = 0; j < 3; j++) {
		A[j] = new int[3], B[j] = new int[3], C[j] = new int[3];

	}
	int m1[3][3] = {1,4,7,
					2,5,8,
					3,6,9};
	int m2[3][3] = {1,-1,2,
					2,-1,2,
					3,-3,0 };
	// llenamos A segun m1
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			A[i][j]= m1[i][j] ;
		}
	}
	// llenamos B segun m2
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			B[i][j] = m2[i][j];
		}
	}
	// muestra las matrices
	cout << "Primera matriz:" << endl;
	imprimirMatriz(A);
	cout << "Segunda matriz:" << endl;
	imprimirMatriz(B);
	// Multiplicación de matrices A y B
	multmat(A, B, C);
	// Impresión de las matrices resultante
	cout << "matriz resultante:" << endl;
	imprimirMatriz(C);
	delete[] A, B, C; //Desasigna la memoria
	return 0;
}
// funcion para imprimir la matriz
void imprimirMatriz(int** A) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << A[i][j] << " ";
		}
		cout << endl;
	}
}
// obtiene median punteros las tres matrices
// se aplica la formula de multiplicacion
// mediante 3 for, los dos primeros inicializan 
// la matriz en 0, despues se aplica la formula
// nueva[i][j]+primera[i][k]*segunda[k][j]
void multmat(int** A, int** B, int** C) {

	for (int i = 0; i < 3; i++) {

		for (int j = 0; j < 3; j++) {

			C[i][j] = 0;

			for (int k = 0; k < 3; k++) {

				C[i][j] = C[i][j] + A[i][k] * B[k][j];

			}

		}

	}

}