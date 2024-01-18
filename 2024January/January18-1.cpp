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
#define MIN -1000000001
#define MAX 1000000001

// vector<pair<int ,int>> v;
// vector<int> ans;
// int main(){
//     int T;
//     cin>>T;
//     for(int i=0;i<T;i++){
//         int tmp1,tmp2;
//         cin>>tmp1>>tmp2;
//         v.push_back({tmp1,tmp2});
//     }
//     for(int i=0;i<T;i++){
//         int cnt=1;
//         for(int j=0;j<T;j++){
//             if(i!=j){
//                 if(v[i].first<v[j].first && v[i].second<v[j].second){
//                     cnt+=1;
//                 }
//             }
//         }
//         ans.push_back(cnt);
//     }

//     for(int i=0;i<T;i++){
//         cout<<ans[i]<<" ";
//     }
// }

//백트래킹 연산자구하기
// int T;
// int operands[11];
// int operators[4];
// int mymin= 1000000001;
// int mymax= -1000000001;//반대로 해주는 이유
// void getAnswer(int result , int idx){
//     if(idx==T){
//         if(result>mymax){
//             mymax=result;
//         }
//         if(result<mymin){
//             mymin=result;
//         }
//         return;
//     }   
//     //차례대로 덧 뺄 곱 나
//     for(int i=0;i<4;i++){
//         if(operators[i]>0)//연산자가 있다면
//         {
//             operators[i]--;
//             if(i==0){
//                 getAnswer(result + operands[idx],idx+1);
//             }else if(i==1){
//                 getAnswer(result - operands[idx],idx+1);
//             }else if(i==2){
//                 getAnswer(result * operands[idx],idx+1);
//             }else{
//                 getAnswer(result / operands[idx],idx+1);
//             }
//             operators[i]++;

//         }
//     }
//     return;
// }


// int main(){
//     cin>> T;
//     for(int i=0;i<T;i++){
//         cin>>operands[i];
//     }
//     for(int i=0;i<4;i++){
//         cin>>operators[i];
//     }

//     getAnswer(operands[0],1);

//     cout<<mymax<<"\n"<<mymin;
// }


// 차집합으로 풀어보자(셀프넘버)
// 개망함
// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// int main() {
//     vector<int> U(10000);
//     vector<int> ans;
//     vector<int> inv;
    
//     for (int i = 0; i < 10000; i++) {
//         U[i] = i + 1;
//     }
        

//     for (int i = 0; i < 10000; i++) {
//         if (i >= 0 && i < 9) {
//             inv.push_back((i + 1) + (i + 1));
//         } else if (i >= 9 && i < 99) {
//             inv.push_back((i + 1) + (i + 1) / 10 + (i + 1) % 10);
//         } else if (i >= 99 && i < 999) {
//             inv.push_back((i + 1) + (i + 1) / 100 + (i + 1) / 10 + (i + 1) % 10);
//         } else if (i >= 999 && i < 9999) {
//             inv.push_back((i + 1) + (i + 1) / 1000 + (i + 1) / 100 + (i + 1) / 10 + (i + 1) % 10);
//         }else if(i==9999){
//             inv.push_back((i+1) + (i+1)/10000 + (i+1)/1000 + (i+1)/100 +(i+1)/10 +(i+1)%10);
//         }
//     }

//     ans.resize(U.size() + inv.size());
//     auto itr = set_difference(U.begin(), U.end(), inv.begin(), inv.end(), ans.begin());
//     ans.erase(itr, ans.end());

//     for(int i=0;i<ans.size();i++){
//         cout<<ans[i]<<"\n";
//     }
    
//     return 0;
// }


//셀프 넘버 

bool check[10001]={0,};
vector<int> v(10001);
int ans,tmp;
int main(){
    for(int i=0;i<10000;i++){
        ans=i+1;
        tmp=i+1;
        while(tmp>0){
            ans+=(tmp)%10;
            tmp=tmp/10;
        }
        if(ans<=10000){
            check[ans]=1;
            //cout<<ans<<endl;
        }
    }
    for(int i=1;i<=10000;i++){
        if(check[i]==0){
            cout<<i<<endl;
        }
    }
}