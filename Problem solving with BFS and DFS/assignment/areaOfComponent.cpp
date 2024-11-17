#include <bits/stdc++.h>
using namespace std;

int dfs(int x, int y, vector<vector<char>>& matrix, vector<vector<bool>>& visited) {
    int area = 0;
    int N = matrix.size();
    int M = matrix[0].size();

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    vector<pair<int, int>> stack;
    stack.push_back({x, y});
    visited[x][y] = true;

    while (!stack.empty()) {
        auto [currX, currY] = stack.back();
        stack.pop_back();
        area++;

        for (int i = 0; i < 4; i++) {
            int newX = currX + dx[i];
            int newY = currY + dy[i];

            if (newX >= 0 && newX < N && newY >= 0 && newY < M &&
                matrix[newX][newY] == '.' && !visited[newX][newY]) {
                visited[newX][newY] = true;
                stack.push_back({newX, newY});
            }
        }
    }
    
    return area;
}

int main() {
    int N, M;
    cin >> N >> M;
    
    vector<vector<char>> matrix(N, vector<char>(M));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> matrix[i][j];
        }
    }

    vector<vector<bool>> visited(N, vector<bool>(M, false));
    int minArea = INT_MAX;
    bool foundComponent = false;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (matrix[i][j] == '.' && !visited[i][j]) {
                foundComponent = true;
                int area = dfs(i, j, matrix, visited);
                minArea = min(minArea, area);
            }
        }
    }

    cout << (foundComponent ? minArea : -1) << endl;

    return 0;
}
