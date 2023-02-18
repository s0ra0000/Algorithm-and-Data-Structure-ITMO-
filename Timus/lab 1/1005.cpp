#include<bits/stdc++.h>
#include <limits>
#include <iostream>
using namespace std;
main(){
	int n,a[21],min_dif = numeric_limits<int>::max(),max;
	cin >> n;
	max = 1 << n-1;
	for(int i=0; i<n;i++)
		cin >> a[i];
	for(int i=0; i<=max;i++){
		int tmp = i;
		int pile0 = 0,pile1 = 0;
		for(int j=0; j<n; j++){
			if((tmp & 0x1) == 0)
				pile0+=a[j];
			else
				pile1+=a[j];
			tmp = tmp >> 1;
		}
		if(min_dif > abs(pile0-pile1))
			min_dif = abs(pile0-pile1);
	}
	cout << min_dif;
	return 0;
}
