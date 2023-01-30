#include<iostream>
#include<string>
#define Max_size 10000
using namespace std;


// c++은 이미 stack class가 있어서 이를 이용해도 좋다.https://blockdmask.tistory.com/96
typedef struct _stack
{
    int arr[Max_size];
    int top;
} Stacks;


void Stack_Init(Stacks *st);
void StackPuch(Stacks* st, int X);
int StackPop(Stacks* st);
int StackSize(Stacks* st);
int StackEmpty(Stacks* st);
int StackTop(Stacks* st);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int num;
    cin >> num;
    
    Stacks st;
    Stack_Init(&st);

    string str;
    for(int i=0; i<num; i++){
        cin >> str;
        
        if(str == "push"){
            int num;
            cin >> num;
            StackPuch(&st, num);
        }
        else if(str == "pop"){
            cout << StackPop(&st) << "\n";
        }
        else if(str == "size"){
            cout << StackSize(&st)<< "\n";
        }
        else if(str == "empty"){
            cout << StackEmpty(&st)<< "\n";
        }
        else if(str == "top"){
            cout << StackTop(&st)<< "\n";
        }
    }
    return 0;
}

void Stack_Init(Stacks *st){
    st->top = -1;
}
void StackPuch(Stacks *st, int X){
    st->top += 1 ;
    st->arr[st->top] = X;
}
int StackPop(Stacks *st){
    if(st->top == -1)
        return -1;
    else{
        st->top -=1;
        return st->arr[st->top + 1];
    }
}
int StackSize(Stacks *st){
    return st->top + 1;
}
int StackEmpty(Stacks *st){
    if(st->top == -1)
        return 1;
    else
        return 0;
}
int StackTop(Stacks *st){
    if(st->top == -1)
        return -1;
    else
        return st->arr[st->top];
}