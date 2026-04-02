// ESTE CODIGO ES UNA VERSIÓN OPTIMIZADA POR Gemini
// SE UTILIZA PARA PROBAR SI EL JUDGER SIGUE ARROJANDO WRONG ANSWER DESPUÉS DE OPTIMIZAR

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// Usamos un INF grande pero que no desborde al sumarse
const int INF = 1e9;

void solve(int caso) {
    int n, m;
    // Si la lectura falla (fin de archivo inesperado), salimos
    if (!(cin >> n >> m)) return;

    // Usamos vector de vectores estándar. Nada de VLAs.
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int min_girth = INF;

    // Buscar el ciclo más corto iniciando BFS desde cada nodo
    for (int i = 0; i < n; i++) {
        vector<int> dist(n, INF);
        vector<int> parent(n, -1);
        queue<int> q;

        dist[i] = 0;
        q.push(i);

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            // SÚPER PODA: Si la distancia al nodo actual ya es mayor o igual a la mitad
            // del mejor ciclo encontrado, es matemáticamente imposible que
            // a partir de aquí cerremos un ciclo más corto.
            if (dist[u] * 2 + 1 >= min_girth) continue;

            for (int v : adj[u]) {
                if (dist[v] == INF) {
                    // Nodo no visitado
                    dist[v] = dist[u] + 1;
                    parent[v] = u;
                    q.push(v);
                } else if (v != parent[u]) {
                    // Chocamos con un nodo visitado que no es nuestro padre inmediato.
                    // Esto forma un ciclo.
                    min_girth = min(min_girth, dist[u] + dist[v] + 1);
                }
            }
        }
        // Si ya encontramos un triángulo, es el mínimo teórico para este tipo de grafo.
        if (min_girth == 3) break;
    }

    // Formato de salida estricto
    cout << "Case " << caso << ": ";
    if (min_girth == INF) {
        cout << "impossible\n";
    } else {
        cout << min_girth << "\n";
    }
}

int main() {
    // Optimización de la entrada/salida para el límite de tiempo
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if (cin >> T) {
        for (int caso = 1; caso <= T; caso++) {
            solve(caso);
        }
    }
    return 0;
}
