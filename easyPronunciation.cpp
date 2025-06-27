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
        int x;
        string s;
        cin >> x >> s;
        string vowel = "aeiou";
        for(auto i : s){
            for(auto j: vowel){
                if (i == j) repeatedWords = 0;
            }
        }
    }
    
    return 0;
}