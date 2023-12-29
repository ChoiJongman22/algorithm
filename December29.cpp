#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <stack>
#include <unordered_map>
#include <queue>
#include <deque>
#include <cmath>//pow함수 선언
#define MAX 500002
using namespace std;

// void cantor(int n){
//     int size = pow(3,n-1); //제곱 표현하는 함수
//     if(n==0){
//         cout<<"-";//0이면 하나만 출력하고 종료
//         return;
//     }
//     cantor(n-1);//반반 나눠서 
//     for(int i=0;i<size;i++){
//         cout <<" ";
//     }
//     cantor(n-1);//반반 나눠서
// }

// int main(){
//     int N;
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
//     while(cin>>N){
//         cantor(N);
//         cout <<"\n";
//     }
//     return 0;

// }

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int testcase;
    cin>>testcase;
    vector<int> arr;
    for(int i=0;i<testcase;i++){
        int temp;
        cin>>temp;
        arr.push_back(temp);
    }
    sort(arr.begin(),arr.end());
    for(int i=0;i<testcase;i++){
        cout<<arr[i]<<"\n";
    }
}