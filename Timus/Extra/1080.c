#include <stdio.h>
#include <stdbool.h>
#define MAX_N 99

bool edges[MAX_N][MAX_N];
bool colors[MAX_N], colored[MAX_N];
bool predColor = true;
bool paint(int n, int i, bool predColor) {
    if (colored[i]) return colors[i] != predColor;

    colored[i] = true;
    bool color = colors[i] = !predColor;

    for (int node = 1; node <= n; ++node) {
        if (!edges[i][node]) continue;
        if (!paint(n, node, color)) return false;
    }
    return true;
}
int main() {
    int n;
    scanf("%d",&n);

    int node;
    for (int i = 1; i <= n; ++i) {
        scanf("%d",&node);
        if (node == 0) continue;
        
        while (node > 0) {
            edges[node][i] = true;
            edges[i][node] = true;
            scanf("%d",&node);
        }
    }
    if (!paint(n,1,true)) {
        printf("-1");
        return 0;
    }
    for (int i = 1; i <= n; ++i) {
       printf("%d",colors[i]);
    }
    return 0;
}
