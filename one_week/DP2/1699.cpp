#include <iostream>
#include <cmath>
#define MAX 100001

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int dp[MAX];

    int n;
    cin >> n ;

    dp[0] = 0;
    for(int i = 1 ; i<= n ; i++){

        dp[i] = i;
        for(int j =1 ; j*j <= i ;j++){
            dp[i] = min(dp[i] , dp[i-j*j]+1);
        }
    }

    cout << dp[n] << '\n';
    return 0;
}