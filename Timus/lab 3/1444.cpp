//1444. Накормить элефпотама
#include<bits/stdc++.h>
#include <iostream>
using namespace std;

// Структура для представления точки с координатами и индексом.
struct point {
    int x, y; // Координаты точки
    int i;   // Индекс точки
} p[30000]; // Массив точек размером 30000
point pk;

// Функция для сравнения двух точек на основе угла между ними и осью X.
// Возвращает true, если угол первой точки меньше угла второй точки.
int cmp(point& a, point& b) {
    if(a.x*b.y == a.y*b.x && a.x*b.x + a.y*b.y >= 0)
        return a.x*a.x + a.y*a.y < b.x*b.x + b.y*b.y;
    return atan2(a.y, a.x) < atan2(b.y, b.x);
}

// Основная функция для решения задачи
void solve(int n){
    // Считываем координаты n точек
    for(int i = 0; i < n; i++) {
        cin >> p[i].x >> p[i].y;
        p[i].i = i;
    }
    // Переносим начало координат в первую точку
    for(int i = n-1; i >= 0; i--)
        p[i].x -= p[0].x, p[i].y -= p[0].y;
    
    // Сортируем точки по углу относительно оси x
    sort(p, p+n, cmp);
    
    int s = 0;
    // Находим точку, для которой векторное произведение 
    // с последующей точкой меньше 0 (или равно 0, и скалярное произведение меньше 0).
    for(int i = 0; i < n-1; i++) {
        point p0 = p[0], p1 = p[i], p2 = p[i+1];
        int d1x = p1.x-p0.x, d2y = p2.y-p0.y, d1y = p1.y-p0.y, d2x = p2.x-p0.x;
        int x = d1x*d2y - d1y*d2x, d = d1x*d2x + d1y*d2y;
        if(x < 0 || x == 0 && d < 0) { 
            s = i;
            break;
        }
    }

    // Выводим результат
    cout << n << endl;
    cout << (p[0].i+1) << endl;
    for(int i = 0; i < n-1; i++)
        cout << (p[(s+i)%(n-1)+1].i+1) << endl;
}

int main() {
    int n;
    // Считываем размер массива точек
    cin >> n;
    // Решаем задачу
    solve(n);
    return 0;
}
