#include<iostream>
#include<algorithm>
#include<vector>
#define MAX 100001

using namespace std;

struct Bus{
    int cnt = 0;
    int time = 0;
    int point = 1;
};

struct People{
    int wait_time;
    bool on = false;
};

struct Point{
    vector<People> Peo;

    void make_Pe(){
        People p;
        Peo.push_back(p);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int arr[5] = {1,3,2,4,3};

    Bus bus;
    bus.point=2;
    bus.time += arr[1];
    
    bus.point >= 5
    bus.point == 1

    if(bus.cnt == 7)
        cout << bus.time << '\n';

    return 0;
}