#include <iostream>
#include <string>
#include <cmath>

using namespace std;


// 두개의 string 자료를 더하고 stoll를 통해 숫자로 바꿔서 계산하는 방법이 있다. https://holuck123.tistory.com/43
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string a, b, c , d;
    cin >> a >> b >> c >> d;

    long long num1 =  stoi(a) * pow(10, b.length()) + stoi(b);
    long long num2 =  stoi(c) * pow(10, d.length()) + stoi(d);

    cout << num1 + num2 << "\n" ; 
    return 0;
}