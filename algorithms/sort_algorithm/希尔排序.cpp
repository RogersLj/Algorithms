#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

void shell_sort(vector<int>&);

int main() {
    vector<int> test = { 40, 8, 2, 15, 37, 42, 11, 29, 24, 7 };
    shell_sort(test);
    for (auto x : test)
        cout << x << " ";
    return 0;
}

void shell_sort(vector<int>& arr) {

    for (int gap = arr.size() / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < arr.size(); i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }

            arr[j] = temp;
        }
    }
}
