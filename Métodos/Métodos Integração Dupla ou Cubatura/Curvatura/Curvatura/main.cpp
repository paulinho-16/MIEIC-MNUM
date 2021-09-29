#include <iostream>

using namespace std;

double f(double x, double y)
{
	return exp(y - x);
}

void Metodo_Trapezios(double A, double a, double B, double b, double nx, double ny)
{
	double hx, hy, soma = 0;
	hx = (A - a) / (double) nx;
	hy = (B - b) / (double) ny;
	soma += f(0, 0) + f(0, 0.5) + f(0.5, 0) + f(0.5, 0.5);
	soma += 2 * (f(0, 0.25) + f(0.25, 0) + f(0.5, 0.25) + f(0.25, 0.5));
	soma += 4 * f(0.25, 0.25);
	soma = ((hx * hy) / 4.0)*soma;
	cout << "\nResultado pelo Metodo dos Trapezios: " << soma << endl;
}

void Metodo_Simpson(double A, double a, double B, double b, double nx, double ny)
{
	double hx, hy, soma = 0;
	hx = (A - a) / (double)nx;
	hy = (B - b) / (double)ny;
	soma += f(0, 0) + f(0, 0.5) + f(0.5, 0) + f(0.5, 0.5);
	soma += 4 * (f(0, 0.25) + f(0.25, 0) + f(0.5, 0.25) + f(0.25, 0.5));
	soma += 16 * f(0.25, 0.25);
	soma = ((hx * hy) / 9.0) * soma;
	cout << "\nResultado pelo Metodo de Simpson: " << soma << endl;
}

int main()
{
	Metodo_Trapezios(0.5, 0, 0.5, 0, 2, 2);
	Metodo_Simpson(0.5, 0, 0.5, 0, 2, 2);

	system("pause");
	return 0;
}