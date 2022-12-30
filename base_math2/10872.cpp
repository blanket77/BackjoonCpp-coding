#include<iostream>
using namespace std;

int fac(int x);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int x;
    cin >> x;
    cout << fac(x) << "\n";

    return 0;
}

int fac(int x){
    if (x==0)
        return 1;
    else
        return x*fac(x-1);
}