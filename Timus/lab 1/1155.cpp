#include<bits/stdc++.h>
using namespace std;

const int CORNERS = 8;

void print(int i, int j, bool s);
void operation(int i, int j, int *a, int lim, bool add_op);

int main() {
    int a[CORNERS];

    for(int i = 0; i < CORNERS; i++) {
        cin >> a[i];
    }
    
    if((a[0]+a[2]+a[5]+a[7]) != (a[1]+a[3]+a[4]+a[6])) {
        cout << "IMPOSSIBLE";
        return 0;
    }

    for (int k = 0; k < 2; k++) {
        for (int i = 0; i < CORNERS; i++) {
            int opposite = (i + 4) % CORNERS;
            
            if (k == 0 && a[i] != 0) {
                // remove operation
                operation(i, (i + 1) % CORNERS, a, a[i], false);
                operation(i, (i + 3) % CORNERS, a, a[i], false);
                operation(i, opposite, a, a[i], false);
            } else if (k == 1 && a[i] != 0) {
                // add operation
                operation(i, (i + 1) % CORNERS, a, a[i], true);
                operation(i, (i + 3) % CORNERS, a, a[i], true);
                operation(i, opposite, a, a[i], true);
            }
        }
    }

    return 0;
}

void print(int i, int j, bool s) {
    char corners[CORNERS] = {'A','B','C','D','E','F','G','H'};
    
    if(s)
        cout << corners[i] << corners[j] << '+' << endl;
    else
        cout << corners[i] << corners[j] << '-' << endl;
}

void operation(int i, int j, int *a, int lim, bool add_op) {
    while (lim--) {
        if (add_op) {
            a[i]++;
            a[j]++;
            print(i, j, true);
        } else {
            if(a[i] > 0 && a[j] > 0) {
                a[i]--;
                a[j]--;
                print(i, j, false);
            }
        }
    }
}
