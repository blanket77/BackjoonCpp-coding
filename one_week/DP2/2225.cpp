#include<iostream>
#define MAX 201
#define mod 1000000000

using namespace std;

long long dp[MAX][MAX] = {0, };

//y개를 더해 x값이 나오는 경우
long long sol(int N, int K){

    if(K == 0)
        return 0;
    if(K == 1)
        return 1;

    if(dp[N][K] > 0){   //해당 문제의 답이 있으면
        return dp[N][K];
    }

    for(int i = 0 ; i <= N; i++){
        dp[N][K] += sol(i , K-1);
        dp[N][K] %= mod;
    }
    return dp[N][K];
}

int main(){

    int N,K;
    cin >> N >> K;

    long long result = sol(N, K);
    cout << result << '\n';

    return 0;
}
