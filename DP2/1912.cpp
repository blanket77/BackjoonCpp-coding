#include <iostream>
#define MAX 100001

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    int arr[MAX];
    int dp[MAX] = {0, };

    for(int i = 1 ; i <= n ; i++){
        cin >> arr[i];
    }

    int result = arr[1];    
    dp[1] =  arr[1];
    for(int i = 2 ; i <= n ; i++){
        dp[i] = max(arr[i], dp[i-1] + arr[i]);

        result = max(result, dp[i]);
    }

    cout << result << '\n';
    return 0;
}