#include <iostream>
#include <iomanip>

using namespace std;

void Metodo_Newton(double x) {
	cout << "\nMetodo de Newton - Exercicio 1: " << endl;
	for (unsigned int i = 0; i <= 1; i++) {
		cout << "\nIteracao: " << i << "\n x = " << x << endl;
		x = x - (pow((cos(x + 1.1)), 3) + x - 2.6) / (1 - 3 * pow(cos(x + 1.1), 2) * sin(x + 1.1));
	}
}

double f(double x) {
	return 5 * cos(x) - sin(x);
}

void Metodo_Seccao_Aurea(double x1, double x2) {
	cout << "\nMetodo da Seccao Aurea - Exercicio 4: " << endl;
	double B = (sqrt(5) - 1) / 2.0;
	double A = pow(B, 2);
	double x3 = x1 + A*(x2-x1), x4 = x1 + B*(x2-x1);
	for (unsigned int i = 0; i <= 2; i++) {
		cout << "\nIteracao " << i << ": \n";
		cout << " x1 = " << x1 << "\t x2 = " << x2 << "\t x3 = " << x3 << "\t x4 = " << x4 << endl;
		cout << " f(x1) = " << f(x1) << "\t f(x2) = " << f(x2) << "\t f(x3) = " << f(x3) << "\t f(x4) = " << f(x4) << endl;
		if (f(x3) < f(x4)) {
			x2 = x4;
			x4 = x3;
			x3 = x1 + B * (x4 - x1);
		}
		else {
			x1 = x3;
			x3 = x4;
			x4 = x3 + B * (x2 - x3);
		}
	}
}

double xl(double t, double x) {
	return sin(x) + sin(2 * t);
}

void Metodo_Runga_Kutta_4_ordem(double a, double b, double x, double h) {
	cout << "\nMetodo de Runga-Kutta 4 ordem - Exercicio 5: " << endl;
	int iteracoes = 0;
	double delta1, delta2, delta3, delta4;
	for (double i = a; i <= b; i += h) {
		cout << "\nIteracao " << iteracoes << ": \n";
		cout << " t = " << i << "\t x = " << fixed << setprecision(7) << x << endl;
		delta1 = h * xl(i, x);
		delta2 = h * xl(i + h / 2.0, x + delta1 / 2.0);
		delta3 = h * xl(i + h / 2.0, x + delta2 / 2.0);
		delta4 = h * xl(i + h, x + delta3);
		x += delta1 / 6.0 + delta2 / 3.0 + delta3 / 3.0 + delta4 / 6.0;
		iteracoes++;
	}
	cout << "\nQuociente de Convergencia para t = 1.5: " << (1.768150 - 1.767816) / (1.768184 - 1.768150) << endl;
}

int main() {
	Metodo_Newton(1.8);
	cout << "\n ---------- \n";
	Metodo_Seccao_Aurea(2, 4);
	cout << "\n ---------- \n";
	Metodo_Runga_Kutta_4_ordem(1, 1.5, 1, 0.125);
	cout << endl;
	system("pause");
	return 0;
}
