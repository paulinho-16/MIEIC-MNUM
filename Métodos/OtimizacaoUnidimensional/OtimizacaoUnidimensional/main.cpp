#include <iostream>
#include "vector"

using namespace std;

double f(double x) {
	return sin(x);
	//return pow(2 * x + 1, 2) - 5 * cos(10 * x);
}

vector<double> Pesquisa(double guess, double step) {
	double x0, x1, x2;
	if (f(guess) < f(guess + step))
		step = -step;
	x0 = guess;
	x1 = guess + step;
	x2 = guess + 2 * step;
	while (f(x1) > f(x2)) {
		x0 = x1;
		x1 = x2;
		x2 += step;
	}
	cout << endl << "x0 = " << x0 << "\tx1 = " << x1 << "    x2 = " << x2 << endl;
	vector<double> res = { x0,x1,x2 };
	return res;
}

vector<double> Metodo_Tercos(double a, double b) {
	double x1 = 0, x2 = 0, intervalo;
	vector<double> res;
	while (abs(b-a) > pow(10, -5)) {
		intervalo = (b-a) / 3.0;
		x1 = a + intervalo;
		x2 = a + 2 * intervalo;
		if (f(x2) < f(x1))
			a = x1;
		else
			b = x2;
	}
	if (a == x1)
		res = { x1,x2,b };
	else
		res = { a,x1,x2 };
	cout << "\nResultado pelo Metodo dos Tercos: " << res[1] << endl;
	return res;
}

double Quadratica(double x1, double x2, double x3) {
	double res;
	res = x2 + (x2-x1)*(f(x1) - f(x3)) / (2 * (f(x3) - 2 * f(x2) + f(x1)));
	cout << "\nResultado pelo Metodo da Quadrica: " << res << endl;
	return res;
}

vector<double> Metodo_Seccao_Aurea(double a, double b) {
	double x1 = 0, x2 = 0, intervalo;
	double B = (sqrt(5) - 1) / 2.0;
	vector<double> res;
	while (abs(b - a) > pow(10, -5)) {
		intervalo = (b - a) * B;
		x2 = a + intervalo;
		x1 = a + 2 * intervalo;
		if (f(x2) < f(x1)) {
			a = x1;
		}
		else
			b = x2;
	}
	if (a == x1)
		res = { x1,x2,b };
	else
		res = { a,x1,x2 };
	cout << "\nResultado pelo Metodo da Seccao Aurea: " << res[1] << endl;
	return res;
}

vector<double> Metodo_Seccao_Aurea_eficiente_Minimo(double x1, double x2) {
	double B = (sqrt(5) - 1) / 2.0;
	double A = pow(B, 2);
	double x3, x4;
	vector<double> res;
	while (abs(x2 - x1) > 0.001) {

		x3 = x1 + A * (x2 - x1);
		x4 = x1 + B * (x2 - x1);
		if (f(x3) < f(x4)) {
			x2 = x4;
		}
		else {
			x1 = x3;
		}
	}
	if (x1 == x3)
		res = { x3,x4,x2 };
	else
		res = { x1,x3,x4 };
	cout << "\nResultado do Minimo pelo Metodo da Seccao Aurea eficiente: " << res[1] << "  |  f(x) = " << f(res[1]) << endl;
	cout << "\nf(x1) " << f(x1) << "\nf(x2) " << f(x2) << "\nf(x3) " << f(x3) << "\nf(x4) " << f(x4) << endl;
	return res;
}

vector<double> Metodo_Seccao_Aurea_eficiente_Maximo(double x1, double x2) {
	double B = (sqrt(5) - 1) / 2.0;
	double A = pow(B, 2);
	double x3, x4;
	vector<double> res;
	while (abs(x2 - x1) > 0.001) {
		x3 = x1 + A * (x2 - x1);
		x4 = x1 + B * (x2 - x1);
		if (f(x3) > f(x4)) {
			x2 = x4;
		}
		else {
			x1 = x3;
		}
	}
	if (x1 == x3)
		res = { x3,x4,x2 };
	else
		res = { x1,x3,x4 };
	cout << "\nResultado do Maximo pelo Metodo da Seccao Aurea eficiente: " << res[1] << "  |  f(x) = " << f(res[1]) << endl;
	cout << "\nf(x1) " << f(x1) << "\nf(x2) " << f(x2) << "\nf(x3) " << f(x3) << "\nf(x4) " << f(x4) << endl;
	return res;
}

int main() {
	vector<double> intervalos;
	vector<double> resultados_tercos, resultados_aurea, resultados_aurea_eficiente, resultados_aurea_eficiente2;
	double resultado;
	intervalos = Pesquisa(2, 0.1);
	resultados_tercos = Metodo_Tercos(intervalos[0], intervalos[2]);
	resultado = Quadratica(intervalos[0], intervalos[1], intervalos[2]);
	resultados_aurea = Metodo_Seccao_Aurea(intervalos[0], intervalos[2]);
	resultados_aurea_eficiente = Metodo_Seccao_Aurea_eficiente_Minimo(intervalos[0], intervalos[2]);
	resultados_aurea_eficiente2 = Metodo_Seccao_Aurea_eficiente_Minimo(-1,0);
	resultados_aurea_eficiente2 = Metodo_Seccao_Aurea_eficiente_Maximo(-1, 0);
	cout << endl;
	system("pause");
	return 0;
}