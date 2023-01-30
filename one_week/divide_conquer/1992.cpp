#include <iostream>
#define MAX 64

using namespace std;

int map[MAX][MAX];
int N;

bool check(int r, int c, int n){
    int start = map[r][c];
    for (int i = r; i < r + n; i++){
        for (int j = c; j < c + n; j++){
            if(start != map[i][j])
                return false;
        }
    }
    return true;
}

void divide(int r, int c, int n){
    if(check(r, c , n)){
        cout << map[r][c];
    }

    else{
        int size = n / 2;
        cout << '(';
        for(int i = 0 ; i < 2 ; i++){
            for(int j = 0 ; j < 2; j++){
                divide(r + size * i, c + size * j, size);
            }
        }
        cout << ')';
    }
}


int main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);

    cin >> N ;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            scanf("%1d", &map[i][j]);
            // cin >> map[i][j];
        }
    }
    
    divide(0,0,N);
    return 0;
}