#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, E;
    cin >> N >> E;

    vector<vector<bool>> graph(N, vector<bool>(N, false));

    for (int i = 0; i < E; ++i)
    {
        int u, v;
        cin >> u >> v;
        graph[u][v] = true;
    }

    int Q;
    cin >> Q;

    for (int i = 0; i < Q; ++i)
    {
        int A, B;
        cin >> A >> B;
        if (A == B)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << (graph[A][B] ? "YES" : "NO") << endl;
        }
    }

    return 0;
}