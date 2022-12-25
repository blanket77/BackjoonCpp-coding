#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int num;
    cin >> num;

    int arr[10001] = {0,};
    int n;
    for(int i = 0 ; i <num; i++){
        cin >> n;
        arr[n] += 1;
    }

    for(int i = 1 ; i < 10001; i++){
        for(int j = 0 ; j < arr[i]; j++)
            cout << i << "\n";
    }

    return 0;
}