#include <iostream>
#include <vector>
using namespace std;

int findFloorFirstOccurrence(const vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1;
    int result = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            result = mid;
            high = mid - 1; // Move left to find the first occurrence
        } else if (arr[mid] < target) {
            result = mid;   // Update result because arr[mid] is the current floor
            low = mid + 1;  // Move right to find a closer floor
        } else {
            high = mid - 1; // Move left
        }
    }

    return result;
}

int main() {
    vector<int> arr = {1, 4, 4, 6, 6, 8, 9};
    int target = 5;
    
    int index = findFloorFirstOccurrence(arr, target);
    
    if (index != -1) {
        cout << "First occurrence of floor of " << target << " is " << arr[index] << " at index " << index << endl;
    } else {
        cout << "No floor found for " << target << endl;
    }
    
    return 0;
}
