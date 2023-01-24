#include <iostream>
#include <queue>
#include <string>
#define MAX 10000

using namespace std;

int Start, End;
bool password_prime[MAX]; 
bool visited[MAX];

// 에라토스테네스 체로 소수구해놈
void prime_and_initialize(){
    for(int i = 0; i < MAX; i++){
        password_prime[i] = true;
        visited[i] = false; 
    } //초기화

    for(int i = 2 ; i < MAX; i++ ){
        for(int j = 2; i * j < MAX ; j++)
        password_prime[i*j] = false;
    }
}

//최단 거리
void sol(){
    queue<pair<int,int>> Q;
    Q.push(make_pair(Start,0));
    visited[Start] = true;

    while(!Q.empty()){
        int Cur_Num = Q.front().first;
        int Cnt = Q.front().second;
        Q.pop();

        if(Cur_Num == End){
            cout << Cnt << '\n';
            return;
        }

        int Next_Num;
        for (int i = 0 ;  i < 4 ; i++){
            for (int j = 0; j < 10; j++){
                string s = to_string(Cur_Num);
                s[i] = j + '0';
                Next_Num = stoi(s);

                if(password_prime[Next_Num] == false) continue;
                if(visited[Next_Num] == true) continue;
                if(Next_Num >= 10000 || Next_Num < 1000) continue;

                visited[Next_Num] = true;
                Q.push(make_pair(Next_Num, Cnt + 1)); 
            }
        }
    }
    cout << "Impossible" << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // freopen("Input.txt", "r", stdin);
    int TC;
    cin >> TC;
    
    for(int i = 0 ; i< TC; i++){
        prime_and_initialize(); 
        cin >> Start >> End;
        sol();
    }


    return 0;
}