/*
 * main.c
 *
 *  Created on: Sep 30, 2019
 *      Author: Dmitry Shakhtorin
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// 1. Реализовать функцию перевода из 10 системы в двоичную используя рекурсию.
void dec_to_bin(int x) {
	if (x) {
		dec_to_bin(x>>1); // x / 2
		printf("%d", x % 2);
	}
}

/*
 * 2. Реализовать функцию возведения числа a в степень b:
 * a. без рекурсии;
 * b. рекурсивно;
 * c. *рекурсивно, используя свойство чётности степени.
 */
long pow1(int a, int b) {
	int i;
	long x = 1;
	for (i = 0; i < b; i++) {
		x *= a;
	}
	return x;
}

long pow2(int a, int b) {
	return b ? a * pow2(a, b - 1) : 1;
}

long pow3(int a, int b) {
	if (b == 0)
		return 1;
	if (b % 2 == 1)
		return a * pow3(a, b - 1);
	else {
		long c = pow3(a, b / 2);
		return c * c;
	}
}

/*
 * 3. Исполнитель Калькулятор преобразует целое число, записанное на экране.
 * У исполнителя две команды, каждой команде присвоен номер:
 * 1. Прибавь 1 2.Умножь на 2 Первая команда увеличивает число на экране на 1,
 * вторая увеличивает это число в 2 раза. Сколько существует программ,
 * которые число 3 преобразуют в число 20?
 * а) с использованием массива; б) с использованием рекурсии.
 */
int calcArr() {
	int i;
	int arr[20];
	arr[2] = 0;
	arr[3] = 1;
	for (i = 4; i <= 20; i++) {
		if (i % 2 == 0)
			arr[i] = arr[i - 1] + arr[i / 2];
		else
			arr[i] = arr[i - 1];
	}
	return arr[20];
}

int calcRec(int i) {
	if (i == 2)
		return 0;
	if (i == 3)
		return 1;
	if (i % 2 == 0)
	    return calcRec(i - 1) + calcRec(i / 2);
	else
	    return calcRec(i - 1);
}

int main(int argc, const char** argv) {

	//1
    int d;
    printf("Введите целое число: ");
    scanf("%d", &d);
    dec_to_bin(d);
    printf("\n");

    //2
    int n;
    printf("Введите целое число a: ");
    scanf("%d", &d);
    printf("Введите степень n: ");
    scanf("%d", &n);
    printf("a) Число %d возведенное в степень %d равно: %ld\n", d, n, pow1(d, n));
    printf("b) Число %d возведенное в степень %d равно: %ld\n", d, n, pow2(d, n));
    printf("c) Число %d возведенное в степень %d равно: %ld\n", d, n, pow3(d, n));

    //3
    printf("a) Колличество программ проеобразующих 3 в 20: %d\n", calcArr());
    printf("b) Колличество программ проеобразующих 3 в 20: %d\n", calcRec(20));

    return 0;
}
