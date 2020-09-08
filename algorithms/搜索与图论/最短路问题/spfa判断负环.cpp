#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 100010;

int n, m;
int h[N], e[N], w[N], ne[N], idx;
int dist[N];
int cnt[N];
bool st[N];

void add(int a, int b, int c) 
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++;
}

bool spfa()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    queue<int> q;
    //起点1不一定在负权回路中
    for (int i = 1; i <= n; i ++) {
        q.push(i);
        st[i] = true;
    }
    
    while (q.size()) {
        auto t = q.front();
        q.pop();
        st[t] = false;
        
        for (int i = h[t]; ~i; i = ne[i]) {
            int j = e[i];
            if (dist[j] > dist[t] + w[i]) {
                dist[j] = dist[t] + w[i];
                cnt[j] = cnt[t] + 1;
                
                if (cnt[j] >= n) return true;
                if (!st[j]) {
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }
    return false;
}

int main()
{
    memset(h, -1, sizeof h);
    cin >> n >> m;
    
    while (m --) {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
    }
    
    if (spfa()) cout << "Yes" << endl;
    else cout << "No" << endl;
    
    return 0;
} 
