#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    queue<int> q;

    int N, K;
    cin >> N >> K;
          
    for(int i = 1; i <= N; i++ ){
        q.push(i);
    }

    cout << '<' ;
    while(q.size() > 1){
        for(int i = 0 ; i < K - 1 ; i++){
            q.push(q.front());
            q.pop(); 
        }
        cout << q.front() << ", ";
        q.pop();
    }

    cout << q.front() << ">\n"; 

    return 0;
}