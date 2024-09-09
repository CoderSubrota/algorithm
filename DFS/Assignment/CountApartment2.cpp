#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<vector<char>> building;
vector<vector<bool>> visited;

int dfs(int x, int y) {
    // Check if the current position is out of bounds or a wall or already visited
    if (x < 0 || x >= N || y < 0 || y >= M || building[x][y] == '#' || visited[x][y])
        return 0;

    // Mark the cell as visited
    visited[x][y] = true;

    // Initialize the size of the apartment
    int size = 1;

    // Explore the four possible directions (up, down, left, right)
    size += dfs(x + 1, y);  // down
    size += dfs(x - 1, y);  // up
    size += dfs(x, y + 1);  // right
    size += dfs(x, y - 1);  // left

    return size;
}

int main() {
    cin >> N >> M;

    building.resize(N, vector<char>(M));
    visited.resize(N, vector<bool>(M, false));

    // Input the building layout
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> building[i][j];
        }
    }

    vector<int> room_sizes;

    // Traverse through the matrix
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            // If we find an unvisited room ('.'), perform DFS
            if (building[i][j] == '.' && !visited[i][j]) {
                int size = dfs(i, j);
                room_sizes.push_back(size);
            }
        }
    }

    // Sort the room sizes in ascending order
    sort(room_sizes.begin(), room_sizes.end());

    // If no apartments found, print 0
    if (room_sizes.empty()) {
        cout << 0;
    } else {
        // Print the room sizes
        for (int size : room_sizes) {
            cout << size << " ";
        }
    }

    return 0;
}
