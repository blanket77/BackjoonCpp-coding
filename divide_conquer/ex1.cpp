#include <iostream>
using namespace std;

int fastsum(int x){
    if (x == 1){
        return x;
    }
    else{
        if(x % 2 == 0){
            return fastsum(x/2)*2 + (x/2)*(x/2);
        }
        else{
            return fastsum((x-1)/2) *2 + ((x-1)/2)* ((x-1) /2) + x;
        }
    }
}

int main(){
    int A;
    cin >> A;
    cout << fastsum(A);
}