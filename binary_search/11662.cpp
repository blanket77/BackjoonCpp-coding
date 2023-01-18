#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct point{
    double x,y;
}typedef point;

point A,B,C,D;
double ans;

point ONE_P(double p){
    point tmp;
    tmp.x = A.x + (B.x - A.x) * (p/100);
    tmp.y = A.y + (B.y - A.y) * (p/100);
    return tmp; 
}

point TWO_P(double p){
    point tmp;
    tmp.x = C.x + (D.x - C.x) * (p/100);
    tmp.y = C.y + (D.y - C.y) * (p/100);
    return tmp; 
}

double distance(point A, point B){
    return sqrt( pow(A.x - B.x,2) + pow(A.y - B.y,2));
}

void sol(){
    
    ans = 2*10e4;

    double l = 0 , r = 100;
    double p,q;
    while(r - l >= 1e-6){  //오차범위 때문에
        p = ( (l*2 + r)/3 );
        q = ( (l + r*2)/3 );

        point fp1 = ONE_P(p);
        point fp2 = ONE_P(q);
        
        point tp1 = TWO_P(p);
        point tp2 = TWO_P(q);
        
        double d1 = distance(fp1, tp1);
        double d2 = distance(fp2, tp2);
        
        ans = min(ans, min(d1, d2));
        if(d1 > d2){
            l = p;
        }
        else{
            r = q;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y >> D.x >> D.y;

    sol();
    cout << fixed;
    cout.precision(10);
    cout << ans << '\n';
    return 0;
}


