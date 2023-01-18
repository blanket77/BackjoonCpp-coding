#include <iostream>
#include <algorithm>
#define MAX 200000

using namespace std;

long long arr[MAX];
int anw = -1;
int N, C;

void sol(){
    int start = arr[0]; int end = arr[N-1];

    while (start <= end){
        int mid = (start + end) / 2;
        int befor_index = 0;
        int wifi = 1;

        for(int i = 1 ; i < N ; i++){
            if(arr[i] - arr[befor_index] >= mid){
                befor_index = i;
                wifi++;
            }
        }

        if (wifi >= C){
            start = mid +1;
            anw = max(anw, mid);
        }
        else{
            end = mid -1;
        }
    }

 
    // arr[mid] 만큼 건너 띤다. wift++ 하고 
    // 만약 건너뛰었을 때 최대 거리를 뛰어넘었을 때 C와 비교한다.
    // 찾은 개수가 C와 같으면 거리가 더 멀 수 있으니 start = mid +1로 한다.
    // 찾은 개수가 C보다 크면 거리를 늘려야해서 start = mid +1이어야한다.
    // 찾은 개수가 C보다 작으면 거리를 줄여야해서 end = mid - 1 이어야한다.
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> C;

    for(int i = 0 ; i < N; i++){
        cin >> arr[i]; 
    }

    sort(arr, arr + N);
    
    sol();

    cout << anw << '\n';
    return 0;            
}