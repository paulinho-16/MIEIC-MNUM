#include <iostream>

using namespace std;

void Gauss_Jacobi(double x1, double x2, double x3, double x4) {
	double x1_ant, x2_ant, x3_ant, x4_ant;
	for (unsigned int i = 0; i <= 2; i++) {
		cout << "\nIteracao " << i << ": " << endl;
		cout << "\nx1 = " << x1 << "\nx2 = " << x2 << "\nx3 = " << x3 << "\nx4 = " << x4 << endl;
		x1_ant = x1; x2_ant = x2; x3_ant = x3; x4_ant = x4;
		x1 = (1 + x2_ant + x3_ant - x4_ant) / 4.5;
		x2 = (-1 + x1_ant - x3_ant + x4_ant) / 4.5;
		x3 = (-1 + x1_ant - 2 * x2_ant + x4_ant) / 4.5;
		x4 = (-2 * x1_ant + x2_ant + x3_ant) / 4.5;
	}
}

double Tl(double T) {
	return -0.25 * (T - 45);
}

void Metodo_Euler(double T, double t, double h) {
	for (unsigned int i = 0; i <= 2; i++) {
		cout << "\nIteracao " << i << ": " << endl;
		cout << "\nt = " << t << "\nT = " << T << endl;
		t += h;
		T += h * Tl(T);
	}
}

int main() {

	cout << "\nGAUSS-JACOBI: " << endl << endl;
	Gauss_Jacobi(0.25, 0.25, 0.25, 0.25);
	cout << "\nEULER: : " << endl << endl;
	Metodo_Euler(23, 1, 0.4);

	system("pause");
	return 0;
}
