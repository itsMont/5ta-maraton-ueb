// ESTE CODIGO ES UNA VERSIÓN OPTIMIZADA POR Gemini
// SE UTILIZA PARA PROBAR SI EL JUDGER SIGUE ARROJANDO WRONG ANSWER DESPUÉS DE OPTIMIZAR

#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T, caso = 1;
    if (!(cin >> T)) return 0;

    while (T--) {
        int n, m;
        cin >> n >> m;

        vector<int> adj[505];
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int min_girth = INF;

        // BFS desde cada nodo para encontrar el Girth
        for (int i = 0; i < n; i++) {
            // EXTREMADAMENTE IMPORTANTE: Inicializar correctamente
            vector<int> dist(n, INF);
            vector<int> parent(n, -1);
            queue<int> q;

            dist[i] = 0;
            q.push(i);

            while (!q.empty()) {
                int u = q.front();
                q.pop();

                for (int v : adj[u]) {
                    if (dist[v] == INF) {
                        dist[v] = dist[u] + 1;
                        parent[v] = u;
                        q.push(v);
                    }
                    // Si ya visitamos v y no es el padre de u, cerramos un ciclo
                    else if (v != parent[u]) {
                        min_girth = min(min_girth, dist[u] + dist[v] + 1);
                    }
                }
                // Poda: Si ya encontramos un ciclo de 3, es el mínimo posible en grafos simples
                if (min_girth == 3) break;
            }
            if (min_girth == 3) break;
        }

        cout << "Case " << caso++ << ": ";
        if (min_girth == INF) cout << "impossible\n";
        else cout << min_girth << "\n";
    }

    return 0;
}
