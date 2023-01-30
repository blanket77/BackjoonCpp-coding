#include <iostream>
#include <algorithm>
#define MAX 500000

using namespace std;

int list_1[MAX];
int list_2[MAX]; 
int c[MAX] = {0, };
int N, M;

// 1. list_1을 정렬 하고 list_2 값을 하나하나 찾아본다.
// 2. 찾다가 없으면 0을 출력하고 있으면 1을 출력한다.
// 찾을 때 이분법을 이용한다. 찾는 값이 더 크면 left = mid + 1 

void sol(){
    sort(list_1 , list_1 + N);
    

    for(int i = 0 ; i < M ; i++){
        int left = 0; int right = N  ; int mid; 
        // list_1에서 검색 ~ N과 연관 //list_2가 찾으려는 값
        while(left <= right){
            mid = (left + right) / 2;
            
            if(list_2[i] > list_1[mid]){
                left = mid + 1 ;
            }
            else if(list_2[i] < list_1[mid]){
                right = mid - 1 ;
            }
            else{
                c[i] = 1;
                break;
            }                
        }
    }
    for(int i = 0 ; i < M ; i++){
        cout << c[i] << ' ';
    }
    cout << '\n';
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

    sol();

    return 0;
}