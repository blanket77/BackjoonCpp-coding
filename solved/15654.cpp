#include <iostream>
#include <algorithm>
#define MAX 8

using namespace std;

int arr[MAX];
int result[MAX];
bool visited[MAX];
int N,M;

void func(int idx){
    if(idx == M){
        for(int i = 0 ; i < M ; i++){
            cout << result[i] << ' ';
        }
        cout << '\n';
        return;
    } 

    for(int i = 0; i < N; i++){
        if(!visited[i]){
            visited[i] = true;
            result[idx] = arr[i];
            func(idx + 1);

            visited[i] = false;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for(int i = 0 ; i < N; i++){
        cin >> arr[i];
    }

    sort(arr, arr + N);
    func(0);

    return 0;
}


