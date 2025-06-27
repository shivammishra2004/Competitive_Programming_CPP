#include <bits/stdc++.h>
using namespace std; 

void swapp(vector<char> &v,int counto,int counti){
    int i = 0;
    while(counto && counti){
        if(v[i] == '0'){
            v[i] = '1';
            counti--;
        }else{
            v[i] = '0';
            counto--;
        }
        i++;
    }
    while(counto--){
        v[i] = '0';
        i++;
    }
    while(counti--){
        v[i] = '1';
        i++;
    }
    return;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        vector<char> v{s.begin(),s.end()};
        // for(auto i:v){
        //     cout << i;
        // }
        // cout << endl;
        int counto= 0,counti=0;
        for(auto i:v){
            if (i == '0') counto++;
            else counti++;
        }
        // cout << counto << " " << counti;
        // cout << endl;
        swapp(v,counto,counti);
        // for(auto i:v){
        //     cout << i;
        // }
        // cout << endl;
        int i = 0;
        while(i<v.size()){
            if(s[i] != v[i]){
                i++;
            }else break;
        }
        cout << v.size()-i << endl;

    }
    return 0;
}