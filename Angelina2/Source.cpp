#include <stdio.h> 
#include <iostream> 
#include <math.h> 
#include <conio.h> 
using namespace std;
double Fact(int N)
{
	if (N < 0) { return 0; }
	if (N == 0) { return 1; }
	if (N > 0) { return N*Fact(N - 1); }
}
double F1(double x, double toch)
{
	double y;
	for (int k = 1;k <= 4;k++)
	{
		y = pow(x, k) / Fact(2 * k);
	}
	return round(log(y)*pow(10, toch)) / pow(10, toch);

}
double F2(double x, double toch)
{
	double y;
	if (x > 4.5) { y = 3 * x*x; }
	else if (x < 1) { y = cos(2 * x)*cos(2 * x)*(-1); }
	else { y = exp(-x); }
	return round(y*pow(10, toch)) / pow(10, toch);
}
double F3(double x, double size)
{

	double y = 0;
	for (int i = 1;i <= size;i += 2)
	{
		y += pow(sin(i*x), i);
	}
	return y;
}
double(*func)(double, double);

void funcStart(int start, int finish, double shag, int size, int out, double(*func)(double, double))
{

}

int main()
{
	double x;

	setlocale(0, "rus");

	int start, finish;
	printf("какую фугкцию вычислять?\n1.F1\n2.F2\n3.F3\n");
	int fn;
	scanf("%i", &fn);
	printf("Введите промежуток \nот ");
	scanf("%i", &start);
	printf("до ");
	scanf("%i", &finish);
	float shag;
	printf("Введите шаг табуляции ");
	scanf("%f", &shag);
	int size;
	printf("Введите точность вычисления (кол-во знаков после запятой) в f1,f2/число членов в f3(x) ");
	scanf("%i", &size);
	int out;
	printf("1.Вывести на экран\n2.Запист в фаил\n ");
	scanf("%i", &out);


	switch (fn)
	{
	case 1:func = &F1;;break;
	case 2:func = F2;break;
	case 3:func = F3;break;
	}
	if (out == 1)
	{
		double min = 99999.0; int locm = 0;
		for (double x = start;x <= finish;x += shag)
		{
			double l = func(x, size);
			printf("F(%1.3f) = %f \n", x, l);
			if (l < min) { min = l; }
		}
		for (double x = start;x <= finish;x += shag)
		{
			if (func(x, size) == min) { locm++; }
		}
		printf(" найденно %i локальных минимумов = %f \n", locm, min);
	}
	else
	{
		printf("Введите имя фаила ");
		char name[30];
		scanf("%s", name);
		FILE *f1;
		f1 = fopen(name, "w");
		double min = 99999.0; int locm = 0;
		for (double x = start;x <= finish;x += shag)
		{
			double l = func(x, size);
			fprintf(f1, "F(%1.3f) = %f \n", x, l);
			if (l < min) { min = l; }
		}
		for (double x = start;x <= finish;x += shag)
		{
			if (func(x, size) == min) { locm++; }
		}
		fprintf(f1, " найденно %i локальных минимумов = %f \n", locm, min);
		fclose(f1);
	}
	_getch();
	return 0;
}
