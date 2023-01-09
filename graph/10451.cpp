#include <iostream>
#include <string>
#include <vector>
#define MAX 1001

using namespace std;

int N, result = 0; // N은 정점개수, result는 순열 사이클 개수
bool map[MAX][MAX]; //인접행렬
bool visted[MAX];
bool cycle[MAX];

void reset();
void DFS(int V);
void DFS_cyc(int V);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int num;
    cin >> num;

    vector<int> vec;
    for(int i = 0 ; i < num; i++){

        int a;
        cin >> N ;


        vec.erase(vec.begin(), vec.end());
        reset();

        for(int i = 0 ; i < N ; i++){
            cin >> a;
            vec.push_back(a);
        }

        int b;
        for(int i = 0; i < N ; i++){
            b = vec[i];
            map[i+1][b] = true; 
        } // 인접행렬

        for(int i = 1 ; i <= N ; i++){
            DFS(i);
        }

        cout << result <<"\n";
    
    }
    return 0;
}

void reset(){
    for(int i = 1 ; i <= N; i++){
        result = 0;
        visted[i] = false;
        cycle[i] = false;
        for(int j = 1 ; j <= N; j++){
            map[i][j] = false;
        }
    }
}

void DFS(int V){
    visted[V] = true;
    for(int i = 1 ; i <= N; i++){
        if(visted[i] == true && map[V][i] == true && cycle[i] == false){
            result++;
            DFS_cyc(V);
        }
        else if(visted[i] == false && map[V][i] == true && cycle[i] == false){
            DFS(i);
        }
    }
}

void DFS_cyc(int V){
    cycle[V] = true;
    for(int i = 1 ; i <= N; i++){
        if(cycle[i] == false && map[V][i] == true){
            DFS_cyc(i);
        }
    }
}