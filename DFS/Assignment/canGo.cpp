#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    // Create a 2D matrix to represent the map
    vector<vector<char>> map(N, vector<char>(M));

    // Read the map from the input
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
        }
    }

    // Find the coordinates of room A and room B
    int Ax, Ay, Bx, By;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (map[i][j] == 'A') {
                Ax = i;
                Ay = j;
            } else if (map[i][j] == 'B') {
                Bx = i;
                By = j;
            }
        }
    }

    // Create a visited matrix to keep track of visited cells
    vector<vector<bool>> visited(N, vector<bool>(M, false));

    // Create a queue for BFS
    queue<pair<int, int>> q;

    // Add room A to the queue
    q.push({Ax, Ay});
    visited[Ax][Ay] = true;

    // Directions for moving up, down, left, and right
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    // Perform BFS
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        // If we reached room B, output YES
        if (x == Bx && y == By) {
            cout << "YES" << endl;
            return 0;
        }

        // Explore neighboring cells
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

           
            if (nx >= 0 && nx < N && ny >= 0 && ny < M && map[nx][ny] != '#' && !visited[nx][ny]) {
                q.push({nx, ny});
                visited[nx][ny] = true;
            }
        }
    }

   
    cout << "NO" << endl;

    return 0;
}