#include <bits/stdc++.h>
using namespace std; 

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int t;
    cin >> t;
    // cout << t << endl;
    while(t--){
        int u,h,d;
        cin >> u >> h >> d;
        vector<int> v;
        for(int i = 0;i<u;i++){
            int a;
            cin >> a;
            v.push_back(a);
        }
        int i = 0;
        bool parachute = true;
        int hills = 1;
        while(i<v.size()-1){
            if(v[i] + h >= v[i+1] && v[i] <= v[i+1] ){
                hills++;
                // cout << 'a' << hills<< endl;
            }else if(v[i] > v[i+1]){
                if(v[i]-d <= v[i+1]){
                    hills++;
                    // cout << 'b' << hills<< endl;
                }else if(parachute){
                    parachute = false;
                    hills++;
                    // cout << 'c' << hills<< endl;
                }else if(parachute == false){
                    break;
                }
            }else{
                break;
            }
            i++;
        }
        cout << hills << endl;
    }
    return 0;
}