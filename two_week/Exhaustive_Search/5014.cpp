#include <iostream>
#include <queue>
#define MAX 1000001

using namespace std;

int F,S,G,U,D;
bool visited[MAX];

void BFS(int S){
    queue <pair<int, int>> q ;
    q.push(make_pair(S, 0));
    visited[S]= true;

    while(!q.empty()){
        int point = q.front().first;
        int cnt = q.front().second;
        q.pop();

        if(point == G){
            cout << cnt << '\n';
            return;
        }

        int up = point + U;
        if(up <= F){
            if(visited[up] == false){
                visited[up] = true;
                q.push(make_pair(up, cnt+1));
            }
        }

        int down = point - D;
        if(down >= 0){
            if(visited[down] == false){
                visited[down] = true;
                q.push(make_pair(down, cnt+1));
            }
        }
    }
    cout << "use the stairs" << '\n' ;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
//   freopen("input.txt", "r", stdin);
    cin >> F >> S >> G >> U >> D;
    visited[0] = true;
    BFS(S);

    return 0;
}