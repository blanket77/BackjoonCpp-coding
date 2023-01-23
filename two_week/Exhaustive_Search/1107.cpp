#include <iostream>
#include <string>
#define MAX 1000000

using namespace std;

bool broken[10] = {false, };

bool Possible(int N){
    if(N == 0){
        if(broken[N])
            return false;
        else
            return true;
    }

    while(N){
        if(broken[N % 10])
            return false;
        N /= 10;
    }
    return true;
}

int Search(int N){
    int result = abs(100-N);
    int tmp;
    for(int i = 0; i < MAX; i++){
        if(Possible(i)){
            tmp = to_string(i).length();
            tmp += abs(N - i);
            result = min(result, tmp);
        }
    }
    return result;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    for(int i = 0 ; i < M ; i++){
        int n;
        cin >> n;
        broken[n] = true;
    }

    cout << Search(N) << '\n';

    return 0;
}