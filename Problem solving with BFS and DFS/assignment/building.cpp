#include <bits/stdc++.h>
#define ll long long int
using namespace std;

class UnionFind {
public:
    vector<ll> parent, rank;

    UnionFind(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1);
        for (int i = 1; i <= n; ++i) parent[i] = i;
    }

    int find(int u) {
        if (parent[u] != u) parent[u] = find(parent[u]);
        return parent[u];
    }

    bool unite(int u, int v) {
        int rootU = find(u), rootV = find(v);
        if (rootU == rootV) return false;
        if (rank[rootU] > rank[rootV]) parent[rootV] = rootU;
        else if (rank[rootU] < rank[rootV]) parent[rootU] = rootV;
        else {
            parent[rootV] = rootU;
            rank[rootU]++;
        }
        return true;
    }
};

int main() {
    ll N, E, totalCost = 0, connectedEdges = 0;
    cin >> N >> E;

    vector<vector<int>> edges(E, vector<int>(3));
    for (int i = 0; i < E; ++i) {
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2]; 
    }

    sort(edges.begin(), edges.end(), [](vector<int>& a, vector<int>& b) {
        return a[2] < b[2];
    });

    UnionFind uf(N);
    for (int i = 0; i < E; ++i) {
        int A = edges[i][0], B = edges[i][1], W = edges[i][2];
        if (uf.unite(A, B)) {
            totalCost += W;
            connectedEdges++;
        }
        if (connectedEdges == N - 1) break; 
    }
    if (connectedEdges == N - 1) cout << totalCost;
    else cout << -1;

    return 0;
}
