#include <iostream>
#include <iomanip>

using namespace std;

double f(double x) {
	return pow(x - 5, 2) + pow(x, 4);
}

double x_1, x_2, x_3;

void Metodo_Seccao_Aurea(double x1, double x2) {
	cout << "\nMetodo da Seccao Aurea - Exercicio 1: " << endl;
	double x3, x4;
	double B = (sqrt(5) - 1) / 2.0;
	double A = pow(B, 2);
	bool first = true;
	x3 = x1 + A * (x2 - x1);
	x4 = x1 + B * (x2 - x1);
	while (abs(x2 - x1) > 0.0001) {
		if (f(x3) < f(x4)) {
			x2 = x4; x4 = x3;
			x3 = x1 + B * (x4 - x1);
			first = true;
		}
		else {
			x1 = x3; x3 = x4;
			x4 = x3 + B * (x2 - x3);
			first = false;
		}
	}
	if (first) {
		cout << " x1 = " << x3 << "\t x2 = " << x4 << "\t x3 = " << x2 << endl;
		x_1 = x3; x_2 = x4; x_3 = x2;
	}
	else {
		cout << " x1 = " << x1 << "\t x2 = " << x3 << "\t x3 = " << x4 << endl;
		x_1 = x1; x_2 = x3; x_3 = x4;
	}
}

void Interpolacao_Quadratica(double x1, double x2, double x3) {
	cout << "\nMetodo da Interpolacao Quadratica - Exercicio 1: " << endl;
	double res = x2 + ((x2 - x1) * (f(x1) - f(x3))) / (2 * (f(x3) - 2 * f(x2) + f(x1)));
	cout << "\nResultado do Minimo: " << res << endl;
}

double I(double x) {
	return sqrt(1 + pow(2.5 * exp(2.5 * x), 2));
}

double Metodo_Trapezios(double a, double b, double h) {
	double soma = 0;
	cout << "\nMetodo dos Trapezios - Exercicio 2: " << endl;
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
	cout << "\nMetodo de Simpson - Exercicio 2: " << endl;
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
	cout << "\nErro de Simpson: " << (sll - sl) / 15.0 << endl;
}

void Erro_Euler(double s, double sl, double sll) {
	cout << "\nErro de Simpson: " << (sll - sl) << endl;
}

double Cl(double t, double T, double C) {
	return -exp(-0.5 / (T + 273)) * C;
}

double Tl(double t, double T, double C) {
	return 30 * exp(-0.5 / (T + 273)) * C - 0.5 * (T - 20);
}

double Metodo_Euler_Sistemas(double t, double T, double C, double h) {
	double t_ant, T_ant, C_ant;
	cout << "\nMetodo de Euler para Sistemas - Exercicio 4 a): " << endl;
	for (unsigned int i = 0; i <= 2; i++) {
		cout << "\nIteracao " << i << ": " << endl;
		cout << " t = " << t << "\t T = " << T << "\t C = " << C << endl;
		if (i == 2) {
			return T;
		}
		t_ant = t; T_ant = T; C_ant = C;
		t += h;
		T += Tl(t_ant, T_ant, C_ant) * h;
		C += Cl(t_ant, T_ant, C_ant) * h;
	}
}

double Metodo_Euler_Sistemas_alinea_c(double t, double T, double C, double h) {
	double t_ant, T_ant, C_ant;
	cout << "\nMetodo de Euler para Sistemas - Exercicio 4 c): " << endl;
	while (t <= 0.5) {
		cout << " t = " << t << "\t T = " << T << "\t C = " << C << endl;
		if (t == 0.5) {
			return T;
		}
		t_ant = t; T_ant = T; C_ant = C;
		t += h;
		T += Tl(t_ant, T_ant, C_ant) * h;
		C += Cl(t_ant, T_ant, C_ant) * h;
	}
}

