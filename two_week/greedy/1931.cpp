#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const pair<int, int> &a, const pair<int, int> &b){
    if(a.second == b.second)
        return a.first < b.first; //6 6 7 7 이런 경우 때문에 적어줘야한다.
    else 
        return a.second < b.second;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin.tie(NULL);

    //핵심은 언제 더 빨리 끝나는지가 중요하다.
    //단, 조건은 시작시간이 그 전에 끝난 시간보다 같거나 커야한다.
    // if(그전에 끝난 시간 <= 시작 시간)

    int N, start, end;
    vector<pair<int, int>> schedule;
    
    cin >> N;
    for(int i = 0 ; i < N ; i++){
        cin >> start >> end;
        schedule.push_back(make_pair(start,end));
    }

    sort(schedule.begin(), schedule.end(), cmp);

    // for(int i = 0; i < N; i++){
    //     cout << schedule[i].first << ' ' <<schedule[i].second << '\n';
    // }

    int tmp = schedule[0].second;
    int count = 1;
    for(int i = 1 ; i < N; i++){
        if(tmp <= schedule[i].first){
            count++;
            tmp = schedule[i].second;
        }
    }
    cout << count << '\n';
    return 0;
}