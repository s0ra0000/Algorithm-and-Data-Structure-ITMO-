#include<bits/stdc++.h>
#include <iostream>
using namespace std;
int x[100005], y[100005];
int solve(int n);
int main()
{
	int n;
	cin >> n;
	cout << solve(n);
}
int solve(int n){
	long long result = 0;
	for(int i=1; i<=n;i++){
		cin >> x[i] >> y[i];
	}
	sort(x+1,x+1+n);
	sort(y+1,y+1+n);
	for(int i=1; i<n;i++){
		long long tmp = (x[i+1]-x[i] + y[i+1]-y[i]);
		tmp *= i; tmp *= (n-i); tmp *= 2;
		result += tmp;
	}
	result /= n;
	result /= (n-1);
	return result;
}



