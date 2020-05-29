#include <stdio.h>
#include <iostream>
// defino para poder crear mat[][]

using namespace std;
//definen funciones
void imprimirMatriz(int mat[3][3], int fila, int columna);
int puntoSilla(int mat[3][3], int posFila, int posColumna, int fila, int columna);

int main()
{
	int mat[3][3] = {
		3, 3, 6,
		1, 3, 2,
		1, 2, 1 };

	cout << endl;
	//se obtienen los tamanos de filas columnas
	int filas = (sizeof(mat) / sizeof(mat[0]));
	int columnas = (sizeof(mat[0]) / sizeof(mat[0][0]));
	cout << "Matriz: \n";
	imprimirMatriz(mat,filas,columnas);

	// recorro toda la matriz en busca de un punto de silla
	// si encuentro uno nombro la posicion [i][j]
	for (int i = 0; i < filas; i++) {
		for (int j = 0; j < columnas; j++) {
			if (puntoSilla(mat, i, j,filas,columnas) == 1) {
				cout << "Punto de silla encontrado en fila: "<<i<<"  columna: "<<j<<endl;
			}
		}
	}

	return 0;
}
//metodo que imprime una matriz bidimensional
void imprimirMatriz(int mat[3][3], int fila, int columna)
{

	int i, j;

	for (i = 0;  i< fila; i++)
	{
		for (j = 0;  j< columna; j++) {
			cout << mat[i][j]<<" ";
		}
		cout << endl;
	}
}
// metodo que ubicado en un punto obtiene si es punto de silla o no
int puntoSilla(int mat[3][3], int indI, int indJ, int fila, int columna)
{
	// variable que sirve para ver si no encontro punto.
	// 1 es si encontro 0 es no
	// se presupone que es punto
	int noenc = 1;
	for (int i = 0; i < fila ; i++)
	{
		for (int j = 0; j < columna; j++)
		{
			// busca si no es el mayor de su columna o si no es tambien el menor de su fila
			if (mat[indI][indJ] > mat[indI][j] || mat[indI][indJ] < mat[i][indJ]) {
				noenc = 0;
			}
		}
	}

	return noenc;
}

