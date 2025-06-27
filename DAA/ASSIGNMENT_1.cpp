#include<bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void linear(vector<int>& arr,int x){
    bool found = false;
    for(int i=0;i<arr.size();i++){
        if(arr[i] == x){
            found = true;
            break;
        }
    }
    if(found) cout<<"Element is present"<<endl;
    else cout<<"Element is not present"<<endl;
}

void binary(vector<int>& arr,int x){
    bubbleSort(arr);
    int hi = 
    int lo = 0;
    bool found = false;
    while(hi >= lo){
        int mid = (hi + lo)>>1;
        if(arr[mid] == x){
            found = true;
            cout<<"Element is present at index: " << mid <<endl;
            break;
        }
        if(arr[mid] > x){
            hi = mid -1;
        }
        else lo = mid + 1;
    }
    if(!found) cout<<"Element is not present"<<endl;
}

int main(){
    int n;
    cout<<"Enter the size of the array : ";
    cin>>n;

    int arr[n];
    cout<<"Enter the elements of the array : ";
    for(int i=0;i<n;i++) cin>>arr[i];

    int x;
    cout<<"Enter the number to be found : ";
    cin>>x;

    cout<<"Enter 1 to use linear search, 2 to use binary search : ";
    int method = 1;
    cin>>method;
    if(method == 1) linear(arr,x);
    else if(method == 2) binary(arr,x);
    else cout<<"Invalid method chosen"<<endl;

    
    return 0;
}