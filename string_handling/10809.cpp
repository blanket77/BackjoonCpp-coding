#include<iostream>
#include<string>
#define Size 26

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int alpa[Size];
    for(int i = 0; i < Size; i++){
        alpa[i] = -1;
    }
    string str;
    cin >> str;
    
    for(int i=0; i<str.length(); i++){
        int A = str[i] - 'a';
        if(alpa[A] == -1) 
            alpa[A] = i ;    
    }

    for(int i=0; i< Size ; i++)
        cout << alpa[i] <<" ";
    
    return 0;
}