#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector <int> arr; 
    int num, k;
    cin >> num >> k ;

    int n;
    for(int i=0; i< num; i++){
        cin >> n;
        arr.push_back(n);
    }

    sort(arr.begin(), arr.end());

    cout << arr[k-1] << "\n";
    return 0;
}