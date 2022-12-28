#include<iostream>
#include<vector>

using namespace std;
//아니면 if문을 써서 3으로 나눈 나머지 따라서 if문을 만들고 for문을 쓸 때 str.size()%3 부터 시작하면 된다.https://zz12345.tistory.com/7 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    cin >> str ;

    while (str.size() % 3 != 0) {
        str = '0' + str;
    }
    
    for (int i = 0 ; i < str.size() ; i+=3){
        cout << (str[i] - '0')*4  + (str[i+1] - '0')*2 + (str[i+2] - '0') ;
    }

    return 0;
}