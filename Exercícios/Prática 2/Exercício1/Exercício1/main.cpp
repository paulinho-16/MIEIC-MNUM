#include <iostream>
using namespace std;

int main()
{
	double r1, r2;
	for (double x1 = 1; x1 < 20.1; x1 += 0.1)
	{
		cout << "  " <<  x1 << ": " << exp(x1) << endl;
		r1 = x1;
	}
	cout << "--------------------------------" << endl;
	for (int x2 = 1; x2 <= 20; x2++)
	{
		cout << "  " << x2 << ": " << exp(x2) << endl;
		r2 = x2;
	}
	cout << endl << (r1 == r2) << endl;
	system("pause");
	return 0;
}