#include<iostream>
using namespace std;

int num_Count(int x, int num);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m;
    cin >> n >>m ;

    int n_two_count = num_Count(n, 2);
    int n_five_count = num_Count(n, 5);
    
    int nm_two_count = num_Count(n - m, 2);
    int nm_five_count = num_Count(n - m, 5);
    
    int m_two_count = num_Count(m, 2);
    int m_five_count = num_Count(m, 5);

    int two_count = n_two_count - nm_two_count - m_two_count;
    int five_count = n_five_count - nm_five_count - m_five_count;
    
    cout << min(two_count, five_count) << "\n";

    return 0;
}

int num_Count(int x, int num){
    int count = 0;
    for(long long i = num; i <= x; i *= num ){
        count += x/i;
    } // i <= x 등호 잘 생각하자.
    return count;
}