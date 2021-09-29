#include <iostream>
#include <vector>

using namespace std;

void Metodo_Gauss_Seidel(double x1, double x2, double x3, double x4) {
	int iteracoes = 0;
	double x1_ant, x2_ant, x3_ant, x4_ant;
	do {
		cout << iteracoes << " : " << "\nx1 = " << x1 << "\nx2 = " << x2 << "\nx3 = " << x3 << "\nx4 = " << x4 << endl << endl;
		x1_ant = x1;
		x2_ant = x2;
		x3_ant = x3;
		x4_ant = x4;
		x1 = (25 - 0.5 * x2_ant - 3 * x3_ant - 0.25 * x4_ant) / 6.0;
		x2 = (-1.2 * x1 - 0.25 * x3_ant - 0.2 * x4_ant + 10) / 3.0;
		x3 = (x1 - 0.25 * x2 - 2 * x4_ant + 7) / 4.0;
		x4 = (-2 * x1 - 4 * x2 - x3 - 12) / 8.0;
		iteracoes++;
	} while (abs(x1 - x1_ant) > pow(10, -5) || abs(x2 - x2_ant) > pow(10, -5) || abs(x3 - x3_ant) > pow(10, -5) || abs(x4 - x4_ant) > pow(10, -5));

}

void Metodo_Trapezios_Cubatura(double A, double a, double B, double b, double nx, double ny) {
	double hx, hy, soma = 0;
	hx = (A - a) / (double) nx;
	hy = (B - b) / (double)ny;
	soma += 1.1 + 7.7 + 1.2 + 7.3;
	soma += 2 * (2.1 + 1.5 + 1.4 + 2.2);
	soma += 4 * (3.1);
	soma = (hx * hy) / 4.0 * (soma);
	cout << "\nResultado: " << soma << endl << endl;
}

double yl(double x, double y, double z) {
	return z;
}

double zl(double x, double y, double z) {
	return 2 + pow(x, 2) + x * z;
}

vector<double> Sistema_Eq(double x, double y, double z, double h) {
	double x_ant, y_ant, z_ant;
	vector<double> valores;
	for (unsigned int i = 0; i <= 2; i++) {
		cout << "\nIteracao: " << i << ": " << endl;
		cout << "x = " << x << endl;
		cout << "y = " << y << endl;
		x_ant = x; y_ant = y; z_ant = z;
		x += h;
		y += h * yl(x_ant, y_ant, z_ant);
		z += h * zl(x_ant, y_ant, z_ant);
	}
	valores = { y,z };
	return valores;
}

void Runge_Kutta4(double x, double y, double z, double h) {
	double x_ant, y_ant, z_ant;
	double deltay1, deltay2, deltay3, deltay4;
	double deltaz1, deltaz2, deltaz3, deltaz4;
	for (unsigned int i = 0; i <= 2; i++) {
		cout << "\nIteracao: " << i << ": " << endl;
		cout << "x = " << x << endl;
		cout << "y = " << y << endl;
		cout << "z = " << z << endl;
		x_ant = x; y_ant = y; z_ant = z;
		x += h;
		deltay1 = h * yl(x_ant, y_ant, z_ant);
		deltaz1 = h * zl(x_ant, y_ant, z_ant);
		deltay2 = h * yl(x_ant + h / 2.0, y_ant + deltay1 / 2.0, z_ant + deltaz1 / 2.0);
		deltaz2 = h * zl(x_ant + h / 2.0, y_ant + deltay1 / 2.0, z_ant + deltaz1 / 2.0);
		deltay3 = h * yl(x_ant + h / 2.0, y_ant + deltay2 / 2.0, z_ant + deltaz2 / 2.0);
		deltaz3 = h * zl(x_ant + h / 2.0, y_ant + deltay2 / 2.0, z_ant + deltaz2 / 2.0);
		deltay4 = h * yl(x_ant + h, y_ant + deltay3, z_ant + deltaz3);
		deltaz4 = h * zl(x_ant + h, y_ant + deltay3, z_ant + deltaz3);
		y += deltay1 / 6.0 + deltay2 / 3.0 + deltay3 / 3.0 + deltay4 / 6.0;
		z += deltaz1 / 6.0 + deltaz2 / 3.0 + deltaz3 / 3.0 + deltaz4 / 6.0;
	}
}

void Calcular_QC(double s, double sl, double sll) {
	double result = (sl - s) / (sll - sl);
	cout << "\nQC: " << result << endl;
}

int main() {
	vector<double> S_vetor, SL_vetor, SLL_vetor;
	//Metodo_Gauss_Seidel(2.12687, 2.39858, 3.99517, -3.73040);
	//Metodo_Trapezios_Cubatura(2, 0, 2, 0, 2, 2);
	/*S_vetor = Sistema_Eq(1, 1, 0, 0.25);
	cout << "\n-----\n";
	SL_vetor = Sistema_Eq(1, 1, 0, 0.25 / 2.0);
	cout << "\n-----\n";
	SLL_vetor = Sistema_Eq(1, 1, 0, 0.25 / 4.0);
	cout << endl;
	cout << "QC do y: " << endl;
	Calcular_QC(S_vetor[0], SL_vetor[0], SLL_vetor[0]);
	cout << "QC do z: " << endl;
	Calcular_QC(S_vetor[1], SL_vetor[1], SLL_vetor[1]);*/
	Runge_Kutta4(1, 1, 0, 0.25);
	system("pause");
	return 0;
}
