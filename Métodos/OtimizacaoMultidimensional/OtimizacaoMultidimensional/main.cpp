#include <iostream>
#include <vector>

using namespace std;

double f(double x, double y) {
	return pow(y, 2) - 2 * x * y - 6 * y + 2 * pow(x, 2) + 12;
}

double dfx(double x, double y) {
	return 4 * x - 2 * y;
}

double dfy(double x, double y) {
	return 2 * y - 2 * x - 6;
}

vector<double> Pesquisa_Multidimensional(double x, double y, double h) {

	vector<double> X = { x,y };
	vector<double> X_ANT = { x,y };
	vector<double> gradiente = { 0,0 };
	bool voltar;

	do {
		voltar = true;
		while (voltar) {
			X_ANT[0] = X[0];
			X_ANT[1] = X[1];
			X[0] = X_ANT[0] - h * gradiente[0];
			X[1] = X_ANT[1] - h * gradiente[1];
			gradiente[0] = dfx(X[0], X[1]);
			gradiente[1] = dfy(X[0], X[1]);
			if (f(X[0], X[1]) < f(X_ANT[0], X_ANT[1])) {
				h *= 2;
				voltar = false;
			}
			else if (f(X[0], X[1]) > f(X_ANT[0], X_ANT[1])) {
				h /= 2.0;
				voltar = true;
			}
		}
	} while (abs(X[0] - X_ANT[0]) > 0.01 || abs(X[1] - X_ANT[1]) > 0.01);

	cout << "\nPesquisa Multidimensional:   x = " << X[0] << "  |  y = " << X[1] << endl;
	return X;
}

double g(double x, double y) {
	return sin(y) + pow(y, 2) / 4.0 + cos(x) + pow(x, 2) / 4.0 - 1;
}

void Metodo_Quadrica(double x, double y) {
	for (unsigned int i = 0; i <= 4; i++) {
		cout << "\nIteracoes: " << i << ": \n";
		cout << "\nx = " << x << "\ny = " << y << endl;
		x = x - ((x / 2.0 - sin(x)) / (1 / 2.0 - cos(x)));
		y = y - ((cos(y) + y / 2.0) / (1 / 2.0 - sin(y)));
	}
	cout << "\nMetodo Quadrica:   x = " << x << "  |  y = " << y << "  |  g(x,y)  = " << g(x,y) << endl;
}

double h(double x, double y) {
	return pow(y, 2) - 2 * x * y - 6 * y + 2 * pow(x, 2) + 12;
}

void Metodo_Lesenberg_Marquardt(double x, double y, double lambda) {
	double x_ant, y_ant;
	for (unsigned int i = 0; i <= 20; i++) {
		cout << "\nIteracao " << i << ": \n";
		cout << "\nx = " << x << "\ny = " << y << "\nh(x,y) = " << h(x,y) << endl;
		x_ant = x; y_ant = y;
		x = -(2 * y_ant - 2 * x_ant - 6) / 2.0 - (4 * x_ant - 2 * y_ant) / 2.0 + x_ant - (4*x_ant-2*y_ant)*lambda;
		y = -y_ant - (4 * x_ant - 2 * y_ant) / 2.0 + 2 * x_ant + 6 - (2*y_ant-2*x_ant-6)*lambda;
		if (h(x, y) > h(x_ant, y_ant)) {
			x = x_ant;
			y = y_ant;
			lambda /= 2.0;
		}
		else {
			lambda *= 2.0;
		}
	}
}

int main() {

	vector<double> pesquisa;
	pesquisa = Pesquisa_Multidimensional(1, 1, 1);
	cout << "\n\nMETODO QUADRICA\n\n";
	Metodo_Quadrica(0, 0);
	cout << "\n\nMETODO LESENBERG MARQUARDT\n\n";
	Metodo_Lesenberg_Marquardt(1, 1, 1);


	cout << endl;
	system("pause");
	return 0;
}