void Metodo_Runge_Kutta_4_ordem(double t, double T, double C) {
	double deltat1, deltat2, deltat3, deltat4, deltac1, deltac2, deltac3, deltac4;
	cout << "\nMetodo de Runge-Kutta 4 para Sistemas - Exercicio 4 b): " << endl;
	for (unsigned int i = 0; i <= 2; i++) {
		cout << "\nIteracao " << i << ": " << endl;
		cout << " t = " << t << "\t T = " << T << "\t C = " << C << endl;
		deltat1 = 0.25 * Tl(t, T, C);
		deltac1 = 0.25 * Cl(t, T, C);
		deltat2 = 0.25 * Tl(t + 0.25 / 2.0, T + deltat1 / 2.0, C + deltac1 / 2.0);
		deltac2 = 0.25 * Cl(t + 0.25 / 2.0, T + deltat1 / 2.0, C + deltac1 / 2.0);
		deltat3 = 0.25 * Tl(t + 0.25 / 2.0, T + deltat2 / 2.0, C + deltac2 / 2.0);
		deltac3 = 0.25 * Cl(t + 0.25 / 2.0, T + deltat2 / 2.0, C + deltac2 / 2.0);
		deltat4 = 0.25 * Tl(t + 0.25, T + deltat3, C + deltac3);
		deltac4 = 0.25 * Cl(t + 0.25, T + deltat3, C + deltac3);
		t += 0.25;
		T += deltat1 / 6.0 + deltat2 / 3.0 + deltat3 / 3.0 + deltat4 / 6.0;
		C += deltac1 / 6.0 + deltac2 / 3.0 + deltac3 / 3.0 + deltac4 / 6.0;
	}
}

double w(double x, double y) {
	return -1.1 * x * y + 12 * y + 7 * pow(x, 2) - 8 * x;
}

double dwx(double x, double y) {
	return -1.1 * y + 14 * x - 8;
}

double dwy(double x, double y) {
	return 12 - 1.1 * x;
}

void Metodo_Gradiente(double x, double y, double lambda) {
	double xn, yn;
	cout << "\nMetodo do Gradiente - Exercicio 5: " << endl;
	int i = 0;
	while (true) {
		cout << "\nIteracao " << i << ": " << endl;
		cout << " x = " << x << "\t y = " << y << "\t lambda = " << lambda << endl;
		xn = x - lambda * dwx(x, y);
		yn = y - lambda * dwy(x, y);
		if (w(xn, yn) < w(x, y)) {
			x = xn;
			y = yn;
			lambda *= 2;
			i++;
		}
		else {
			lambda /= 2.0;
		}
		if (i == 1) {
			cout << "\nValor da funcao ao final de 1 iteracao: " << w(x, y) << endl;
			break;
		}
	}
}

int main() {
	double st, stl, stll, ss, ssl, ssll;
	Metodo_Seccao_Aurea(-2, 4);
	Interpolacao_Quadratica(x_1, x_2, x_3);
	cout << "\n ---------- \n";
	st = Metodo_Trapezios(0, 1, 0.125);
	stl = Metodo_Trapezios(0, 1, 0.125/2.0);
	stll = Metodo_Trapezios(0, 1, 0.125/4.0);
	Quociente_Convergencia(st, stl, stll);
	Erro_Trapezios(st, stl, stll);
	cout << "\n ---------- \n";
	ss = Metodo_Simpson(0, 1, 0.125);
	ssl = Metodo_Simpson(0, 1, 0.125 / 2.0);
	ssll = Metodo_Simpson(0, 1, 0.125 / 4.0);
	Quociente_Convergencia(ss, ssl, ssll);
	Erro_Simpson(ss, ssl, ssll);
	cout << "\n ---------- \n";
	double se, sel, sell;
	se = Metodo_Euler_Sistemas(0, 25, 2.5, 0.25);
	cout << "\n ---------- \n";
	Metodo_Runge_Kutta_4_ordem(0, 25, 2.5);
	cout << "\n ---------- \n";
	sel = Metodo_Euler_Sistemas_alinea_c(0, 25, 2.5, 0.25 / 2.0);
	sell = Metodo_Euler_Sistemas_alinea_c(0, 25, 2.5, 0.25 / 4.0);
	Quociente_Convergencia(se, sel, sell);
	Erro_Euler(se, sel, sell);
	cout << "\n ---------- \n";
	Metodo_Gradiente(3, 1, 0.1);
	cout << endl;
	system("pause");
	return 0;
}