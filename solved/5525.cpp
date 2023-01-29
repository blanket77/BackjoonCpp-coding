#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    string str;
    cin >> str;

    int ans = 0;
    for(int i = 0; i < m ; i++){
        int k = 0;

        if(str[i] == 'O')
            continue;
        else{
            //string은 범위 벗어나도 알아서 됌
            while(str[i+1] == 'O' && str[i+2] == 'I'){
                k++;
                if(k == n){
                    ans++;
                    k--;
                }
                i += 2;
            }
        }
    }
    cout << ans << '\n';

    return 0;
}