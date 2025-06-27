#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n,m,k;
        cin >> n >> m >> k;
        string s;
        cin >> s;
        for (int i=0; i<n+1; i++)
        {
            if (i==n)
            {
                cout << "YES" << endl;
                break;
            }

            if (s[i]=='L')
            {

            }

            if (s[i]=='W')
            {
                if (s[i+1]=='W')
                {
                    cout << "NO" << endl;
                    break;
                }
                else if (m<=1 && k>0) 
                {
                    k--;
                }
                else if (m>1) 
                {

                }
                else 
                {
                    cout << "NO" << endl;
                    break;
                }
            }

            if (s[i]=='C')
            {
                int countC=0;
                int j=i+1;
                while(true)
                {
                    if (s[j] =='C'){
                        countC++;
                    }
                    else break;
                }
                if (countC>=m)
                {
                    cout <<"NO";
                    break;
                }
                else if(countC < m)
                {
                    if(s[i-1] == 'L' || i-1==0)
                    {
                        i+=countC-1;
                    }
                }
            }

        }
    }


    return 0;
}