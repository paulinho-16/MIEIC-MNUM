#define _USE_MATH_DEFINES

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

double f(double x)
{
	return pow(x,4) + 2*pow(x,3)-x-1;
}

double d_f(double x)
{
	return 4 * pow(x, 3) + 6 * pow(x, 2) - 1;
}

double f1(double x) // variancia de Picard_Peano para f(x) = 2x^2-5x-2
{
	return (2 * pow(x, 2) - 2) / 5.0;
}

void Metodo_Bissecao(double a, double b)
{
	double xn;
	int iteracoes = 0;
	while (abs(a - b) > pow(10, -5))
	{
		xn = (a + b) / 2.0;
		cout << iteracoes << "\ta = " << a << "\tb = " << b << "\tf(a) = " << f(a) << "\tf(b) = " << f(b) << "\txn = " << xn << "\tf(xn) = " << f(xn) << endl;
		if (f(a) * f(xn) < 0)
			b = xn;
		else
			a = xn;
		iteracoes++;
	}
	cout << "\nRaiz: " << xn << endl;
}

void Metodo_Corda(double a, double b)
{
	double xn;
	int iteracoes = 0;
	for (unsigned int i = 0; i < 50; i++)
	{
		xn = (a * f(b) - b * f(a)) / (double)(f(b) - f(a));
		cout << iteracoes << "\ta = " << a << "\tb = " << b << "\tf(a) = " << f(a) << "\tf(b) = " << f(b) << "\txn = " << xn << "\tf(xn) = " << f(xn) << endl;
		if (abs(f(xn)) < pow(10, -5) || abs(b - a) < pow(10, -5))
			break;
		if (f(a) * f(xn) < 0)
			b = xn;
		else
			a = xn;
		iteracoes++;
	}
	cout << "\nRaiz: " << xn << endl;
}

void Metodo_Newton(double x0)
{
	double anterior;
	int iteracoes = 0;
	for (unsigned int i = 0; i < 50; i++)
	{
		iteracoes++;
		cout << iteracoes << ":\txk: " << x0 << endl;
		anterior = x0;
		x0 = x0 - (f(x0) / (double)d_f(x0));
		if (abs(anterior - x0) < pow(10, -5))
			break;
	}
	cout << "\nRaiz: " << x0 << endl;
}

void Metodo_Picard_Peano(double x0)
{
	double anterior;
	int iteracoes = 0;
	while (true)
	{
		iteracoes++;
		anterior = x0;
		x0 = f1(x0);
		cout << iteracoes << ":\txn: " << x0 << endl;
		if (abs(x0 - anterior) < pow(10, -5))
			break;
	}
	cout << "\nRaiz: " << x0 << endl;
}

int main()
{
	//Metodo_Bissecao(-1,0);
	//Metodo_Corda(0, 1);
	//Metodo_Newton(1);
	//Metodo_Picard_Peano(-1);

	system("pause");
	return 0;
}