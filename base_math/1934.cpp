#include<iostream>

using namespace std;

int gcd(int a, int b);
int lcm(int a, int b);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int num;
    cin >> num;

    for(int i =0; i < num; i++){
        int a,b;
        cin >> a >> b;
        cout << lcm(a,b) << "\n";
    }
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
