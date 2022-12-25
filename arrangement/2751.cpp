#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector <int> A;
    int num;
    cin >> num;

    for (int i=0; i<num; i++){
        int n;
        cin >> n;
        A.push_back(n);
    }

    sort(A.begin(), A.end());
    for(int elem : A)
        cout << elem << "\n";
    return 0;
}