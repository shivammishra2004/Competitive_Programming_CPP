#include <bits/stdc++.h>
using namespace std; 

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    char c;
    cin >> c;
    vector<char> v;
    char a;
    vector<char> some = {'q','w','e','r','t','y','u','i','o','p','a','s','d','f','g','h','j','k','l',';','z','x','c','v','b','n','m',',','.','/'};
    while(cin >> a) v.push_back(a);
    if (c == 'L'){
        for(int i = 0;i<v.size();i++){
            for(int j = 0;j<some.size();j++){
                if(v[i] == some[j]){
                    if(j% 10 != 9) cout << some[j+1];
                    else cout << some[j];
                }
            }
        }
    }else{
        for(int i = 0;i<v.size();i++){
            for(int j = 0;j<some.size();j++){
                if(v[i] == some[j]){
                    if(j%10 !=0) cout << some[j-1];
                    else cout << some[j];
                }
            }
        }
    }
    return 0;
}