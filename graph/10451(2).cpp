#include <iostream>
#define MAX 1001

using namespace std;

int N, result = 0; // N은 정점개수, result는 순열 사이클 개수
bool map[MAX][MAX] = {false, }; //인접행렬, 방향그래프만 있기 때문에 일차원으로 해도 된다.
bool visted[MAX] = {false,};

void DFS(int A);
void reset(); // fill함수를 써서 할수도 있다.https://se-jung-h.tistory.com/entry/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98C-%EB%B0%B1%EC%A4%80-10451-%EC%88%9C%EC%97%B4-%EC%82%AC%EC%9D%B4%ED%81%B4

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int num;
    cin >> num;

    for(int i = 0 ; i < num ; i++){
        cin >> N;
        reset();
        int n;
        for(int i = 1 ; i <= N ; i++){
            cin >> n;
            map[i][n] = true;
        }

        for(int i = 1 ; i <= N ; i++){
            if(!visted[i]){
                DFS(i);
                result++;
            }
        }
        cout << result << "\n";
    }

    return 0;

}

void DFS(int A){
    visted[A] = true;

    for(int i = 1 ; i <= N; i++ ){
        if (map[A][i] == true && visted[i] == false)
            DFS(i);
    } 
}

void reset(){
    result = 0;
    for(int i = 1; i <= N ; i++){
        visted[i] = false;
        for(int j = 1; j <= N ; j++){
            map[i][j] = false;
        }
    }
}