#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    for(int k=0; k<n; k++)
    {
        int num;
        cin >> num;
        vector<int> dp( num +1);

        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 4;
        for(int i = 4 ; i <= num ; i++)
        {
            dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
        }

        cout << dp[num] << "\n";
    }
    return 0;
}