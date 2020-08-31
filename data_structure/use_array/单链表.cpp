#include <iostream>

using namespace std;

const int N = 100010;

// head 表示头结点的下标
// e[i] 表示节点i的值
// ne[i] 表示节点i的next指针是多少
// idx 存储当前已经用到了哪个点

int head, idx;
int e[N], ne[N];

// 初始化
void init() {
    head = -1;
    idx = 0;
}

// 将x插到头结点
void add_to_head(int x) {
    e[idx] = x, ne[idx] = head, head = idx ++;
}

// 将x插到下标是k的点后面
void add(int k, int x) {
    e[idx] = x, ne[idx] = ne[k], ne[k] = idx ++;
}

// 将下标是k的点后面的点删掉
void remove(int k) {
    ne[k] = ne[ne[k]];
}

int main() {
    int m;
    cin >> m;
    
    init();
    
    while (m --) {
        string op;
        int k, x;
        cin >> op;
        if (op == "H") {
            cin >> x;
            add_to_head(x);
        }
        else if (op == "I") {
            cin >> k >> x;
            add(k - 1, x);
        }
        else {
            cin >> k;
            if (!k) head = ne[head]; //当k为0时，表示删除头结点
            remove(k - 1);
        }
    }
    
    for (int i = head; ~i; i = ne[i]) cout << e[i] << ' ';
    return 0;
}
