#define _USE_MATH_DEFINES 
#define _CRT_SECURE_NO_WARNINGS
#define N 100
#include <stdio.h>
#include <locale.h>
#include <math.h>
double* full_elements(double* ptr_array, int n)
{
	double z, y=0;
	z = 2.1 / n;
	for (int i = 0; i < n; i++)
	{
		y += z;
		ptr_array [i] = pow(y, 2) - pow(cos(y + 1), 2);
	}
	return (ptr_array);
}
int put_elements(double* ptr_array, int n)
{
	for (int i = 0; i < n; i ++)
	{
		printf("%+lf \n", ptr_array[i]);
	}
}
double calc_elements(double* ptr_array, int n)
{
	double max= ptr_array[1], min= ptr_array[1], sum=0;
	for (int i = 0; i < n; i++)
	{
		if (ptr_array[i] > max) max = ptr_array[i];
		if (ptr_array[i] < min) min = ptr_array[i];
	}
	for (int i = 0; i < n; i++)
	{
		if ((ptr_array[i] != max) && (ptr_array[i] != min)) sum += ptr_array[i];
	}
	return (sum);
}
double sum_elements(double* ptr_array, int begin, int end)
{
	double sum = 0;
	for (int i = begin; i < end+1; i++)
	{
		sum += ptr_array[i];
	}
	return (sum);
}
int find_element(double* ptr_array, int n, double element)
{
	double y=0;
	for (int i = 0; i < n; i++)
	{
		if (ptr_array[i] == element) y = ptr_array[i];
	}
	if (y == 0) return (-1); else return (y);
}
float min_element(double* ptr_array,int n, double a, double b)
{
	double y = 100;
	for (int i = 0; i < n; i++)
	{
		if ((ptr_array[i] < y) && (ptr_array[i] > a) && (ptr_array[i] < b)) y = ptr_array[i];
	}
	if (y == 100) return (0); else return (y);
}
int lab14task3()
{
	double array[N], find, a, b;
	int size;
	printf("¬ведите размер массива          > ");
	scanf("%d", &size);
	printf("¬ведите первое число интервала  > ");
	scanf("%lf", &a);
	printf("¬ведите второе число интервала  > ");
	scanf("%lf", &b);
	full_elements(array, size);
	put_elements(array, size);
	printf("минимальный элемент в интервале= %+lf \n", min_element(array, size, a, b));
}
int lab14task2()
{
	double array[N], find;
	int size, begin, end;
	printf("¬ведите размер массива          > ");
	scanf("%d", &size);
	printf("¬ведите первый элемент суммы    > ");
	scanf("%d", &begin);
	printf("¬ведите последний элемент суммы > ");
	scanf("%d", &end);
	printf("¬ведите искомый элемент         > ");
	scanf("%lf", &find);
	full_elements(array, size);
	//put_elements(array, size);
	printf("сумма= %+lf \n", sum_elements(array, begin, end));
	printf("индекс элемента= %d \n", find_element(array, size, find));
}
int lab14task1()
{
	double array[N];
	int size;
	printf("¬ведите размер массива > ");
	scanf("%d", &size);
	full_elements(array, size);
	put_elements(array, size);
	printf("сумма=%+lf \n", calc_elements(array, size));
}
int main()
{
	setlocale(LC_CTYPE, "RUS");
	char c;
	printf("¬ведите номер задани€ лабораторной ");
	scanf("%c", &c);
	switch (c)
	{
	case '1':
		lab14task1();
		break;
	case '2':
		lab14task2();
		break;
	case '3':
		lab14task3();
		break;
	default:
		printf("Ќеизвестна€ операци€.\n");
	}
}