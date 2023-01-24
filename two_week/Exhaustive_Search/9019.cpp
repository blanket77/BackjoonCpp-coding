#include <iostream>
#include <queue>
#define MAX 10000

using namespace std;

bool visited[MAX];
int Start, End;

void initial(){
    for(int i = 0 ; i < MAX ; i++){
        visited[i] = false;
    }
}

void sol(){
    queue<pair<int, string>> Q;
    Q.push(make_pair(Start, ""));
    visited[Start] = true;

    while(!Q.empty()){
        int cur_num = Q.front().first;
        string cur_op = Q.front().second;
        Q.pop();

        if(cur_num == End){
            cout << cur_op << '\n';
            return ;
        }

        int D = (cur_num*2)%10000;
        if(!visited[D]){
            visited[D] = true;
            Q.push(make_pair(D,cur_op + "D"));
        }
    
        int S = (cur_num -1);
        if(S < 0) 
            S = 9999;
        if(!visited[S]){
            visited[S] = true;
            Q.push(make_pair(S, cur_op + "S"));
        }
    
        int L = (cur_num % 1000) * 10 + cur_num /1000 ;
        if(!visited[L]){
            visited[L] = true;
            Q.push(make_pair(L, cur_op + "L"));
        }

        int R = (cur_num % 10) * 1000 + cur_num / 10;
        if(!visited[R]){
            visited[R] = true;
            Q.push(make_pair(R, cur_op + "R"));
        }

    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // freopen("input.txt", "r", stdin);

    int TC;
    cin >> TC;
    for(int i = 0; i < TC ; i++){
        cin >> Start >> End;
        initial();
        sol();
    }
    return 0;
}