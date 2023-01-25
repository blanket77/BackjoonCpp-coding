#include <iostream>
#include <set>
#include <string>
#include <algorithm>

#define MAX 201

using namespace std;

int A, B ,C;
bool visited[MAX][MAX][MAX];
set<int> result;

void DFS(int a, int b, int c){
    visited[a][b][c] = true;
    int tmpA, tmpB, tmpC;

    // A -> B
    if( B > a+b){
        tmpA = 0; tmpB = b + a; tmpC = c; 
    }
    else{
        tmpA = a - (B-b); tmpB = B; tmpC =c;
    }
    if(!visited[tmpA][tmpB][tmpC]){
        if(tmpA == 0){
            result.insert(tmpC);
        }
        DFS(tmpA, tmpB, tmpC);
    }
    // A -> C
    if( C > a+c){
        tmpA = 0; tmpB = b; tmpC = a+c; 
    }
    else{
        tmpA = a - (C-c); tmpB = b; tmpC = C;
    }
    if(!visited[tmpA][tmpB][tmpC]){
        if(tmpA == 0){
            result.insert(tmpC);
        }
        DFS(tmpA, tmpB, tmpC);
    }
    // B -> C
    if( C > b+c){
        tmpA = a; tmpB = 0; tmpC = b+c; 
    }
    else{
        tmpA = a; tmpB = b - (C-c); tmpC =C;
    }
    if(!visited[tmpA][tmpB][tmpC]){
        if(tmpA == 0){
            result.insert(tmpC);
        }
        DFS(tmpA, tmpB, tmpC);
    }
    // B -> A
    if( A > a+b){
        tmpA = b+a; tmpB = 0; tmpC = c; 
    }
    else{
        tmpA = A; tmpB = b - (A-a); tmpC =c;
    }
    if(!visited[tmpA][tmpB][tmpC]){
        if(tmpA == 0){
            result.insert(tmpC);
        }
        DFS(tmpA, tmpB, tmpC);
    }
    // C -> A
    if( A > a+c){
        tmpA = a+c; tmpB = b; tmpC = 0; 
    }
    else{
        tmpA = A; tmpB = b; tmpC = c - (A-a);
    }
    if(!visited[tmpA][tmpB][tmpC]){
        if(tmpA == 0){
            result.insert(tmpC);
        }
        DFS(tmpA, tmpB, tmpC);
    }
    // C -> B
    if( B > b+c){
        tmpA = a; tmpB = b+c; tmpC = 0; 
    }
    else{
        tmpA = a; tmpB = B; tmpC = c - (B-b);
    }
    if(!visited[tmpA][tmpB][tmpC]){
        if(tmpA == 0){
            result.insert(tmpC);
        }
        DFS(tmpA, tmpB, tmpC);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("input.txt", "r", stdin);

    cin >> A >> B >> C;
    DFS(0,0,C);
    result.insert(C);
    for(set<int>::iterator iter = result.begin(); iter != result.end(); iter++){
        cout << *iter << " ";
    }

    return 0;
}
