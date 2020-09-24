#include<iostream>
#include<vector>

using namespace std;

void InsertionSort(vector<int>&, int);

int main() {
  vector<int> test = { 3, 7, 6, 4, 5, 1, 2, 8 };
  InsertionSort(test, test.size());

  for (auto x : test)
    cout << x << " ";

  return 0;
}

void InsertionSort(vector<int>& arr, int len) {
  for (int i = 1; i < len; ++i) {   //注意i从1开始
    int key = arr[i];    //需要插入的元素  
    int j = i - 1;   //已排序区间 
    while ((j >= 0) && (arr[j] > key)) {
      arr[j + 1] = arr[j];    //元素向后移动
      j--;
    }
    arr[j + 1] = key;
  }
}
