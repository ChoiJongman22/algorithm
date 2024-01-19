#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <unordered_map>
#include <queue>
#include <deque>
#include <cmath> //pow함수 선언
#include <limits.h>
#include <map>
using namespace std;
#define INF 10000000
#define MAX 31
// struct Pos{
//     int x, y;
// };
// int N,M;
// int MIN =987654321;
// bool selected[13];
// vector<Pos> house_pos;
// vector<Pos> chicken_pos;
// vector<Pos> picked;

// int Distance(Pos a, Pos b){
//     return abs(a.x-b.x) + abs(a.y-b.y);
// }

// void Find_Min_Dist(){
//     int result=0;
//     for(int i=0;i<house_pos.size();i++){
//         int min_dist=987654321;
//         for(int j=0;j<picked.size();j++){
//             min_dist=min(min_dist,Distance(house_pos[i],picked[j]));
//         }
//         result+=min_dist;
//     }
//     MIN=min(MIN,result);
// }

// void Find_M_Combination(int x,int m){
//     if(m==M){
//         Find_Min_Dist();
//     }
//     for(int i=x;i<chicken_pos.size();i++){
//         if(selected[i]==true){
//             continue;
//         }
//         selected[i]=true;
//         picked.push_back({chicken_pos[i].x,chicken_pos[i].y});
//         Find_M_Combination(i,m+1);
//         selected[i]=false;
//         picked.pop_back();
//     }
// }


// int main(){
//     cin>>N>>M;
//     for(int i=0;i<N;i++){
//         for(int j=0;j<N;j++){
//             int tmp;
//             cin>>tmp;
//             if(tmp==1){//집이면
//                 house_pos.push_back({i,j});
//             }else if(tmp==2){//치킨이면
//                 chicken_pos.push_back({i,j});
//             }
//         }
//     }
//     Find_M_Combination(0,0);
//     cout<<MIN<<"\n";
//     return 0;
// }

// int cnt=0;
// int main(){
//     int T;
//     cin.tie(0);
//     cout.tie(0);
//     ios::sync_with_stdio(0);
//     cin>>T;
//     for(int i=0;i<T;i++){
//         string a;
//         cin>>a;
//         map<char,int> myMap;
//         bool isOk=true;
//         myMap[a[0]]=1;
//         for(int j=1;j<a.size();j++){
//             if(a[j]==a[j-1]){
//                 continue;
//             }else{
//                 if(myMap[a[j]]>0){
//                     isOk=false;
//                 }else{
//                     myMap[a[j]]=1;
//                 }
//             }
//         }
//         if(isOk==false){
//             continue;
//         }else{
//             cnt+=1;
//         }
//     }
//     cout<<cnt<<endl;
// }


//DP 포도주


vector<int> pd(10001,0);
vector<int> DP(10001,0);
int main(){
    int T;
    cin >> T;
    for(int i=1;i<=T;i++){
        cin>>pd[i];
    }
    DP[0]=0;
    DP[1]=pd[1];
    DP[2]=pd[1]+pd[2];
    for(int i=3;i<=T;i++){
        DP[i]=max({DP[i-3]+pd[i-1]+pd[i],DP[i-2]+pd[i],DP[i-1]});
    }
    cout<<DP[T];
}