#include <iostream>
#include <string>
#include <list>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    cin >> str;

    list<char> li(str.begin(), str.end());

    //list<char>::iterator cusor = li.end();  https://novlog.tistory.com/262
    auto cusor = li.end();

    int m;
    cin >> m;
    
    for(int i = 0 ; i < m; i++){
        char cmd;
        cin >> cmd;

        if(cmd == 'L'){
            if(cusor != li.begin()){
                cusor--;
            }
        }
        
        else if(cmd == 'D'){
            if(cusor != li.end()){
                cusor++;
            }
        }

        else if(cmd == 'B'){
            if(cusor != li.begin()){
                cusor--;
                cusor = li.erase(cusor);
            }
        }

        else if(cmd == 'P'){
            char c;
            cin >> c;
            li.insert(cusor, c);
        }
    }

    // abcd가 있다고 커서는 제일 오른쪽에 있다면 abcd(cusor)가 된다. 
    for(cusor = li.begin(); cusor != li.end(); cusor++ ){
        cout << *cusor ;
    }

    return 0 ;
}
