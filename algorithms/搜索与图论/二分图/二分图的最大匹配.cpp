#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 510, M = 100010;

int n1, n2, m;
int h[N], e[M], ne[M], idx;
int match[N];
bool st[N]; //每次考虑所有n2

void add(int a, int b) 
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

bool find(int x)
{
    for (int i = h[x]; ~i; i = ne[i]) {
        int j = e[i];
        if (!st[j]) {
            st[j] = true;
            //还没有匹配或者能为左边找到另外匹配
            if (!match[j] || find(match[j])) {
                match[j] = x;
                return true;
            }
        }
    }
    
    return false;
}

int main()
{
    cin >> n1 >> n2>> m;
    
    memset(h, -1, sizeof h);
    
    while (m --) {
        int a, b;
        cin >> a >> b;
        add(a, b); //只需要考虑左边到右边匹配
    }
    
    int res = 0;
    for (int i = 1; i <= n1; i ++) {
        memset(st, 0, sizeof st);
        if (find(i)) res ++;
    }
    
    cout << res << endl;
    return 0;
}
