#include <iostream>
using namespace std;

enum week{
    SUN, MON,TUE, WED, THU, FRI, SAT
};

int main()
{
    int arr[12] = {31, 28, 31, 30, 31 ,30, 31, 31 , 30 ,31 ,30, 31 };
    int M,D;
    cin >> M >> D;

    int num, sum = 0;
    for(int i=0; i<M-1; i++)
        sum += arr[i];

    num = (sum + D) %7; 
    
    switch(num){
        case MON:
            cout<<"MON"; break;
        case TUE:
            cout<<"TUE"; break;
        case WED:
            cout<<"WED"; break;        
        case THU:
            cout<<"THU"; break;
        case FRI:
            cout<<"FRI"; break;
        case SAT:
            cout<<"SAT"; break; 
        case SUN:
            cout<<"SUN";break;             
    }
    return 0;
}