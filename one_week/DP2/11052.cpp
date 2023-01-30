#include <iostream>
#define MAX 1001

using namespace std;

int N;
int arr[MAX];
int dp[MAX];

void PS(){
    dp[0] = 0;
    dp[1] = arr[1];

    for(int i = 2 ; i <= N ; i++){
        for(int j = 1 ; j <= i  ; j++){
            dp[i] = max(arr[j] + dp[i - j], dp[i]);
        }
    }
}

int main(){

    cin >> N;

    for(int i = 1 ; i <= N; i++){
        cin >> arr[i];
    }

    PS();

    cout << dp[N] << '\n';

    return 0;
}