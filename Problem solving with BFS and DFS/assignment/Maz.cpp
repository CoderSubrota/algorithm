#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 10;
bool vis[N][N];
int parent[N][N][2];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

int n, m;
char graph[N][N];

bool valid(int ci, int cj) {
    return ci >= 0 && ci < n && cj >= 0 && cj < m;
}

bool bfs(int si, int sj) {
    queue<pair<int, int>> q;
    q.push({si, sj});
    vis[si][sj] = true;

    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();

        for (int i = 0; i < 4; i++) {
            int ci = x + dx[i], cj = y + dy[i];
            if (valid(ci, cj) && !vis[ci][cj] && graph[ci][cj] != '#') {
                vis[ci][cj] = true;
                q.push({ci, cj});
                parent[ci][cj][0] = x;
                parent[ci][cj][1] = y;
                if (graph[ci][cj] == 'D') return true;
            }
        }
    }
    return false;
}

void markPath(int exitX, int exitY) {
    while (graph[exitX][exitY] != 'R') {
        if (graph[exitX][exitY] != 'D')
            graph[exitX][exitY] = 'X';
        int tempX = parent[exitX][exitY][0];
        int tempY = parent[exitX][exitY][1];
        exitX = tempX;
        exitY = tempY;
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++) 
            cin >> graph[i][j];

    int startX = -1, startY = -1;

    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++) 
            if (graph[i][j] == 'R') {
                startX = i; startY = j; 
                break;
            }

    if (bfs(startX, startY)) {
        int exitX, exitY;

        for (int i = 0; i < n; i++) 
            for (int j = 0; j < m; j++) 
                if (graph[i][j] == 'D') {
                    exitX = i; exitY = j; 
                    break;
                }

        markPath(exitX, exitY);
    }

    for (int i = 0; i < n; i++, cout << endl) 
        for (int j = 0; j < m; j++) 
            cout << graph[i][j];

    return 0;
}
