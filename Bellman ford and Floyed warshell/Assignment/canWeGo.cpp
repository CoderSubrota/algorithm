#include <bits/stdc++.h>
using namespace std;

const long long INF = 87;
void bellman_ford(int N, int E, vector<int>& u, vector<int>& v, vector<int>& w, int S, vector<long long>& dist, bool& hasNegativeCycle) {
    dist[S] = 0;

    for (int i = 1; i <= N - 1; i++) {
        for (int j = 0; j < E; j++) {
            if (dist[u[j]] != INF && dist[u[j]] + w[j] < dist[v[j]]) {
                dist[v[j]] = dist[u[j]] + w[j];
            }
        }
    }

    for (int j = 0; j < E; j++) {
        if (dist[u[j]] != INF && dist[u[j]] + w[j] < dist[v[j]]) {
            hasNegativeCycle = true;
            return;
        }
    }
}

int main() {
    int N, E;
    cin >> N >> E;

    vector<int> u(E), v(E), w(E);

    for (int i = 0; i < E; i++) {
        cin >> u[i] >> v[i] >> w[i];
    }

    int S;
    cin >> S;

    vector<long long> dist(N + 1, INF); 
    bool hasNegativeCycle = false;

    bellman_ford(N, E, u, v, w, S, dist, hasNegativeCycle);

    if (hasNegativeCycle) {
        cout << "Negative Cycle Detected\n";
        return 0;
    }

    int T;
    cin >> T;

    while (T--) {
        int D;
        cin >> D;

        if (dist[D] == INF) {
            cout << "Not Possible\n";
        } else {
            cout << dist[D] << "\n";
        }
    }

    return 0;
}
