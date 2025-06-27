#include <bits/stdc++.h>
using namespace std; 

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    int t;
    cin >> t;
    while(t--){
        int x,y;
        cin >> x >> y;
        int screen = 0;
        int increment = 0;
        if(y>2){
            screen = ceil((double)y / 2);
            increment = y%2;
            int fuck = 15-4*increment;
            if (increment == 0) fuck = 0;
            if(x>(fuck+7*(y/2))){
                screen += ceil(double(x-(fuck+7*(y/2)))/15);
            }
        }else if(y ==2){
            screen = 1;
            screen += ceil(double(x-7)/15);
        }else if(y ==1){
            screen = 1;
            screen += ceil(double(x-11)/15);
        }else if(y == 0){
            screen = ceil(double(x)/15);
        }
        cout << screen << endl;
    }
    
    return 0;
}