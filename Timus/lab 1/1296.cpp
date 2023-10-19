//1296. Гиперпереход
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main() {
	// Объявление переменных: длина последовательности, максимальный потенциал, текущая сумма и массив для грави-интенсивности.
	int n, max = 0, sum = 0;
	long long int a[60001];

	// Считывание длины последовательности.
	cin >> n;

	// Считывание грави-интенсивности для каждого момента времени.
	for(int i=0; i<n; i++)
		cin >> a[i];

	// Инициализация максимального потенциала и текущей суммы, если первое значение положительное.
	if(a[0] > 0) {
		max = a[0];
		sum = a[0];
	}

	// Проход по всем значениям грави-интенсивности, начиная со второго.
	for(int i=1; i<n; i++) {
		// Обновляем текущую сумму.
		sum = sum + a[i];
		// Если текущая сумма становится отрицательной, обнуляем её.
		if(sum < 0) {
			sum = 0;
		}
		// Если текущая сумма больше максимальной, обновляем максимальную сумму.
		if(sum > max) {
			max = sum;
		}
	}

	// Вывод максимального гравитационного потенциала.
	cout << max;

	return 0;
}
