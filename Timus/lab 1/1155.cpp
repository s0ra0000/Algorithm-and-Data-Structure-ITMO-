#include<bits/stdc++.h>
#include <iostream>
using namespace std;

int sum(int *a);
void print(int i,int j, bool s);
void remove(int i, int j, int *a);
void add(int i, int j, int *a, int lim);
void create_solve(int i, int *a);
void remove_solve(int i, int *a);
int largest(int *tmp_arr,int old_max_addr,int *size);

main(){
	int a[9];
	int *arr_addr[8];
	int max_addr = 0;
	int size = 8;
	for(int i = 0; i < 8; i++){
		cin >> a[i];
	}
	if(a[0]+a[2]+a[5]+a[7] != a[1]+a[3]+a[4]+a[6]){
		cout << "IMPOSSIBLE";
		return 0;
	}
	
	for(int i=0; i<8; i++){
		int tmp_arr[8];
		copy(a,a+8,tmp_arr);
		max_addr = largest(tmp_arr,max_addr,&size);
		remove_solve(max_addr,a);
	}
	max_addr = 0;
	for(int i=0; i<8; i++){
		int tmp_arr[8];
		copy(a,a+8,tmp_arr);
		max_addr = largest(tmp_arr,max_addr,&size);
		create_solve(max_addr,a);
	}
	return 0;
}
int largest(int *tmp_arr,int old_max_addr,int *size){
	int max_addr = 0;
	max_addr = distance(tmp_arr,max_element(tmp_arr,tmp_arr+*size));
	for(int i=max_addr; i<*size-1;i++){
			tmp_arr[i]=tmp_arr[i+1];
		}
	return max_addr;
}

int sum(int *a){
	int sum = 0;
	for(int i=0; i<8;i++){
		sum+=a[i];
	}
	return sum;
}
void print(int i,int j, bool s){
	char corners[8] = {'A','B','C','D','E','F','G','H'};
	
	if(s)
		cout << corners[i] << corners[j] << '+'<< endl;
	else
		cout << corners[i] << corners[j] << '-'<< endl;
}
void remove(int i,int j, int *a){
	bool dec = false;
	while(a[i] != 0 && a[j] != 0){
		a[i]-=1;
		a[j]-=1;
		print(i,j,false);
	}
}
void add(int i, int j,int *a,int lim){
	while(a[i] < lim){
		a[i]+=1;
		a[j]+=1;
		print(i,j,true);
	}
}
void remove_solve(int i,int *a){
	if(a[i] != 0){
		if(i == 0 || i == 4){
			remove(i,i+1,a);
			remove(i,i+3,a);
			remove(i,(i+4)%8,a);
		}
		if(i==1 || i == 2 || i==5 || i==6){
			remove(i,i-1,a);
			remove(i,i+1,a);
			remove(i,(i+4)%8,a);
		}
		if(i==3 || i== 7){
			remove(i,i-3,a);
			remove(i,i-1,a);
			remove(i,(i+4)%8,a);
		}
	}
}

void create_solve(int i, int *a){
	if(i<4 && a[i] != 0){
		if(a[i] != 0 &&  a[i+6] != 0 && i < 2){
			add(i+1,i+5,a,a[i]);
			remove(i,i+1,a);
			remove(i+5,i+6,a);
			
		}
		if(a[i] != 0 && a[i+2] !=0 && i == 2){
			add(i+1,i+5,a,a[i]);
			remove(i,i+1,a);
			remove(i+2,i+5,a);
			
		}
		if(a[i] != 0 && a[i+2] !=0 && i == 3){
			add(0,i+1,a,a[i]);
			remove(0,i,a);
			remove(i+1,i+2,a);
		}
	}
}











