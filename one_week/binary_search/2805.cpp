#include <iostream>
#define MAX 1000000

using namespace std;

long long N, M;
long long list[MAX];
long long l_max = 0;
long long ans = 0;

void sol(){
    int left = 1;
    int right = l_max;
    long long mid;

    // 1. left와 right의 중간값인 mid를 구한다.
    // 2. list[]의 차를 구해서 sum에 다 더한다.. 만약 음수면 더하지 않는다.
    // 3. 만약 sum 값이 M보다 같거나 크면, mid값(자르는 높이)이 더 커야한다. 따라서 left = mid +1, 최대 ans를 저장
    // 4. 그렇지 않으면 mid값이 더 작아야하므로 right = mid - 1
    // 5. left <= right이면 반복한다.  
    while(left <= right){
        mid = (left + right) / 2;

        long long sum = 0; 
        int tmp;

        for(int i = 0 ; i < N ; i++){
            tmp = list[i] - mid;
            if(tmp > 0)
                sum += tmp; 
        }

        if(sum >= M){
            left = mid + 1;
            ans = max(mid, ans);
        }
        
        else{
            right = mid - 1;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for(int i = 0 ; i < N ; i++){
        cin >> list[i];
        l_max= max(l_max, list[i]);
    }

    sol();

    cout << ans << '\n';
    return 0;
}