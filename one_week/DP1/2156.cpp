#include <iostream>
#define MAX 10001

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    int arr[MAX];
    int dp[MAX];

    for(int i = 1 ; i <= n ; i++){
        cin >> arr[i];
    }

    dp[0] = arr[0] = 0;
    dp[1] = arr[1];
    dp[2] = arr[1] + arr[2];

    for(int i = 3; i <=n ; i++){
        dp[i] = max(dp[i-3] + arr[i-1] + arr[i], max(dp[i-2] + arr[i], dp[i-1]));
    }
    
    cout << dp[n] << '\n';
    return 0;
}