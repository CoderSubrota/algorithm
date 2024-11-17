#include <bits/stdc++.h>
#define ll long long int
using namespace std;

class UnionFind {
public:
    vector<ll> parent, rank;

    UnionFind(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        for (int i = 1; i <= n; ++i) parent[i] = i;
    }

    int find(int u) {
        if (parent[u] != u) {
            parent[u] = find(parent[u]);
        }
        return parent[u];
    }

    bool unite(int u, int v) {
        int rootU = find(u);
        int rootV = find(v);
        if (rootU == rootV) return false;
        if (rank[rootU] > rank[rootV]) {
            parent[rootV] = rootU;
        } else if (rank[rootU] < rank[rootV]) {
            parent[rootU] = rootV;
        } else {
            parent[rootV] = rootU;
            rank[rootU]++;
        }
        return true;
    }
};

int main() {
    int N, E;
    cin >> N >> E;

    vector<vector<ll>> edges(E, vector<ll>(3)); 
    for (int i = 0; i < E; ++i) {
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2]; 
    }


    sort(edges.begin(), edges.end(), [](vector<ll>& a, vector<ll>& b) {
        return a[2] < b[2];
    });

    UnionFind uf(N);
    ll totalCost = 0; 
    ll edgesInMST = 0;

    for (int i = 0; i < E; ++i) {
        ll A = edges[i][0], B = edges[i][1], W = edges[i][2];
        if (uf.unite(A, B)) {
            totalCost += W;
            edgesInMST++;
        }
    }

    if (edgesInMST < N - 1) {
        cout << "Not Possible" << endl;
    } else {
        ll redundantRoads = E - edgesInMST; 
        cout << redundantRoads << " " << totalCost << endl; 
    }

    return 0;
}
