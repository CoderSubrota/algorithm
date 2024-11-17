#include <bits/stdc++.h>
using namespace std;

class UnionFind {
public:
vector<int> parent, rank;

    UnionFind(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1);
        for (int i = 1; i <= n; ++i) parent[i] = i;
    }

    int find(int u) {
        return parent[u] == u ? u : parent[u] = find(parent[u]);
    }

    bool unite(int u, int v) {
        int rootU = find(u), rootV = find(v);
        if (rootU == rootV) return false; 
        if (rank[rootU] > rank[rootV]) parent[rootV] = rootU;
        else {
            parent[rootU] = rootV;
            if (rank[rootU] == rank[rootV]) rank[rootV]++;
        }
        return true;
    }
};

int main() {
    int N, E, cycleEdges = 0;
    cin >> N >> E;
    
    UnionFind uf(N);
    while (E--) {
        int A, B;
        cin >> A >> B;
        if (!uf.unite(A, B)) cycleEdges++;
    }

    cout << cycleEdges;
    return 0;
}
