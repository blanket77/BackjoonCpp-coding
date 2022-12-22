#include <iostream>
using namespace std;

int main(){
    int num;
    cin >> num;
    
    int arr[num];
    for(int i=0; i<num; i++){
        cin >> arr[i];
    }  // input data

    int MIN= arr[0];
    int MAX = arr[0];

    for(int i=1; i<num; i++){
        if(MIN > arr[i])
            MIN = arr[i];
        if(MAX < arr[i])
            MAX = arr[i];
    }
    
    cout << MIN << " " << MAX;

    return 0;
}