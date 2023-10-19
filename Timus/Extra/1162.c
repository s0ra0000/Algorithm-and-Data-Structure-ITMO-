#include <stdio.h>
#include <stdbool.h>
struct Edge {
    struct Edge * pred;
    unsigned int end;
    float rate, commission;
};

struct Edge * edges_node[101];
float this_balance[101];

bool hasProfit(float balance, unsigned currency) {
    if (balance <= 0) return false;
    if (this_balance[currency] != 0) return balance > this_balance[currency];
    
    this_balance[currency] = balance;
    for (struct Edge * edge = edges_node[currency]; edge != NULL; edge = edge->pred) 
        if (hasProfit((balance - edge->commission) * edge->rate, edge->end))
            return true;

    this_balance[currency] = 0;
    return false;
}

int main() {    
    unsigned n, m, s;
    float v;
    scanf("%d %d %d %fl",&n,&m,&s,&v);
    unsigned a, b;
    float r_ab, c_ab, r_ba, c_ba;
    for (unsigned i = 0; i < m; ++i) {
        scanf("%d %d %fl %fl %fl %fl",&a,&b,&r_ab,&c_ab,&r_ba,&c_ba);
        edges_node[a] = new Edge {edges_node[a], b, r_ab, c_ab};
        edges_node[b] = new Edge {edges_node[b], a, r_ba, c_ba};
    }

    if (hasProfit(v, s)) printf("YES\n");
    else printf("NO\n");
    
    return 0;
}
