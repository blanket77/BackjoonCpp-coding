#include <iostream>
using namespace std;

int main(){
    int num;
    cin >> num;

    char num2;
    int sum = 0;

    for(int i=0; i<num ; i++){
        cin >> num2;
        sum += (num2-'0');
    }
    cout << sum << endl;

    return 0;
}