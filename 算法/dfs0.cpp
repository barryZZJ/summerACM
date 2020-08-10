#include <bits/stdc++.h>
#include <cstdlib>

using namespace std;

typedef long long ll;

const int INF = 999999999;
const int N = 1005;

// 1013 Battle Over Cities

struct edge{
    int t;
    edge(int _t) : t(_t){}
};

int p[N];
int n, m, k;
vector<edge> g[N];
bool seen[N];

void dfs(int x){
    seen[x] = true;
    for(edge e:g[x]){
        if (!seen[e.t]){
            dfs(e.t);
        }
    }
}


int main(){
    scanf("%d%d%d", &n, &m, &k);
    fill(p, p + n + 1, 0);
    for (int i = 0; i < m; i++){
        int a, b;
        scanf("%d%d", &a, &b);
        g[a].push_back(edge(b));
        g[b].push_back(edge(a));
    }

    for (int i = 0; i < k; i++){
        int a, res = 0;
        scanf("%d", &a);
        fill(seen, seen + n + 1, false);
        seen[a] = true;
        for (int j = 1; j <= n; j++){
            if(!seen[j]){
                dfs(j);
                res++;
            }
        }
        printf("%d\n", --res);
    }
}