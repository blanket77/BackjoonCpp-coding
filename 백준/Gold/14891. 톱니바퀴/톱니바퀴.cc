#include <iostream>
#include <vector>
#include <queue>

using namespace std;


int wheel[4][8];
int check[4] = {0, };

// 톱니바퀴의 12시 방향은 0
// 첫번째 1점, 두번째 2점, 세번째 4점, 네번째 8점
int get_score(){
    int score = 0;
    for(int i=0; i<4; i++){
        if(wheel[i][0] == 1){
            score += 1 << i;
        }
    }
    return score;
}

// num : 0 ~ 3
// dir : 1 (시계), -1 (반시계)
void simulate(int num, int dir){
    check[num] = dir;

    // 왼쪽
    for(int i=num-1; i>=0; i--){
        // 기준 != 기준 왼쪽
        if(wheel[i+1][6] != wheel[i][2]){
            check[i] = -check[i+1];
        }else{
            break;
        }
    }
    
    // 오른쪽
    for(int i=num+1; i<4; i++){
        // 기준 != 기준 오른쪽
        if(wheel[i-1][2] != wheel[i][6] ){
            check[i] = -check[i-1];
        }else{
            break;
        }
    }

    for(int i=0; i<4; i++){
        if(check[i] == 1){
            int temp = wheel[i][7];
            for(int j=7; j>0; j--){
                wheel[i][j] = wheel[i][j-1];
            }
            wheel[i][0] = temp;
        }else if(check[i] == -1){
            int temp = wheel[i][0];
            for(int j=0; j<7; j++){
                wheel[i][j] = wheel[i][j+1];
            }
            wheel[i][7] = temp;
        }
    }

}

int main(){
    ios::sync_with_stdio(0);  
    cin.tie(0);

    string str;

    for(int i=0; i<4; i++){
        cin >> str;
        for(int j=0; j<8; j++){
            wheel[i][j] = str[j] - '0';
        }
    }

    int N;
    int num, dir;
    
    cin >> N;
    for(int i = 0; i < N ; i++){
        cin >> num >> dir;

        fill(check, check+4, 0);
        simulate(num-1, dir);
    }

    int result = get_score();

    cout << result << "\n";

    return 0;
}
