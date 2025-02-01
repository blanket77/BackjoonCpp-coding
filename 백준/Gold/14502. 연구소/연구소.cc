#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int origin_map[10][10]; // 초기 상태의 맵
int map[10][10]; // 벽을 세운 후의 맵
int visited[10][10];  // 이 배열은 더 이상 바이러스 시뮬레이션에 사용하지 않습니다.

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int ans = -1; // 안전 영역의 최대 크기

void virus_dfs(int x, int y, int temp[10][10], int temp_visited[10][10]); // 바이러스 확산
void three_wall_and_thread_virus(int cnt); // 벽 3개 세우기 및 바이러스 전파

// 바이러스 확산을 임시 배열(temp)에서 진행하는 DFS 함수
void virus_dfs(int x, int y, int temp[10][10], int temp_visited[10][10]) {
    temp_visited[x][y] = 1;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx >= N || ny < 0 || ny >= M)
            continue;
        if (!temp_visited[nx][ny] && temp[nx][ny] == 0) {
            temp[nx][ny] = 2; // 빈 칸에 바이러스 전파
            virus_dfs(nx, ny, temp, temp_visited);
        }
    }
}

// 3개의 벽을 세우고, 현재의 벽이 세워진 상태(map)를 임시 배열(temp)로 복사하여
// 그 상태에서 바이러스 확산을 시뮬레이션한 후 안전 영역을 계산한다.
void three_wall_and_thread_virus(int cnt) {

    if (cnt == 3) {
        int temp[10][10];

        int temp_visited[10][10] = {0};  // 모두 0으로 초기화
        copy(&map[0][0], &map[0][0] + 10 * 10, &temp[0][0]); // map 배열을 temp 배열로 복사
        
        // temp 배열에서 바이러스(값이 2인 위치)부터 DFS를 통해 전파
        for (int i = 0; i < N; i++){
            for (int j = 0; j < M; j++){
                if (temp[i][j] == 2 && !temp_visited[i][j]) {
                    virus_dfs(i, j, temp, temp_visited);
                }
            }
        }
        
        // temp 배열에서 안전 영역(값이 0인 칸) 개수를 세기
        int safe_zone = 0;
        for (int i = 0; i < N; i++){
            for (int j = 0; j < M; j++){
                if (temp[i][j] == 0)
                    safe_zone++;
            }
        }
        ans = max(ans, safe_zone);
        return;
    }
    
    // 벽 3개가 아직 세워지지 않은 경우, 빈 칸(0)을 찾아 벽(1)을 설치하고 재귀호출
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            if (map[i][j] == 0) {
                map[i][j] = 1;
                three_wall_and_thread_virus(cnt + 1);
                map[i][j] = 0; // 재귀 호출 후 원상복구
            }
        }
    }
}

void get_safe_zone(){
    int safe_zone = 0;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            if(map[i][j] == 0){
                safe_zone++;
            }
        }
    }
    ans = max(ans, safe_zone);
    return;
}

// 바이러스 전파
void virus_dfs(int x, int y){
    if(visited[x][y] == 0){
        visited[x][y] = 1;
        map[x][y] = 2;  
    }
    for (int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        // 범위를 벗어나지 않고
        if(nx < 0 || nx >= N || ny < 0 || ny >= M)
            continue;
        // 방문하지 않은 빈 칸인 경우
        if(!visited[nx][ny] && map[nx][ny] == 0)
            virus_dfs(nx, ny);
    }
    return;
}

int main(){
    cin >> N >> M;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            cin >> origin_map[i][j];
        }
    }
    
    // 초기 상태: origin_map에서 map으로 복사 (전역 map 사용)
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            map[i][j] = origin_map[i][j];
        }
    }
    
    // 벽 3개 세우기 및 바이러스 시뮬레이션
    three_wall_and_thread_virus(0);
    
    cout << ans << endl;
    
    return 0;
}
