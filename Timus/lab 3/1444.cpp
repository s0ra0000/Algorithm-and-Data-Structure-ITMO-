#include<bits/stdc++.h>
#include <iostream>
using namespace std;

struct point {
    int x, y;
    int i;
} p[30000];
point pk;
int f(point& a, point& b);
void solve(int n);

int main() {
    int n;
    cin >> n;
    solve(n);
    return 0;
}

void solve(int n){
	for(int i = 0; i < n; i++) {
        int x, y;
        cin >> p[i].x >> p[i].y;
        p[i].i = i;
    }
    for(int i = n-1; i >= 0; i--)
        p[i].x -= p[0].x, p[i].y -= p[0].y;
    sort(p, p+n, f);
    int s = 0;
    for(int i = 0; i < n-1; i++) {
        point p0 = p[0], p1 = p[i], p2 = p[i+1];
        int d1x = p1.x-p0.x, d2y = p2.y-p0.y, d1y = p1.y-p0.y, d2x = p2.x-p0.x;
        int x = d1x*d2y - d1y*d2x, d = d1x*d2x + d1y*d2y;
        if(x < 0 || x == 0 && d < 0) { 
            s = i;
            break;
        }
    }

    cout << n << endl;
    cout << (p[0].i+1) << endl;
    for(int i = 0; i < n-1; i++)
        cout << (p[(s+i)%(n-1)+1].i+1) << endl;
}
int f(point& a, point& b) {
    if(a.x*b.y == a.y*b.x && a.x*b.x + a.y*b.y >= 0)
        return a.x*a.x + a.y*a.y < b.x*b.x + b.y*b.y;
    return atan2(a.y, a.x) < atan2(b.y, b.x);
}
