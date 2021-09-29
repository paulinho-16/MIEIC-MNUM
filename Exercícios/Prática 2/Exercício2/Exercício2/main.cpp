#include <iostream>
#include <cmath>
using namespace std;

int main()						// INACABADO
{
	int a;
	double x = 1,rq;
	cout << "Valor de a: ";
	cin >> a;
	while (abs(x * x - a) <= 0.1)
	{
		x += 0.1;
	}
	cout << "SQRT(" << a << ") : " << x << endl;
	system("pause");
	return 0;
}