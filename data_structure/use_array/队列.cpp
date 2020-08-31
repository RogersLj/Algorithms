#include <iostream>

using namespace std;

const int N = 100010;

/*
(1) “push x” – 向队尾插入一个数x；

(2) “pop” – 从队头弹出一个数；

(3) “empty” – 判断队列是否为空；

(4) “query” – 查询队头元素。
*/

int m;
int q[N], head, tail;

int main() {
    head = 0, tail = -1;
    cin >> m;
    while (m --) {
        string op;
        int x;
        cin >> op;
        
        if (op == "push") {
            cin >> x;
            q[++ tail] = x;
        }
        else if (op == "pop") head ++;
        else if (op == "empty") cout << (head <= tail ? "NO" : "YES") << endl;
        else cout << q[head] << endl;
    }
    return 0;
}

