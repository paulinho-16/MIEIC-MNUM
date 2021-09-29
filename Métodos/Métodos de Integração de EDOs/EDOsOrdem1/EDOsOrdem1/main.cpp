#include <iostream>

using namespace std;

double f(double x, double y, double z)
{
	return z * y + x;
}

double g(double x, double y, double z)
{
	return z * x + y;
}

double sy, sz;

void Metodo_EDOs(double a, double A, double h)
{
	double x0 = 0, y0 = 1, z0 = 1;
	double deltay1, deltay2, deltay3, deltay4, deltaz1, deltaz2, deltaz3, deltaz4;
	for (x0 = a; x0 <= A; x0 += h)
	{
		deltay1 = h * f(x0, y0, z0);
		deltaz1 = h * g(x0, y0, z0);
		deltay2 = h * f(x0 + h / 2.0, y0 + deltay1 / 2.0, z0 + deltaz1 / 2.0);
		deltaz2 = h * g(x0 + h / 2.0, y0 + deltay1 / 2.0, z0 + deltaz1 / 2.0);
		deltay3 = h * f(x0 + h / 2.0, y0 + deltay2 / 2.0, z0 + deltaz2 / 2.0);
		deltaz3 = h * g(x0 + h / 2.0, y0 + deltay2 / 2.0, z0 + deltaz2 / 2.0);
		deltay4 = h * f(x0 + h, y0 + deltay3, z0 + deltaz3);
		deltaz4 = h * g(x0 + h, y0 + deltay3, z0 + deltaz3);
		y0 += deltay1 / 6.0 + deltay2 / 3.0 + deltay3 / 3.0 + deltay4 / 6.0;
		z0 += deltaz1 / 6.0 + deltaz2 / 3.0 + deltaz3 / 3.0 + deltaz4 / 6.0;
	}
	cout << "\nResultado pelo Metodo de Runga-Kutta 4: y0 = " << y0 << " e z = " << z0 <<  endl;
	sy = y0;
	sz = z0;
}

void Coeficiente(double s, double sl, double sll)
{
	cout << (sl - s) / (double)(sll - sl);
}

void Erro(double sll, double sl)
{
	cout << (sll - sl) / 15.0;
}

int main()
{
	double Sy, SyL, SyLL, Sz, SzL, SzLL;
	Metodo_EDOs(0, 0.4999, 0.0125);
	cout << "\n----------\n";
	Sy = sy;
	Sz = sz;
	Metodo_EDOs(0, 0.4999, 0.0125 / 2);
	cout << "\n----------\n";
	SyL = sy;
	SzL = sz;
	Metodo_EDOs(0, 0.4999, (0.0125 / 2) / 2.0);
	cout << "\n----------\n";
	SyLL = sy;
	SzLL = sz;
	cout << "\nCoeficiente de y: ";
	Coeficiente(Sy, SyL, SyLL);
	cout << "\nCoeficiente de z: ";
	Coeficiente(Sz, SzL, SzLL);
	cout << "\n\n----------\n";
	cout << "\nErro de y: ";
	Erro(SyLL, SyL);
	cout << "\n\n----------\n";
	cout << "\nErro de z: ";
	Erro(SzLL, SzL);
	cout << "\n\n----------\n";
	system("pause");
	return 0;
}