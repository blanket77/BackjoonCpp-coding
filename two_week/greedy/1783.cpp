#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin.tie(NULL);

    // 오른쪽 움직임을 기준으로 생각해서 알고리즘을 짜야한다.
    // 처음 시작할 때 자기 자신이 있는 곳도 방문한 곳으로 생각해야한다.
    // 행이 3이상이고 열이 7이상이면 열 갯수 - 2를 하면된다.
    // 행이 3이상이고 열이 7미만이면 열갯수만큼 방문한 칸이다. 하지만 최대 4칸까지만 된다.
    // 행이 2면 두칸이 가야한다. (열-1)/2+1만큼 간다/ 하지만 최대 4칸까지만 된다.

    // 행이 1이면 무조건 한칸이다. 

    int N, M;
    cin >> N >> M;

    int result; 
    if(N >= 3 && M >= 7){
        result = M - 2;
    }
    else if(N >= 3 && M < 7){
        result = M;
        if(result > 4 )
            result = 4;
    }
    else if(N == 2){
        result = (M-1)/2 + 1;
        if(result > 4 )
            result = 4;
        }
    else
        result =1;

    cout << result << '\n';
    return 0;
}