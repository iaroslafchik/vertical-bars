#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <math.h>

unsigned __int64 uintPow(unsigned __int64 _X, unsigned __int64 _Y) {
	if (_Y == 0) return 1;
	if (_Y == 1) return _X;
	unsigned __int64 X = _X;
	for (; _Y != 0 ; _Y--) {
		X *= _X;
	}
	return X;
}

int main() {
	setlocale(0, ".1251");
	srand(time(0));

	unsigned __int64 seed = 0, digit = 0, height, width;

	printf("¬ведите ширину [1; 18] и высоту эквалайзера [1; 10]: ");
	for ( ; ; ) {
		if (scanf("\n%lld%lld", &width, &height) == 2 &&\
			width > 0 && height > 0 && height <= 10) {
			break;
		}
	}

	for (__int64 i = width; i != 0; i--) {
		seed += (rand() % height) * uintPow(10, i - 1);
	}

	for (__int64 i = 0; i != height; i++) {
		for (__int64 j = width; j != 0; j--) {
			digit = seed / uintPow(10, j - 1) % 10;
			if (digit == i) {
				printf("\033[7m%.0lld\033[0m", digit);
				if (digit != height - 1) {
					seed += uintPow(10, j - 1);
				}
			}
			else {
				printf(" ");
			}
		}
		printf("\n");
	}
}