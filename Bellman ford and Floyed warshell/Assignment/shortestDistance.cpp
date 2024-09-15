#include <bits/stdc++.h>
using namespace std;
const long long int INF = 1e18;

class shortestDistanceFind
{
public:
    void floydWarshall(int N, vector<vector<long long int>> &dist)
    {

        for (int k = 1; k <= N; k++)
        {
            for (int i = 1; i <= N; i++)
            {
                for (int j = 1; j <= N; j++)
                {
                    if (dist[i][k] != INF && dist[k][j] != INF)
                    {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }
    }
};

bool validateInput(int N, int E, int A, int B, long long W)
{
    if (A < 1 || B < 1 || A > N || B > N || W < 0)
    {
        return false; 
    }
    return true;
}

int main()
{
    shortestDistanceFind sdf;
    int N, E;
    cin >> N >> E;

    if (N <= 0 || E < 0)
    {
        return 0;
    }

    vector<vector<long long int>> dist(N + 1, vector<long long int>(N + 1, INF));

    for (int i = 1; i <= N; i++)
    {
        dist[i][i] = 0;
    }

    for (int i = 0; i < E; i++)
    {
        int A, B;
        long long int W;
        cin >> A >> B >> W;

        if (!validateInput(N, E, A, B, W))
        {
            return 0; 
        }

        dist[A][B] = min(dist[A][B], W);
    }


    sdf.floydWarshall(N, dist);

    int Q;
    cin >> Q;

    while (Q--)
    {
        int X, Y;
        cin >> X >> Y;

        if (X < 1 || X > N || Y < 1 || Y > N)
        {
            continue; 
        }

        if (dist[X][Y] == INF)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << dist[X][Y] << endl;
        }
    }

    return 0;
}
