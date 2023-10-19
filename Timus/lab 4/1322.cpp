//1322. Шпион
#include<bits/stdc++.h>
#include <iostream>
using namespace std;

// Функция дешифровки строки
void solve(int N, int M, int k, string s);

int main() { 
    string s;
    int k;
    
    // Ввод номера строки и зашифрованной строки
    cin >> k;
    cin >> s;
    
    // Запуск функции дешифровки
    solve(s.size(), 1000000, k - 1, s);

    return 0;
}

void solve(int N, int M, int k, string s) {
    // Массив для подсчета количества вхождений каждого символа
    int *count = new int[M];
    fill(count, count + M, 0); // инициализация нулями
    
    // Подсчет вхождений каждого символа
    for (int i = 0; i < N; i++) {
        count[s[i]]++;
    }

    // Преобразование массива count в префиксную сумму
    int sum = 0;
    for (int i = 0; i < M; i++) {
        sum += count[i];
        count[i] = sum - count[i];
    }

    // Массив для восстановления исходной строки
    int *t = new int[N];
    for (int i = 0; i < N; i++) {
        t[count[s[i]]] = i;
        count[s[i]]++;
    }

    // Восстановление исходной строки на основе массива t
    int j = t[k];
    char *result = new char[N];
    for (int i = 0; i < N; i++) {
        result[i] = s[j];
        j = t[j];
    }

    // Вывод исходной строки
    for (int i = 0; i < N; i++) {
        cout << result[i];
    }
}
