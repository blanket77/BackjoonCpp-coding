#include <iostream>
#include <string>
#include <queue>
#define MAX 10001

using namespace std;

bool map[MAX][MAX]; //인접행렬
bool visted[MAX];
queue <int> q;

void reset();
void DFS(int V, int N);
void BFS(int V, int N);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, V;  // 정점, 간선, 탐색 시작
    cin >> N >> M >> V;

    int a,b;
    for(int i = 0; i < M ; i++){
        cin >> a >> b; 
        map[a][b] = true; map[b][a] = true;
    }
    reset();
    DFS(V, N);
    cout << "\n";
    
    reset();
    BFS(V, N);
    cout << "\n";
    
    return 0;
}

void reset(){
    for(int i = 0 ; i < MAX; i++)
        visted[i] = false;
}

void DFS(int V, int N){
    visted[V] = true;
    cout << V << " ";
    for(int i = 1 ; i <= N; i++){
        if(visted[i] == false && map[V][i] == true){
            DFS(i, N);
        }
    }
}

void BFS(int V, int N){

    q.push(V);
    visted[V] = true;
    cout << V << " ";

    while(!q.empty()){

        for(int i = 1 ; i <= N; i++){
            if(visted[i] == false && map[q.front()][i] == true){
                q.push(i);
                visted[i] = true;
                cout << i << " " ;
            }
        }
        q.pop();
    }
}