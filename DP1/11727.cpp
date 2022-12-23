#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int num;
    cin >> num;
    vector<int> dp( num +1);

    dp[1] = 1;
    dp[2] = 3;
    for(int i = 3 ; i <= num ; i++)
    {
        dp[i] = dp[i-1] + 2*dp[i-2];
        dp[i] %= 10007;
    }

    cout << dp[num]%10007;
    return 0;
}