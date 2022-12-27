#include<iostream>

using namespace std;

int gcd(int a, int b);
int lcm(int a, int b);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a,b;
    cin >> a >> b;
    cout << gcd(a,b) << "\n";
    cout << lcm(a,b) << "\n";
    
    return 0;
}

int gcd(int a, int b){
    if(a % b == 0 ){
        return b;
    }
    else
        return gcd(b, a % b);
}

int lcm(int a, int b){
    return (a*b) / gcd(a,b) ; 
}
