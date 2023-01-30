#include <iostream>
using namespace std;

int main(){
    int num;
    cin >> num;
    
    int half = (2*num -1)/2;

    for(int i = 0 ; i < half+1 ; i++)
    {
        for(int j = 0 ; j < num-i-1; j++)
            cout << " "; 
    
        for(int j = 0 ; j < i+1; j++)
            cout << "*"; 
        cout << "\n";
    }

    for(int i = 0 ; i < half ; i++)
    {
        for(int j = 0 ; j < i+1; j++)
            cout << " "; 
    
        for(int j = 0 ; j < num-i-1; j++)
            cout << "*";
        cout << "\n";
    }

    return 0;
}