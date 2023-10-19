//1401. Игроки
#include<bits/stdc++.h>
#include <iostream>
using namespace std;

// Глобальные переменные:
int m = 3;                 // Используется для нумерации L-образных фигур.
int A[512][512];           // Матрица для представления доски.

// Функция для замощения квадратной доски L-образными фигурами.
void paveSquare(int n, int x, int y, int hx, int hy);

int main()
{
    int n, px, py; 
    cin >> n;             // Ввод размера доски
    cin >> px >> py;      // Ввод координат пропущенной клетки

    int s = pow(2,n);     // Вычисление реального размера доски
    paveSquare(s, 0, 0, px-1, py-1);  // Вызов функции для замощения доски

    // Вывод результата
    for(int i = 0; i < s; i++){
        for(int j = 0; j < s; j++){
            cout << A[i][j]<< " ";
        }
        cout << endl;
    }
}

void paveSquare(int n, int x, int y, int hx, int hy)
{
    // Базовый случай: доска размером 2x2
    if(n == 2)
    {
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < 2; j++){
                if(x+i != hx || y+j != hy){
                    A[x+i][y+j] = m++/3;  // Замощаем клетку L-образной фигурой
                }
            }
        }
        return;
    }

    // Для каждой из 4 частей текущего квадрата
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            // Если текущий квадрат не содержит пропущенную клетку,
            // замощаем центр этого квадрата
            if(x + i*n/2 > hx || hx >= x + i*n/2+n/2 || y + j*n/2 > hy || hy >= y + j*n/2+n/2)
            {
                A[x+n/2-1+i][y+n/2-1+j] = m++/3;
            }
        }           
    }
    
    // Рекурсивный вызов для каждого из 4 частей текущего квадрата
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            if(x + i*n/2 <= hx && hx < x + i*n/2+n/2 && y + j*n/2 <= hy && hy < y + j*n/2+n/2)
                paveSquare(n/2, x + i*n/2, y + j*n/2, hx, hy); 
            else 
                paveSquare(n/2, x + i*n/2, y + j*n/2, x + n/2 - 1 + i, y + n/2 - 1 + j);
        }
    }
}
