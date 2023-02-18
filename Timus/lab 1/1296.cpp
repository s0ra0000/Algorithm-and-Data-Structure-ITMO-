#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int main(){
	int n,max = 0,sum = 0;
	long long int a[60001];
	cin >> n;
	for(int i=0; i<n;i++)
		cin >> a[i];
	if(a[0] > 0){
		max = a[0];
		sum = a[0];
	}
	for(int i=1; i<n; i++){
		sum = sum + a[i];
		if(sum < 0){
			sum = 0;
		}
		if(sum > max)	
		{max = sum;
			}
	}
	cout << max;
	return 0;
}
