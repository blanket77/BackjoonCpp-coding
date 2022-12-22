#include <iostream>
using namespace std;

int main(){
    int num;
    cin >> num;
    
    int star = 2*num -1;

    for(int i=0; i<num; i++){
        for(int j=0; j < star/2-i; j++){
            cout << " ";
        }
       for(int j=0; j < 2*i+1; j++){
            cout << "*";
        }

        cout << "\n";
    }  

    return 0;
}