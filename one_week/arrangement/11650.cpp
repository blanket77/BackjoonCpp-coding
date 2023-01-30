#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

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

    sort(A.begin(), A.end());
    for(int i =0; i< num; i++)
        cout << A[i].first << " " << A[i].second<< "\n";
    return 0;
}