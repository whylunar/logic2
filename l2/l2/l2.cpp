// l2.cpp: определяет точку входа для консольного приложения.
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
const int N = 1000;																	
int a[N][N], b[N][N], c[N][N], elem_c;

int main(void)
{

	setlocale(LC_ALL, "RUS");

	setvbuf(stdin, NULL, _IONBF, 0);
	setvbuf(stdout, NULL, _IONBF, 0);
	double start, end; // объявляем переменные для определения времени выполнения

	FILE* fp = NULL;
	char name[] = "time.txt";

	int i = 0, j = 0, r;

	fp = fopen(name, "a");
	if (fp != NULL) {
		printf("Файл запущен удачно \n");
	}
	else {
		printf("Ошибка!\n");
		exit(0);
	}
	fprintf(fp, " %d Элементов - ", N);


	srand(time(NULL)); // инициализируем параметры генератора случайных чисел
	while (i < N)
	{
		while (j < N)
		{
			a[i][j] = rand() % 100 + 1; // заполняем массив случайными числами
			j++;
		}
		i++;
	}
	srand(time(NULL)); // инициализируем параметры генератора случайных чисел
	i = 0; j = 0;
	while (i < N)
	{
		while (j < N)
		{
			b[i][j] = rand() % 100 + 1; // заполняем массив случайными числами
			j++;
		}
		i++;
	}
	start = clock();

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			elem_c = 0;
			for (r = 0; r < N; r++)
			{
				elem_c = elem_c + a[i][r] * b[r][j];
				c[i][j] = elem_c;
			}
		}
	}

	end = clock();
	fprintf(fp, " %lf секунд\n", (end - start) / CLOCKS_PER_SEC);
	fclose(fp);
	return(0);
}
