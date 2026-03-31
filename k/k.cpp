#include <bits/stdc++.h>
using namespace std;

int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);
    double pi = 2*acos(0.0);
    int N;
    int caso = 1;
    cin>>N;
    while(caso<=N)
    {
        double r;
        cin>>r;
        double area= r*r*(4-pi);
        printf("Case %d: %.2f\n ", caso, area);
        caso++;
    }

    return 0;
}
