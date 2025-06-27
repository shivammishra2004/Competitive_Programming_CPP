#include <bits/stdc++.h>
using namespace std; 

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    int n;
    cin >> n;
    char a,b;
    cin >> a >> b;
    if(a == b){
        cout << "NO";
        return 0;
    }
    int count = 2;
    char c;
    while(cin>>c){
        count++;
        if(c != ' '){
            if(count %(n+1) == 1 || count%(n-1) == 1){
                if( c != a){
                    cout << "NO";
                    return 0;
                }
            }else{
                if(c != b){
                    cout << "NO";
                    return 0;
                }
            }
        }
    }
    cout << "YES";
    return 0;
}