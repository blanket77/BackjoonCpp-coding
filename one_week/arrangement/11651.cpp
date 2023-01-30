#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair <int,int>p1, pair <int, int>p2 )
{
    if(p1.second == p2.second)
        return p1.first < p2.first;
    else
        return p1.second < p2.second;
}

int main()
{
    vector <pair<int,int>> A;
    int num;
    cin >> num;

    int x,y;
    for (int i=0; i<num; i++){
        cin >> x >> y;
        A.push_back({x, y});
    }

    sort(A.begin(), A.end(), compare);

    for(int i =0; i< num; i++)
        cout << A[i].first << " " << A[i].second<< "\n";
    return 0;
}
/* 이건 compare 함수를 안씀
int main()
{
    vector <pair<int,int>> A;
    int num;
    cin >> num;

    int x,y;
    for (int i=0; i<num; i++){
        cin >> x >> y;
        A.push_back({y, x});
    }

    sort(A.begin(), A.end());
    for(int i =0; i< num; i++)
        cout << A[i].second << " " << A[i].first<< "\n";
    return 0;
}*/