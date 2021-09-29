#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{	
	double anterior = exp(1) - 1;
	cout << " Ano 0 | " << fixed << setprecision(12) << exp(1) - 1 << endl;
	anterior = anterior - 1;
	for (size_t i = 1; i <= 25; i++)
	{
		cout << " Ano " << i << " | " << fixed << setprecision(12) << anterior << endl;
		if (i == 1)
		{
			continue;
		}
		anterior = anterior * i - 1;
	}
	cout << "\n\n\nErro absoluto: " << abs(-7.017 * pow(10, 11) - anterior) << endl;
	cout << "\n\n\nErro relativo: " << abs(-7.017 * pow(10, 11) - anterior)/(-7.017 * pow(10, 11)) << endl;
	system("pause");
	return 0;
}