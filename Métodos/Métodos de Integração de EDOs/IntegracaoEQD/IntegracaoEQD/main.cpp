#include <iostream>

using namespace std;

double EQD(double x, double y)
{
	return pow(x, 2) + pow(y, 2);
}

double Metodo_Euler(double a, double A, double h)
{
	double x0 = 0, y0 = 0;
	for (x0 = a; x0 <= A; x0 += h)
	{
		y0 += h * EQD(x0, y0);
	}
	cout << "\nResultado pelo Metodo de Euler: " << y0 << endl;
	return y0;
}

double Metodo_RungaKutta2(double a, double A, double h)
{
	double x0 = 0, y0 = 0;
	for (x0 = a; x0 <= A; x0 += h)
	{
		y0 += h * EQD(x0 + h / 2.0, y0 + (h / 2.0) * EQD(x0, y0));
	}
	cout << "\nResultado pelo Metodo de Runga-Kutta 2: " << y0 << endl;
	return y0;
}

double Metodo_RungaKutta4(double a, double A, double h)
{
	double x0 = 0, y0 = 0;
	double delta1, delta2, delta3, delta4;
	for (x0 = a; x0 <= A; x0 += h)
	{
		delta1 = h * EQD(x0, y0);
		delta2 = h * EQD(x0 + h / 2.0, y0 + delta1 / 2.0);
		delta3 = h * EQD(x0 + h / 2.0, y0 + delta2 / 2.0);
		delta4 = h * EQD(x0 + h, y0 + delta3);
		y0 += delta1 / 6.0 + delta2 / 3.0 + delta3 / 3.0 + delta4 / 6.0;
	}
	cout << "\nResultado pelo Metodo de Runga-Kutta 4: " << y0 << endl;
	return y0;
}

void Coeficiente(double s, double sl, double sll)
{
	cout << "\nCoeficiente: " << (sl - s) / (double)(sll - sl) << endl;
}

void Erro_RK4(double sll, double sl)
{
	cout << "\nErro de RK4: " << (sll - sl) / 15.0 << endl;
}

int main() 
{
	double S, SL, SLL;
	S = Metodo_Euler(0,1.4,0.1);
	cout << "\n----------\n";
	SL = Metodo_Euler(0, 1.4, 0.1 / 2);
	cout << "\n----------\n"; 
	SLL = Metodo_Euler(0, 1.39, (0.1/2)/2.0);
	cout << "\n----------\n";
	Coeficiente(S, SL, SLL);
	cout << "\n----------\n";
	double S1, S1L, S1LL;
	S1 = Metodo_RungaKutta2(0, 1.4, 0.1);
	cout << "\n----------\n";
	S1L = Metodo_RungaKutta2(0, 1.4, 0.1 / 2);
	cout << "\n----------\n";
	S1LL = Metodo_RungaKutta2(0, 1.39, (0.1 / 2) / 2.0);
	cout << "\n----------\n";
	Coeficiente(S1, S1L, S1LL);
	cout << "\n----------\n";
	double S2, S2L, S2LL;
	S2 = Metodo_RungaKutta4(0, 1.3999, 0.0125);
	cout << "\n----------\n";
	S2L = Metodo_RungaKutta4(0, 1.3999, 0.0125 / 2);
	cout << "\n----------\n";
	S2LL = Metodo_RungaKutta4(0, 1.3999, (0.0125 / 2) / 2.0);
	cout << "\n----------\n";
	Coeficiente(S2, S2L, S2LL);
	cout << "\n----------\n";
	Erro_RK4(S2LL, S2L);
	cout << "\n----------\n";
	system("pause");
	return 0;
}