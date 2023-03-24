#include <algorithm>
#include <iostream>
using namespace std;
struct obstacle{
  int count;
  int num;
};
const int MAXNUM = 10010;
obstacle o[MAXNUM];
int ans[MAXNUM][MAXNUM];

bool cmp(obstacle a, obstacle b);
void solve(int n);

int main()
{
	int n;
	cin >> n;
	solve(n);
	return 0;
}
void solve(int n){
	for (int i = 0; i < n; i++) {
	    cin >> o[i].count;
	    o[i].num = i + 1;
  	}
	sort(o, o + n, cmp);
	int m = o[0].count;
	int t = 0;
	for (int i = 0; i < n&&t<n; i++){
		for (int j = 0; j < m;j++) {
	    	if (o[t].count > 0) {
	    		ans[i][j] = o[t].num;
	        	o[t].count--;
	        }
		    if (o[t].count == 0)
				t++;
		}
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
	    	if (ans[j][i] == 0)
				break;
	        else 
	        	cout << ans[j][i] << " ";
	    }
	}
}

bool cmp(obstacle a, obstacle b) {
	return (a.count > b.count);
}
