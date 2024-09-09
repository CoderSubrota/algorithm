#include <bits/stdc++.h>
using namespace std;
vector<int> v[1005];
bool vis[1005];
bool getNumber = false;

void bfs(int src, int des)
{
    queue<pair<int, int>> q;
    q.push({src, 0});
    vis[src] = true;

    while (!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();
        int par = p.first;
        int level = p.second;

        if (par == des)
        {
            cout << par << endl;
            getNumber = true;
        }
        for (int child : v[par])
        {
            if (vis[child] == false)
            {
                q.push({child, level + 1});
                vis[child] = true;
            }
        }
    }
    if (getNumber == false)
    {
        cout << "Not Get It" << endl;
    }
    else
    {
        cout << "Get it" << endl;
    }
}

int main()
{
    int n, e;
    cin >> n >> e;

    while (e--)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int src;
    cin >> src;
    memset(vis, false, sizeof(vis));
    int des = 0;
    bfs(src, des);
    for (int i = 0; i < n; i++)
    {
        cout << i << " " << vis[i] << endl;
    }
    return 0;
}