#include<iostream>
#include<algorithm>
#define MAX 100001

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    int arr[MAX];

    arr[0] = 0;
    for(int i = 1 ; i <= N ; i++){
        cin >> arr[i];
    }
    sort(arr, arr + N + 1);

    int mid = N/2;
    int sum = 0 ;

    if(N%2==0){
        for(int i = 0 ; i < mid; i++){
            sum += arr[N-i] - arr[i]; 
        }
    }
    else{
        for(int i = 0 ; i < mid+1; i++){
            sum += arr[N-i] - arr[i]; 
        }       
    } 
        

    cout << sum << '\n';
    return 0;
}