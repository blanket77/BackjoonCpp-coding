#include<iostream>
#include<string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    for(int i = 0 ; i < 100; i++){
        string str;
        getline(cin, str);

        //while(getline(cin, str))로 쓸 수도 있다. 즉 getline을 true false을 return한다.
        if(str.size() == 0)
            break;

        int Anum = 0; //대문자
        int anum = 0; //소문자
        int Nnum = 0; //숫자
        int Xnum = 0; //공백

        for(char ele : str){
            if(ele >= 'A' && ele <= 'Z')
                Anum++;
            else if(ele >= 'a' && ele <= 'z')
                anum++;
            else if(ele >= '0' && ele <= '9')
                Nnum++;
            else if(ele == ' ')
                Xnum++;        
        }
        
        cout << anum << " " << Anum << " " << Nnum << " " << Xnum << "\n" ;
    }
    return 0;
}