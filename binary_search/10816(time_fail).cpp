#include <iostream>
#include <algorithm>
#define MAX 500000

using namespace std;

int N ,M;
int list_1[MAX];
int list_2[MAX];
int cnt[MAX] = {0, };

void sol(){
    sort(list_1, list_1 + N);

    for(int i = 0 ; i < M ; i++){
        int left = 0; int right = N -1 ; int mid; 

        while(left <= right){
            mid = (left + right) / 2;

            if(list_2[i] > list_1[mid]){
                left = mid + 1;
            } 
            else if(list_2[i] < list_1[mid]){
                right = mid - 1; 
            }
            else{
                cnt[i] = 1;
                break;
            }
        }

        if(cnt[i] == 1){
            for(int j = 1 ; j < N - mid ; j++){
                if(list_1[mid + j] == list_1[mid])
                    cnt[i]++;
                else 
                    break;
            }
            for(int j = 1 ; j <= mid ; j++){
                if(list_1[mid - j] == list_1[mid])
                    cnt[i]++;
                else 
                    break;
            }
        }
    }   
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

    for(int i = 0 ; i < M ; i++){
        cout << cnt[i] << ' ' ;
    }

    return 0;
}