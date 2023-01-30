#include <iostream>
#define MAX 2187 // 3^7

using namespace std;

int N;
int arr[MAX][MAX];
int result[3];

bool check(int r, int c, int n){
    int first = arr[r][c];
    for(int i = r; i < r + n; i++){
        for(int j = c; j < c + n ; j++){
            if (first != arr[i][j])
                return false;
        }
    }
    return true;
}

void divide(int r, int c, int n){
    if(check(r, c, n)){
        result[arr[r][c]]++;
    }
    else{
        int size = n / 3;
        
        for(int i = 0 ; i < 3 ; i++){
            for(int j = 0 ; j < 3; j++){
                divide(r + size * i, c + size * j, size);
            }
        }
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            int input;
            cin >> input;
            input++;
            arr[i][j] = input;
        }
    } 

    divide(0, 0, N);

    for(int i = 0 ; i < 3 ; i++){
        cout << result[i] << '\n';
    }

    return 0;
}