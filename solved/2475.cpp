#include <iostream>
#include <cmath>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   
    int sum = 0;

    int a;
    for(int i = 0 ; i <5 ; i++){
        cin >> a;
        sum += pow(a, 2);
    }

    cout << sum % 10 << '\n'; 
    return 0;
}