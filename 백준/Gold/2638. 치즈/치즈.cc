#include <iostream>
#include <cstring>

using namespace std;

int cheeze[110][110] = {0};
int visited[110][110] = {0};

int n,m;
int preCheeze = 0;
int nowCheeze = 0;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

// 경계 밖에 있는지 확인
bool isVailed(int x, int y){
    return (x >=0 && x < n && y >=0 && y < m);
}

//초기화 시켜줌
void init(){
    nowCheeze = 0; // 지금 현재 cheeze가 몇개 있는지
    memset(visited, 0, sizeof(visited)); // 다시 방문했는지 초기화
}

// 치즈있는지 확인하기
void dfs(int x, int y){
    visited[x][y]++;

    int nX;
    int nY;

    for(int k = 0 ; k < 4 ; k++){
        nX = x + dx[k];
        nY = y + dy[k];
        if(isVailed(nX, nY) && visited[nX][nY] == 0 && cheeze[nX][nY] == 0 )
            dfs(nX, nY);    
    }
}


void melt(){
    // 테두리는 어짜피 cheeze가 아님
    int nx, ny;

    //치즈 주변에 공기가 있으면(visited == 1)이면 녹아야한다. 
    for (int i = 1; i < n - 1; i++){ 
        for (int j = 1; j < m - 1; j++){ 
            int count = 0;
            for(int k = 0 ; k < 4 ; k++){
                nx = i + dx[k];
                ny = j + dy[k];
                if(visited[nx][ny] == 1){
                    if(cheeze[i][j] == 1){
                        count++;
                        if(count == 2){
                            cheeze[i][j] = 0;
                            nowCheeze++;
                            break; // 녹았는데 굳이 다른 방향에 공기가 있는지 확인을 안해도 된다.
                        }
                    }
                }
            }
        }
    }
}

int main(){
    cin >> n >> m;

    //cheeze입력
    for(int i = 0 ; i < n ; i++)
        for(int j = 0 ; j < m ; j++)
            cin >> cheeze[i][j];
        
    int time = 0;

    while(1){


        init(); // 지금 치즈가 몇개인지 visted(공기 인지 확인) = false로 초기화
        dfs(0,0); // 공기인 부분은 visited = true로 만듬
        
        // for(int i = 0 ; i < n ; i++){
        //     for(int j = 0 ; j < m ; j++){
        //         cout << visited[i][j] << " ";
        //     }
        //     cout << "\n";
        // }

        melt(); // 공기인 부분이 있으면 그 부분을 cheeze라고 생각하고 녹임

        if(nowCheeze == 0) break; // 지금 cheeze가 없다면 while문 탈출

        time++; // 한타임 돔
        preCheeze = nowCheeze; // 이전 cheeze로 취급
    }



    cout << time << "\n";

    return 0; 
}
