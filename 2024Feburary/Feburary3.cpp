#include <iostream>
#include <stack>
using namespace std;

//1번 조건 충족시키기
bool is_vowel(char c){
    if(c=='a' || c=='e' || c=='i'||c=='o'||c=='u'){
        return true;
    }
    return false;
}

bool quality(string T){
    bool flag=false;
    int c=0;
    int v=0;
    for(int i=0;i<T.size();i++){
        if(is_vowel(T[i])==true){
            flag=true;
            v+=1;
            c=0;
        }else{
            c+=1;
            v=0;
        }
        //2번 조건
        if(v>2 || c>2){
            return false;
        }
        //3번 조건
        if(i>0 && T[i-1]==T[i] && (T[i]!='e' && T[i]!='o')){
            return false;
        }
    }
    if(flag==true){
        return true;
    }else{
        return false;
    }
}

int main(){
    string ca;
    while(true){
        cin>>ca;
        if(ca=="end"){
            break;
            return 0;
        }
        if(quality(ca)){
            cout<<"<"<<ca<<">"<<" is acceptable."<<"\n";
        }else{
            cout<<"<"<<ca<<">"<<" is not acceptable."<<"\n";

        }
    }
}