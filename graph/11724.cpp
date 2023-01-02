#include <iostream>
#include <string>
#include <queue>
#define MAX 10001

using namespace std;

int N, M;
bool visted[MAX];
bool map[MAX][MAX]; //인접행렬
queue <int> q;

void reset();
void DFS(int v);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    reset();

    int a,b;
    for(int i = 0; i < M ; i++){
        cin >> a >> b; 
        map[a][b] = true; map[b][a] = true;
    }

    int sum = 0;
    for(int i = 1; i <= N; i++){
        if(visted[i] == false){
            sum++;
            DFS(i);
        }
    }
    cout << sum << "\n";
}


void reset(){
    for(int i = 0 ; i < MAX; i++)
        visted[i] = false;
}

void DFS(int v){
    visted[v] = true;

    for(int i = 1; i <= N; i++){
        if(visted[i] == false && map[v][i] == true )
            DFS(i);
    }
}