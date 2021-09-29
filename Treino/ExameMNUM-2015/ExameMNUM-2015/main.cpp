#include <iostream>
#include <iomanip>

using namespace std;

double Tl(double t, double T) {
	return -0.25 * (T - 37);
}

void Metodo_Euler(double t, double T, double h) {
	cout << "\nMetodo de Euler - Exercicio 1: " << endl;
	for (unsigned int i = 0; i <= 2; i++) {
		cout << "\nIteracao " << i << ": \n";
		cout << " T = " << T << endl;
		T += h * Tl(t, T);
		t += h;
	}
}

double g(double x) {
	return 2 * log(2 * x);
}

void Metodo_Picard_Peano(double x) {
	cout << "\nMetodo de Picard-Peano - Exercicio 4: " << endl;
	for (unsigned int i = 0; i <= 1; i++) {
		cout << "\nIteracao " << i << ": \n";
		cout << " x = " << x << endl;
		x = g(x);
	}
}

double L(double x) {
	return sqrt(1 + pow(2.5 * exp(2.5 * x), 2));
}

double Metodo_Trapezios(double a, double b, double h) {
	double soma = 0;
	cout << "\nMetodo dos Trapezios - Exercicio 5: " << endl;
	for (double x = a; x <= b; x += h) {
		if (x == a || x == b) {
			soma += L(x);
		}
		else {
			soma += 2 * L(x);
		}
	}
	double resultado = (h / 2.0) * soma;
	cout << "\nResultado pelo Metodo dos Trapezios para h = " << h << ": " << fixed << setprecision(7) << resultado << endl;
	return resultado;
}

double Metodo_Simpson(double a, double b, double h) {
	double soma = 0;
	int iteracoes = 0;
	cout << "\nMetodo de Simpson - Exercicio 5: " << endl;
	for (double x = a; x <= b; x += h) {
		if (x == a || x == b) {
			soma += L(x);
		}
		else if (iteracoes%2 != 0) {
			soma += 4 * L(x);
		}
		else {
			soma += 2 * L(x);
		}
		iteracoes++;
	}
	double resultado = (h / 3.0) * soma;
	cout << "\nResultado pelo Metodo de Simpson para h = " << h << ": " << fixed << setprecision(7) << resultado << endl;
	return resultado;
}

void Quociente_Convergencia(double s, double sl, double sll) {
	cout << "\nQuociente de Convergencia: " << fixed << setprecision(7) << (double)(sl - s) / (sll - sl) << endl;
}

void Erro_Trapezios(double s, double sl, double sll) {
	cout << "\nErro dos Trapezios: " << fixed << setprecision(7) << (sll - sl) / 3.0 << endl;
}

void Erro_Simpson(double s, double sl, double sll) {
	cout << "\nErro de Simpson: " << fixed << setprecision(7) << (sll - sl)/15.0 << endl;
}

double h(double x) {
	return pow(x, 3) - 10 * sin(x) + 2.8;
}

void Metodo_Bissecao(double a, double b) {
	double m;
	cout << "\nMetodo da Bissecao - Exercicio 7: " << endl;
	for (unsigned int i = 0; i <= 2; i++) {
		cout << "\nIteracao " << i << ": \n";
		cout << " b = " << b << endl;
		m = (a + b) / 2.0;
		if (h(a) * h(b) < 0) {
			b = m;
		}
		else {
			a = m;
		}
	}
}

int main() {
	double st, slt, sllt, ss, sls, slls;
	Metodo_Euler(5, 3, 0.4);
	cout << "\n ---------- \n";
	Metodo_Picard_Peano(1.1);
	cout << "\n ---------- \n";
	st = Metodo_Trapezios(0, 1, 0.125);
	slt = Metodo_Trapezios(0, 1, 0.125/2.0);
	sllt = Metodo_Trapezios(0, 1, 0.125/4.0);
	Quociente_Convergencia(st, slt, sllt);
	Erro_Trapezios(st, slt, sllt);
	cout << "\n ---------- \n";
	ss = Metodo_Simpson(0, 1, 0.125);
	sls = Metodo_Simpson(0, 1, 0.125/2.0);
	slls = Metodo_Simpson(0, 1, 0.125/4.0);
	Quociente_Convergencia(ss, sls, slls);
	Erro_Simpson(ss, sls, slls);
	cout << "\n ---------- \n";
	Metodo_Bissecao(1.5, 4.2);
	cout << endl;
	system("pause");
	return 0;
}