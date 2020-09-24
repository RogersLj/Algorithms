#include<iostream>
#include<vector>
using namespace std;

void CountSort(vector<int>&);

int main() {
  vector<int> test = { 3, 3, 6, 2, 5, 1, 2, 8 };
  CountSort(test);
  for (auto x : test)
    cout << x << " ";
  return 0;
}

int FindMax(vector<int> arr) {
  int max = arr[0];
  for (auto x : arr)
    if (x > max)
      max = x;
  return max;
}

int FindMin(vector<int> arr) {
  int min = arr[0];
  for (auto x : arr)
    if (x < min)
      min = x;
  return min;
}

void CountSort(vector<int>& arr) {
  int max = FindMax(arr);
  int min = FindMin(arr);
  vector<int> count(max - min + 1,0);   //需要分配数组大小,节省了数组空间

  for (int i = 0; i < arr.size(); i++) {  //开始计数
    count[arr[i]-min]++;   //
  }

  int index = 0;
  for (int k = 0; k <count.size(); k++) {
    for (int cnt = 0; cnt < count[k]; cnt++)
      arr[index++] = k+min;
  }
}
