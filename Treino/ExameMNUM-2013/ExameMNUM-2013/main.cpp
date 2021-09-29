#include <iostream>

using namespace std;

double yl(double t, double y, double z) {
	return z;
}

double zl(double t, double y, double z) {
	return 0.5 + pow(t, 2) + t * z;
}

void Metodo_Euler_Sistemas(double t, double h, double y, double z) {
	double y_ant, z_ant;
	cout << "\nMetodo de Euler para Sistemas - Exercicio 1: " << endl;
	for (unsigned int i = 0; i <= 2; i++) {
		cout << "\nIteracao " << i << ": \n";
		cout << " t = " << t << "\t y = " << y << endl;
		y_ant = y; z_ant = z;
		y += yl(t, y_ant, z_ant) * h;
		z += zl(t, y_ant, z_ant) * h;
		t += h;
	}
}

void Metodo_Runge_Kutta_4_ordem(double t, double h, double y, double z) {
	double deltay1, deltay2, deltay3, deltay4, deltaz1, deltaz2, deltaz3, deltaz4;
	cout << "\nMetodo de Runge-Kutta 4 para Sistemas - Exercicio 1: " << endl;
	for (unsigned int i = 0; i <= 2; i++) {
		cout << "\nIteracao " << i << ": \n";
		cout << " t = " << t << "\t y = " << y << endl;
		deltay1 = h * yl(t, y, z);
		deltaz1 = h * zl(t, y, z);
		deltay2 = h * yl(t + h / 2.0, y + deltay1 / 2.0, z + deltaz1 / 2.0);
		deltaz2 = h * zl(t + h / 2.0, y + deltay1 / 2.0, z + deltaz1 / 2.0);
		deltay3 = h * yl(t + h / 2.0, y + deltay2 / 2.0, z + deltaz2 / 2.0);
		deltaz3 = h * zl(t + h / 2.0, y + deltay2 / 2.0, z + deltaz2 / 2.0);
		deltay4 = h * yl(t + h, y + deltay3, z + deltaz3);
		deltaz4 = h * zl(t + h, y + deltay3, z + deltaz3);
		y += deltay1 / 6.0 + deltay2 / 3.0 + deltay3 / 3.0 + deltay4 / 6.0;
		z += deltaz1 / 6.0 + deltaz2 / 3.0 + deltaz3 / 3.0 + deltaz4 / 6.0;
		t += h;
	}
}

double Z(double x, double y) {
	return 3 * pow(x, 2) - x * y + 11 * y + pow(y, 2) - 8 * x;
}

double dZx(double x, double y) {
	return -y + 6 * x - 8;
}

double dZy(double x, double y) {
	return 2 * y - x + 11;
}


void Metodo_Gradiente(double x, double y, double lambda) {
	double xn, yn;
	cout << "\nMetodo do Gradiente - Exercicio 3: " << endl;
	for (unsigned int i = 0; i <= 1; i++) {
		cout << "\nIteracao " << i << ": \n";
		cout << " x = " << x << "\t y = " << y << "\t Z(x,y) = " << Z(x, y) << "\t dZx = " << dZx(x, y) << "\t dZy = " << dZy(x, y) << "\t lambda = " << lambda << endl;
		xn = x - lambda * dZx(x, y);
		yn = y - lambda * dZy(x, y);
		if (Z(xn, yn) < Z(x, y)) {
			x = xn;
			y = yn;
			lambda *= 2;
		}
		else {
			lambda /= 2.0;
		}
	}
}

double f(double x) {
	return exp(1.5 * x);
}

double Metodo_Simpson(double a, double b, double h) {
	int iteracoes = 0;
	double soma = 0;
	cout << "\nMetodo de Simpson - Exercicio 4: " << endl;
	for (double t = a; t <= b; t += h) {
		if (t == a || t == b) {
			soma += f(t);
		}
		else if (iteracoes % 2 != 0) {
			soma += 4 * f(t);
		}
		else {
			soma += 2 * f(t);
		}
		iteracoes++;
	}
	double resultado = (h / 3.0) * soma;
	cout << "\nResultado do Integral  para h = " << h << ": " << resultado << endl;
	return resultado;
}

void Quociente_Convergencia(double s, double sl, double sll) {
	cout << "\nQuociente de Convergencia: " << (double)(sl - s) / (sll - sl) << endl;
}

void Erro_Relativo(double s, double sl, double sll) {
	cout << "\nErro relativo: " << (sll - sl) / 15.0 << endl;
}

double g(double x) {
	return (x - 3.7) + pow(cos(x + 1.2), 3);
}

double gl(double x) {
	return 1 - 3 * pow(cos(x + 1.2), 2) * sin(x + 1.2);
}

void Metodo_Newton(double x) {
	cout << "\nMetodo de Newton - Exercicio 5: " << endl;
	for (unsigned int i = 0; i <= 1; i++) {
		cout << "\nIteracao " << i << ": \n";
		cout << " x = " << x << endl;
		x = x - g(x) / gl(x);
	}
}

int main() {
	double s, sl, sll;
	Metodo_Euler_Sistemas(0, 0.25, 0, 1);
	cout << "\n ---------- \n";
	Metodo_Runge_Kutta_4_ordem(0, 0.25, 0, 1);
	cout << "\n ---------- \n";
	Metodo_Gradiente(2, 2, 0.5);
	cout << "\n ---------- \n";
	s = Metodo_Simpson(1, 1.5, 0.125);
	cout << "\n ---------- \n";
	sl = Metodo_Simpson(1, 1.5, 0.125/2.0);
	cout << "\n ---------- \n";
	sll = Metodo_Simpson(1, 1.5, 0.125/4.0);
	Quociente_Convergencia(s, sl, sll);
	Erro_Relativo(s, sl, sll);
	cout << "\n ---------- \n";
	Metodo_Newton(3.8);
	cout << endl;
	system("pause");
	return 0;
}
