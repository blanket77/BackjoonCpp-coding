#include <iostream>

using namespace std;



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin.tie(NULL);

    int coin[10];
    int result = 0;

    int N, M;

    cin >> N >> M;
    
    for(int i = 0 ; i < N ; i++){
        cin >> coin[i];
    }

    for(int i = N - 1 ; i >= 0 ; i--){
        result += M / coin[i];
        M %= coin[i]; 
    } //오름차순이기 때문에 정렬안하고 해도 된다.

    cout << result << '\n';
    return 0;
}