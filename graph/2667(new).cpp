#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
int map[26][26];
bool check[26][26];
vector<int> v;
int n;
int cnt = 0;
int dir[4][2] = { {-1,0}, {0,1},{1,0},{0,-1} }; // 상하좌우 이동
void dfs(int x, int y) {
	for (int i = 0; i < 4; i++) {
		int nx = x + dir[i][0];
		int ny = y + dir[i][1];

		if (nx >= 0 && ny >= 0 && nx < n && ny < n) {
			if (check[nx][ny] == false && map[nx][ny] == 1) {
				check[nx][ny] = true;
				cnt++;
				dfs(nx, ny);
			}
		}
	}
}
int main() {
	scanf("%d",&n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%1d", &map[i][j]); // 정수 한개씩 입력받음
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (check[i][j] == false && map[i][j] == 1) {
				check[i][j] = true;
				cnt++;
				dfs(i, j);
				v.push_back(cnt); // 단지개수 push
				cnt = 0;
			}
		}
	}
	cout << v.size() << '\n'; // v의 size가 단지 개수
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << '\n';
	}
}