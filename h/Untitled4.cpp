#include <bits/stdc++.h>
using namespace std;


int binDec(int bin)
{
    int n = to_string(bin).size();
    int sum = 0;
    for(int i = 0; i < n; i++)
    {
        int factor = bin%10;
        cout<<factor<<endl;
        sum += factor * pow(2,n-i);
        bin/=10;
    }
    return sum;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int num = binDec(100);
    cout<<num;


    return 0;
}
