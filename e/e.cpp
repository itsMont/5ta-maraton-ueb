
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
        cin>>N;
        // Hacer lista de adyacencia. Consultar libro competitiva
        vector<int> adj[N];
        for(int i = 0; i < N-1; i++)
        {
            int X,Y;
            cin>>X>>Y;
            adj[X-1].push_back(Y-1);
        }
        // Aplicar DFS con pila
        vector<int> parents(N, -1);
        // Guarda cómo se hacen las invitaciones
        vector<int> order;
        stack<int> nodos;
        // El amigo descarrilado siempre es el primero
        nodos.push(0);
        while(!nodos.empty())
        {
            int u = nodos.top();
            nodos.pop();
            order.push_back(u);
            for(int v : adj[u])
            {
                // Agregar padre de v
                parents[v] = u;
                nodos.push(v);
            }
        }
        // Calcular tamaños subarboles. Cada uno tiene por lo menos 1 nodo
        vector<long long> subarbolesTamanos(N, 1);

        // Recorrer el orden de invitaciones de adelante para atrás
        for(int i = N-1; i>=0; i--)
        {
            int u = order[i];
            // Si el nodo u NO es la raiz
            if(parents[u] != -1)
            {
                // Al padre del nodo u se le agrega el tamaño del subarbol donde u es la raiz
                subarbolesTamanos[parents[u]] += subarbolesTamanos[u];
            }
        }

        // Los amigos posibles son los que tienen relacion (ancestro, descendiente)
        long long paresAncestroDesc = 0;
        for(int i = 0; i < N; i++)
        {
            paresAncestroDesc += subarbolesTamanos[i] - 1;
        }

        // Contar por complemento
        // Pares no amigos = Pares posibles - pares (ancestro, descendiente)
        // Pares posibles = N(N-1)/2
        long long ans = N*(N-1)/2 - paresAncestroDesc;

        cout<<"Case "<<caso<<": "<<N-1<<" "<<ans<<"\n";
        caso++;
    }

    return 0;
}

/*
2
2
1 2
3
1 2
1 3
*/
