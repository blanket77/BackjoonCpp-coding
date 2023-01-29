#include <iostream>
#define MAX 500

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;

    cin >> n;

    int arr[MAX][MAX];
    int dp[MAX][MAX];

    for(int i = 0 ; i < n ; i++){
        for(int j = 0; j <= i; j++){
            cin >> arr[i][j];
        }
    }

    dp[0][0] = arr[0][0];
    for(int i = 1 ; i < n ; i++){
        for(int j = 0; j <= i; j++){
            if(j == 0)
                dp[i][j] = dp[i-1][j] + arr[i][j];
            else if(j == i)
                dp[i][j] = dp[i-1][j-1] + arr[i][j];
            else
                dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + arr[i][j];
        }
    }

    // for(int i = 0 ; i < n ; i++){
    //     for(int j = 0; j <= i; j++){
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    int result = 0;
    int s = n - 1;
    for(int i = 0 ; i < n; i++){
        result = max(dp[s][i],result);
    }

    cout << result <<'\n'; 
    return 0;
}