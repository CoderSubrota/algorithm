#include <bits/stdc++.h>
using namespace std;

#define INF 1e18  
#define ll long long int 

void dijkstra(int source, vector<vector<pair<ll, ll>>>& adj, vector<ll>& dist) {
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    dist[source] = 0;
    pq.push({0, source});

    while (!pq.empty()) {
        ll u = pq.top().second;
        pq.pop();

        for (auto& edge : adj[u]) {
            ll v = edge.first, weight = edge.second;
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
}

int main() {
    ll N, E;
    cin >> N >> E;
    
    vector<vector<pair<ll, ll>>> adj(N + 1);  
    for (ll i = 0; i < E; i++) {
        ll A, B, W;
        cin >> A >> B >> W;
        adj[A].push_back({B, W});
    }

    ll source;
    cin >> source;

    vector<ll> dist(N + 1, INF);  
    dijkstra(source, adj, dist);  

    ll T;
    cin >> T;

    while (T--) {
        ll D, DW;
        cin >> D >> DW;

        cout << (dist[D] <= DW ? "YES" : "NO") << "\n";
    }

    return 0;
}
