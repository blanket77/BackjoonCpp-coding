#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> positive;
vector<int> negative;

bool zero_is = false;
int one_count = 0;


int greedy(){

    int result = 0 ;
    // positive 행렬은 내림차순  5 4 3 2 1
    // negative 행렬은 오름차순 -5 -4 -3 -2
    sort(positive.begin(), positive.end(), greater<>());
    sort(negative.begin(), negative.end(), less<>());

    // positive 행렬 갯수가 홀수면 1 추가
    if(positive.size() % 2){
        positive.push_back(1);
    }
    
    // positive 행렬를 묶어 곱하고 result에 더해준다.
    for(int i = 0 ; i < positive.size() ; i += 2){
        result += positive[i] * positive[i+1];
    }
    // 1있는 만큼 더해준다.
    result += one_count;

    // negative 행렬 갯수가 홀수면
    // 그리고 만약 0이 있으면 0을 마지막에 넣어주고 그렇지 않으면 1을 넣어준다.
    if(negative.size() % 2){
        if(zero_is)
            negative.push_back(0);
        else 
            negative.push_back(1);
    }

    // negative 행렬를 묶어 곱하고 result에 더해준다.
    for(int i = 0 ; i < negative.size() ; i += 2){
        result += negative[i] * negative[i+1];
    }

    return result;
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    int num;
    for(int i = 0 ; i < N ; i++){
        cin >> num;
        if(num > 1)
            positive.push_back(num);
        else if(num == 1)
            one_count++;
        else if(num < 0)
            negative.push_back(num);
        else 
            zero_is = true;    
    }

    cout << greedy() << '\n';

    return 0;
}