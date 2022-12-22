#include <iostream>
using namespace std;

int main(){
    int num;
    cin >> num;

    for(int i =0 ; i < num - 1 ; i++){
        for(int j = 0; j < num-i-1 ; j++){
            cout << " ";
        }
        cout << "*";
        for(int j = 0; j < 2*i-1 ; j++){
            cout << " ";
        }
        if(i==0)
            cout << "\n";
        else    
            cout << "*\n";
    }

    int star = 2 * num - 1;
    for(int i = 0 ; i < star ; i++){
        cout << "*";
    }
    return 0;
}