#include <iostream>
#include <vector>

using namespace std;

int board[9][9];
vector<pair<int, int>> points;
int cnt = 0; // 빈칸 수
bool finish = false; //완성 flag

bool check(pair<int, int> p){
    for(int i = 0 ; i < 9 ; i++){
        if(board[p.first][i] == board[p.first][p.second] && i != p.second)
            return false; //같은 row에 같은 숫자면 false
        if(board[i][p.second] == board[p.first][p.second] && i != p.first)
            return false; //같은 column에 같은 숫자면 false
    }

    int start_x = (p.first / 3) *3;
    int start_y = (p.second / 3) *3;
    for(int i = start_x; i < start_x + 3; i++)
        for(int j = start_y ; j < start_y + 3 ; j++){
            if(board[i][j] == board[p.first][p.second] && (i != p.first && j != p.second))
                return false;
        }
    return true;
}

void sudoku(int N){
    if(finish)
        return;

    if(N == cnt){
        for(int i = 0 ; i < 9; i++){
            for(int j = 0 ; j < 9 ; j++)
                cout << board[i][j] << ' ';
            cout << '\n';
        }
        finish = true;
        return;
    }
    
    for(int i = 1; i <= 9 ; i++){
        int r = points[N].first; int c = points[N].second;
        board[r][c] = i;
        if(check(points[N])) // sudoku condition을 만족하면 다음 빈칸 채우러감
            sudoku(N+1);
    }

    // board[points[N].first][points[N].second] = 0; // 못 찾았을 때 처음 값으로 만들기
    return;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for(int i = 0 ; i < 9; i++){
        for(int j = 0 ; j < 9 ; j++){
            cin >> board[i][j];
            if(board[i][j] == 0){
                cnt++; 
                points.push_back(make_pair(i,j)); // 빈칸 좌표 저장
            }
        }
    }

    sudoku(0);
    return 0;
}