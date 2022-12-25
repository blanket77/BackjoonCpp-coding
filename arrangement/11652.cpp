#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long arr[100001];
    
    int num;
    cin >> num ;;

    for(int i=0; i< num; i++){
        cin >> arr[i];
    }

    sort(arr, arr + num);

    
    int max=1;
    int count=1;
    long long anw = arr[0];
    
    for(int i=1 ; i< num; i++){
        if(arr[i] == arr[i-1])
            count++;
        else{
            if(max < count){
                max = count;
                anw = arr[i-1];
            } //값이 다를 때만 if를 돌리는 것이 시간상 더 효율이 좋다.
            count = 1;
        }
    }

    if(max < count){
        max = count;
        anw = arr[num-1];
    } //마지막 값을 테스트하기 위해서 이렇게 적음

    cout << anw << "\n";
    return 0;
}