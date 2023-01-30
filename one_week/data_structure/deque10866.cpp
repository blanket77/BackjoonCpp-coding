#include<iostream>
#include<string>
#include<deque>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    deque <int> Q;

    int num;
    cin >> num;

    for(int i=0; i<num; i++){
        string st;
        cin >> st;

        if(st == "push_front"){
            int n;
            cin >> n;
            Q.push_front(n);
        }
        if(st == "push_back"){
            int n;
            cin >> n;
            Q.push_back(n);
        }
        else if(st == "pop_front"){
            if(!Q.empty()){
                cout << Q.front() << "\n";
                Q.pop_front();
            }
            else
                cout << -1 << "\n";
        }
        else if(st == "pop_back"){
            if(!Q.empty()){
                cout << Q.back() << "\n";
                Q.pop_back();
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