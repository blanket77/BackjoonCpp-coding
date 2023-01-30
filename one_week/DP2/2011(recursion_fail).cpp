#include <iostream>
#include <string>
#define MAX 5001
#define MOD 1000000

using namespace std;

int dp[MAX] = {0, };
string tmp;
string str;

int codes(int n){
    if(str[1] == '0'){
        cout << '0' << '\n';
        exit(0);
    }

    if(dp[n] > 0 )
        return dp[n];
    
    int s;
    if(str[n-1] == '1' ||  (str[n-1] == '2' && str[n] >= '0' && str[n] <= '6')  ){
        dp[n] = codes(n-2) + codes(n-1);        
        dp[n] %= MOD;
    }
    else{
        dp[n] = codes(n-1);
        dp[n] %= MOD;
    }

    return dp[n];
}

int main(){

    cin >> tmp;
    str = "0";
    str = str.append(tmp);
    dp[0] = 1;

    int size =  str.length();
    codes(size - 1 );
    cout << dp[size -1 ] << '\n';
    return 0;
}