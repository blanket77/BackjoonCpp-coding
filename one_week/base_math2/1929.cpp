#include<iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int m, n;
    cin >> m >> n ;

    bool *arr = new bool[n+1]{} ;
    //vector<bool> arr(n+1, false); 를 이용해도 된다.

    arr[1] = true;
    
    //int LEN = _msize(arr) / sizeof(bool);  // 크기를 구하기 위해서는 sizeof가 아닌 _msize로 Heap 영역에 할당된 메모리의 크기를 가져온다. (wiindow에서만 가능하다.)

    // 에라토스테네스의 체를 이용하여 만든 알고리즘이다.
    for(int i = 2; i <= n; i++){
        for (int j = 2 ; i*j <= n; j++){
            arr[i*j] = true; 
        }
    }

    for(int i = m ; i <= n; i++){
        if (arr[i] == false)
            cout << i << "\n"; 
    }

    delete[] arr;

    return 0;
}