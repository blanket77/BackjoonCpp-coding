#include <iostream>
#include <algorithm>
#define MAX 1001

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    int result = 0;
    int arr[MAX];
    int dp[MAX];

    for(int i = 1 ; i <= N ; i++){
        cin >> arr[i];
    }

        for(int i = 1 ; i <= N; i++){
        dp[i] = arr[i];

        for(int j = 1 ; j <= i-1 ; j++){
            if(arr[i] > arr[j]){ //어떤 위치보다 값이 작은 것 중에서 
                dp[i] = max(dp[i], dp[j] + arr[i]);
            }
        }
        result = max(dp[i], result);
    }

    cout << result  << '\n';
    return 0;
}