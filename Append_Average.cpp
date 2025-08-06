#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void printSet(multiset<int> s)
{
    while (!s.empty())
    {
        cout << *s.begin() << " ";
        s.erase(s.begin());
    }
    cout << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        ll sum = 0;
        int x =  INT_MAX,y=INT_MAX;
        for (int i = 0; i < n; i++)
        {
            int temp;
            cin >> temp;
            sum += temp;
            if(x>=temp){
                y= x;
                x = temp;
            }else if(y >= temp){
                y = temp;
            }
        }
        int cnt = 0;

        while (cnt < k && y > x + 1)
        {
            y = (x + y + 1) / 2;
            cnt++;
            sum += y;
        }
        sum += (k - cnt)*1LL * ((x + y + 1) / 2);
        cout << sum << endl;
    }
}
