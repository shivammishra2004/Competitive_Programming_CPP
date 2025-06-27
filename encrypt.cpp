#include <bits/stdc++.h>
using namespace std; 

int binarySearch(const std::vector<char>& arr, char key) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == key) {
            return mid;
        } else if (arr[mid] < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1; // Key not found
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<char> v;
        while(n--){
            char a;
            cin >> a;
            v.push_back(a);
        }
        set<char> s(v.begin(), v.end());
        vector<char> vec;
        for(auto i: s){
            vec.push_back(i);
        }
        for(int i = 0;i<v.size();i++){
            int index = binarySearch(vec,v[i]);
            cout << vec[vec.size()-1-index];
        }
        cout << endl;
    }
    
    return 0;
}