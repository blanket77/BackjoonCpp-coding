#include<iostream>
#include<vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, B;
    cin >> N >> B;
    vector <char> vec; //string을 써서 += 로 연장할 수 있고 reverse를 통해 문자열을 거꾸로 바꿔서 출력한다 (<algorithm> 필요) https://minyeok2ee.gitlab.io/boj/boj-11005/ 
    
    while(true){
        if(N % B < 10)
            vec.push_back(N % B + '0');
        else
            vec.push_back((N % B - 10 +'A'));

        if(N / B == 0)
            break;
        N = N / B;
    } //몫이 0이 나올 때까지 함. 기존의 나누기랑은 다름.

    for(int i = 0 ; i < vec.size(); i++){
        cout << vec[vec.size() - i - 1];
    } // vec.reserve(vec.begin(), vec.end())를 써서 차례로 나오게 할 수 있다. 
    cout << "\n";
    
    return 0;
}