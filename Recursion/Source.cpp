#include<iostream>
using namespace std;

void elevator(int floor);
long long int factorial(long long int n);
double Power(double a, int n);
void Fibonacci(int n/*, int a = 0, int b =1*/);

//#define ELEVATOR
//#define FACTORIAL
//#define POWER
#define FIBONACCI_1

void main()
{
	setlocale(LC_ALL, "Russian");

#ifdef DEBUG
	cout << "Hello World";
	main(); // main function call  
#endif // DEBUG

#ifdef ELEVATOR
	int floor;
	cout << "Введите номер этажа: "; cin >> floor;
	elevator(floor);
#endif // ELEVATOR

#ifdef FACTORIAL
	int n;
	cout << "Введите число для вычисления факториала: "; cin >> n;
	cout << n << "! = " << factorial(n) << endl;
#endif // FACTORIAL

#ifdef POWER
	int a; // основание степени
	int n; // показатель степени
	cout << "Введите основание и показатель степени: "; cin >> a >> n;
	cout << Power(a, n);
#endif // POWER

	int n;
	cout << "До какого предельного значения нужно вывести ряд Фибоначчи: "; cin >> n;
	Fibonacci(n);
	cout << endl;

	main();
}

void elevator(int floor)
{
	if (floor == 0)
	{
		cout << "Мы в подвале, выход платный :-D" << endl;
		return;
	}
	cout << floor << endl;
	elevator(floor - 1);
	cout << floor << endl;
}

long long int factorial(long long int n)
{
	/*if (n == 0) return 1;
	int f = n * factorial(n - 1);
	return f;*/

	/*if (n == 0) return 1;
	return n * factorial(n - 1);*/

	return(n == 0) ? 1 : n * factorial(n - 1);
}

double Power(double a, int n)
{
	
	/*if (n == 0) return 1;
	if (n < 0)
	{
		double N = 1 / a * Power(a, n + 1);
	return N;
	}
	else
	{
		double N = a * Power(a, n - 1);
	return N;
	}*/

	/*if (n < 0)
	{
		a = 1 / a;
		n = -n;
	}
	return (n == 0) ? 1 : a * Power(a, n - 1);*/

	return n == 0 ? 1 : n > 0 ? a * Power(a, n - 1) : 1 / a * Power(a, n + 1); // когда ты только подумал, что начал понимать тернарник
}

void Fibonacci(int n/*, int a, int b*/)
{
	static int a = 0, b = 1, c = 1; // как глобальные; хранятся в области памяти, где глобальные.
	if (a > n) return;
	cout << a << "\t";
	//Fibonacci(n, b, a + b);
	/*a = b;
	b = c;
	c = a + b;*/
	c = (a = b) + (b = c);
	Fibonacci(n);
}