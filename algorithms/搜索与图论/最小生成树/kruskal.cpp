#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010, M = 200010, INF = 0x3f3f3f3f;

int n, m;
int p[N];

struct Edge
{
    int a, b, c;
    
    bool operator< (const Edge& e) const {
        return c < e.c;
    } 
}edges[M];

int find(int x) 
{
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int kruskal()
{
    sort(edges, edges + m);
    
    for (int i = 1; i <= n; i ++) p[i] = i;
    
    int res = 0, cnt = 0;
    for (int i = 0; i < m; i ++) {
        int a = edges[i].a, b = edges[i].b, c = edges[i].c;
        
        a = find(a), b = find(b);
        if (a != b) {
            p[a] = b;
            res += c;
            cnt ++;
        }
    }
    
    if (cnt  < n - 1) return INF;
    return res;
}

int main()
{
    cin >> n >> m;
    
    for (int i = 0; i < m; i ++) {
        int a, b, c;
        cin >> a >> b >> c;
        edges[i] = {a, b, c};
    }
    
    int t = kruskal();
    if (t == INF) cout << "impossible" << endl;
    else cout << t << endl;
    
    return 0;
} 
