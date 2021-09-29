#include <iostream>

using namespace std;

double cl(double C, double T) {
	return -exp(-0.5 / (T + 273)) * C;
}

double tl(double C, double T) {
	return 20 * exp(-0.5 / (T + 273)) * C - 0.5 * (T - 20);
}

double Metodo_Euler_Sistemas(double t,double c, double T, double h) {
	double c_ant, T_ant;
	for (unsigned int i = 0; i <= 2; i++) {
		cout << "\nIteracao: " << i << ": " << endl;
		cout << "t = " << t << "\nc = " << c << "\nT = " << T << endl << endl;
		c_ant = c; T_ant = T;
		t += h;
		c += h * cl(c_ant, T_ant);
		T += h * tl(c_ant, T_ant);
	}
	return c;
}

void Metodo_RK4_Sistemas(double t, double c, double T, double h) {
	double deltac1, deltac2, deltac3, deltac4, deltat1, deltat2, deltat3, deltat4;
	for (unsigned int i = 0; i <= 2; i++) {
		cout << "\nIteracao: " << i << ": " << endl;
		cout << "t = " << t << "\nc = " << c << "\nT = " << T << endl << endl;
		deltac1 = h * cl(c, T);
		deltat1 = h * tl(c, T);
		deltac2 = h * cl(c + deltac1 / 2.0, T + deltat1 / 2.0);
		deltat2 = h * tl(c + deltac1 / 2.0, T + deltat1 / 2.0);
		deltac3 = h * cl(c + deltac2 / 2.0, T + deltat2 / 2.0);
		deltat3 = h * tl(c + deltac2 / 2.0, T + deltat2 / 2.0);
		deltac4 = h * cl(c + deltac3, T + deltat3);
		deltat4 = h * tl(c + deltac3, T + deltat3);
		t += h;
		c += deltac1 / 6.0 + deltac2 / 3.0 + deltac3 / 3.0 + deltac4 / 6.0;
		T += deltat1 / 6.0 + deltat2 / 3.0 + deltat3 / 3.0 + deltat4 / 6.0;
	}
}

void Coeficiente_Convergencia(double s, double sl, double sll) {
	cout << "\nQC: " << (sl - s) / (sll - sl) << endl;
}

void Calcular_Erro(double sl, double sll) {
	cout << "\nERRO: " << (sll - sl);
}

double Tl(double T) {
	return -0.25 * (T - 42);
}

void Metodo_Euler(double t, double T, double h) {
	double c_ant, T_ant;
	for (unsigned int i = 0; i <= 2; i++) {
		cout << "\nIteracao: " << i << ": " << endl;
		cout << "t = " << t << "\nT = " << T << endl << endl;
		t += h;
		T += h * Tl(T);
	}
}

void Gauss_Seidel(double x1, double x2, double x3, double x4) {
	for (unsigned int i = 0; i <= 1; i++) {
		cout << "Iteracao: " << i << ": " << "\nx1 = " << x1 << "\nx2 = " << x2 << "\nx3 = " << x3 << "\nx4 = " << x4 << endl << endl;

		x1 = (2.5 - 0.5 * x2 - 3 * x3 - 0.25 * x4) / 6.0;
		x2 = (3.8 - 1.2 * x1 - 0.25 * x3 - 0.2 * x4) / 3.0;
		x3 = (10 + x1 - 0.25 * x2 - 2 * x4) / 4.0;
		x4 = (7 - 2 * x1 - 4 * x2 - x3) / 8.0;
	}
}

int main() {
	double s, sl, sll;
	cout << "\nMETODO EULER 1: " << endl;
	s = Metodo_Euler_Sistemas(0, 1, 15, 0.25);
	//cout << "\nMETODO RK4 : " << endl;
	//Metodo_RK4_Sistemas(0, 1, 15, 0.25);
	cout << "\nMETODO EULER 2: " << endl;
	sl = Metodo_Euler_Sistemas(0, 1, 15, 0.25/2.0);
	cout << "\nCl: " << sl << endl;
	cout << "\nMETODO EULER 3: " << endl;
	sll = Metodo_Euler_Sistemas(0, 1, 15, 0.25/4.0);
	cout << "\nCll: " << sll << endl;
	Coeficiente_Convergencia(s, sl, sll);
	Calcular_Erro(sl, sll);
	cout << "\nMETODO EULER PARA O EX 4: " << endl;
	Metodo_Euler(5, 10, 0.4);
	cout << "\nGAUSS SEIDEL: " << endl;
	Gauss_Seidel(0, 0, 0, 0);
	bool mnum_nao_presta = true;

	cout << endl;
	system("pause");
	return 0;
}
