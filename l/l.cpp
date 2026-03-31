#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T, caso = 1;
    cin>>T;
    while(T--)
    {
        int n, ans=0;
        cin>>n;
        int costos[n][n];
        for(int i = 0; i < n ; i++)
        {
            for(int j = 0; j < n; j++)
            {
                cin>>costos[i][j];
            }
        }
        for(int i = n-1; i > 0 ; i--)
        {
            ans += costos[i][i];
            for(int j = 1; j<= n - i; j++)
            {
                if(min(ans + costos [i][i-j], ans + costos[i-j][i] ) == ans + costos [i][i-j] )
                {
                    ans += costos [i][i-j];
                }
                if(min(ans + costos [i][i-j], ans + costos[i-j][i] ) == ans + costos [i-j][i])
                    ans += costos[i-j][i];
            }
        }
        // Sumar el ultimo costo
        ans += costos[0][0];
        cout<<"Case "<<caso<<": "<<ans<<"\n";
        caso++;
    }

    return 0;
}
/*

2
2
10 10
9000 10
3
14 23 0
0 14 0
1000 9500 14

*/
