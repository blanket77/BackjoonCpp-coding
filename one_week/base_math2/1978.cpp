#include<iostream>
#include<string>
#include <algorithm>
using namespace std;

// 소수는 1과 자기 자신으로만 나누어지는 1보다 큰 정수이다. 즉 약수가 2개만 있을 때 이용해 문제를 풀어낼 수 있다.
// https://codesyun.tistory.com/63
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int num;
    cin >> num ;

    int count = 0;

    for(int i = 0 ; i< num; i++){
        int n;
        cin >> n;
        bool sel = true;

        if(n ==1 )
            sel = false;

        for(int j = 2; j < n ; j++){
            if(n % j == 0){
                sel = false;
                break;
            }
        }
        if(sel)
            count++;
    }

    cout << count << "\n";
    return 0;
}