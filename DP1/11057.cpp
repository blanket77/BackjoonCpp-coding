#include <iostream>
#define mod 10007
using namespace std;

int main()
{
    int dp[1001][10] = {0, } ;
    int num;
    cin >> num;

    for(int j = 0; j<=9; j++){
        dp[1][j] =1;    
    }
    
    for(int i = 2; i<=num; i++){
        for(int j = 0; j<=9; j++){
            for(int k = 0; k<=j; k++)
            {
                dp[i][j] = (dp[i][j]+(dp[i-1][k])) % mod; 
            }
        }
    }

    int sum = 0;
    for(int j = 0; j <= 9 ;j++){
        sum = (sum + dp[num][j]) ;  
    }
    sum = sum % mod;

    cout << sum  << "\n";

    return 0;
}