#include <iostream>
#include <vector>
#define MAX 20001

using namespace std;

vector <int> map[MAX];
bool color[MAX][2]; // [0], [1]은 서로서로 다른 색깔을 의미한다.
//false -> [0]을 색칠  true -> [1]을 색칠
bool ch = true; // 이분그래프가 맞다.

//난 공간을 최대한 적게 쓰기 위해 color bool함수로 받았다. 하지만 가독성을 위해서는 int형으로 바꾸고 
//코딩하면 코딩도 수월해진다. 색칠을 안했다는 것을 visited[0] = 0 으로 표현하고 1, 2를 RED, BLUE로 표현하면 되니깐
// https://jdselectron.tistory.com/51 (여기서 그렇게 했고 BFS로도 구현했다.)
int V , E;

void reset(){
    for(int i = 1; i <= V ; i++){
        color[i][0] = false;
        color[i][1] = false;
        map[i].clear();
    }
    ch = true;
}

void DFS(int x){

    if(color[x][0] == false && color[x][1] == false){
        color[x][0] = true; 
    }

    for (int i = 0; i < map[x].size(); i++){
        int next = map[x][i];
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
            map[a].push_back(b);
            map[b].push_back(a);
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