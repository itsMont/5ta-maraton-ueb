#include <bits/stdc++.h>
using namespace std;


long long solve(string S ,int p, int q)
{
    vector <string> nombres;
    long long ans = 0;
    int n = S.size();
    for(int i = p; i<=q; i++)
    {
        for(int idx = 0; idx<n; idx++)
        {
            if(idx+i <= n)
            {
                string nombre = S.substr(idx,i);
                // Busca ocurrencia de nombre
                if(find(nombres.begin(), nombres.end(), nombre)!=nombres.end())
                    continue;
                else
                {
                    //cout<<nombre<<endl;
                    nombres.push_back(nombre);
                    ans++;
                }
            }
            else
                break;
        }
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T, caso = 1;

    cin>>T;

    while(T--)
    {
        string S;
        int p, q;
        long long ans = 0;
        cin>>S;
        cin>>p>>q;
        ans = solve(S ,p, q);
        cout<<"Case "<<caso<<": "<<ans<<"\n";
        caso++;
    }


    return 0;
}

/*
2
abcdef
2 5
abcdfccd
2 5


5
abcdef
2 5
aaaaa
1 5
ababa
1 3
banana
2 4
abcabc
1 6
*/
