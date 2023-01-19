#include <iostream>

using namespace std;

char arr[3072][6144];


void star(int n , int row, int col);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;

    cin >> n;

    // 높이는 n까지 넓이는 2n - 1까지 이다.
    for(int i = 0 ; i < n; i++){
        for(int j = 0 ; j < 2*n - 1 ; j++){
            arr[i][j] = ' ';
        }
    }

    star(n, 0, n-1);

    for(int i = 0 ; i < n; i++){
        for(int j = 0 ; j < 2*n - 1 ; j++){
            cout << arr[i][j];
        }
        cout << '\n';
    }

    return 0;
}

void star(int n , int row, int col){
    
    if(n == 3){
        arr[row][col] = '*';

        arr[row + 1][col - 1] = '*';
        arr[row + 1][col + 1] = '*';

        arr[row + 2][col - 2] = '*';
        arr[row + 2][col - 1] = '*';
        arr[row + 2][col] = '*';
        arr[row + 2][col + 1] = '*';
        arr[row + 2][col + 2] = '*';
    }
    else{
        star(n/2, row, col);
        star(n / 2 , row + n / 2, col - n/2);
        star(n / 2 , row + n / 2, col + n/2 );
    }
}

