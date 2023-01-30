#include<iostream>

using namespace std;

int gcd(int a, int b);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int num;
    cin >> num;

    for(int k = 0 ; k<num ; k++){
        int n;
        cin >> n;

        int arr[100];
        for(int i = 0 ; i<n; i++){
            cin >> arr[i];
        }   // 배열에 입력값들 저장하기

        long long sum = 0; //합이 int형 범위를 벗어남
        for(int i = 0 ; i < n-1 ; i++){
            for(int j = i+1; j <n; j++){
                sum += gcd(arr[i], arr[j]);
            }
        } // 모든 쌍의 최대공약수 구해서 더하기

        cout << sum << "\n";
    }
    return 0;
}

int gcd(int a, int b){
    if(a % b == 0 ){
        return b;
    }
    else
        return gcd(b, a % b);
}
