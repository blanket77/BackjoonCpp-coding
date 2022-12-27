#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    string str;
    string temp[1000];

    cin >> str;

    int size = str.length();
    for(int i = 0 ; i< size; i++)
        temp[i] = str.substr(i, size);
    
    sort(temp, temp + size);
    
    for(int i = 0 ; i < size ; i++){
        cout << temp[i] << "\n";
    } 
    return 0;
}