#include <iostream>
#include <vector>
using namespace std;

const int n = 1e5+2;
bool vis[n];
vector<int> adj[n];

void dfs(int node) {
    //preorder
    vis[node] = true;
    cout << node << endl;

    #pragma omp parallel for
    for (auto it = adj[node].begin(); it != adj[node].end(); it++) {
        int neighbor = *it;
        if (!vis[neighbor]) {
            dfs(neighbor);
        }
    }

    //postorder
}

int main() {
    for (int i = 0; i < n; i++) {
        vis[i] = false;
    }

    int m, n;
    cin >> m >> n;

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(1);

    return 0;
}
