#include <iostream>

using namespace std;

int cnt;
int n;

void sum(int a){

    if(a == n){
        cnt++;
        return;
    }
    else if(a>n){
        return;
    }
    sum(a+1);
    sum(a+2);
    sum(a+3);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin.tie(NULL);

    int num;
    cin >> num;
    
    for(int i = 0 ; i < num ; i++){
        cin >> n;

        cnt = 0;
        sum(0);

        cout << cnt << '\n';
    }
    return 0;
}