#include<algorithm>
#include<iostream>
#define MAX 26

using namespace std;

int Map[MAX][2];
int N; 

void preorder (int N){
    if (N == -1) return;
    cout << (char)(N + 'A');

    preorder(Map[N][0]);
    preorder(Map[N][1]);
}

void inorder (int N){
    if (N == -1) return;

    inorder(Map[N][0]);
    cout << (char)(N + 'A');
    inorder(Map[N][1]);
}

void postorder (int N){
    if (N == -1) return;

    postorder(Map[N][0]);
    postorder(Map[N][1]);
    cout << (char)(N + 'A');
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // 0 : A , 1 : B라고 생각하자

    cin >> N; 
    char a, b, c;
    int x;
    for(int i = 0; i < N ;i++){
        cin >> a >> b >> c;
        x = a - 'A';

        if (b == '.' )
            Map[x][0] = -1;
        else 
            Map[x][0] = b - 'A';

        if (c == '.')
            Map[x][1] = -1;
        else
            Map[x][1] = c - 'A';
    }

    preorder(0); // 전위 순회
    cout << '\n';
    inorder(0); // 중위 순회
    cout << '\n';
    postorder(0); // 후위 순회
    cout << '\n';


    return 0;
}