#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N,K,L;
int bam[101][101] = {0,};
int apple[101][101] = {0,};

bool is_game_over(int y, int x){
    if(y <= 0 || y > N || x <= 0 || x > N || bam[y][x] == 1){
        return true;
    }
    return false;
}

int main(){
    ios::sync_with_stdio(0);  
    cin.tie(0);

    cin >> N;
    cin >> K;

    for(int i = 0; i < K; i++){
        int y,x;
        cin >> y >> x;
        apple[y][x] = 1;
    }

    cin  >> L;
    queue <pair<int,char>> info;
    for(int i = 0; i < L; i++){
        int x;
        char c;
        cin >> x >> c;
        info.push({x,c});
    }

    int time = 0;
    int dir = 0; // 0: 오른쪽(0,1), 1: 아래(1,0), 2: 왼쪽(-1,0), 3: 위(-1,0)
    // 3 => 2 , 3 => 0   , 이렇게 하면 L은 -1, R은 +1
    // 2 => 1 , 2 => 3
    // 1 => 0 , 1 => 2
    // 0 => 3 , 0 => 1
    
    pair<int,int> head = {1,1};
    queue<pair<int,int>> snake;

    snake.push(head);
    bam[1][1] = 1;

    while(true){
        time++;  

        if(dir == 0)
            head.second++;
        else if(dir == 1)
            head.first++;
        else if(dir == 2)
            head.second--;
        else if(dir == 3)
            head.first--;

        if(is_game_over(head.first,head.second)){
            break;
        }

        snake.push(head);
        bam[head.first][head.second] = 1;

        if(apple[head.first][head.second] == 0){
            pair<int,int> tail = snake.front();
            snake.pop();
            bam[tail.first][tail.second] = 0;
        } 
        else{
            apple[head.first][head.second] = 0;
        }

        // 끝난뒤 방향 바꾸기
        if(info.front().first == time){
            
            if(info.front().second == 'L'){
                dir = (dir + 4 - 1) % 4;
            }else{
                dir = (dir + 4 + 1) % 4;
            }
            info.pop();
        }

        // cout << "time : " << time << endl;  
        // cout << "bam" << endl;

        // for(int i = 1; i <= N; i++){
        //     for(int j = 1; j <= N; j++){
        //         cout << bam[i][j] << " ";
        //     }
        //     cout << endl;
        // }

        // cout << "apple" << endl;
        // for(int i = 1; i <= N; i++){
        //     for(int j = 1; j <= N; j++){
        //         cout << apple[i][j] << " ";
        //     }
        //     cout << endl;
        // }
    }


    cout << time;
    return 0;
}
