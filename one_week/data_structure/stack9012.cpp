#include <iostream>
#include <string>
#include <stack>
using namespace std;

// '('를 push로 받고 ')'일 때는 pop을 실행한다. 그 후 push일 때   https://seoftware.tistory.com/21
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int num;
    cin >> num;

    for(int i=0; i< num; i++){
        stack <char> st;
        string str;
        cin >> str;

        for(char ch : str){
            st.push(ch);
        } //문자를 다 스택에 입력받음
        
        int n=0;
        int size = st.size();
        string anw = "YES";

        for(int j = 0 ; j < size; j++){
            if(!st.empty() && st.top() == ')')
                n += 1;
            else if(!st.empty() && st.top() == '('){
                n -= 1;
                if(n<0){
                    anw = "NO";
                    break;
                }
            }
            st.pop();
        }
        if(n != 0){
            anw = "NO";
        }
           cout << anw << "\n";
    }
    return 0;
}
