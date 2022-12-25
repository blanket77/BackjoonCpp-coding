#include <iostream>
#define MAX 91
using namespace std;


int main()
{
    long long dp[MAX][2] = {0, } ;
    int num;
    cin >> num;

    dp[1][0] = 0;
    dp[1][1] = 1;
    for(int i = 2; i<=num; i++){
        dp[i][0] = dp[i-1][0] + dp[i-1][1];
        dp[i][1] = dp[i-1][0];
    }
    
    long long result = dp[num][0] + dp[num][1];
    cout << result << "\n";
    return 0;
}
