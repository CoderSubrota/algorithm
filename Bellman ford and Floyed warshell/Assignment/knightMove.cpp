#include<bits/stdc++.h>
using namespace std;

int dx[] = {2, 2, -2, -2, 1, 1, -1, -1};
int dy[] = {1, -1, 1, -1, 2, -2, 2, -2};

bool isValid(int x, int y, int N, int M) {
    return x >= 0 && x < N && y >= 0 && y < M;
}

int minKnightMoves(int N, int M, int Ki, int Kj, int Qi, int Qj) {
    if (Ki == Qi && Kj == Qj) return 0;  

    vector<vector<bool>> visited(N, vector<bool>(M, false));
    queue<pair<int, int>> q;  
    queue<int> steps; 
    q.push({Ki, Kj});
    steps.push(0);
    visited[Ki][Kj] = true;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        int stepCount = steps.front();
        q.pop();
        steps.pop();

        for (int i = 0; i < 8; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx == Qi && ny == Qj) {
                return stepCount + 1;
            }

            if (isValid(nx, ny, N, M) && !visited[nx][ny]) {
                visited[nx][ny] = true;
                q.push({nx, ny});
                steps.push(stepCount + 1);
            }
        }
    }

    return -1; 
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, M, Ki, Kj, Qi, Qj;
        cin >> N >> M >> Ki >> Kj >> Qi >> Qj;
        cout << minKnightMoves(N, M, Ki, Kj, Qi, Qj) << endl;
    }
    return 0;
}
