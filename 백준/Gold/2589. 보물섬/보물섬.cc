#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m;
char map[50][50];
int visited[50][50];
int result = 0;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

// 유효한 좌표인지 확인하는 함수
bool isValid(int x, int y) {
    if (x < 0 || x >= n || y < 0 || y >= m) {
        return false;
    }
    return true;
}

// 방문 여부 초기화
void initCheck() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            visited[i][j] = 0;
        }
    }
}

// BFS 함수
void bfs(int x, int y) {
    queue<pair<int, int>> q;
    visited[x][y] = 1;  // 시작점을 방문 처리
    q.push({x, y});

    while (!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            // 유효한 좌표이고, 'L'인 경우
            if (isValid(nx, ny) && map[nx][ny] == 'L' && visited[nx][ny] == 0) {
                visited[nx][ny] = visited[cx][cy] + 1;  // 거리 갱신
                result = max(result, visited[nx][ny] - 1);  // 최대 거리 갱신
                q.push({nx, ny});
            }
        }
    }
}

int main() {
    cin >> n >> m;

    // 지도 입력 받기
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }

    // 모든 육지에서 BFS를 실행
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] == 'L') {
                initCheck();  // 방문 배열 초기화
                bfs(i, j);    // BFS 실행
            }
        }
    }

    cout << result;  // 최대 거리 출력
    return 0;
}
