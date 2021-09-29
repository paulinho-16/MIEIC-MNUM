#include <iostream>
#include <iomanip>

using namespace std;

double f1(double x, double y) {
	return pow(x, 2) - y - 1.2;
}

double f2(double x, double y) {
	return -x + pow(y, 2) - 1;
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
	double hn, kn;
	cout << "\nMetodo de Newton para Sistemas - Exercicio 2: " << endl;
	for (unsigned int i = 0; i <= 2; i++) {
		cout << "\nIteracao " << i << ": ";
		cout << "\n x = " << x << "\t y = " << y << endl;
		hn = -((f1(x, y) * df2y(x, y) - f2(x, y) * df1y(x, y)) / (df1x(x, y) * df2y(x, y) - df2x(x, y) * df1y(x, y)));
		kn = -((f2(x, y) * df1x(x, y) - f1(x, y) * df2x(x, y)) / (df1x(x, y) * df2y(x, y) - df2x(x, y) * df1y(x, y)));
		x += hn;
		y += kn;
	}
}

double C(double x) {
	return pow(x, 7) + 0.5 * x - 0.5;
}

void Metodo_Corda(double a, double b) {
	double m;
	cout << "\nMetodo da Corda - Exercicio 4: " << endl;
	for (unsigned int i = 0; i <= 3; i++) {
		cout << "\nIteracao " << i << ": ";
		m = (a * C(b) - b * C(a)) / (double)(C(b) - C(a));
		cout << "\n a = " << a << "\t b = " << b << "\t m = " << m << endl;
		if (C(a) * C(m) < 0) {
			b = m;
		}
		else {
			a = m;
		}
	}
}

double yl(double t, double y, double z) {
	return z;
}

double zl(double t, double y, double z) {
	return 0.5 + pow(t, 2) + t * z;
}

void Metodo_Euler(double t, double y, double z, double h) {
	double t_ant, y_ant, z_ant;
	cout << "\nMetodo de Euler - Exercicio 5: " << endl;
	for (unsigned int i = 0; i <= 2; i++) {
		cout << "\nIteracao " << i << ": ";
		cout << "\n t = " << t << "\t y = " << y << endl;
		t_ant = t;  y_ant = y; z_ant = z;
		z += h * zl(t_ant, y_ant, z_ant);
		y += h * yl(t_ant, y_ant, z_ant);
		t += h;
	}
}

void Metodo_Runge_Kutta_4_ordem(double t, double y, double z, double h) {
	double deltay1, deltay2, deltay3, deltay4, deltaz1, deltaz2, deltaz3, deltaz4;
	cout << "\nMetodo de Runge-Kutta 4 - Exercicio 5: " << endl;
	for (unsigned int i = 0; i <= 2; i++) {
		cout << "\nIteracao " << i << ": ";
		cout << "\n t = " << t << "\t y = " << y << endl;
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

double I(double x) {
	return sqrt(1 + pow(1.5 * exp(1.5 * x), 2));
}

double Metodo_Trapezios(double a, double b, double h) {
	double soma = 0;
	cout << "\nMetodo dos Trapezios - Exercicio 6: " << endl;
	for (double x = a; x <= b; x += h) {
		if (x == a || x == b) {
			soma += I(x);
		}
		else {
			soma += 2 * I(x);
		}
	}
	double resultado = (h / 2.0) * soma;
	cout << "\nResultado pelo Metodo dos Trapezios para h = " << h << ": " << fixed << setprecision(7) << resultado << endl;
	return resultado;
}

double Metodo_Simpson(double a, double b, double h) {
	double soma = 0;
	int iteracoes = 0;
	cout << "\nMetodo de Simpson - Exercicio 6: " << endl;
	for (double x = a; x <= b; x += h) {
		if (x == a || x == b) {
			soma += I(x);
		}
		else if (iteracoes%2 != 0) {
			soma += 4 * I(x);
		}
		else {
			soma += 2 * I(x);
		}
		iteracoes++;
	}
	double resultado = (h / 3.0) * soma;
	cout << "\nResultado pelo Metodo de Simpson para h = " << h << ": " << fixed << setprecision(7) << resultado << endl;
	return resultado;
}

void Quociente_Convergencia(double s, double sl, double sll) {
	cout << "\nQuociente de Convergencia: " << (double)(sl - s) / (sll - sl) << endl;
}

void Erro_Trapezios(double s, double sl, double sll) {
	cout << "\nErro dos Trapezios: " << (sll - sl) / 3.0 << endl;
}

void Erro_Simpson(double s, double sl, double sll) {
	cout << "\nErro dos Trapezios: " << (sll - sl) / 15.0 << endl;
}

int main() {
	double st, stl, stll, ss, ssl, ssll;
	Metodo_Newton_Sistemas(1, 1);
	cout << "\n ---------- \n";
	Metodo_Corda(0, 0.8);
	cout << "\n ---------- \n";
	Metodo_Euler(0, 0, 1, 0.25);
	cout << "\n ---------- \n";
	Metodo_Runge_Kutta_4_ordem(0, 0, 1, 0.25);
	cout << "\n ---------- \n";
	st = Metodo_Trapezios(0, 2, 0.5);
	stl = Metodo_Trapezios(0, 2, 0.5/2.0);
	stll = Metodo_Trapezios(0, 2, 0.5/4.0);
	Quociente_Convergencia(st, stl, stll);
	Erro_Trapezios(st, stl, stll);
	cout << "\n ---------- \n";
	ss = Metodo_Simpson(0, 2, 0.5);
	ssl = Metodo_Simpson(0, 2, 0.5 / 2.0);
	ssll = Metodo_Simpson(0, 2, 0.5 / 4.0);
	Quociente_Convergencia(ss, ssl, ssll);
	Erro_Simpson(ss, ssl, ssll);
	cout << endl;
	system("pause");
	return 0;
}
