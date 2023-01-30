#include <iostream>
#define MAX 20001

using namespace std;

bool map[MAX][MAX] = {false, };
bool color[MAX][2]; // [0], [1]은 서로서로 다른 색깔을 의미한다.
//false -> [0]을 색칠  true -> [1]을 색칠
bool ch = true; // 이분그래프가 맞다.

int V , E;

void reset(){
    for(int i = 1; i <= V ; i++){
        color[i][0] = false;
        color[i][1] = false;
        for(int j = 1 ; j <= V ; j++){
            map[i][j] = false;
        }
    }
    ch = true;
}

void DFS(int x){

    if(color[x][0] == false && color[x][1] == false){
        color[x][0] = true; 
    }

    for (int next = 1 ; next <= V; next++){
        if(map[x][next] == true) {
            if(color[x][0] == true && color[next][0] == false && color[next][1] == false){
                color[next][1] = true;
                DFS(next);
            }
            else if(color[x][1] == true && color[next][0] == false && color[next][1] == false){
                color[next][0] = true;
                DFS(next);
            }

            else if(color[x][0] == true && color[next][0] == false && color[next][1] == true )  //앞뒤가 서로 다른 색깔이다. 이분그래프이다.
            {}
            else if(color[x][1] == true && color[next][0] == true && color[next][1] == false) //앞뒤가 서로 다른 색깔이다. 이분그래프이다.
            {}

            else if(color[x][0] == true && color[next][0] == true && color[next][1] == false){ //앞뒤가 서로 같은 색깔이다. 이분그래프가 아니다.
                ch = false;
                return;
            }
            else if(color[x][1] == true && color[next][0] == false && color[next][1] == true){//앞뒤가 서로 같은 색깔이다. 이분그래프가 아니다.
                ch = false;
                return;
            }
        }
    }

    // if(color[x][0] == false && color[x][1] == false){
    //     if(check == false){
    //         color[x][0] = true;
    //         check = true;
    //     }
    //     else{
    //         color[x][1] = true;
    //         check = false;
    //     }
    // }
    // else if( (color[x][0] == true && check == false) || (color[x][1] == true && check == true)){
    //     return; // 이분그래프가 맞음
    // }

    // else if( (color[x][0] == true && check == true) || (color[x][1] == true && check == false)){
    //     ch = false;
    //     return;
    // }
    // for(int i = 0 ; i < V; i++){
    //     if(map[x][i] == true ){
    //         DFS(i);
    //     }
    // }

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int K ;
    cin >> K;

    for(int i = 0 ; i < K ; i++){
        cin >> V >> E;
        reset();

        int a, b;
        for(int i = 0 ; i < E ; i++){
            cin >> a >> b;
            map[a][b] = true; map[b][a] = true;
        }

        for(int i = 1 ; i <= V ; i++){
            if(color[i][0] == false && color[i][1] == false)
                DFS(i);
        }

        if(ch == true)
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';    
    }

    return 0;
}