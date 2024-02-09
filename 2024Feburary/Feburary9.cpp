

//영단어 암기는 괴로워
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
using namespace std;
unordered_map<string,int> app;

bool cmp(pair<string, int> &a, pair<string, int> &b){
    if(a.second==b.second){
        if(a.first.length()==b.first.length()){
            return a.first<b.first;//조건 3 . 길이 비교 후 알바펫순 비교
        }
        return a.first.length()>b.first.length();//조건 2. 길이 비교

    }
    return a.second>b.second;//조건 1. 출연 빈도 수 
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    int n,m;
    cin>> n >> m;
    for(int i=0;i<n;i++){
        string str;
        cin>>str;
        if(str.length()>=m){
            app[str]+=1;
        }
    }
    vector<pair<string,int>> vec(app.begin(),app.end());
    sort(vec.begin(),vec.end(),cmp);
    for(auto p:vec){
        cout<<p.first<<"\n";
    }
}

//예산


//블로그
