#include <iostream>
#include <vector>
#define MAX 100001

using namespace std;

//이차원 배열 [MAX][MAX]을 쓰면 컴파일에러가 생김
vector<int> v[MAX];
bool visited[MAX] = {false, };
int parents[MAX];
int N;

void DFS(int x){
    visited[x] = true;

    for(int i = 0 ; i < v[x].size() ; i++){
        int next = v[x][i];
        if(visited[next] == false){
            parents[next] = x;
            DFS(next);
        }
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    int a,b;
    for(int i = 0 ; i < N - 1 ; i++){
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    DFS(1);

    for(int i = 2 ; i <= N; i++){
        cout << parents[i] << '\n';
    }

    return 0;
}