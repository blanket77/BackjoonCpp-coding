#include <iostream>
#define MAX 1000001

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    bool arr[MAX] = {false, }; // false가 소수
    
    arr[1] = true;
    for(int i = 2; i < MAX; i++ ){
        for(int j = 2; j*i < MAX; j++){
            arr[i*j] = true;
        }
    } //에라토스테네스의 체로 소수 구함

    while(true){
        int n;
        cin >> n;

        if(n == 0 )
           break;

        bool ck = false;

        for(int a = 3 ; a < n; a += 2){
            // int b = n - a;
            if(arr[a] == false && arr[n-a] == false ){
                cout << n << " = " << a << " + " << n-a << "\n";
                ck = true;
                break;
            }
        }

        if(!ck)
            cout << "Goldbach's conjecture is wrong." << "\n";

        // int a = 3, b = 3;

        // while(n != a + b ){
            
        //     b += 2; // 소수는 2를 제외하면 홀수이기 때문에
        //     while(arr[b] != false){
        //         b += 2;
        //         if(b > n || a + b > n ){
        //             a++;
        //             while(arr[a] != false){
        //                 a++;
        //             }
        //             b = a;
        //         }
        //     }
        // } //이렇게 하면 무조건 시간초과이다. 결과값들을 보면 소수의 뒷부분과 앞부분 쪽으로 구성되어있다.
        // cout << n << " = " << a << " + " << b << "\n";
    }
}