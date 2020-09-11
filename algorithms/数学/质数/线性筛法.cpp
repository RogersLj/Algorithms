#include <iostream>

using namespace std;

const int N = 1000010;

int cnt;
int primes[N];
bool st[N];

void get_primes(int n)
{
    for (int i = 2; i <= n; i ++) {
        if (!st[i]) primes[cnt ++] = i;
        for (int j = 0; primes[j] * i <= n; j ++) {
            st[primes[j] * i] = true;
            if (i % primes[j] == 0) break;
        }
    }
}


/*
1. 每个数只会被它的最小质因子筛掉
if (i % primes[j] == 0) break; 从小到大枚举primes， primes[j]一定是i的最小质因子
此时primes[j]也一定是primes[j] * i的最小质因子
该情况下primes[j] * i是被其最小质因子primes[j]筛掉

if (i % primes[j] != 0) //从小到大枚举primes， primes[j]一定是primes[j] * i的最小质因子
该情况下primes[j] * i是被其最小质因子primes[j]筛掉

2.每个合数都会被筛掉
一个合数x = primes[j] * i
当枚举到i时 x就会被筛掉
*/

int main()
{
    int n;
    cin >> n;
    
    get_primes(n);
    
    cout << cnt << endl;
    
    return 0;
}
