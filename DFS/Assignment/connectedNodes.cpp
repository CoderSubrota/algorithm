#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, E;
    cin >> N >> E;

    vector<vector<int>> adj(N);

    // Read the edges and add them to the adjacency list
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // since it's an undirected graph
    }

    int Q;
    cin >> Q;

    // Process each query
    for (int i = 0; i < Q; i++) {
        int X;
        cin >> X;

        // Sort the adjacency list of X in descending order
        sort(adj[X].rbegin(), adj[X].rend());

        // Print the connected nodes
        bool isConnect = false;
        for (int j = 0; j < adj[X].size(); j++) {
            if (adj[X][j] != X) { // don't print X itself
                cout << adj[X][j] << " ";
                isConnect = true;
            }
        }

        if (!isConnect) {
            cout << "-1";
        }

        cout << endl;
    }

    return 0;
}