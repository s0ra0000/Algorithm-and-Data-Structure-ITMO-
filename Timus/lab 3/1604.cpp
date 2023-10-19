//1604. В Стране Дураков
#include <algorithm>
#include <iostream>
using namespace std;

// Структура для представления знака с ограничением скорости
struct obstacle{
  int count; // Количество таких знаков
  int num;   // Номер (или тип) этого знака
};

const int MAXNUM = 10010;
obstacle o[MAXNUM];      // Массив для хранения информации о знаках
int ans[MAXNUM][MAXNUM]; // Двумерный массив для хранения порядка установки знаков

// Функция сравнения для сортировки массива знаков по убыванию количества
bool cmp(obstacle a, obstacle b) {
	return (a.count > b.count);
}

// Функция решения задачи
void solve(int n) {
	// Чтение количества каждого типа знака и его номера (типа)
	for (int i = 0; i < n; i++) {
	    cin >> o[i].count;
	    o[i].num = i + 1;
  	}
	
	// Сортировка массива знаков по убыванию количества каждого знака
	sort(o, o + n, cmp);
	
	// Распределение знаков по строкам и столбцам
	int m = o[0].count;
	int t = 0;
	for (int i = 0; i < n && t < n; i++) {
		for (int j = 0; j < m; j++) {
	    	if (o[t].count > 0) {
	    		ans[i][j] = o[t].num;
	        	o[t].count--;
	        }
		    if (o[t].count == 0)
				t++;
		}
	}
	
	// Вывод порядка знаков на экран
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
	    	if (ans[j][i] == 0)
				break;
	        else 
	        	cout << ans[j][i] << " ";
	    }
	}
}

// Основная функция
int main() {
	int n; // Количество различных типов знаков
	cin >> n;
	solve(n); // Вызов функции решения
	return 0;
}
