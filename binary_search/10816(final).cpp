#include <iostream>
#include <algorithm>
#define MAX 500000

using namespace std;

int N ,M;
int list_1[MAX];
int list_2[MAX];

//k이상 처음 위치
int lower_b(int k){
    int left = 0;
    int right = N - 1;
    int mid;
    while (left < right){
        mid = (left + right) / 2;
        if(list_1[mid] >= k){
            right = mid;
        }
        else
            left = mid + 1;
    }
    return right;
}

//k초과 처음 위치
int upper_b(int k){
    int left = 0;
    int right = N - 1;
    int mid;
    while (left < right){
        mid = (left + right) / 2;
        if(list_1[mid] <= k){
            left = mid + 1;
        }
        else
            right = mid;
    }
    return right;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i = 0 ; i < N ; i++){
        cin >> list_1[i];
    }

    cin >> M;
    for(int i = 0 ; i < M ; i++){
        cin >> list_2[i];
    }

    sort(list_1, list_1 + N);

    for(int i = 0 ; i < M ; i++){
        int a = lower_b(list_2[i]);
        int b = upper_b(list_2[i]);

        if(b == N -1 && list_1[N-1] == list_2[i])   
            b++;

        cout << b - a << ' '; 
    }
    cout << '\n' ;

    return 0;
}

