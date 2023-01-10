#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

int w, h;
int map[50][50] = {0,};
bool check[50][50]= {false, };
int dir[8][2] = { {0,-1}, {0,1},{-1,0},{1,0},{-1,-1},{-1 ,1},{1,-1},{1,1} }; // 상하좌우, 대각선 이동

void reset() {
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            map[y][x] = 0;
            check[y][x] = 0;
        }
    }
}

void dfs(int y, int x) {
	for (int i = 0; i < 8; i++) {
		int nx = x + dir[i][0];
		int ny = y + dir[i][1];

		if (nx >= 0 && ny >= 0 && nx < w && ny < h) {
			if (check[ny][nx] == false && map[ny][nx] == 1) {
				check[ny][nx] = true;
				dfs(ny, nx);
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	while(1){
		cin >> w >> h;
		
		if(w == 0 && h == 0)
			break;

		reset();

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> map[i][j];
			}
		}


		int isoland = 0;
		for (int y = 0; y < h; y++) {
			for (int x = 0; x < w; x++) {
				if (check[y][x] == false && map[y][x] == 1) {
					isoland++;
					check[y][x] = true;
					dfs(y, x);
				}
			}
		}
		cout <<isoland << '\n'; 
	}
	return 0;
}