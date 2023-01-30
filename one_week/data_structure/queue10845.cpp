#include<iostream>
#include<string>
#include<queue>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    queue <int> Q;

    int num;
    cin >> num;

    for(int i=0; i<num; i++){
        string st;
        cin >> st;

        if(st == "push"){
            int n;
            cin >> n;
            Q.push(n);
        }
        else if(st == "pop"){
            if(!Q.empty()){
                cout << Q.front() << "\n";
                Q.pop();
            }
            else
                cout << -1 << "\n";
        }
        else if(st == "size"){
            cout << Q.size() << "\n";
        }
        else if(st == "empty"){
            cout << Q.empty() << "\n";
        }
        else if(st == "front"){
            if(!Q.empty())
                cout << Q.front() << "\n";
            else
                cout << -1 << "\n";
        }
        else if(st == "back"){
            if(!Q.empty())
                cout << Q.back() << "\n";
            else
                cout << -1 << "\n";
        }
        }
    return 0;
}