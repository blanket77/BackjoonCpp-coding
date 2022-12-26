#include<iostream>
#include<string>
#define Size 26

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;

    getline(cin, str);

    for(int i = 0; i < str.size() ; i++){
        if( (str[i] >= 'a' && str[i] <= 'a'+12) || str[i] >= 'A' && str[i] <= 'A'+12 )
            str[i] += 13;
        else if ( (str[i] >= 'a'+13 && str[i] <= 'z') || str[i] >= 'A'+13 && str[i] <= 'Z' )
            str[i] -= 13;
        }
    

    cout << str << "\n";

    return 0;
}