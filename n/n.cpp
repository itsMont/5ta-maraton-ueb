#include <bits/stdc++.h>
using namespace std;

string I(string bin,int i, int j)
{
    int n = bin.size();
    i--;
    j--;
    string conv = "";
    for(int idx = 0;idx<n;idx++)
    {
        if(idx >= i && idx<=j)
        {
            if(bin[idx] == '1')
                conv += '0';
            else if(bin[idx] == '0')
                conv += '1';
        }
        else
            conv += bin[idx];
    }
    return conv;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, caso=1;

    cin>>N;
    while(N--)
    {
        cout<<"Case "<<caso<<":\n";
        string bin;
        int q;
        cin>>bin;
        cin>>q;
        int n = bin.size();
        while(q--)
        {
            string comando;
            cin>>comando;
            if(comando == "I")
            {
                int i, j;
                cin>>i>>j;
                bin = I(bin,i,j);
                continue;
            }
            else if(comando == "Q")
            {
                int idx;
                cin>>idx;
                cout<<bin[idx-1]<<"\n";
                continue;
            }
        }

        caso++;
    }
    return 0;
}
