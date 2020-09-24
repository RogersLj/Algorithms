#include<iostream>
#include<vector>

using namespace std;

void radixsort(vector<int>&);
int maxbit(vector<int>);

int main() {
    vector<int> test = { 77, 15, 31, 50, 8, 100, 24, 3, 43, 65 };
    radixsort(test);
    for (auto x : test)
        cout << x << " ";
    return 0;
}

int maxbit(vector<int> arr) //求数据的最大位数
{
    int max = arr[0];
    for (auto x : arr)
        if (x > max)
            max = x;

    int bit = 1;

    while (max >= 10)
    {
        max /= 10;
        ++bit;
    }
    return bit;
}

void radixsort(vector<int>& arr) //基数排序
{
    int bit = maxbit(arr);
    vector<int> tmp(arr.size());
    vector<int> count(10); //0-9计数器
    int i, j, k;
    int radix = 1;
    for (i = 1; i <= bit; i++) //进行bit次排序
    {
        for (j = 0; j < 10; j++)
            count[j] = 0; //每次分配前清空计数器
        for (j = 0; j < arr.size(); j++)
        {
            k = (arr[j] / radix) % 10; 
            count[k]++;
        }
        for (j = 1; j < 10; j++)
            count[j] = count[j - 1] + count[j]; 

        for (j = arr.size() - 1; j >= 0; j--) 
        {
            k = (arr[j] / radix) % 10;
            tmp[count[k] - 1] = arr[j];
            count[k]--;
        }

        for (j = 0; j < arr.size(); j++) 
            arr[j] = tmp[j];
        radix = radix * 10;
    }
}
