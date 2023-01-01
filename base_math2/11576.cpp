#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int to_ten(const int *arr, int A, int m); //arr 배열, A는 진법, m은 갯수
void ten_to_B(int ten, int B);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int A, B;
    cin >> A >> B;

    int m; int arr[25];
    cin >> m;

    for(int i = 0 ; i < m ; i++){
        cin >> arr[i];
    }
    reverse(arr, arr + m ); // reverse를 쓰지 말고 to_ten에서 m을 알기 때문에 m-- 로 sum을 더해나가면 된다.

    int ten_tmp = to_ten(arr, A, m); // 10진법으로 만듬
    ten_to_B(ten_tmp, B);

    return 0;
}

int to_ten(const int *arr, int A, int m){
    int sum = 0;
    for(int i = 0 ; i < m ; i++){
        sum += arr[i] * pow(A, i);
    }
    
    return sum;
}
void ten_to_B(int ten, int B){
    vector <int> vec;
    
    while(ten != 0){
        vec.push_back(ten % B);
        ten /= B;
    }
    reverse(vec.begin(), vec.end());

    for(int ele : vec)
        cout << ele << " ";
    cout << "\n";
}