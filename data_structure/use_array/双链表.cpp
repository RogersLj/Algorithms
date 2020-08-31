#include <iostream>

using namespace std;

const int N = 100010;

int m;
int e[N], l[N], r[N], idx;

void init() {
    r[0] = 1, l[1] = 0;// 0是左端点，1是右端点
    idx = 2;
}

// 在第k个节点的右边插入一个数x
void insert(int k, int x) {
    e[idx] = x;
    r[idx] = r[k], l[idx] = k;
    l[r[k]] = idx, r[k] = idx ++;
}

// 删除第k个节点
void remove(int k) {
    r[l[k]] = r[k];
    l[r[k]] = l[k];
}

int main() {
    cin >> m;
    
    init();
    
    while (m --) {
        string op;
        cin >> op;
        int k, x;
        if (op == "L") {
            cin >> x;
            insert(0, x);
        }
        else if (op == "R") {
            cin >> x;
            insert(l[1], x);
        }
        else if (op == "D") {
            cin >> k;
            remove(k + 1);
        }
        else if (op == "IR") {
            cin >> k >> x;
            insert(k + 1, x);
        }
        else {
            cin >> k >> x;
            insert(l[k + 1], x);
        }
    }
    
    for (int i = r[0]; i != 1; i = r[i]) cout << e[i] << ' ';
    return 0;
}
