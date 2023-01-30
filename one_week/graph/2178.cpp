#include<cstdio>
#include<algorithm>
#include<iostream>
#include<queue>
#define MAX 100

using namespace std;

bool map[MAX][MAX] = {false, }; 
bool visited[MAX][MAX] = {false, };
int check[MAX][MAX] = {0,};
int N, M;  // N은 행,y  // M은 열,x
int dir[4][2] = { {-1,0}, {0,1},{1,0},{0,-1} }; // 상하좌우 이동


void BFS(int y, int x) {
    queue <pair<int, int>> q;
    q.push(make_pair(y,x));
    visited[y][x] = true;

    while(!q.empty()){
        int x = q.front().second;
        int y = q.front().first;
        q.pop();

        for(int i = 0 ; i < 4 ; i++){
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];

            if(nx >= 0 && ny >= 0 && nx < M && ny < N){
                if(map[ny][nx] == true && visited[ny][nx] == false){
                    check[ny][nx] = check[y][x] + 1;
                    visited[ny][nx] = true;
                    q.push(make_pair(ny, nx));
                }
            }
        }
    }
}

int main() {

    cin >> N >> M;  
    
    for(int y = 0 ; y < N; y++){
        for(int x = 0 ; x < M; x++){
            scanf("%1d", &map[y][x]);         
        }
    }

    BFS(0,0);
    cout << check[N-1][M-1] + 1 << '\n';

    return 0;
}