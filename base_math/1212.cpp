#include<iostream>
#include<string>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    cin >> str ;

    if(str == "0")
        cout << 0 << "\n";

    int slen = str.length();
    string result;
    
     
    for(int i = slen -1 ; i >= 0; i--){
        int n = (str[i] - '0');
        for(int j = 0 ; j < 3; j++){
            result = to_string(n % 2)+ result; 
            n /= 2;
        }
    }

    int a = 0; // 앞에 0이 나오는 것을 방지
    while(result[a] == '0'){
        a++;
    }
    
    int rlen = result.length();
    for(int i = a ; i < rlen; i++){
        cout << result[i];
    }

    return 0;
}