#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring> // memset 사용
using namespace std;

int N, M;
int map[51][51];  // N 최대 50
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int temp[51][51]; // 각 셀까지 도달하는 시간 (-1이면 아직 도달하지 않음)
vector<pair<int, int>> virus_pos;
int min_ans = 987654321; 

// 입력 및 초기화: 빈 칸은 0, 벽은 1, 바이러스(초기 비활성)는 2 → 내부적으로 -1로 표시
void inputAndInit(){
    cin >> N >> M;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            cin >> map[i][j];
            if (map[i][j] == 2){
                virus_pos.push_back({i, j});
                map[i][j] = -1;  // 후보 바이러스 위치는 -1 (비활성)로 저장
            }
        }
    }
}

// 다중 소스 BFS 진행
void all_bfs(){
    queue<pair<int,int>> q;
    memset(temp, -1, sizeof(temp));  // 모든 셀을 -1로 초기화

    // 활성 바이러스(값 2)를 큐에 넣고 시작 (시간 0)
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            if(map[i][j] == 2){
                temp[i][j] = 0;
                q.push({i, j});
            }
        }
    }

    // BFS 전개
    while(!q.empty()){
        auto cur = q.front(); q.pop();
        int cx = cur.first, cy = cur.second;
        for (int i = 0; i < 4; i++){
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
            if (map[nx][ny] == 1) continue; // 벽은 건너뜀
            if (temp[nx][ny] != -1) continue; // 이미 방문한 곳이면 패스
            temp[nx][ny] = temp[cx][cy] + 1;
            q.push({nx, ny});
        }
    }
    
    // 모든 빈 칸(0)에 대해 도달시간 확인
    int temp_max = 0;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            if (map[i][j] == 0){ // 빈 칸만 검사 (비활성 바이러스(-1)는 감염 대상이 아님)
                if (temp[i][j] == -1) return; // 도달 불가능한 빈 칸이 있으면 이 조합 무효
                temp_max = max(temp_max, temp[i][j]);
            }
        }
    }
    min_ans = min(min_ans, temp_max);
}

// 재귀를 통한 활성 바이러스 선택 (조합)
void get_virus_map_and_day(int idx, int cnt) {
    if(cnt == M) {
        all_bfs();
        return;
    }
    for (int i = idx; i < virus_pos.size(); i++) {
        int x = virus_pos[i].first;
        int y = virus_pos[i].second;
        if(map[x][y] == 2) continue;  // 이미 활성화된 경우
        map[x][y] = 2;  // 선택: 활성 바이러스로 변경
        get_virus_map_and_day(i + 1, cnt + 1);
        map[x][y] = -1; // 원상 복구 (비활성)
    }
}

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    // freopen("a.txt", "r", stdin); // 파일 입력 사용 시
    inputAndInit();
    get_virus_map_and_day(0, 0);
    
    if(min_ans == 987654321)
        cout << -1 << "\n";
    else
        cout << min_ans << "\n";
    
    return 0;
}
