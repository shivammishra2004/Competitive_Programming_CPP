#include <bits/stdc++.h>
using namespace std; 

int counter(vector<char> v){
    int count= 0, realcount = 0;
    for(int i =0;i<v.size();i++){
        if(v[i] == '.'){
            count++;
            realcount++;
            if(count >=3){
                return 2;
            }
        }else if(v[i] == '#'){
            count = 0;
        }
    }
    return realcount;

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
            char s;
            cin >> s;
            v.push_back(s);
        }
        cout << counter(v) << endl;
    }
    
    return 0;
}