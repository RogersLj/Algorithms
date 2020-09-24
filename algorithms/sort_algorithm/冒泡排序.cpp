// 迭代算法
#include<iostream>
#include<vector>

using namespace std;

void BubbleSort(vector<int>&);

int main() {
  vector<int> test = { 3, 7, 6, 4, 5, 1, 2, 8 };
  BubbleSort(test);

  for (auto x : test)
    cout << x << " ";

  return 0;
}

void BubbleSort(vector<int>& arr) {
  for (int i = 0; i < arr.size() - 1; i++)
    for (int j = 0; j < arr.size() - i - 1; j++)
      if (arr[j] > arr[j+1])
        swap(arr[j], arr[j+1]);
}


// 递归算法
#include<iostream>
#include<vector>

using namespace std;

void Recursive_BubbleSort(vector<int>&, int);

int main() {
  vector<int> test = { 3, 7, 6, 4, 5, 1, 2, 8 };
  Recursive_BubbleSort(test,test.size());

  for (auto x : test)
    cout << x << " ";

  return 0;
}

void Recursive_BubbleSort(vector<int>& arr, int n) {
  if (n == 1) return;

  for (int i = 0; i < arr.size() - 1; i++) {
    if (arr[i] > arr[i + 1])
      swap(arr[i], arr[i + 1]);
  }

  Recursive_BubbleSort(arr, n - 1);
}
