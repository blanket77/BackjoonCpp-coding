#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin.tie(NULL);
    
    int e, s, m;
    cin >> e >> s >> m;
    
    int E = 1, S = 1, M = 1;
    int year = 1;
    while(true){
        if(E == e && S == s && M == m){
            break;
        }
        E++; S++; M++;
        if(E > 15){
            E = 1;
        }
        if(S > 28){
            S = 1;
        }
        if(M > 19){
            M = 1;
        }
        year++;
    }

    cout << year << '\n';
    return 0;
}