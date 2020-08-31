#include <iostream>

using namespace std;

const int N = 100010;

int n, m;
int p[N];

int find(int x) {
    if (p[x] != x) p[x] = find(p[x]); //路径压缩
    return p[x];
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i ++) p[i] = i;
    
    while (m --) {
        string op;
        cin >> op;
        int a, b;
        cin >> a >> b;
        if (op == "M") {
            int pa = find(a), pb = find(b);
            p[pa] = pb;
        }
        else {
            int pa = find(a), pb = find(b);
            if (pa == pb) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
    return 0;
}
