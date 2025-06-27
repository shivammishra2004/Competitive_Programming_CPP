#include <bits/stdc++.h>
using namespace std;

void selectionSort(vector<int>& arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_index]) 
                min_index = j;
        }
        swap(arr[i], arr[min_index]);
    }
}

void print(const vector<int>& arr) {
    for (int i : arr) 
        cout << i << " ";
    cout << endl;
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) 
        cin >> arr[i];

    selectionSort(arr, n);

    cout << "Sorted Array: ";
    print(arr);

    return 0;
}
