#include <iostream>
#define MAX 10001   

using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // freopen("input.txt", "r", stdin);
    int N,M;
    int arr[MAX];    
    cin >> N >> M;

    for(int i = 0 ; i < N; i++){
        cin >> arr[i];
    }

    int Start = 0, End = 0;
    int sum = 0;
    int cnt=0;

    while(Start <= End && End <= N){
        if(sum == M){
            cnt++;
        }
        if(sum >= M || End == N){
            sum -= arr[Start];
            Start++;
        }
        else if(sum < M ){
            sum += arr[End];
            End++;
        }
    }

    cout << cnt << '\n';
    return 0;
}