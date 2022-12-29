#include<iostream>
#include<string>
#include <algorithm>
using namespace std;


//revese()나 result = "A" + result 는 시간 복잡도가 O(n) 이다. result = result + "A"도 시간복잡도 경우 따라는 O(n)이지만 result += "A" 는 O(n)이다.
//시간 초과가 안나오게 하기 위해 reverse을 안 쓰고 += 쓰도록 노력했다.
//다음 블로그에서는 가독성이 높이고 순차적으로 풀었다. https://minyeok2ee.gitlab.io/boj/boj-1212/
//다음 블로그에서는 binary 배열을 미리 만들어서 풀었다. reverse 써도 되는데??  https://khu98.tistory.com/6
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    cin >> str ;

    if(str == "0")
        cout << 0 << "\n";   //이렇게 안하면 0을 입력 받았을 때 0이 안나온다.

    int slen = str.length();
    string result;
    
     
    for(int i = slen -1 ; i >= 0; i--){
        int n = (str[i] - '0');
        for(int j = 0 ; j < 3; j++){
            result += to_string(n % 2); 
            n /= 2;
        } 
    }
    
    int a = result.length() - 1; // 앞에 0이 나오는 것을 방지
    while(result[a] == '0'){
        a--;
    }
    
    for(int i = a ; i >= 0; i--){
        cout << result[i];
    }

    return 0;
}