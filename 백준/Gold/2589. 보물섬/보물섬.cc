#include <iostream>
#include <vector>  
#include <queue> 
#include <algorithm>
using namespace std;

int n, m;
char map[50][50];
int visted[50][50];
int result = 0;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};


bool isVaild(int x, int y){
    if(x < 0 || x >= n || y < 0 || y >= m){
        return false;
    }
    return true;
}

void initCheck(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            visted[i][j] = 0;
        }
    }
}

void bfs(int x, int y){
    queue<pair<int, int>> q;
    visted[x][y] = 1;

    q.push({x, y});


    while(!q.empty()){
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++){
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if(isVaild(nx, ny) && map[nx][ny] == 'L' && visted[nx][ny] == 0){
                visted[nx][ny] = visted[cx][cy] + 1;
                result = max(result, visted[nx][ny] -1 );
                q.push({nx, ny});
            }
        }
    }

}


int main(){
    cin >> n >> m;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> map[i][j];
        }
    }

    for(int i = 0 ; i < n; i++){
        for(int j = 0; j < m; j++){
            if(map[i][j] == 'L') {   
                initCheck();
                bfs(i,j);
            }
        }
    }
    cout << result;
    return 0;
}