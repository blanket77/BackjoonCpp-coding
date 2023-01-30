#include <iostream>
#include <algorithm>
#define MAX 500000

using namespace std;

int N ,M;
int list_1[MAX];
int list_2[MAX];
int cnt[MAX] = {0, };

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i = 0 ; i < N ; i++){
        cin >> list_1[i];
    }

    cin >> M;
    for(int i = 0 ; i < M ; i++){
        cin >> list_2[i];
    }

    sort(list_1, list_1 + N);

    for(int i = 0 ; i < M ; i++){
        int a = lower_bound(list_1, list_1 + N , list_2[i]) - list_1;
        int b = upper_bound(list_1, list_1 + N , list_2[i]) - list_1;

        cout << b - a << ' '; 
    }
    cout << '\n' ;

    return 0;
}