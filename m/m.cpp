#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T, caso = 1;
    cin>>T;
    while(caso<=T)
    {
        long long N, M, sum = 0;
        cin>>N>>M;

        long long nums[N];
        long long subsec = 0;
        for(int i = 0; i < N;i++)
        {
            cin>>nums[i];
            sum += nums[i];
            if(nums[i] % M == 0)
                subsec++;
            // verificar que no se cuente dos veces un solo elemento
            if(i>0 && sum%M == 0)
                subsec++;
        }
        // utilizar i y j para armar subarreglos y comparar divisibilidad
        for(int i = 1; i<N-1; i++)
        {

            sum = nums[i];
            for(int j = i+1; j < N; j++)
            {
                sum += nums[j];
                if(sum % M == 0)
                {
                    subsec++;
                }
            }
        }
        cout<<"Case "<<caso<<": "<<subsec<<"\n";
        caso ++;
    }

    return 0;
}

/*
2
4 4
2 1 4 3
6 3
1 2 3 4 5 6
*/
