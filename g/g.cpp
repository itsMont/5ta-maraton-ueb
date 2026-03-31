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
        int ans = 0;

        int n, P, Q;
        cin>>n>>P>>Q;

        int pesos[n], sum = 0;
        // Orden no decreciente
        for(int i = 0; i <n; i++)
            cin>>pesos[i];

        for(int i = 0; i <n; i++)
        {
            sum += pesos[i];
            ans++;
            // Suma de pesos
            // Ya no se pueden meter más huevos
            if(ans > P)
            {
                ans--;
                break;
            }

            // Supero los gramos en tazón
            if(sum > Q)
            {
                ans--;
                break;
            }
        }
        // Encontrar el máximo numero de huevos que pueden hervir sin riesgo
        // P-> Maximo número de huevos en el tazón Q -> capacidad de tazón en gramos
        // Es como problema de knapsack pero especial

        cout<<"Case "<<caso<<": "<<ans<<"\n";
        caso++;
    }

    return 0;
}


/*
2
3 2 10
1 2 3
4 5 5
4 4 5 5


6
3 2 10
1 2 3
4 5 5
1 2 3 4
5 5 30
1 2 3 4 5
6 3 10
1 1 1 1 1 1
3 10 2
5 5 5
10 5 10
1 1 1 1 1 1 1 1 1 1

3
3 2 10
1 2 3
4 5 5
4 4 5 5
3 2 10
1 2 3

*/
