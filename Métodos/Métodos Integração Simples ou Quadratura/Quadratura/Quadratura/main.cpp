#include <iostream>
#include <math.h>

# define M_PI 3.14159265358979323846

using namespace std;

double f(double x)
{
	return sin(x) / pow(x,2);
}

double Metodo_Trapezios(double a, double b, int n, double h)
{
	double soma = 0;
	for (unsigned int i = 0; i <= n ; i++)
	{
		if (i == 0 || i == n)
			soma += f(a + i * h);
		else
			soma += 2*f(a + i * h);
	}
	soma = (h / 2.0) * soma;
	cout << "\nSoma pelo Metodo dos Trapezios = " << soma << endl << endl;
	return soma;
}

double Metodo_Simpson(double a, double b, int n, double h)
{
	double soma = 0;
	for (unsigned int i = 0; i <= n; i++)
	{
		if (i == 0 || i == n)
			soma += f(a + i * h);
		else if (i % 2 == 1)
			soma += 4 * f(a + i * h);
		else
			soma += 2 * f(a + i * h);
	}
	soma = (h / 3.0) * soma;
	cout << "\nSoma pelo Metodo de Simpson = " << soma << endl << endl;
	return soma;
}

double Calcular_QST(double s, double sl, double sll)
{
	return (sl - s) / (sll - sl);
}

double Calcular_QSS(double s, double sl, double sll)
{
	return (sl - s) / (sll - sl);
}

double Calcular_Erro(double sl, double sll, double denominador)
{
	return (sll - sl) / denominador;
}

int main()
{
	double ST, SS, STL, SSL, STLL, SSLL;

	cout << "\nPara n = 4: \n\n";
	ST = Metodo_Trapezios(M_PI / 2.0, M_PI, 4, M_PI / 8.0);
	SS = Metodo_Simpson(M_PI / 2.0, M_PI, 4, M_PI / 8.0);

	cout << "\nPara n = 8: \n\n";
	STL = Metodo_Trapezios(M_PI / 2.0, M_PI, 8, M_PI / 16.0);
	SSL = Metodo_Simpson(M_PI / 2.0, M_PI, 8, M_PI / 16.0);

	cout << "\nPara n = 16: \n\n";
	STLL = Metodo_Trapezios(M_PI / 2.0, M_PI, 16, M_PI / 32.0);
	SSLL = Metodo_Simpson(M_PI / 2.0, M_PI, 16, M_PI / 32.0);

	double QST = Calcular_QST(ST, STL, STLL);
	double QSS = Calcular_QSS(SS, SSL, SSLL);

	cout << "\nCoeficiente de Convergencia ST = " << QST << endl;
	cout << "\nCoeficiente de Convergencia SS = " << QSS << endl;

	//double ET = Calcular_Erro();

	system("pause");
	return 0;
}