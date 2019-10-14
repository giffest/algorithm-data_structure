/*
 * main.c
 *
 *  Created on: Sep 29, 2019
 *      Author: Dmitry Shakhtorin
 */

#include <stdio.h>
#include <stdlib.h>

// Алгоритм Эвклида
int gcd(int x, int y) {
    while (x != y) {
        if (x > y)
            x = x - y;
        else
            y = y - x;
    }
    return x;
}

// Алгоритм Эвклида с делением
int gcdDiv(int a, int b) {
	while (b != 0) {
		int c  = a % b;
		a = b;
		b = c;
	}
	return a;
}

// Определение средней оценки с помощью цикла while.
float avrg1() {
	int sum = 0;
	int count = 0;
	int in;
	while (count < 10){
		printf("Введите число %d: ", ++count);
		scanf("%d", &in);
		sum = sum + in;
	}
	return sum / 10;
}

// Определение средней оценки с помощью цикла while. Используем флаг
float avrg2() {
	int sum = 0;
	int counter = 0;
	int in;
	printf("Вводите числа или -1 для выхода. Первое число: ");
	scanf("%d", &in);
	while (in != -1) {
		sum = sum + in;
		counter++;
		printf("Введите число: ");
		scanf("%d", &in);
	}
	if (counter	!= 0)
		return printf("Среднее введенных чисел: %.2f\n", (float)sum / (float)counter);
	else
		return -1;
}

// Определение средней оценки с помощью цикла while. Используем флаг
float avrg3() {
	int sum = 0;
	int counter = 0;
	int in = 0;
	printf("Вводите числа или -1 для выхода.\n");
//	scanf("%d", &in);
	while (in != -1) {
		sum = sum + in;
		counter++;
		printf("Введите число: ");
		scanf("%d", &in);
	}
	if (--counter != 0) {
		return printf("Среднее введенных чисел: %.2f\n", (float)sum / (float)counter);
	}
	else
		return -1;
}

//  Переворот числа
int reverse(int old) {
	int new = 0;
	while (old > 0) {
		new *= 10;
		new += old % 10;
		old /= 10;
	}
	return new;
}

// Возведение в степень
int steps = 0;
int expon(int a, int n) {
	int k = 0;
	int b = 1;
	while (k != n) {
		steps++;
		k++;
		b *= a;
	}
	return b;
}

int expon2(int a, int n) {
	int b = 1;
	for (int i = 0; i < n; i++) {
		steps++;
		b *= a;
	}
	return b;
}

// Ускоренное возведение в степень
int exponPower(int a, int n) {
	int b = 1;
	while (n) { // n != 0
		steps++;
		if (n % 2) { // n % 2 == 1
			n--;
			b *= a;
		} else {
			a *= a;
			n /= 2;
		}
	}
	return b;
}

int main(int argc, const char** argv) {

    printf("GCD: %d\n", gcd(7, 49));
    printf("GCDDiv: %d\n", gcdDiv(5, 25));
//    printf("Среднее: %d\n", (int)avrg1());
//    printf("Среднее введенных чисел: %.2f\n", avrg2());
//    avrg2();
//    avrg3();
    printf("reverse: %d\n", reverse(46492432));
    printf("Число %d возведенное в %d степень: %d\n", 2, 30, expon(2, 30));
    printf("%d\n", steps);
    steps = 0;
    printf("Число %d возведенное в %d степень: %d\n", 2, 30, expon2(2, 30));
    printf("%d\n", steps);
    steps = 0;
    printf("Число %d возведенное в %d степень: %d\n", 2, 30, exponPower(2, 30));
    printf("%d\n", steps);

    return 0;
}

