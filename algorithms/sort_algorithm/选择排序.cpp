#include<iostream>
#include<vector>

using namespace std;

void SelectionSort(vector<int>&);

int main() {
  vector<int> test = { 3, 7, 6, 4, 5, 1, 2, 8 };
  SelectionSort(test);

  for (auto x : test)
    cout << x << " ";

  return 0;
}

void SelectionSort(vector<int>& arr) {
  for (int i = 0; i < arr.size()-1; i++) {
    int min = i;
    for (int j = i + 1; j < arr.size(); j++)
      if (arr[j] < arr[min]) min = j;

    swap(arr[i], arr[min]);
  }
}
