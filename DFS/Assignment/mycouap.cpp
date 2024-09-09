#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<vector<char>> building;
vector<vector<bool>> visited; 

int dfs(int x, int y) {
    if (x < 0 || x >= N || y < 0 || y >= M || building[x][y] == '#' || visited[x][y])
        return 0;
    visited[x][y] = true;
    int size = 1;
    size += dfs(x + 1, y);
    size += dfs(x - 1, y);
    size += dfs(x, y + 1);
    size += dfs(x, y - 1);
    return size;
}

int main() {
    cin >> N >> M;
    building.resize(N, vector<char>(M));
    visited.resize(N, vector<bool>(M, false));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> building[i][j];
        }
    }

    vector<int> room_sizes;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (building[i][j] == '.' && !visited[i][j]) {
                int size = dfs(i, j);
                room_sizes.push_back(size);
            }
        }
    }

    sort(room_sizes.begin(), room_sizes.end());

    if (room_sizes.empty()) {
        cout << 0;
    } else {
        for (int size : room_sizes) {
            cout << size << " ";
        }
    }

    return 0;
}
