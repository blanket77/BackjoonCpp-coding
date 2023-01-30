#include <iostream>
#include <queue>
#define MAX 1000

using namespace std;

int N, M;
int days[MAX][MAX];
queue<pair<int, int>> q; 


int dx[4] = {0, 0 , 1, -1};
int dy[4] = {1, -1, 0, 0}; //상하좌우

void BFS(){

    while(!q.empty()){
        int y = q.front().first; 
        int x = q.front().second;
        q.pop();

        int nx, ny;
        for(int i = 0 ; i < 4 ; i++){
           nx = x + dx[i];
           ny = y + dy[i];

           if(nx >= 0 && ny >= 0 && nx < M && ny < N){
                if(days[ny][nx] == 0){
                    days[ny][nx] = days[y][x]+ 1;
                    q.push(make_pair(ny,nx));
                }
           }
        }  
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> M >> N;

    //N은 y,  M은 x를 의미
    for(int i = 0 ; i < N; i++){
        for(int j = 0 ; j < M; j++){
            cin >> days[i][j]; 
            if(days[i][j] == 1){
                q.push(make_pair(i,j));
            }
        }
    }

    BFS();
    
    int result = 0; 
    for(int i = 0 ; i < N; i++){
        for(int j = 0 ; j < M; j++){
            if(days[i][j] == 0){
                cout << -1 <<'\n';
                return 0;
            }
            result = max(result, days[i][j]);
        }
    }
    
    cout << result - 1 << '\n';
    
    return 0;
}