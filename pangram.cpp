#include <bits/stdc++.h>
using namespace std; 

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<char> v;
    v.push_back(tolower(s[0]));
    bool isPresent = true;
    int count = 1;
    for(int i = 0;i<s.size();i++){
        isPresent = false;
        for(int j = 0;j<v.size();j++){
            if (v[j]==tolower(s[i])){
                isPresent = true;
            }
            if(isPresent) break;
        }
        if (!isPresent) v.push_back(tolower(s[i])), count++;
    }
    cout << ((v.size() == 26)? "YES" : "NO");
    
    return 0;
}