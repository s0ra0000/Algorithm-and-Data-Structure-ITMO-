	#include <bits/stdc++.h>
	#include <iostream>
	#include <string>
	using namespace std;
	bool solve(string s);
	main(){
		string n;
		cin >> n;
		if(solve(n)){
			cout << "Success";
		}
		return 0;
	}
	
	bool solve(string s){
		vector<char> arr;
		vector<int> addr;
		if(s.length()==1) {
			cout << 1;
			return false;	
		}
		for(int i=0; i<s.length();i++){
			if(s[i]=='{' || s[i] == '(' || s[i] == '['){
				arr.push_back(s[i]);
				addr.push_back(i);
			}
			else if(s[i] != ']' && s[i] != ')' && s[i] != '}'){
				continue;
			}
			else{
				if(arr.empty()){
					cout << i+1;
					return false;
				}
				else{
					if(s[i]=='}' && '{' == arr.back()){
						arr.pop_back();
						addr.pop_back();
					}
					else if(s[i]==')' && '(' == arr.back()){
						arr.pop_back();
						addr.pop_back();
					}
					else if(s[i]==']' && '['== arr.back()){
						arr.pop_back();
						addr.pop_back();
					}
					else{
						cout<<i+1;
						return false;
				}
				}
				
			}
			
		}
		if(!arr.empty()){
			cout << addr.back()+1;
			return false;
		}
		return true;
	}

