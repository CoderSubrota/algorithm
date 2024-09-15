// class Solution {
// public:
//     bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
//         vector<vector<int>> adj(n);
//         for (auto& edge : edges) {
//             adj[edge[0]].push_back(edge[1]);
//             adj[edge[1]].push_back(edge[0]);
//         }

//         vector<bool> visited(n, false);
//         return dfs(source, destination, adj, visited);
//     }

//     bool dfs(int node, int destination, vector<vector<int>>& adj, vector<bool>& visited) {
//         if (node == destination) return true;
//         visited[node] = true;
//         for (int neighbor : adj[node]) {
//             if (!visited[neighbor]) {
//                 if (dfs(neighbor, destination, adj, visited)) return true;
//             }
//         }
//         return false;
//     }
// };
