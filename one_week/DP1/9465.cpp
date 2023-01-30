#include <iostream>
#define MAX 100001

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    for(int t = 0 ; t < T ; t++){
        int n;
        cin >> n;

        int arr[MAX][2];
        int dp[MAX][2];   // 여기까지 최대 합

        for(int i = 1 ; i <= n ; i++){
            cin >> arr[i][0]; 
        }

        for(int i = 1 ; i <= n ; i++){
            cin >> arr[i][1]; 
        }

        dp[0][0] = 0 ; dp[0][1] = 0 ;
        dp[1][0] = arr[1][0];   dp[1][1] = arr[1][1];

        for(int i = 2 ; i <= n ; i++ ){
            dp[i][0] = max( dp[i-1][1] , dp[i-2][1] ) + arr[i][0];
            dp[i][1] = max( dp[i-1][0] , dp[i-2][0] ) + arr[i][1];
        }
        cout << max(dp[n][0], dp[n][1]) <<'\n';

    }
    return 0;
}