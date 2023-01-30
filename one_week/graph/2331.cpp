#include <iostream>
#include <cmath>

using namespace std;
bool visted[236197] = {false, };

int abc(int A, int P){
    int sum = pow(A % 10, P);
    while((A/10)){
        A/=10;
        sum += pow(A % 10, P);
    }

    return sum;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int A, P;
    cin >> A >> P;

    int S = A;
    while(!visted[S]){
        visted[S] = true;
        S = abc(S, P);    
    }    

    int rem = S;

 
    fill(visted, visted+236197, false);
    
    visted[rem] = true;
    S = A;
    int cnt = 0;
    while(!visted[S]){
        cnt++;
        visted[S] = true;
        S = abc(S, P);    
    }   

    cout << cnt << "\n";

    return 0;
}