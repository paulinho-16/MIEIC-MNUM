#include <iostream>

using namespace std;

double f1(double x, double y)
{
	return sqrt((x * y + 5 * x - 1) / 2.0);
}

double f2(double x, double y)
{
	return sqrt(x + 3 * log(x));
}

double d_f1_x(double x, double y)
{
	return -y + 4 * x - 5;
}

double d_f2_x(double x, double y)
{
	return 3.0 / x + 1;
}

double d_f1_y(double x, double y)
{
	return -x;
}

double d_f2_y(double x, double y)
{
	return -2 * y;
}

void Picard_Peano_Sistemas(double x, double y)
{
	int iteracoes = 0;
	double x_anterior = x - 10, y_anterior = y - 10;
	while ((abs(x - x_anterior) > pow(10, -5)) && (abs(y - y_anterior) > pow(10, -5)))
	{
		iteracoes++;
		x_anterior = x;
		y_anterior = y;
		x = f1(x, y);
		y = f2(x, y);
		cout << iteracoes << ": x = " << x << "  y = " << y << endl;
	}
	cout << "\nResposta: x = " << x << "  y = " << y << endl;
}

void Newton_Sistemas(double x, double y)
{
	int iteracoes = 0;
	double x_anterior, y_anterior, jacobian, hn, kn;
	while (true)
	{
		iteracoes++;
		x_anterior = x;
		y_anterior = y;
		jacobian = d_f1_x(x,y) * d_f2_y(x,y) - d_f1_y(x,y) * d_f2_x(x,y);
		hn = -(f1(x, y) * d_f2_y(x, y) - f2(x, y) * d_f1_y(x, y)) / (double) jacobian;
		kn = -(d_f1_x(x, y) * f2(x, y) - d_f2_x(x, y) * f1(x, y)) / (double) jacobian;
		x += hn;
		y += kn;
		cout << iteracoes << ":\tx = " << x << "  y = " << y << endl;
		if ((abs(x - x_anterior) < pow(10, -5)) && (abs(y - y_anterior) < pow(10, -5)))
			break;
	}

	cout << "\nResposta: x = " << x << "  y = " << y << endl;
}

int main()
{
	//Picard_Peano_Sistemas(4, 4);
	Newton_Sistemas(3.5, 2.3);

	system("pause");
	return 0;
}