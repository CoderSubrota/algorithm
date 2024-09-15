#include <bits/stdc++.h>
using namespace std;

const int dx[] = {-1, 1, 0, 0}; 
const int dy[] = {0, 0, -1, 1};

bool isValid(int x, int y, int n, int m, vector<vector<char>>& grid) {
    return (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == '.');
}

void dfs(int x, int y, int n, int m, vector<vector<char>>& grid, vector<vector<bool>>& visited) {
    visited[x][y] = true;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (isValid(nx, ny, n, m, grid) && !visited[nx][ny]) {
            dfs(nx, ny, n, m, grid, visited);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
    int si, sj, di, dj;
    cin >> si >> sj >> di >> dj;
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    dfs(si, sj, n, m, grid, visited);
    if (visited[di][dj]) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}