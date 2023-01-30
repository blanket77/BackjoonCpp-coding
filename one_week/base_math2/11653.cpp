#include<iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n ;
    int i = 2;
    
    while( n != 1){
        if (n % i == 0){
            n /= i;
            cout << i << "\n";
        }
        else
            i++;
    }

    return 0;
}