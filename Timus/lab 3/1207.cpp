//1207. Медиана на плоскости
#include<bits/stdc++.h>
#include <iostream>
using namespace std;

// Определение структуры для хранения координат точек и их идентификаторов.
struct Node{
	long long x,y,id;
}arr[10005];

// Функция для сравнения двух точек на основе их угла относительно arr[0].
bool cmp(Node a,Node b){
	Node vec1,vec2;

	// Расчет вектора от arr[0] до a
	vec1.x = a.x-arr[0].x; vec1.y = a.y-arr[0].y;

	// Расчет вектора от arr[0] до b
	vec2.x = b.x-arr[0].x; vec2.y = b.y-arr[0].y;

	// Возвращаем true, если векторное произведение vec1 и vec2 положительно.
	// Это говорит о том, что точка a находится левее точки b относительно arr[0].
	return vec1.x*vec2.y - vec2.x*vec1.y > 0;
}

void solve(int n){
	// Чтение первой точки и установка ее идентификатора
	cin >> arr[0].x >> arr[0].y;
	arr[0].id = 0;

	// Чтение остальных точек
	for(int i = 1; i < n; i ++)
	{
		cin >> arr[i].x >> arr[i].y;
		arr[i].id = i;
		// Если текущая точка левее или ниже arr[0], делаем ее arr[0].
		if(arr[i].x < arr[0].x) 
			swap(arr[0],arr[i]);
		else if(arr[i].x==arr[0].x && arr[i].y<arr[0].y)
			swap(arr[0],arr[i]);
	}

	// Сортировка точек начиная со второй на основе угла относительно arr[0].
	sort(arr+1,arr+n,cmp);

	// Выводим идентификаторы arr[0] и arr[n/2] как искомые точки.
	cout << arr[0].id+1 <<" "<<arr[n/2].id+1;
}

int main(){
	int n;
	// Чтение количества точек
	cin >> n;

	// Запуск функции решения с n точками
	solve(n);

	return 0;
}
