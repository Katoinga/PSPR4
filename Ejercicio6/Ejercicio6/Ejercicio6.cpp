

#include<iostream>
#include<conio.h>

using namespace std;
char comprobarSimetria(int** A, int filas, int columnas);
char comprobarAntiSimetria(int** A, int filas, int columnas);
void imprimirMatriz(int** m, int f, int c);
void rellenarMatriz(int** m, int f, int c);
int** hallarTranspuesta(int** m, int f, int c);
void Triangular(int** A, int fila, int columna);
void Triangular2(int** A, int fila, int columna);
int main() {
	int filas=1, columnas=1;
	char band = 'F';
	char band2 = 'F';
	int op;
	cout << "Digite el numero de filas: "; 
	cin >> filas;
	cout << "Digite el numero de columnas: "; 
	cin >> columnas;
	int** A;
	// Inicializo matrices dinamicas con punteros**
	A = new int * [filas];
	for (int i = 0; i < filas; i++) {
		A[i] = new int[columnas];
	}
	int** aux;
	aux = new int* [filas];
	for (int i = 0; i < filas; i++) {
		aux[i] = new int[columnas];
	}

	//Rellenando matriz
	rellenarMatriz(A, filas, columnas);
	imprimirMatriz(A, filas, columnas);
	//
	
		cout << "Menu:\n1.Transpuesta\n2.Simetria\n3.M.T.Superior o inferior";
		cout <<"\nIngrese opcion\n";
		cin >> op;
	
		switch (op)
		{
		case 1:
			cout << "\nTranpuesta\n";
			aux = hallarTranspuesta(A, filas, columnas);
			imprimirMatriz(aux, columnas, filas);

			break;
		case 2:
			cout << "\nComprobando si es simetrica o antisimetrica\n";
			band2 = comprobarAntiSimetria(A, filas, columnas);
			band = comprobarSimetria(A, filas, columnas);
			aux = hallarTranspuesta(A, filas, columnas);
			imprimirMatriz(aux, columnas, filas);
			if (band == 'V') {
				cout << "\nEs una matriz simetrica\n";
			}
			else {
				cout << "\nNo es simetrica";
			}
			if (band2 == 'A') {
				cout << "\nEs una matriz anti-simetrica\n ";
			}
			else {
				cout << "\nNo es anti simetrica";
			}
			break;
		case 3:
			cout << "\nComprobando si es matriz triangular\n";
			cout << "superior o inferior\n";
			Triangular(A, filas, columnas);
			Triangular2(A, filas, columnas);
			break;
		default:
			cout << "\nno es una opcion valida!!\n";
			break;
		}
	
	
	return 0;
}
// calcula la transpuesta de la matriz
// retorna una matriz transpuesta de la matriz inicial
int** hallarTranspuesta(int** m, int filas, int columnas) {
	int** B;
	B = new int* [columnas];
	for (int i = 0; i < columnas; i++) {
		B[i] = new int[filas];
	}
	
	for (int i = 0;i < columnas;i++) {
		for (int j = 0;j < filas;j++) {
			B[i][j] = m[j][i];
		}
	}
	return B;
}

// comprueba si es anti simetrica segun la formula
char comprobarAntiSimetria(int** A, int filas, int columnas) {
	char flag = 'A';
	//el if es para no tener que hacer todo el calculo si 
	// la matriz no es cuadratica
	if (filas == columnas) {
		for (int i = 0;i < filas;i++) {
			for (int j = 0;j < columnas;j++) {
				//podria llamar a la funcion de la transpuesta pero 
				//es mucho menos codigo y mas simple asi
				// antisimimetrica si opuesta es igual a su transpuesta
				if (A[i][j] != -A[j][i]) {
					flag = 'F';
				}
			}
		}
	}
	else {
		flag = 'F';
	}
	return flag;
}
// comprueba si es simetrica segun la formula
char comprobarSimetria(int** A, int filas, int columnas) {
	char flag = 'V';
	//el if es para no tener que hacer todo el calculo si 
	// la matriz no es cuadratica
	if (filas == columnas) {
		for (int i = 0;i < filas;i++) {
			for (int j = 0;j < columnas;j++) {
				//podria llamar a la funcion de la transpuesta pero 
				//es mucho menos codigo y mas simple asi
				if (A[i][j] != A[j][i]) {
					flag = 'F';
				}
			}
		}

	}
	else {
		flag = 'F';
	}
	return flag;
}

void Triangular(int** A, int fila, int columna){
	// imrpime el tringular superior
	cout << "\n\n\n\t Triangular Inferior \n\n";
	for (int i = 0;i < fila;i++) {
		for (int j = 0;j < columna;j++) {
			cout << "\t ";
			if (j >= i)                cout << A[i][j];
		}
		cout << endl;
	}
	// imprime el triangular inferior
	cout << "\n\n\n\t Triangular Superior \n\n";
	for (int i = 0;i < fila;i++) {
		for (int j = 0;j < columna;j++) {
			cout << "\t ";
			if (i >= j)                cout << A[i][j];
		}
		cout << endl;
	}
	int  inferior = 0;
	int i, j;
	i = 1;
	//Inferior:
	// encuentra si se encuentran en la region inferior de la matriz
	// aunque en realidad se llame matriz inferior cuando estan arriba a la derecha
	while (i < fila) {
		j = 0;
		do {
			if (A[i][j] == 0) {
				j++;
			}
			else {
				inferior = 1;
				break;
			}
		} while ((j < i) && (inferior == 0));
		i++;
	}
	//Superior: 
	//encuentra si se encuentran en la region superior de la matriz
	// aunque en realidad se llame matriz superior cuando estan abajo a la izq

	if (inferior == 0) {
		cout << "\n!!!EXISTETriangular superior";
	}
	
	if ((inferior == 1)) {
		cout << "\nNO superior";
	}
	cout << endl;
}
void Triangular2(int** A, int fila, int columna) {
	int superior = 0;
	
	//Superior: 
	//encuentra si se encuentran en la region superior de la matriz
	// aunque en realidad se llame matriz superior cuando estan abajo a la izq
	int f = 0, c = 1;
	while (f < fila)
	{
		// no comprueba la ultima fila porque siempre daria que no existe
		if (f >=fila-1) {
			break;
		}
		do
		{
			if (A[f][c] == 0) {
				c++;			
			}
			else {
				superior = 1;
				cout << f << c << A[f][c];
				break;
			}
		} while ((c < fila) && (superior == 0));
		f++;
		c = f+1;
	}

	if (superior == 0) {
		cout << "\n!!EXISTE Triangular  inferior ";
	}
	if ((superior == 1)) {
		cout << "\nNo inferior";
	}
	cout << endl;
}

// funcion que rellena la matriz con lo que introduzca el usuario
void rellenarMatriz(int** m, int f, int c) {
	for (int i = 0;i < f;i++) {
		for (int j = 0;j < c;j++) {
			cout << "Digite un valor para la matriz: ";
			cin >> m[i][j];
		}
	}
}
// int f: filas, int c: columnas, int**m matriz
void imprimirMatriz(int** m,int f, int c) {
	
	for (int i = 0;i < f;i++) {
		for (int j = 0;j < c;j++) {
			cout << m[i][j] << " ";
		}
		cout << endl;
	}
}
