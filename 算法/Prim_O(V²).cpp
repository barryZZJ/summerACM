/*
prim 最小生成树算法
过程：prim算法将图分为两部分，假设原顶点集为V，将其分为S和V-S两部分，S为已经确定在最小生成树上的顶点，
开始时,将任意一个顶点加入到S，然后每次在V-S中寻找距离S中的点最近的点。作为下一个加入最小生成树上的点。
所有N个节点都加入到最小生成树中时，最小生成树构造完毕。
  
实现：对于邻接矩阵构造的图，可以用low[N]保存每个顶点到已加入生成树中所有点的最小距离。
每次寻找这个距离最小的一个点加入最小生成树中。再根据这个点的距离更新其它未加入生成树中的点。
直到所有的点都加入到最小生成树中。
*/
  
// Eg:HDU 1102
  
#include <stdio.h>
#include <string.h>
#include <iostream>
#define inf 1000000
using namespace std;
  
int g[210][210];
int low[210]; // 记录已加入最小生成树集合中的点到没见过的点j的最小距离，每加入一个点到集合中就更新一次low中的值
int vis[210]; // 表示该点是否已经加入最小生成树中
int n;
  
int prim() {
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            g[i][j] = inf;
        }
    }
  
    for (int i=0; i<n; ++i) {
        low[i] = g[0][i];
    }
  
    int ans = 0;
    memset(vis, 0, sizeof(vis));
    vis[0] = 1;
    
    int r = n-1;
    while (r--) { // 每次加一个点，循环n-1次加完n-1个点。
        int minp = -1; // V-S中最近的点
        int mind = inf; // 记录最近的距离
        for (int j=0; j<n; ++j) { // 循环找当前剩下的点中 距离最小生成树点集距离最短的点。
            if (!vis[j] && low[j] < mind) {
                mind = low[j];
                minp = j;
            }
        }
  
         if (minp == -1) return -1;
         vis[minp] = 1; // 加入最小生成树点集
         ans += mind;
  
         for (int j=0; j<n; ++j) { // 更新没加入最小生成树的点中 距离是否会缩短。
            /*if (!vis[j] && low[j] > low[k] + g[k][j]) {
                    low[j] = low[k] + g[k][j];
            }*/
  
             if (!vis[j] && low[j] > g[minp][j]) { // 上面的if是错的。low数组存储的距离是当前点到生成树中所有点距离最小的的点。
                    low[j] = g[minp][j]; // 因为这个点加入最小生成树集合中，可以和其中任意一个点连一条边。
            }
        }
    }
    return ans;
}
  
  
int main() {
    int q;
    while(cin >> n) {
        for (int i=0; i<n; ++i) {
            for (int j=0; j<n; ++j) {
                cin >> g[i][j];
            }
        }
  
        cin >> q;
        for (int i=0; i<q; ++i) {
            int a, b;
            cin >> a >> b;
            a--, b--;
            g[a][b] = 0;
            g[b][a] = 0;
        }
  
        int ans = prim();
        cout << ans << endl;
    }
    return 0;
}
