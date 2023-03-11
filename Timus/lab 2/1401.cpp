#include<bits/stdc++.h>
#include <iostream>
using namespace std;
void paveSquare(int n, int x, int y, int hx, int hy);
int m = 3, A[512][512];
int main()
{
    int n, px, py;
    cin >> n;
    cin >> px >> py;
    int s = pow(2,n);
    paveSquare(s, 0, 0, px-1, py-1);
    for(int i = 0; i < s; i++){
        for(int j = 0; j < s; j++){
        	cout << A[i][j]<< " ";
		}
    	cout << endl;
    }
}
void paveSquare(int n, int x, int y, int hx, int hy)
{
    if(n == 2)
    {
        for(int i = 0; i < 2; i++){
        	for(int j = 0; j < 2; j++){
        		if(x+i != hx  || y+j != hy){
        			 A[x+i][y+j] = m++/3;
				}
			}
		}
        return;
    }
    for(int i = 0; i < 2; i++){
    	for(int j = 0; j < 2; j++){
    		 if(x + i*n/2 > hx || hx >= x + i*n/2+n/2 || y + j*n/2 > hy || hy >= y + j*n/2+n/2)
               {
               	 A[x+n/2-1+i][y+n/2-1+j] = m++/3;
			   }
		}           
	}
        
    for(int i = 0; i < 2; i++){
    	  for(int j = 0; j < 2; j++){
    	  	if(x + i*n/2 <= hx && hx < x + i*n/2+n/2 && y + j*n/2 <= hy && hy < y + j*n/2+n/2)
                paveSquare(n/2, x + i*n/2, y + j*n/2, hx, hy); 
            else 
                paveSquare(n/2, x + i*n/2, y + j*n/2, x + n/2 - 1 + i, y + n/2 - 1 + j);
		  }
	}
}

