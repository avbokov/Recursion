#include<iostream>
using namespace std;

int Factorial(int number);
double Power(double a, int n);
void Print(int arr[], const int n);
void FillFibonacci(int arr[], const int n);
int Fibonacci(int number_fib);

void main()
{
	setlocale(LC_ALL, "Russian");

	int number, number_fib, n;
	double a;
	const int SIZE_FIB = 47;
	int arr_fib[SIZE_FIB];

	cout << "Введите число для вычисления его факториала: "; cin >> number;
	cout << "Факториал числа " << number << " равен: " << Factorial(number) << endl << endl;

	cout << "Введите число для возведения в степень: "; cin >> a;
	cout << "В какую степень будем возводить число " << a << "? "; cin >> n;
	cout << "Число " << a << " в степени " << n << " равно: " << Power(a, n) << endl << endl;

	cout << "Ряд Фибоначчи для значений до int'a: " << endl;
	FillFibonacci(arr_fib, SIZE_FIB);
	Print(arr_fib, SIZE_FIB);
	cout << endl << endl;

	cout << "Введите количество значений из ряда Фибоначчи: "; cin >> number_fib;
	cout << endl;
	cout << "Ряд Фибоначчи для " << number_fib << " значений выглядит так: ";
	
	//cout << Fibonacci(number_fib);

	for (int i = 1; i <= number_fib; i++)
	{
		cout <<Fibonacci(i) << " ";
	}

	cout << endl << endl;

	cout << "Введите число, до которого будет выведен ряд Фибоначчи: "; cin >> number_fib;
	cout << endl;
	cout << "Ряд Фибоначчи до числа " << number_fib << " выглядит так: ";
	
	for (int i = 1; Fibonacci(i) <= number_fib; i++)
	{
		cout << Fibonacci(i) << " ";
	}
}

int Factorial(int number)
{
	//int F;
	if (number == 0) return 1;
	else
	{
		/*cout << number << endl;
		F = number * Factorial(number - 1);
		cout << number << "\t" << F << endl;*/
		return number * Factorial(number - 1);
		//return F;
	}
}

double Power(double a, int n) // а - число, n - показатель степени
{
	if (n < 0)
	{
		a = 1 / a;
		n = -n;
	}
	if (n == 0) return 1;
	else return a * Power(a, n - 1);
}

void Print(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
}

void FillFibonacci(int arr[], const int n) // без рекурсии, так сказать для вхождения в Фибоначчи
{
	arr[0] = 0;
	arr[1] = 1;
	for (int i = 2; i < n; i++)
	{
		arr[i] = arr[i - 2] + arr[i - 1];
	}
}

int Fibonacci(int number_fib)
{
	//int F;
	if (number_fib == 1) return 0;
	if (number_fib == 2) return 1;
	else
	{
		//F = Fibonacci(number_fib - 1) + Fibonacci(number_fib - 2);
		//cout << F << "\t";
		return Fibonacci(number_fib - 1) + Fibonacci(number_fib - 2);
		//return F;
	}
	// так и не получилось сделать вывод значений внутри рекурсивной функции
}

