#include<iostream>
using namespace std;

// 0의 개수는 소인수분해시 2와 5의 개수에 따라 결정
// 나는 2와 5의 개수를 구하고 둘 중 작은 수를 구해서 풀었지만
// 모든 숫자는 2와 5의 개수 중 2의 개수가 무조건 많으므로 5의 개수만 구해서도 풀었도 됐다.
// https://luv-n-interest.tistory.com/957
// 이 블로그는 5의 배수를 n/5 + n/25 + n/125로 풀었다.( n이 500까지 이므로)
// https://minyeok2ee.gitlab.io/boj/boj-1676/

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    int twoCount = 0; 
    int fiveCount = 0;

    for(int i = 1; i<=n ; i++){
        int tmp = i;
        while(tmp % 2 == 0){
            twoCount++;
            tmp /= 2;
        } // 이거 굳이 안 써도 풀림
        
        while(tmp % 5 == 0){
            fiveCount++;
            tmp /= 5;
        }
    }
    int result = min(twoCount, fiveCount);
    cout << result <<"\n";

    return 0;
}
