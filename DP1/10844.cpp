#include <iostream>
#define mod 1000000000

using namespace std;

int main()
{

    int dp[101][10] = {0,};
    int num;
    cin >> num;

    for(int j = 1; j<=9; j++){
        dp[1][j] =1;    
    }
    
    for(int i = 2; i<=num; i++){
        for(int j = 0; j<=9; j++){
            if(j==0)
                dp[i][j] = dp[i-1][j+1] % mod;
            else if(j==9)
                dp[i][j] = dp[i-1][j-1] % mod;
            else
                dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1]) % mod;    
        }
    }

    int sum = 0;
    for(int j = 0; j <= 9 ;j++){
        sum = (sum + dp[num][j]) % mod;  
    }

    cout << sum << "\n";

    return 0;
}