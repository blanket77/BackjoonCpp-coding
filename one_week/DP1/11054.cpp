#include <iostream>
#define MAX 1001

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int arr[MAX];
    int ldp[MAX];  // 왼쪽 수열 최대 길이
    int rdp[MAX]; // 오른쪽 수열 최대 길이

    int N;
    cin >> N;

    for(int i = 1 ; i <= N; i++){
        cin >> arr[i];
    }

    int result = -1;
    for(int i = 1 ; i <=N; i++){
        ldp[i] = 1;

        for(int j = 1 ; j <= i - 1 ; j++ ){
            if(arr[j] < arr[i])
                ldp[i] = max(ldp[i], ldp[j] + 1);
        }
        ldp[i] = max(ldp[i], result);
    }

    result = -1;

    for(int i = N ; i >= 1; i--){
        rdp[i] = 1;

        for(int j = N ; j >= i + 1 ; j-- ){
            if(arr[i] > arr[j])
                rdp[i] = max(rdp[i], rdp[j] + 1);
        }
    }

    for(int i = 1 ; i <= N; i++){
        result = max(ldp[i] + rdp[i] - 1 ,result);
    }
    cout << result << '\n';
    return 0;
}