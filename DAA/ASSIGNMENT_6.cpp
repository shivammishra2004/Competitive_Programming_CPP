#include<bits/stdc++.h>
using namespace std;

void countingSort(vector<int>& arr, int n) {
    int maxVal = *max_element(arr.begin(), arr.end());
    vector<int> count(maxVal + 1, 0), output(n);
    for (int i = 0; i < n; i++) count[arr[i]]++;
    for (int i = 1; i <= maxVal; i++) count[i] += count[i - 1];
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }
    for (int i = 0; i < n; i++) arr[i] = output[i];
}

void print(vector<int>& arr) {
    for (auto i : arr) cout << i << " ";
    cout << endl;
}

int main() {
    cout << "Enter the size of the array : ";
    int n;
    cin >> n;
    cout << "Enter the elements of the array : ";
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    countingSort(arr, n);
    cout << "Sorted array: ";
    print(arr);
    return 0;
}
