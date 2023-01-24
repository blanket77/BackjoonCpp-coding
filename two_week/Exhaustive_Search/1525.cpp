#include <iostream>
#include <queue>
#include <set>

using namespace std;

int dx[4] = {0, 0, 1 ,-1};
int dy[4] = {1, -1, 0 ,0};

string Start, End = "123456780";
set<string> Visited;

void bfs(){
    queue<pair<string, int>> Q;
    Q.push(make_pair(Start,0));
    Visited.insert(Start);

    while(!Q.empty()){
        string Cur = Q.front().first;
        int Cnt = Q.front().second;
        Q.pop();

        if(Cur == End){
            cout << Cnt  << '\n';
            return;
        }

        int Zero_index = Cur.find('0');
        int y = Zero_index / 3;
        int x = Zero_index % 3;
        //[y][x]로 표현 y*3+x = Zero_index 

        for(int i = 0 ; i < 4 ; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if ( nx >= 0 && ny >= 0 && nx < 3 && ny < 3 ){
                string Next = Cur;
                swap(Next[y * 3 + x], Next[ny * 3 + nx]); // x*3+y == Zero_index

                //찾지 못한다면 Visited.end()를 반환, 아니면 index를 반환한다.
                if(Visited.find(Next) == Visited.end()){
                    Visited.insert(Next);
                    Q.push(make_pair(Next, Cnt + 1));
                }
            }
        }
    }
    cout << -1 << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    // freopen("input.txt", "r", stdin);

    for(int i = 0 ; i < 3; i++){
        for(int j = 0 ; j < 3 ; j++){
            int a; cin >>a;
            char Tmp = a + '0';
            Start = Start + Tmp;
        }
    }

    bfs();
    return 0;
}