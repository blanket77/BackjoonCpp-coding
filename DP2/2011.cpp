#include <iostream>
#include <string>
#define MAX 5001
#define MOD 1000000

using namespace std;

int dp[MAX] = {0, };
string tmp;
string str;
int LEN;

void codes(){

    dp[0] = 1;

    for(int i = 1; i <= LEN; i++){

        if((str[i-1] == '1' && str[i] >= '1' && str[i] <= '9') ||  (str[i-1] == '2' && str[i] >= '1' && str[i] <= '6')){
            dp[i] = dp[i-2] % MOD  + dp[i-1] % MOD;
            dp[i] %= MOD;
        }
        else if((str[i-1] == '1' && str[i] == '0') ||  (str[i-1] == '2' && str[i] == '0')){
            dp[i] = dp[i-2] %= MOD;
            dp[i] %= MOD;
        }

        else if(str[i] >= '1' && str[i] <= '9' ){
            dp[i] = dp[i-1] % MOD ;
            dp[i] %= MOD;
        }
        else{
            cout << '0' << '\n';
            exit(0);
        }
    }

}

int main(){

    cin >> tmp;
    str = "0";
    str = str.append(tmp);

    LEN =  str.length() - 1 ;

    codes();
    cout << dp[LEN ] << '\n';
    return 0;
}


