#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct pipe_line {
    int a, b;
    int c;
};

int main() {
    int n, m,s, f;
    scanf("%d %d",&n,&m);
    struct pipe_line pipes[m];
    int res[n+1];
    memset(res, -1, (n+1) * sizeof(*res));
    for (int i = 0; i < m; i++) 
    	scanf("%d %d %d",&pipes[i].a,&pipes[i].b,&pipes[i].c);
    scanf("%d %d",&s,&f);

    res[s] = 0;
    for (int i = 1; i < n; i++)
        for (int j = 0; j < m; j++)
            if (res[pipes[j].a] != -1 && res[pipes[j].b] < res[pipes[j].a] + pipes[j].c)
                res[pipes[j].b] = res[pipes[j].a] + pipes[j].c;
    
    if (res[f] != -1) printf("%d",res[f]);
    else printf("No solution");
    return 0;
}
