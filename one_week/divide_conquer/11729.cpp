#include <iostream>

using namespace std;

void hanoi(int n, int from, int to, int middle){
    if (n == 1){
        cout << from << ' ' << to << '\n' ;
    }
    else{
        hanoi(n-1, from, middle, to);
        cout << from << ' ' << to << '\n';
        hanoi(n-1, middle, to, from);
    }
}

int main(){
    int n;
    cin >> n;

    cout << (1 << n) -1 << '\n'; //shift 연산자
    hanoi(n , 1, 3 ,2);
    return 0;
}