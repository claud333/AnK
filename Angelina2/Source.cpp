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
double* F1(double x, double toch,int &sizeARR,double*arr)
{
	double y;
	for (int k = 1;k <= 4;k++)
	{
		y = pow(x, k) / Fact(2 * k);
	}
	sizeARR++;
	arr = (double*)realloc(arr,sizeof(double)*sizeARR);
	arr[sizeARR-1 ]= round(log(y)*pow(10, toch)) / pow(10, toch);
	return arr;

}
double* F2(double x, double toch, int &sizeARR, double*arr)
{
	double y;
	if (x > 4.5) { y = 3 * x*x; }
	else if (x < 1) { y = cos(2 * x)*cos(2 * x)*(-1); }
	else { y = exp(-x); }
	sizeARR++;
	arr = (double*)realloc(arr, sizeof(double)*sizeARR);
	arr[sizeARR-1]= round(y*pow(10, toch)) / pow(10, toch);
	return arr;
}
double* F3(double x, double size, int &sizeARR, double*arr)
{

	double y = 0;
	for (int i = 1;i <= size;i += 2)
	{
		y += pow(sin(i*x), i);
	}
	sizeARR++;
	arr = (double*)realloc(arr, sizeof(double)*sizeARR);
	arr[sizeARR-1] =y;
	return arr;
}
void locMin(double *arr,int sizeARR,double& min,int &kol)
{
	kol=0;
	min = arr[0]+1;
	for (int i = 0;i < sizeARR;i++)
	{
		if (min > arr[i]) { min = arr[i];kol++; }
	}
	printf("Локальный минимум =%f\nНайденно %i локальных минимумов\n____________________________\n",min,kol);
}
void fileRecord(double *a,int sizeARR, double min, int kol)
{
	FILE *R;
	printf("Введите имя фаила ");
	char name[30];
	scanf("%s", name);
	R = fopen(name, "w");
	for (int i = 0;i < sizeARR;i++)
	{
		fprintf(R, "%f\n", a[i]);
	}
	printf("Локальный минимум =%f\nНайденно %i локальных минимумов\n____________________________\n", min, kol);

}
double*(*func)(double, double,int &,double*);
int main()
{
	double* arr = NULL;
	int sizeARR = 0;
	int  kol;
	double min;
	while (1==1)
	{
		double x;

		setlocale(0, "rus");
		int start, finish;
		printf("какую фугкцию вычислять?\n1.F1\n2.F2\n3.F3\n5.Записать в фаил\n0.Выход\n");
		int fn;
		scanf("%i", &fn);

		switch (fn)
		{
		case 0:exit(0);break;
		case 1:func = &F1;break;
		case 2:func = &F2;break;
		case 3:func = &F3;break;
		case 5:fileRecord(arr, sizeARR, min, kol);continue;break;
		}
		

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




		

		for (double x = start;x <= finish;x += shag)
		{
			arr = func(x, size, sizeARR, arr);
		}
		for (int i = 0;i < sizeARR;i++)
		{
			printf(" %f\n", arr[i]);
		}
		
		locMin(arr, sizeARR,min,kol);
	}
	_getch();

	return 0;
}
