#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <limits>
#define MAX_N 51
using namespace std;

int original[MAX_N][MAX_N]; // 원본 배열 저장
int arr[MAX_N][MAX_N];      // 회전 연산 적용할 배열
int N, M, R;
int ans = numeric_limits<int>::max();
vector<tuple<int, int, int>> rotate_info; // (r, c, s) 저장

// 원본 배열 입력 (원본 배열은 original에 저장)
void input_arr(){
    cin >> N >> M >> R;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            cin >> original[i][j];
        }
    }
}

// 회전 연산 정보 입력 (좌표를 0-indexed로 변환)
void input_rotate_info(){
    int r, c, s;
    for (int i = 0; i < R; i++){
        cin >> r >> c >> s;
        rotate_info.push_back(make_tuple(r - 1, c - 1, s));
    }
}

// 시계방향 회전 연산 함수: (r, c, s)에 대해 각 레이어를 시계방향으로 회전
void apply_rotation_clockwise(int r, int c, int s){
    for (int layer = 1; layer <= s; layer++){
        int top = r - layer;
        int left = c - layer;
        int bottom = r + layer;
        int right = c + layer;
        
        // 시작 위치의 값을 저장 (나중에 옮겨줄 값)
        int temp = arr[top][left];
        
        // 1. 왼쪽 열: 위로 이동
        for (int i = top; i < bottom; i++){
            arr[i][left] = arr[i+1][left];
        }
        // 2. 아래 행: 왼쪽으로 이동
        for (int j = left; j < right; j++){
            arr[bottom][j] = arr[bottom][j+1];
        }
        // 3. 오른쪽 열: 아래로 이동
        for (int i = bottom; i > top; i--){
            arr[i][right] = arr[i-1][right];
        }
        // 4. 윗쪽 행: 오른쪽으로 이동
        for (int j = right; j > left+1; j--){
            arr[top][j] = arr[top][j-1];
        }
        // 저장해둔 값 배치
        arr[top][left+1] = temp;
    }
}

// 모든 행의 합 중 최솟값을 계산
int compute_minimum_row_sum(){
    int minimum = numeric_limits<int>::max();
    for (int i = 0; i < N; i++){
        int sum = 0;
        for (int j = 0; j < M; j++){
            sum += arr[i][j];
        }
        minimum = min(minimum, sum);
    }
    return minimum;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    input_arr();
    input_rotate_info();
    
    // 회전 연산 적용 순서를 저장할 벡터 (인덱스 0 ~ R-1)
    vector<int> order(R);
    for (int i = 0; i < R; i++){
        order[i] = i;
    }
    
    // 모든 순열에 대해 회전 연산 적용
    do {
        // 원본 배열을 arr에 복사 (회전 연산 적용 전 상태 복원)
        for (int i = 0; i < N; i++){
            for (int j = 0; j < M; j++){
                arr[i][j] = original[i][j];
            }
        }
        
        // 현재 순서(order)에 따라 회전 연산을 순차적으로 적용
        for (int idx : order){
            int r, c, s;
            tie(r, c, s) = rotate_info[idx];
            apply_rotation_clockwise(r, c, s);
        }
        
        // 회전 후 배열에서 각 행의 합의 최소값으로 답 갱신
        ans = min(ans, compute_minimum_row_sum());
        
    } while(next_permutation(order.begin(), order.end()));
    
    cout << ans << "\n";
    
    return 0;
}
