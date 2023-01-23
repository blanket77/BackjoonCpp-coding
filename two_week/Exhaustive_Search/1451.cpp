#include <iostream>
#include <queue>
#define MAX 50

using namespace std;

int N,M;
int NUM[MAX][MAX];
long long result_max = -1;

int getSum(int sx, int sy, int ex, int ey){
    int sum = 0;
    for(int i = sy; i<=ey; i++){
        for(int j = sx; j <= ex; j++){
            sum += NUM[i][j];
        }
    }
    return sum;
}

void sol(){
    for(int i = 0; i < N - 2 ; i++){
        for(int j = i+1; j < N - 1 ; j++){
            long long rec1 = getSum(0, 0, M-1, i);
            long long rec2 = getSum(0, i+1, M -1 ,j);
            long long rec3 = getSum(0, j+1, M -1, N-1);
            result_max =  max(result_max, rec1*rec2*rec3);
        }
    }

    for(int i = 0; i < M - 2 ; i++){
        for(int j = i+1; j < M - 1 ; j++){
            long long rec1 = getSum(0, 0, i, N-1);
            long long rec2 = getSum(i+1, 0, j, N-1);
            long long rec3 = getSum(j+1, 0, M-1, N -1);
            result_max =  max(result_max, rec1*rec2*rec3);
        }
    }

    for(int i = 0; i < M - 1 ; i++){
        for(int j = 0; j < N - 1 ; j++){
            long long rec1 = getSum(0, 0, i, j);
            long long rec2 = getSum(0, j+1, i, N-1);
            long long rec3 = getSum(i+1, 0, M-1, N -1);
            result_max =  max(result_max, rec1*rec2*rec3);
        }
    }

    for(int i = 0; i < M - 1 ; i++){
        for(int j = 0; j < N - 1 ; j++){
            long long rec1 = getSum(0, 0, i, N-1);
            long long rec2 = getSum(i+1, 0, M-1, j);
            long long rec3 = getSum(i+1, j+1, M-1, N -1);
            result_max =  max(result_max, rec1*rec2*rec3);
        }
    }

    for(int i = 0; i < N - 1 ; i++){
        for(int j = 0; j < M - 1 ; j++){
            long long rec1 = getSum(0, 0, M-1, i);
            long long rec2 = getSum(0, i+1, j, N-1);
            long long rec3 = getSum(j+1, i+1, M-1, N -1);
            result_max =  max(result_max, rec1*rec2*rec3);
        }
    }

    for(int i = 0; i < M - 1 ; i++){
        for(int j = 0; j < N - 1 ; j++){
            long long rec1 = getSum(0, 0, i, j);
            long long rec2 = getSum(i+1, 0, M-1, j);
            long long rec3 = getSum(0, j+1, M-1, N -1);
            result_max =  max(result_max, rec1*rec2*rec3);
        }
    }
    
}


int main(){
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%1d", &NUM[i][j]);
        }
	}

    sol();

    cout << result_max << '\n';
    return 0 ;
}