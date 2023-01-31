#include <iostream>
#include <algorithm>
#define MAX 15

using namespace std;
int L, C;
char arr[MAX];
char result[MAX];
bool visited[MAX];

bool checks(){
    int cnt = 0;

    for(int i = 0 ; i < L ; i++){
        if(result[i] == 'a'|| result[i] == 'e'|| result[i] == 'i'
            || result[i] == 'o'|| result[i] == 'u'){ 
            cnt++;
        }
    }
    if(cnt >= 1 && L - cnt >= 2)
        return true;
    return false;
}

void DFS(int idx, int start){
    if(idx == L){
        if(checks()){
            for(int i = 0 ; i < L ; i++){
                cout << result[i];
            }
            cout << '\n';
        }
        return;
    }
    
    for(int i = start ; i < C ; i++){
        if(!visited[i]){
            visited[i] = true;
            result[idx] = arr[i]; 
            DFS(idx+1, i+1);

            visited[i] = false;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> L >> C;

    for(int i = 0 ; i < C ; i++){
        cin >> arr[i];
    }        

    sort(arr, arr + C);
    DFS(0,0);

    return 0;
}