#include <iostream>
#include <algorithm>
#define MAX 200000

using namespace std;

int arr[MAX];
int anw = -1;
int wifi = 0;
int N, C;

void sol(){
    int mid;

    //간격을 이분탐색할 것이다.
    int start = 0;
    int end = arr[N - 1] - arr[0];

    while(start <= end){
        mid = (start + end)/2; 

        //첫번째 공유기 설치
        int s = 0; // 첫번째 공유기 위치 인덱스
        wifi = 1;
        for(int i = 1 ; i < N ; i++){
            if( (arr[i] - arr[s]) >=  mid){
                wifi++;
                s = i; //기준 공유기 위치 인덱스 바뀜
            }             
        }

        if(wifi >= C){
            anw = mid;
            start = mid + 1;
            
        }

        else{
            end = mid - 1 ;
        }
    }


}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> C;

    for(int i = 0 ; i < N ; i++){
        cin >> arr[i];
    }

    sort(arr, arr + N);

    sol();
   
    cout << anw << '\n';    
    return 0;            
}