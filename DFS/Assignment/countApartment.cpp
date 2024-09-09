#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M ;

  
    vector<vector<char>> map(N, vector<char>(M));


    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
        }
    }

    
    vector<vector<bool>> visited(N, vector<bool>(M, false));

    int apartmentCount = 0;

   
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (map[i][j] != '#' && !visited[i][j]) {
                apartmentCount++;


                queue<pair<int, int>> q;
                q.push({i, j});
                visited[i][j] = true;


                while (!q.empty()) {
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();

               
                    for (int k = 0; k < 4; k++) {
                        int nx = x + dx[k];
                        int ny = y + dy[k];

                       
                        if (nx >= 0 && nx < N && ny >= 0 && ny < M && map[nx][ny] != '#' && !visited[nx][ny]) {
                            q.push({nx, ny});
                            visited[nx][ny] = true;
                        }
                    }
                }
            }
        }
    }


    cout << apartmentCount << endl;

    return 0;
}