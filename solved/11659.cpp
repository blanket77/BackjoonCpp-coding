#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N,M , i, j;
    cin >> N >> M;

    vector <int> dp(N+1);
    dp[0] = 0;


    int a;
    for(int k = 1 ; k <= N ; k++){
        cin >> a;
        dp[k] = dp[k-1] + a;
    }

    for(int k = 0 ; k < M ; k++){

        cin >> i >> j;
        cout << dp[j] - dp[i - 1] << '\n';
    }

    return 0;
}