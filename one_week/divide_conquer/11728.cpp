#include <iostream>
#define MAX 1000000

using namespace std;

int N, M;
int arr1[MAX];
int arr2[MAX];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for(int i = 0 ; i < N; i++){
        cin >> arr1[i];
    }

    for(int i = 0 ; i < M; i++){
        cin >> arr2[i];
    }

    int i = 0; int j = 0; int k=0;
    while( i < N && j < M){
        if(arr1[i] >= arr2[j]){
            cout << arr2[j++] << ' ';
        }
        else{
            cout << arr1[i++] << ' ';
        }
    }

    while(i < N){
        cout << arr1[i++] << ' ';
    }
    while(j < M){
        cout << arr2[j++] << ' ';
    }


    return 0;
}