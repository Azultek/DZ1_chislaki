#include <iostream>
#include <math.h>
#include <conio.h>
#include <iomanip>
long double function(long double x);
void dichotomies_max(long double eps, long double a, long double b);
void golden_section_max(long double eps, long double a, long double b);
void quadratic_approximation_max(long double eps, long double a, long double b);

void main()
{
	int i = 3;
	switch (i)
	{
	case 1:
		quadratic_approximation_max(0.01, 0, 1);
		break;
	case 2:
		quadratic_approximation_max(0.0001, 0, 1);
		break;
	case 3:
		quadratic_approximation_max(0.0000001, 0, 1);
		break;
	case 4:
		quadratic_approximation_max(pow(10, -17), 0, 1);
		break;
	}
	
	
	
	
}


long double function(long double x)
{

	return sin((-sqrt(11) * pow(x, 4) - pow(x, 2) + 10 * x + 3 - sqrt(7)) / 10) +
		tanh((-pow(x, 4) - pow(5, double(1) / 3) * pow(x, 3) + 3 * x + 3 * pow(5, double(1) / 3) - 2)/ (2 * x + 2 * pow(5, double(1) / 3))) - 1;
}

void dichotomies_max(long double eps, long double a, long double b)
{
	using namespace std;
	int iterations = 0;
	int calculations = 0;
	long double step = eps / 2;
	long double center = 0;
	while (((b - a)) > eps && iterations < 100)
	{
		iterations++;
		calculations += 2;
		center = (b +a) / 2;
		if(function(center - step) > function(center + step))
			b = center;
		else
			a = center;
		cout.setf(ios::fixed);
		long double c = b - a;
		cout << setprecision(20) << c  << endl;

	}
	for (int j = 1; j <= iterations; j++)
	{
		cout << j << endl;
	}
}

void golden_section_max(long double eps, long double a, long double b)
{
	using namespace std;
	long double f = (1 + sqrt(5)) / 2;
	int iterations = 0;
	int calculations = 2;
	long double x1 = b - (b - a) / f;
	long double x2 = a + (b - a) / f;
	long double F1 = function(x1);
	long double F2 = function(x2);
	while (abs(b - a) >= eps && iterations < 100)
	{
		
		
		iterations++;
		if (F1 <= F2)
		{
			a = x1;
			x1 = x2;
			F1 = F2;
			x2 = a + (b - a) / f;
			F2 = function(x2);
		}
		else
		{
			b = x2;
			x2 = x1;
			F2 = F1;
			x1 = b - (b - a) / f;
			F1 = function(x1);
		}

		calculations++;
		cout.setf(ios::fixed);
		long double c = b - a;
		cout << setprecision(20) << c << endl;
	}
	for (int j = 1; j <= iterations; j++)
	{
		cout << j << endl;
	}
}
/*
void quadratic_approximation_max(long double eps, long double a, long double b)
{
	using namespace std;
	int iterations = 0;
	int calculations = 3;
	long double x;
	long double c = (a + b) / 3;
	long double F1 = function(a);
	long double F2 = function(c);
	long double F3 = function(b);
	while (b - a > eps)
	{
		x = (F1 * (c*c - b*b) - F2 * (a*a - b*b) + F3 * (a*a - c*c)) / (2 * (F1 * (c - b) - F2 * (a - b) + F3 * (a - c)));
		if (x > c)
		{
			a = c;
			F1 = F2;
		}
		else
		{
			b = c;
			F3 = F2;
		}
		c = x;
		F2 = function(c);
		iterations++;
		calculations++;
		cout.setf(ios::fixed);
		cout << setprecision(20)<< b - a << endl;
	}
	for (int j = 1; j <= iterations; j++)
	{
		cout << j << endl;
	}
	cout << iterations << endl
		<< calculations;
	cout.setf(ios::fixed);
	cout << setprecision(20)<< endl << c << endl << function(c) << endl;
}*/
//asdasdasdasdasdasdasdasdasdasd
void quadratic_approximation_max(long double eps, long double a, long double b)
{
	using namespace std;
	int iterations = 0;
	int calculations = 3;
	long double x;
	long double c = (a + b) / 2;
	long double F1 = function(a);
	long double F2 = function(c);
	long double F3 = function(b);
	while (b - a > eps)
	{
		x = (c+a)/2 - ((F2 - F1) * (b - c) * (b - a)) / (2 * ((F3 - F1) * (c - a) - (F2 - F1) * (b - a)));

		if (x > c)
		{
			a = c;
			F1 = F2;
		}
		else
		{
			b = c;
			F3 = F2;
		}
		c = x;
		F2 = function(c);
		iterations++;
		calculations++;
		cout.setf(ios::fixed);
		long double c = abs(b - a);
		cout << setprecision(20) << c << endl;
	}
	for (int j = 1; j <= iterations; j++)
	{
		cout << j << endl;
	}
	cout.setf(ios::fixed);
	cout << endl << endl << setprecision(20) << endl << c << endl << function(c) << endl;
}
