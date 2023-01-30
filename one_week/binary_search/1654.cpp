#include <iostream>
#define MAX 10000

using namespace std;

unsigned int K, N;
unsigned int list[MAX];
unsigned int l_max = 0;
unsigned int ans = 0;

void sol(){
    unsigned int left = 1;
    unsigned int right = l_max;
    unsigned int mid; 
    // 0. list max(l_max를 구하고 1과 l_max를 더한 다음 나누기 2를 해서 mid로 한다.)
    // 1. mid를 구한다.
    // 2. list[]를 mid로 나누고 합을 찾는다.
    // 3. sum이 N과 같거나 크면 left를 mid + 1로 바꾼다. 그리고 그 값들의 MAX을 계속 찾아낸다.
    // 4. sum이 N보다 작으면 right를 mid - 1로 바꾼다. 
    // 5. left <= right 일 때만 반복한다.

    while(left <= right ){
        unsigned int sum = 0;
        mid = (left + right) / 2;

        for(int i = 0 ; i < K ; i++){
            sum += (list[i] / mid); 
        }

        if(sum >= N ){
            left = mid + 1;
            ans = max(ans, mid);
        }
        else
            right = mid - 1;
     }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> K >> N;

    for(int i = 0 ; i < K ; i++){
        cin >> list[i];
        l_max = max(l_max, list[i]);
    }
    
    sol();

    cout << ans << '\n';
    return 0;        
}