#include <iostream>
#include <vector>
#define MAX 8

using namespace std;

int N;
int arr[MAX];
bool check[MAX];
int ans = 0;
vector<int> V;

void Calculate(){
    int sum = 0;
    for(int i = 0 ; i < V.size() - 1; i++){
        sum = sum + abs(V[i] - V[i+1]);
    }
    ans = max(ans,sum);
}

void DFS(int n){
    if(n == N){
        Calculate();
        return; 
    }    
    // 체크하고 DFS로 하면 차근차근 체크되고 다 되었을 때 제자리로 돌려놓는다.
    for(int i = 0; i<N; i++){
        if(check[i] == true) 
            continue;
        check[i] = true;
        V.push_back(arr[i]);
        DFS(n+1);
        check[i] = false;
        V.pop_back();
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin.tie(NULL);

    cin >> N;

    for(int i = 0 ; i < N; i++){
        cin >> arr[i];
    }

    DFS(0);

    cout << ans << '\n';

    return 0;
}