#include<bits/stdc++.h>
#include <algorithm>
#include <iostream>
using namespace std;
int height(int r, multimap<int,int> &data);
main(){
	int n,a[100000],root;
	multimap<int,int> data;
	cin >> n;
	for(int i=0; i<n;i++){
		cin >> a[i];
		data.insert(pair<int,int>(i,a[i]));
		if(a[i] == -1)
			root = i;
	}
	if(n==1){
		cout << 1;
		return 0;
	}
	cout << height(root, data);
	return 0;
}
int height(int r, multimap<int,int> &data){
	int h = 1;
	bool xd = false;
//	multimap<int,int>::iterator it;
//	for(it = data.find(r);it!=data.end();it++){
//		cout << it->first;
//		data.erase(r);
//		h = max(height(it->first,data),h);
//		xd=true;
//	}
//	
	
//	for(int i=0; i<*n;i++){
//		if(a[i] == r){
//			h = max(height(i,a,n),h);
//			xd = true;
//		}
//	}


	if(xd) return h+1;
	return h;
	
}
