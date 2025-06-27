#include <bits/stdc++.h>
using namespace std;

int ternarySearch(int l, int r, int key, vector<int>& arr) {
    while (r >= l) {
        int mid1 = l + (r - l) / 3;
        int mid2 = r - (r - l) / 3;

        if (arr[mid1] == key) return mid1;
        if (arr[mid2] == key) return mid2;

        if (key < arr[mid1])
            r = mid1 - 1;
        else if (key > arr[mid2])
            l = mid2 + 1;
        else {
            l = mid1 + 1;
            r = mid2 - 1;
        }
    }
    return -1;
}

int main() {
    cout << "Enter the size of the array: ";
    int r;
    cin >> r;
    int l = 0;

    cout << "Enter the elements of the array: ";
    vector<int> arr(r);
    for (int i = 0; i < r; i++) cin >> arr[i];

    int key;
    cout << "Enter the element to be found: ";
    cin >> key;

    int ans = ternarySearch(l, r, key, arr);
    cout << "Index of " << key << " is " << ans << endl;

    return 0;
}
