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
        // Usando DP con bit mask (Consultar libro programación competitiva)
        // Precio de no hacer ninguna tarea: 0
        int precios[(1<<n)];
        fill(precios, precios + (1<<n), 1e9);
        precios[0] = 0;
        // para n=3, las posibles masks son 000,001,010,011,100,101, 110, 111
        for(int mask = 0; mask < (1<<n); mask++)
        {
            // Navegar matriz
            for(int i = 0; i < n; i++)
            {
                // Precio del i-esimo trabajo
                int iPrecio = costos[i][i];
                // revisar si no está prendido en la i-esima posicion
                if(!(mask & (1<<i) ) )
                {
                    // actualiza precio con recargos de trabajos ya hechos antes de encender
                    for(int j = 0; j < n; j++)
                    {
                        // Si ya se hizo j
                        if(mask & (1<<j))
                            iPrecio += costos[i][j];
                    }
                // actualizar mask. Encender el siguiente trabajo
                int next = mask | (1<<i);
                precios[next] = min( iPrecio + precios[mask], precios[next]);
                }
            }
        }
        cout<<"Case "<<caso<<": "<<precios[(1<<n) -1]<<"\n";
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
