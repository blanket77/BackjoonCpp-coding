#include <iostream>
#define M 8

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int asc = 0 ;
    int dsc = 0 ;

    int input;
    for(int i = 0; i < M ; i++){
        cin >> input;
        if(input == i + 1)
            asc++;
        else if(input == M - i)
            dsc++;
    }

    if(asc == M)
        cout << "ascending" << '\n';

    else if(dsc == M)
        cout << "descending" << '\n';
    else
        cout << "mixed" << '\n';

    return 0;
}