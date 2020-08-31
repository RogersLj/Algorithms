//给定一个长度为N的整数数列，输出每个数左边第一个比它小的数，如果不存在则输出-1。
#include <iostream>

using namespace std;

const int N = 100010;

int stk[N], tt;

int main() {
    int n, x;
    cin >> n;
    for (int i = 0; i < n; i ++) {
        cin >> x;
        while (tt && stk[tt] >= x) tt --;
        if (!tt) cout << -1 << ' ';
        else cout << stk[tt] << ' ';
        stk[++ tt] = x;
    }
    return 0;
}
