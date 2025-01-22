#include <iostream>
#include <string>
#include <vector>
using namespace std;

int N,L,R; // N: map size, L: min diff, R: max diff
int land[50][50]; // map
int visited[50][50] = {0,}; // visited check
int dx[4] = {0,0,-1,1}; // x_direction
int dy[4] = {-1,1,0,0}; // y_direction
vector <pair<int,int>> v; // 연합 좌표
bool flag = false; // 연합 여부

int day = 0; // 걸린 일

// 깊이 우선 탐색
void dfs(int x, int y){
    visited[x][y] = 1; // 방문 체크
    v.push_back({x,y}); // 연합 좌표 저장

    for(int i=0; i<4; i++){ // 4방향 탐색
        int nx = x + dx[i]; // x 좌표
        int ny = y + dy[i]; // y 좌표

        // 범위 밖이거나 방문했으면 넘어감
        if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
        if(visited[nx][ny]) continue;

        // 땅의 차이가 L이상 R이하이면 연합 가능
        int diff = abs(land[x][y] - land[nx][ny]);
        if(diff >= L && diff <= R){
            flag = true; // 연합 가능
            dfs(nx,ny);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);

    cin >> N >> L >> R;

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> land[i][j];
        }
    }

    while(true){
        fill(&visited[0][0], &visited[0][0] + 50*50, 0); // visited 초기화

        for(int i = 0 ; i < N ; i++){
            for(int j = 0 ; j < N ; j++){
                if(visited[i][j]) continue; 
                dfs(i,j); // 깊이 우선 탐색

                int sum = 0; // 연합 총 인구
                
                for(auto a : v) // 연합 인구 합산
                    sum += land[a.first][a.second];
                
                int avg = sum / v.size(); // 연합 평균 인구
                for(auto a : v)
                    land[a.first][a.second] = avg;
                
                v.clear(); // 연합 초기화, 바로 계산하더라도 visited가 1로 되어있어서 같은 날엔 v에 들어간 연합 좌표가 연합이 되지 않음
            }
        }
        if(!flag) break; // 연합이 없으면 종료

        flag = false; // 연합 여부 초기화
        day++; // 일수 증가
        
    }

    cout << day << '\n'; // 결과 출력

    return 0;
}