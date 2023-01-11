#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){
    
    vector<int> v;

    int N;
    cin >> N;
    
    int a;
    double sum = 0;
    for(int i = 0 ; i < N ;i++){
        cin >> a;
        sum += a; 
        v.push_back(a);
    }

    //산술 기하
    // -0 출력 때문에 round 못씀
    cout << (int)floor( (sum / N) + 0.5 ) << '\n';

    //중앙값
    sort(v.begin(), v.end());
    cout << v[v.size()/2 ] << '\n';

    //최빈값
    bool second = false;
    int result = v[0];
    int most = -1;
    int cnt = 1;
    for(int i = 1 ; i < v.size(); i++){
        if(v[i-1] == v[i]){
            cnt++;
        }
        else{
            if(most < cnt ){
                second = false;
                most = cnt;
                result = v[i-1];
            }              
            else if(most == cnt){
                if(second == false){
                    second = true;
                    result = v[i-1];
                }
            }   
            cnt = 1; 
        }
    }

    if(most < cnt){
        result = v.back();
    }
    else if(most == cnt && second == false){
        result = v.back();
    } //마지막까지 확인

    cout << result << '\n';

    //범위
    int b = v.back() - v.front();
    cout << b << '\n';

     return 0;

}