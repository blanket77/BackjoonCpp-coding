#include <iostream>
#include <algorithm>
#define MAX 1000

using namespace std;

bool cmp(const int &a, const int &b){
    return a>b;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin.tie(NULL);

    int arr[MAX];

    int N;
    cin >> N;
    for(int i = 0 ; i < N ; i++){
        cin >> arr[i];
    }

    sort(arr, arr+N, cmp); //오름차순으로 정렬

    int sum = 0;
    for(int i = 0 ; i < N; i++){
        sum += arr[i]*(i+1);
    }

    cout << sum << '\n';
    return 0;
}