#include <iostream>
#include <cmath>

using namespace std;

double iterador(double x)
{
	cout << x << endl;
	return x - (2*pow(x,2)-5*x-2) / double(4*x-5);
}

double f1(double x)
{
	return 0.4* pow(x, 2) - 0.4;
}

double f2(double x)
{
	return sqrt(2.5 * x + 1);
}

double f3(double x)
{
	return -sqrt(2.5 * x + 1);
}

double f4(double x)
{
	return 2.5 + 1.0 / x;
}

void Metodo_Newton(double guess)
{
	double xn = guess;
	int iteracoes = 0;
	for (size_t i = 0; i < 20; i++)
	{
		xn = iterador(xn);
		iteracoes++;
	}
	cout << "\n Iteracoes = " << iteracoes;
	cout << "\n Raiz: " << xn << endl;
}

void Metodo_Picard_Peano(double guess)
{
	double xn = guess;
	int iteracoes = 0;
	for (size_t i = 0; i < 20; i++)
	{
		xn = f1(xn);
		iteracoes++;
	}
	cout << "\n Iteracoes = " << iteracoes;
	cout << endl << "\n Raiz: " << xn << endl;
}

int main()
{

	/*Metodo_Newton(-0.3);
	Metodo_Newton(3);*/

	//Metodo_Picard_Peano(-0.3);
	Metodo_Picard_Peano(-2);

	system("pause");
	return 0;
}