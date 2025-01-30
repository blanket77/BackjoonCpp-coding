#include <iostream>
#define Up 0
#define RIGHT 1
#define Down 2
#define LEFT 3
#define MAX_N 50
using namespace std;

int N,M;
int pos_x,pos_y;
int dir;
int map[MAX_N][MAX_N] = {1,};
int clean_num = 0;

void go_clean(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int dx[4] = {-1,0,1,0}; // UP RIGHT DOWN LEFT
    int dy[4] = {0,1,0,-1}; // UP RIGHT DOWN LEFT

    while(1){
        bool flag = false;

        if(map[pos_x][pos_y] == 0){
            map[pos_x][pos_y] = 2;
            clean_num++;
        }

        for(int i=0;i<4;i++){
            int n_x = pos_x + dx[i];
            int n_y = pos_y + dy[i];
            
            //근처 4방향 중 청소할 공간이 있으면
            if(map[n_x][n_y] == 0){
                while(true){
                    dir = (dir-1+4)%4; // 반시계 방향으로 회전
                    n_x = pos_x + dx[dir];
                    n_y = pos_y + dy[dir];

                    if(map[n_x][n_y] == 0){
                        pos_x = n_x;
                        pos_y = n_y;
                        break;
                    }
                }
                flag = true;
                break;
            }
        }

        //네 방향 모두 청소가 되어있거나 벽인 경우
        if(!flag){
            int n_x = pos_x - dx[dir];
            int n_y = pos_y - dy[dir];

            if(map[n_x][n_y] == 1){
                break;
            }else{
                pos_x = n_x;
                pos_y = n_y;
            }
        }

    }
}

int main(){
    cin >> N >> M;
    cin >> pos_x >> pos_y >> dir;
    
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin >> map[i][j];
        }
    }

    go_clean();

    cout << clean_num << endl;

    return 0;
}