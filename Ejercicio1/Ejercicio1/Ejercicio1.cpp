#include <iostream>

using namespace std;
int factorial(int n);
int combinacion(int n,int k);
int numeros(int n);
void coeficientes(int n, int a[]);
void triangulo(int n, int a[]);
int main()
{
	int n;
	cout << "Ingrese el numero de filas que desea: ";
	cin >> n;
	int* a;
	a = new int[numeros(n)];
	coeficientes(n,a);
	triangulo(n,a);

}
// funcion que imprime el triangulo con un arreglo dado
void triangulo(int n,int a[]) {
	//uso de punteros para imprimir todos los elementos
	// *arr++ salta 4 bytes lo que da el siguiente elemento
	// del arreglo
	int* arr;
	arr = a;
	for (int i = 0; i < n;i++) {
		for (int h = 0;h < n - i;h++) {
			//numero de espacios
			cout << " ";
		}
		for (int j = 0;j <= i;j++) {
				cout << *arr++ << " ";
		}
		
		cout << "\n";
	}
}
void coeficientes(int n, int a[]) {
	//el triangulo de pascal se contruye con 
	// coeficientes binomiales
	// para eso hizo el metodo combinacion.
	int pos = 0;
	for (int i = 0; i < n;i++) {
		for (int j = 0;j <= i;j++) {
			a[pos]= combinacion(i, j) ;
			pos++;
		}

	}
}
//funcion que halla el numero de elementos del triangulo
int numeros(int n) {
	int siz = 0;
	while (n >= 0) {
		siz += n;
		n--;
	}
	return siz;
}
// necesario para la formula de combinacion
int factorial(int n) {
	int f = 1;
	for (int i = 1;i <= n;i++)
		f = f * i;

	return f;
}
int combinacion(int n, int k) {
	// sacado de la formula de la combinacion
	int c= (factorial(n)) / (factorial(k) 
		* factorial(n - k));
	return c;
}