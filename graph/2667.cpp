#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


bool map[27][27] = {false, };
bool visted[27][27] = {false, }; 
int cnt = 0;

void dfs_(int nx, int ny);

void dfs(int x, int y){
    
    //상 검색
    int nx = x-1; int ny = y;
    dfs_(nx, ny);

    //하 검색 
    nx = x+1; ny = y;
    dfs_(nx, ny);

    //좌 검색
    nx = x; ny = y-1;
    dfs_(nx, ny);

    //우 검색
    nx = x; ny = y+1;
    dfs_(nx, ny);
}

void dfs_(int nx, int ny){
    if(visted[nx][ny] == false && map[nx][ny] == 1){
        cnt++;
        visted[nx][ny] = true;
        dfs(nx, ny);
    }
}

int main(){
    
    vector<int> vec;
    int n;
    cin >> n;

    for(int i = 1 ; i <= n; i++){
        for(int j = 1 ; j <= n; j++){
            scanf("%1d", &map[i][j]);
        }
    }
    
    for(int i = 1 ; i <= n; i++){
        for(int j = 1 ; j <= n; j++){
            if(visted[i][j] == false && map[i][j] == 1){
                visted[i][j] = true;
                cnt++;
                dfs(i, j);
                vec.push_back(cnt);
                cnt = 0;
            }
        }
    }

    sort(vec.begin(), vec.end());
    cout << vec.size() << "\n";
    for(int ele : vec){
        cout << ele << "\n";
    }

    return 0;
}