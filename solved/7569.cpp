#include <iostream>
#include <queue>
#define MAX 100

using namespace std;

struct tomato{
    int y,x,z;
};

int M, N, H;
int days[MAX][MAX][MAX];
int dx[6] = {0,0,-1,1,0,0}; 
int dy[6] = {1,-1,0,0,0,0};
int dz[6] = {0,0,0,0,-1,1};

queue<tomato> q;

void BFS(){
    while(!q.empty()){
        int x = q.front().x;
        int y = q.front().y;
        int z = q.front().z;
        q.pop();

        int nx,ny,nz;
        for(int i = 0 ; i < 6 ; i++){
            nx = x + dx[i];
            ny = y + dy[i];
            nz = z + dz[i];
            
            if(nx >= 0 && ny >= 0 && nz >= 0 && nx < M && ny < N && nz < H){
                if(days[ny][nx][nz] == 0){
                    days[ny][nx][nz] = days[y][x][z] + 1 ;
                    q.push({ny,nx,nz});
                }
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> M >> N >> H; // N은 y값, M은 x값, H는 z값 
    for(int k = 0 ; k < H ; k++){
        for(int i = 0 ; i <N; i++){
            for(int j = 0 ; j < M ; j++){
                cin >> days[i][j][k];
                if(days[i][j][k] == 1)
                    q.push({i,j,k});
            }
        }
    }

    BFS();

    int result = 0;
    for(int i = 0 ; i <N; i++){
        for(int j = 0 ; j < M ; j++){
            for(int k = 0 ; k < H ; k++){
                if(days[i][j][k] == 0){
                    cout << -1 << '\n';
                    return 0;
                }
                result = max(result, days[i][j][k]);
            }
        }
    }

    cout << result - 1 << '\n'; 
    return 0;
}
