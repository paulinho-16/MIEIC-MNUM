#include <iostream>
#include <cmath>

using namespace std;

double f(double x)
{
	return -2.75 * pow(x, 3) + 18 * pow(x, 2) - 21 * x - 12;
}

double g(double x)
{
	return x - 2 * log(x) - 5;
}

double h(double x)
{
	return pow(2, sqrt(x)) - 10 * x + 1;
}

double Metodo_Bissecao(double a, double b)
{
	double xn;
	int iteracoes = 0;
	while (abs(b - a) > pow(10,-5))
	{
		iteracoes++;
		cout << "[" << a << " , " << b << "] --> ";
		xn = (a + b) / 2.0;
		if (f(a) * f(xn) < 0)
			b = xn;
		else
			a = xn;
		cout << "xn: " << xn << " | f(a) = " << f(a) << " | f(b) " << f(b) << " | f(xn) = " << f(xn) << " | f(a)*f(xn) = " << f(a) * f(xn) << endl;
	}
	cout << "\n Iteracoes = " << iteracoes;
	cout << "\n Raiz: " << xn << endl;
	return xn;
}

void Metodo_Corda(double a, double b)
{
	double xn = (a * f(b) - b * f(a)) / (double)(f(b) - f(a)), anterior = 0;
	int iteracoes = 0;
	do
	{
		iteracoes++;
		if (f(a) * f(xn) < 0)
			b = xn;
		else
			a = xn;
		anterior = xn;
		xn = (a * f(b) - b * f(a)) / (double)(f(b) - f(a));
		cout << "xn: " << xn << " | f(a) = " << f(a) << " | f(b) " << f(b) << " | f(xn) = " << f(xn) << " | f(a)*f(xn) = " << f(a) * f(xn) << endl;
	} while (abs(xn - anterior) > pow(10, -5));
	cout << "\n Iteracoes = " << iteracoes;
	cout << endl << "\n Raiz: " << xn << endl;
}

int main()
{
	/*Metodo_Bissecao(-2, 0); //Funcao f
	cout << "\n------------------------------\n" << endl;
	Metodo_Bissecao(1, 3); //Funcao f
	cout << "\n------------------------------\n" << endl;
	Metodo_Bissecao(4, 7); //Funcao f
	cout << "\n------------------------------\n" << endl;
	Metodo_Bissecao(0.001, 0.1); //Funcao g
	cout << "\n------------------------------\n" << endl;
	Metodo_Bissecao(9, 10); //Funcao g
	cout << "\n------------------------------\n" << endl;
	Metodo_Bissecao(0, 5); //Funcao h
	cout << "\n------------------------------\n" << endl;
	Metodo_Bissecao(97, 100); //Funcao h
	cout << "\n------------------------------\n" << endl;*/
	
	Metodo_Corda(-2, 0); //Funcao f
	cout << "\n------------------------------\n" << endl;
	/*Metodo_Corda(1, 3); //Funcao f
	cout << "\n------------------------------\n" << endl;
	Metodo_Corda(4, 7); //Funcao f
	cout << "\n------------------------------\n" << endl;*/

	system("pause");
	return 0;
}