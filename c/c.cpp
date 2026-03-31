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
        int N;
        long long M, S, K;
        cin>>N>>M>>S>>K;
        // Lista de adyacencia (destino, pi(ui, vi))
        double adj[N][N];
        int ui, vi;
        double pi;
        while(M--)
        {
            cin>>ui>>vi>>pi;
            double prob = pi/100.0;
            adj[ui][vi] = prob;
            // Por lo que es bidireccional
            adj[vi][ui] = prob;
        }
        // Encontrar la ruta que maximice la probabilidad
        // Usar FLoyd-Warshall

        double dist[N][N];
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < N; j ++)
            {
                if(adj[i][j])
                {
                    dist[i][j] = adj[i][j];

                }
                else
                    dist[i][j] = 0;
            }
        }
        // Encontrar maximo camino de nodo 0 a nodo N-1
        for(int k = 0; k < N; k++)
        {
            for(int i = 0; i < N; i++)
            {
                for(int j = 0; j < N; j++)
                {
                    dist[i][j] = max(dist[i][j], dist[i][k]*dist[k][j]);
//                    cout<<i<<" "<<j<<": "<<dist[i][j]<<endl;
                }
            }
        }

        long double tiempoEsperado = double(S*(2.0*K))/dist[0][N-1];
        cout<<"Case "<<caso<<": "<<fixed << setprecision(10)<<tiempoEsperado<<"\n";
        caso ++;
    }

    return 0;
}

/*
2
5 5 1 10
0 1 70
0 2 40
2 3 100
1 3 50
4 3 80
2 1 30 2
0 1 80


5
3 3 1 5
0 2 50
0 1 90
1 2 90
2 2 5 1
0 1 10
0 1 90
4 4 2 10
0 3 40
0 1 80
1 2 80
2 3 80
4 3 10 2
0 1 100
1 2 50
1 3 100
4 4 1 1
0 1 90
1 2 90
2 0 90
1 3 50
*/
