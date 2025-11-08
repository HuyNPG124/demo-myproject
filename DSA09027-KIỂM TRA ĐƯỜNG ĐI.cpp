#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> visited;
vector<int> component;

void dfs(int u, int id) {
    visited[u] = 1;
    component[u] = id;
    for (int v : adj[u]) {
        if (!visited[v]) dfs(v, id);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;

        adj.assign(N + 1, {});
        visited.assign(N + 1, 0);
        component.assign(N + 1, 0);

        for (int i = 0; i < M; ++i) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int id = 0;
        for (int i = 1; i <= N; ++i) {
            if (!visited[i]) {
                ++id;
                dfs(i, id);
            }
        }

        int Q;
        cin >> Q;
        while (Q--) {
            int x, y;
            cin >> x >> y;
            if (component[x] == component[y]) cout << "YES\n";
            else cout << "NO\n";
        }
    }
    return 0;
}
