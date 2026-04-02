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
        int n,m;
        cin>>n>>m;
        vector<int> caminos[n];
        while(m--)
        {
            int u,v;
            cin>>u>>v;
            caminos[u].push_back(v);
            caminos[v].push_back(u);
        }
        // Encontrar ciclo más pequeño con BFS usando parents
        // Ver libro competitiva
        int longitudCiclo = INT_MAX;
        string ans = "impossible";
        bool ciclo = false;

        // Busca por cada nodo
        for(int i = 0; i < n; i++)
        {
//            cout<<i<<endl;
            queue< pair <int, int> > q;
            vector<int> distance(n, -1);
            distance[i] = 0;
            q.push({i, -1});
            // Ejecutar BFS en busqueda de ciclos
            while(!q.empty())
            {
                int s = q.front().first;
                int padre = q.front().second;
                q.pop();
                // No recorrer innecesariamente
                if (distance[s] * 2 + 1 >= longitudCiclo)
                    break;
                for(auto u: caminos[s])
                {
                    // No recorrer otra vez
                    if(u == padre)
                        continue;
                    // Encontrar ciclo si u ya fue visitado por otro lado
                    if(distance[u] != -1)
                    {
                        // se encontro ciclo mayor 1 (las abejas necesitan 2 arboles)
                        longitudCiclo = min(longitudCiclo, distance[u] + distance[s] + 1);
                        ciclo = true;
                    }
                    else
                    {
                        // u es el vecino y s es el nodo padre (de donde viene)
                        q.push({u, s});
                        distance[u] = distance[s] + 1 ;
//                        cout<<"Diatancia padre "<<s<<" : "<<distance[s]<<" Distancia vecino "<<u<<" :"<<distance[u]<<"\n";
                    }
                }
                // El minimo absoluto es un ciclo de longitud 3
                if (longitudCiclo == 3) break;
            }
            if (longitudCiclo == 3) break;

        }

        if(ciclo)
            ans = to_string(longitudCiclo);
        cout<<"Case "<<caso<<": "<<ans<<"\n";
        caso ++;
    }

    return 0;
}


/*
3
3 3
0 1
1 2
2 0
2 1
0 1
5 6
0 1
1 2
1 3
2 3
0 4
3 4

2

6 7
0 1
1 2
2 0
0 3
3 4
4 5
5 0

8 6
0 1
1 2
2 0
4 5
5 6
6 7


2

4 6
0 1
0 2
0 3
1 2
1 3
2 3

3 2
0 1
1 2

*/
