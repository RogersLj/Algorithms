#include <iostream>
#include<vector>
using namespace std;

void heapSort(vector<int>&, int);
int main()
{
    vector<int> arr = { 40, 2, 8, 29, 37, 24, 11, 15, 7, 36 };
    heapSort(arr, arr.size());
    for (auto x : arr) 
        cout << x << " ";
}


void heapify(vector<int>& arr, int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(vector<int>& arr, int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);   //堆的数量减一
    }
}
