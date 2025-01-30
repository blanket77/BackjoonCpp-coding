#include <iostream>
#define MAX_N 500000
using namespace std;

// 불필요한 전역 N 제거
// int N; // <- 제거

long long dp[MAX_N];

int main() {
    int N;
    cin >> N;

    int i = 0;
    for (; i < 10; i++) {
        dp[i] = i;
        if (i == N) {
            cout << dp[i] << "\n";
            return 0;
        }
    }

    int rem = 1;
    while (rem < i) {
        long long num = dp[rem];
        int last = num % 10;

        for (int j = 0; j < 10; j++) {
            if (j < last) {
                dp[i] = num * 10 + j;
                if (i == N) {
                    cout << dp[i] << "\n";
                    return 0;
                }
                i++;
            } else {
                break;
            }
        }
        rem++;
    }

    cout << -1 << "\n";
    return 0;
}
