#include <iostream>

using namespace std;
#define MAX 7000

int NUM;
char arr[MAX][MAX];

void sol(int row, int col, int size){
    if(size == 3){
        arr[row][col] = '*'; arr[row][col+1] = '*'; arr[row][col+2] = '*';
        arr[row+1][col] = '*';                      arr[row+1][col+2] = '*';
        arr[row+2][col] = '*'; arr[row+2][col+1] = '*'; arr[row+2][col+2] = '*';        

    }

    else{
        int s = size / 3;
        for(int i = 0 ; i < 3 ; i++){
            for(int j = 0 ; j < 3; j++){
                if(i != 1 || j != 1){
                    // cout << "row : " << row + s*i << " col : " << col + s*j << " size : " << s << '\n';  
                    sol(row + s*i, col + s*j, s);
                }
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> NUM;

    for(int i = 0 ; i < NUM ; i++){
        for(int j = 0 ; j < NUM; j++){
            arr[i][j] = ' ';
        }
    }

    sol(0, 0 ,NUM);


    for(int i = 0 ; i < NUM ; i++){
        for(int j = 0 ; j < NUM; j++){
            cout << arr[i][j];
        }
        cout << '\n';
    }

    return 0;
}