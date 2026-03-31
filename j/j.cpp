#include <bits/stdc++.h>
using namespace std;


string decBin(int n)
{
    string bin = "";
    while(n>1)
    {
        bin += to_string(n%2);
        n/=2;
    }
    bin+=to_string(n%2);
    return bin;
}

string paridad(string n)
{
    int co = 0;
    for(int i = 0; i<n.size(); i++)
    {
        if(n[i] == '1')
            co++;
    }
    if(co % 2 ==0)
        return "even";
    return "odd";

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;

    cin>>N;
    int caso = 1;
    while(N--)
    {
        int n;
        cin>>n;
        cout<<"Case "<<caso<<": "<<paridad(decBin(n))<<"\n";
        caso++;
    }
    return 0;
}
