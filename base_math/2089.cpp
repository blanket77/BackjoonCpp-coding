#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    string result;

    if(!n) 
        result = "0";

    while(n){
        if(!(n % -2)){
            result += "0";
            n /= -2;
        }
        else{
            result += "1";
            n = (n - 1) / -2;  // 핵심!! -13을 -2로 나누면서 구해보면 알 수 있다. 참고로 c++ 컴파일러는 -5를 나눌 때 버림을 쓴다.
        }
    }

    reverse(result.begin(), result.end());
    cout << result << "\n";

    return 0;
}