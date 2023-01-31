#include <iostream>
#define MAX 20

using namespace std;

int N, S;
int arr[MAX];
bool visitied[MAX];
int cnt;

void DFS(int idx, int sum){

    for(int i = idx ; i < N ;i++){
        if(!visitied[i]){
            visitied[i] = true;
            int a = arr[i] + sum;
            // cout << a << ' ' <<arr[i] << '\n';

            if(a == S)
                cnt++;

            DFS(i+1, a);

            visitied[i] = false;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> S;


    for(int i = 0 ; i < N ; i++){
        cin >> arr[i];
    }

    DFS(0,0);
    cout << cnt << '\n';
    return 0;
}