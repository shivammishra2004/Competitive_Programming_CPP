#include <bits/stdc++.h>
using namespace std; 

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    string s;
    cin >> s;
    int i = 3;
    string s1 = "";
    for(int i = 0;i<s.size();i++){
        if(i+2 < s.size() && s.substr(i,3) == "WUB"){
            if(!s1.empty() && s1.back() != ' '){
                s1 += ' ';
            }
            i+=3;
        }else{
            s1 += s[i];
            i++;
        }
    }
    while(!s1.empty() && s1.back() == ' '){
        s1.pop_back();
    }
    cout << s1 << endl;
    return 0;
}