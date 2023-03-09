#include<bits/stdc++.h>
#include <limits>
#include <iostream>
using namespace std;
int solve(int n, int k);
int match(int x, int n);
int match(int x, int y, int n, int k, int total);
main(){
	int n,a[100];
	cin >> n;
	for(int i=0; i<n*2;i++){
		cin >> a[i];
	}
	for(int i=0; i<n*2;i+=2){
		cout << solve(a[i],a[i+1])<< endl;
	}
	return 0;
}
int solve(int n, int k){
	int res,x,y;
	x = n / k; 
	y = n % k;
	if(y!=0) return match(x,x+1,k-y,y,n);
	else return match(x,k);
}
int match(int x, int y, int n, int k, int total){
	int sum_1 = 0;
	int tmp = total;
	while(tmp > 0){
		for(int i=1; i<=n;i++){
			sum_1 += (total-x)*x;
			tmp-=x;
		}
	
		for(int i=1; i<=k;i++){
			sum_1 += (total-y)*y;
			tmp-=y;
		}
	}
	return sum_1/2;
}
int match(int x, int n){
	int sum = 0;
	for(int i=n-1; i>0;i--){
		sum += pow(x,2)*i;
	}
	return sum;
}
