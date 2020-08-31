#include <iostream>

using namespace std;

const int N = 100010;

int ne[N];

int main() {
    string a, b;
    int n, m;
    cin >> n >> a >> m >> b;
    
    a = ' ' + a;
    b = ' ' + b;
    
    for (int i = 2, j = 0; i <= n; i ++) {
        while (j && a[i] != a[j + 1]) j = ne[j];
        if (a[i] == a[j + 1]) j ++;
        ne[i] = j;
    }
    
    for (int i = 1, j = 0; i <= m; i ++) {
        while (j && a[j + 1] != b[i]) j = ne[j];
        if (a[j + 1] == b[i]) j ++;
        if (j == n) {
            cout << i - n << ' ';
            j = ne[j];
        }
    }
    return 0;
}
