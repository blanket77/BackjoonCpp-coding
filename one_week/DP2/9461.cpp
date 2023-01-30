#include<iostream>
#define MAX 101

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long dp[MAX];

    dp[1] = 1; dp[2] = 1; dp[3] = 1; dp[4] = 2; dp[5] = 2;
    
    for(int i = 6 ; i < MAX ; i++){
        dp[i] = dp[i-1] + dp[i - 5];
    }

    int num;
    cin >> num;

    for(int i = 0 ; i < num ; i++){
        int N;
        cin >> N;

        cout << dp[N] << '\n';

    }

    return 0;
}