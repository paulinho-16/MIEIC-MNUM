#include <iostream>
#include <iomanip>

using namespace std;

double yl(double t, double y) {
	return (double) y / (t - 1);
}

void Metodo_Euler(double h, double t, double y) {
	cout << "\nMetodo de Euler - Exercicio 1: " << endl;
	for (unsigned int i = 0; i <= 2; i++) {
		cout << "\nIteracao " << i << ": \n";
		cout << " t = " << t << "\t y = " << y << endl;
		y += yl(t, y) * h;
		t += h;
	}
}

void Metodo_Runga_Kutta_4_ordem(double h, double t, double y) {
	double delta1, delta2, delta3, delta4;
	cout << "\nMetodo de Runga-Kutta 4 ordem - Exercicio 1: " << endl;
	for (unsigned int i = 0; i <= 2; i++) {
		cout << "\nIteracao " << i << ": \n";
		cout << " t = " << t << "\t y = " << y << endl;
		delta1 = h * yl(t, y);
		cout << " delta1 = " << delta1;
		delta2 = h * yl(t + h / 2.0, y + delta1 / 2.0);
		cout << "\t delta2 = " << delta2;
		delta3 = h * yl(t + h / 2.0, y + delta2 / 2.0);
		cout << "\t delta3 = " << delta3;
		delta4 = h * yl(t + h, y + delta3);
		cout << "\t delta4 = " << delta4 << endl;
		y += delta1 / 6.0 + delta2 / 3.0 + delta3 / 3.0 + delta4 / 6.0;
		t += h;
	}
}

double w(double x, double y) {
	return -1.7 * x * y + 12 * y + 7 * pow(x, 2) - 8 * x;
}

double dwx(double x, double y) {
	return -1.7 * y + 14 * x - 8;
}

double dwy(double x, double y) {
	return 12 - 1.7 * x;
}

void Metodo_Gradiente(double x, double y, double lambda) {
	double xn, yn;
	cout << "\nMetodo do Gradiente - Exercicio 3: " << endl;
	for (unsigned int i = 0; i <= 1; i++) {
		cout << "\nIteracao " << i << ": \n";
		cout << " x = " << x << "\t y = " << y << "\t lambda = " << lambda << "\t w(x,y) = " << w(x,y) << endl;
		xn = x - lambda * dwx(x, y);
		yn = y - lambda * dwy(x, y);
		if (w(xn, yn) < w(x, y)) {
			x = xn;
			y = yn;
			lambda *= 2;
		}
		else {
			lambda /= 2.0;
		}
	}
}

double f1(double x, double y) {
	return pow(x, 2) - y - 2;
}

double f2(double x, double y) {
	return -x + pow(y, 2) - 2;
}

double df1x(double x, double y) {
	return 2 * x;
}

double df1y(double x, double y) {
	return -1;
}

double df2x(double x, double y) {
	return -1;
}

double df2y(double x, double y) {
	return 2 * y;
}

void Metodo_Newton_Sistemas(double x, double y) {
	double x_ant, y_ant;
	cout << "\nMetodo de Newton para Sistemas - Exercicio 5: " << endl;
	for (unsigned int i = 0; i <= 2; i++) {
		cout << "\nIteracao " << i << ": \n";
		cout << " x = " << x << "\t y = " << y << endl;
		x_ant = x; y_ant = y;
		x = x_ant - (f1(x_ant, y_ant) * df2y(x_ant, y_ant) - f2(x_ant, y_ant) * df1y(x_ant, y_ant)) / (df1x(x_ant, y_ant) * df2y(x_ant, y_ant) - df2x(x_ant, y_ant) * df1y(x_ant, y_ant));
		y = y_ant - (f2(x_ant, y_ant) * df1x(x_ant, y_ant) - f1(x_ant, y_ant) * df2x(x_ant, y_ant)) / (df1x(x_ant, y_ant) * df2y(x_ant, y_ant) - df2x(x_ant, y_ant) * df1y(x_ant, y_ant));
	}
}

double f(double x) {
	return exp(1.5 * x);
}

double Metodo_Simpson(double a, double b, double h) {
	double soma = 0;
	int iteracoes = 0;
	cout << "\nMetodo de Simpson - Exercicio 7: " << endl;
	for (double x = a; x <= b; x += h) {
		cout << "\nIteracao " << iteracoes << ": \n";
		cout << " x = " << x << endl;
		if (x == a || x == b) {
			soma += f(x);
		}
		else if (iteracoes%2 != 0) {
			soma += 4 * f(x);
		}
		else {
			soma += 2 * f(x);
		}
		iteracoes++;
	}
	double result = (h / 3.0) * soma;
	cout << "\nResultado do Integral para h = " << h << ": " << fixed << setprecision(7) << result;
	return result;
}

void Quociente_Convergencia(double s, double sl, double sll) {
	cout << "\nQC = " << (sl - s) / (double)(sll - sl);
}

void Erro_Simpson(double s, double sl, double sll) {
	cout << "\nErro = " << (sll - sl) / 15.0;
}

int main() {
	double s, sl, sll;
	Metodo_Euler(0.25, 2, 2);
	cout << "\n ---------- \n";
	Metodo_Runga_Kutta_4_ordem(0.25, 2, 2);
	cout << "\n ---------- \n";
	Metodo_Gradiente(2.4, 4.3, 0.1);
	cout << "\n ---------- \n";
	Metodo_Newton_Sistemas(1.5, 0.8);
	cout << "\n ---------- \n";
	s = Metodo_Simpson(2.5, 3, 0.125);
	cout << "\n ---------- \n";
	sl = Metodo_Simpson(2.5, 3, 0.125/2.0);
	cout << "\n ---------- \n";
	sll = Metodo_Simpson(2.5, 3, 0.125 / 4.0);
	cout << "\n ---------- \n";
	Quociente_Convergencia(s, sl, sll);
	Erro_Simpson(s, sl, sll);
	cout << endl;
	system("pause");
	return 0;
}
