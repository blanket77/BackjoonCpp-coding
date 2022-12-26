#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    stack <char> st;
    string str;
    cin >> str;

    int result=0;


    for(int i=0; i < str.length(); i++){
        if(str[i] == '('){
            st.push(str[i]);
        } // 레이저로 자를 막대기 개수 세기
        else if(str[i] == ')' && str[i-1] == '('){
            st.pop();
            result += st.size();
        } // 막대기 개수만큼 레이저로 다름
        else{
            result++;
            st.pop();
        }  // '()'가 아닌 ')' 개수가 막대기 개수  
    }
    cout << result << "\n";
    return 0;
}
