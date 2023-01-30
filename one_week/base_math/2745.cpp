#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string N; 
    int B;
    cin >> N >> B;

    reverse(N.begin(), N.end());
    int sum = 0; // 결과값이 10억보다 작으므로
    for(int i = 0 ;i < N.size(); i++){
        if(N[i] >= '0' && N[i] <= '9')
            sum += pow(B, i) * (N[i] - '0');
        else if(N[i] >= 'A' && N[i] <= 'Z')
            sum += pow(B, i) * (N[i] - 'A' + 10);
    } 

    cout << sum << "\n";
    return 0;
}