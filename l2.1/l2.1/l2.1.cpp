// L2.1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
const int N = 10000;
int m[N];
double start, end;
FILE* fp = NULL;
char name[] = "2.txt";
void shell(int* items, int count)
{

    int i, j, gap, k;
    int x, a[5];

    a[0] = 9; a[1] = 5; a[2] = 3; a[3] = 2; a[4] = 1;

    for (k = 0; k < 5; k++) {
        gap = a[k];
        for (i = gap; i < count; ++i) {
            x = items[i];
            for (j = i - gap; (x < items[j]) && (j >= 0); j = j - gap)
                items[j + gap] = items[j];
            items[j + gap] = x;
        }
    }
}

void qs(int* items, int left, int right) //вызов функции: qs(items, 0, count-1);
{
    int i, j;
    int x, y;



    i = left; j = right;

    /* выбор компаранда */
    x = items[(left + right) / 2];

    do {
        while ((items[i] < x) && (i < right)) i++;
        while ((x < items[j]) && (j > left)) j--;

        if (i <= j) {
            y = items[i];
            items[i] = items[j];
            items[j] = y;
            i++; j--;
        }
    } while (i <= j);

    if (left < j) qs(items, left, j);
    if (i < right) qs(items, i, right);
}
int compare(const void* x1, const void* x2)   // функция сравнения элементов массива
{
    return (*(int*)x1 - *(int*)x2);              // если результат вычитания равен 0, то числа равны, < 0: x1 < x2; > 0: x1 > x2
}
void timesort(int* items) {

    fprintf(fp, "  Сортировка Шелла\t");
    start = clock();
    shell(items, N);	//Сортировка Шелла
    end = clock();
    fprintf(fp, " %lf \n", (end - start) / CLOCKS_PER_SEC);

    fprintf(fp, "  Быстрая сортировка \t");
    start = clock();
    qs(items, 0, N - 1);	//Быстрая сортировка
    end = clock();
    fprintf(fp, " %lf \n", (end - start) / CLOCKS_PER_SEC);

    fprintf(fp, "  Ф-я Быстрая сортировка \t");
    start = clock();
    qsort(items, N, sizeof(int), compare);
    end = clock();
    fprintf(fp, " %lf \n", (end - start) / CLOCKS_PER_SEC);

}


int main()
{
    srand(time(NULL));

    int i = 0, j = 0, r;

    fp = fopen(name, "a");
    if (fp != NULL) {
        printf("Файл запущен удачно \n");
    }
    else {
        printf("Файл не найден\n");
        exit(0);
    }
    fprintf(fp, "  Заполнение массива случайными числами \n");
    for (i = 0; i < N; i++) {
        m[i] = rand() % 100 + 1;
    }
    timesort(m);

    fprintf(fp, "  Возрастающая последовательность \n");
    for (i = 0; i < N; i++) {
        m[i] = i;
    }
    timesort(m);

    fprintf(fp, "  Убывающая последовательность \n");
    for (i = 0; i < N; i++) {
        m[i] = N - i;
    }
    timesort(m);

    fprintf(fp, "  Возрастающе-убывающая последовательность \n");
    for (i = 0; i < N / 2; i++) {
        m[i] = i;
    }
    for (i = N / 2; i < N; i++) {
        m[i] = N - i + 1;
    }
    timesort(m);

    fclose(fp);
    return(0);

}
