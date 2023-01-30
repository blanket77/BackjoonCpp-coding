#include <iostream>
#include <string>

using namespace std;

long long gcd(long long a, long long b);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long a,b;
    cin >> a >> b;

    int result = gcd(a,b);

    for(int i=0; i<result; i++)
        cout << "1";
    
    cout << "\n";
    return 0;
}

long long gcd(long long a, long long b){
    if(a % b == 0 ){
        return b;
    }
    else
        return gcd(b, a % b);
}
