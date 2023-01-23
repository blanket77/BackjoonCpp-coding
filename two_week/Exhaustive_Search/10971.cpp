#include <iostream>
#define MAX 11

using namespace std;

bool check[MAX] = {false,};
int visit_num = 0; //방문횟수 기억
int arr[MAX][MAX];
int sum = 0;
int min_sum = 100000000;
int start_num;

int N;

void DFS(int n){
    if(visit_num == N){
        if(arr[n][start_num]>0){
            min_sum = min(min_sum, sum + arr[n][start_num]);
        }
        return;
    }

    for(int i = 1 ; i <= N; i++){
        if(check[i] == true)
            continue;
        if(arr[n][i] == 0)
            continue;
        visit_num++;
        check[i] = 1 ;
        sum += arr[n][i];
        DFS(i);
        visit_num--;
        check[i] = 0;
        sum -= arr[n][i];
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin.tie(NULL);

    cin >> N;
    for(int i = 1 ; i <= N ; i++){
        for(int j = 1 ; j <= N ; j++){
            cin >> arr[i][j];
        }
    }

    for(int i = 1 ; i <= N ; i++ ){
        start_num = i;
        sum = 0;
        visit_num++;
        check[i] = true;
        DFS(i);
        visit_num--;
        check[i] = false;
    }

    cout << min_sum << '\n';
    return 0;
}