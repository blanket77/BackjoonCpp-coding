#include <iostream>

using namespace std;



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin.tie(NULL);

    int N, M, K;
    // N + M 총 학생수
    // N + M - K 대회 참가 K 인턴 참가
    // min(N/2 , M) -> min(N/2 - a, M - b)   K를 나눈다. a = 0 ~ K
    // a + b = k , b = k - a;  a= i 라고 생각하자.
    // 이 때 result = max(result, min())값을 계속 저장한다.
    cin >> N >> M >> K;

    int result = 0;

    for(int i = 0 ; i <= K ; i++){
        int woman = (N - i) / 2;
        int man = M - (K - i);
        if(woman >= 0 && man >= 0)
            result = max(result, min(woman, man));
    }

    cout << result << '\n';

    return 0;
}