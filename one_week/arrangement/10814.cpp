#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

// sort를 쓰기 위해서는 struct를 통해 index를 넣어줘야한다. 아니면 3차원을 통해 index를 넣거나 https://velog.io/@matcha_/%EB%B0%B1%EC%A4%80-10814-%EB%82%98%EC%9D%B4%EC%88%9C-%EC%A0%95%EB%A0%AC-C-%EC%A0%95%EB%A0%AC

bool compare(pair<int, string> p1, pair<int, string> p2 )
{
    if(p1.first != p2.first )
        return p1.first < p2.first;
    else
        return false;    
}

int main()
{
    vector <pair<int,string>> A;
    int num;
    cin >> num;

    int age;
    string str;

    for (int i=0; i<num; i++){
        cin >> age >> str;
        A.push_back({age, str});
    }

    stable_sort(A.begin(), A.end(),compare);
    for(int i =0; i< num; i++)
        cout << A[i].first << " " << A[i].second<< "\n";
    return 0;
}