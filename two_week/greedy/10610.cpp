#include <iostream>
#include <algorithm>

using namespace std;

bool cmp(char c1, char c2){
    return c1 > c2;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin.tie(NULL);

    //30배이기 때문에 마지막 수는 0이여야한다.
    //30배는 3배이다. 즉 모든 자리수 합이 3의 배수여야한다.
    
    string num;

    cin >> num;

    int sum = 0; 
    bool check = false;
    
    for(int i = 0 ; i < num.length(); i++){
        if(num[i] == '0'){
            check = true;
        }
        sum += (num[i] - '0');
    }

    if(check && sum % 3 == 0 ){
        sort(num.begin(), num.end(), cmp);
        cout << num << '\n'; 
    }
    else  
        cout << -1 << '\n'; 

    return 0;
}