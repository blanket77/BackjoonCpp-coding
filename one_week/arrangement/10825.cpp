#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

struct student{
    int kor;
    int eng;
    int mat;
    string name;
};

bool compare(const student &s1, const student &s2 )
{
    if(s1.kor == s2.kor){
        if(s1.eng == s2.eng){
            if(s1.mat == s2.mat)
                return s1.name < s2.name;
            return s1.mat > s2.mat;
        }
        return s1.eng < s2.eng;
    }
    else
        return s1.kor > s2.kor; 
}

int main()
{
    int num;
    cin >> num;
    vector <student> A(num);

    for (int i=0; i<num; i++){
        cin >> A[i].name >> A[i].kor >> A[i].eng >> A[i].mat;
    }
    
    sort(A.begin(), A.end(),compare);

    for(int i =0; i< num; i++)
        cout << A[i].name << "\n";
    return 0;
}