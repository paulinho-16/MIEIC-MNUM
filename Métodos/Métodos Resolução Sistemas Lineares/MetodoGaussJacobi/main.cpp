#include <iostream>

using namespace std;

void Calcular_Residuos(double x1, double x2, double x3)
{
	double residuo_1, residuo_2, residuo_3;
	residuo_1 = 3 * x1 + x2 + x3 - 7;
	residuo_2 = x1 + 4 * x2 + 2 * x3 - 4;
	residuo_3 = 2 * x2 + 5 * x3 - 5;
	cout << "\nResiduo 1: " << residuo_1;
	cout << "\nResiduo 2: " << residuo_2;
	cout << "\nResiduo 3: " << residuo_3 << endl << endl;
}

void Metodo_Gauss_Jacobi(double x1, double x2, double x3)
{
	int iteracoes = 0;
	double x1_ant, x2_ant, x3_ant;
	do {
		cout << iteracoes << ": " << "\nx1 = " << x1 << "\nx2 = " << x2 << "\nx3 = " << x3 << endl << endl;
		iteracoes++;
		x1_ant = x1;
		x2_ant = x2;
		x3_ant = x3;
		x1 = (7 - x2_ant - x3_ant) / 3.0;
		x2 = (4 - x1_ant - 2 * x3_ant) / 4.0;
		x3 = (5 - 2 * x2_ant) / 5.0;
	} while (abs(x1 - x1_ant) > pow(10, -3) || abs(x2 - x2_ant) > pow(10, -3) || abs(x3 - x3_ant) > pow(10, -3));
	Calcular_Residuos(x1, x2, x3);
}

void Metodo_Gauss_Seidel(double x1, double x2, double x3)
{
	int iteracoes = 0;
	double x1_ant, x2_ant, x3_ant;
	do {
		cout << iteracoes << ": " << "\nx1 = " << x1 << "\nx2 = " << x2 << "\nx3 = " << x3 << endl << endl;
		iteracoes++;
		x1_ant = x1;
		x2_ant = x2;
		x3_ant = x3;
		x1 = (7 - x2_ant - x3_ant) / 3.0;
		x2 = (4 - x1 - 2 * x3_ant) / 4.0;
		x3 = (5 - 2 * x2) / 5.0;
	} while (abs(x1 - x1_ant) > pow(10, -3) || abs(x2 - x2_ant) > pow(10, -3) || abs(x3 - x3_ant) > pow(10, -3));
	Calcular_Residuos(x1, x2, x3);
}

int main()
{
	//Metodo_Gauss_Jacobi(0, 0, 0);
	Metodo_Gauss_Seidel(0, 0, 0);

	system("pause");
	return 0;
}