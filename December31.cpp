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
typedef long long ll;

// 택배 수거하기

ll solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    ll answer = 0;
    ll a=0;
    ll b=0; 
    for(int i=n-1;i>=0;i--){
        a-=deliveries[i];
        b-=pickups[i];
        int cnt=0;
        while(a<0||b<0){
            a+=cap;
            b+=cap;
            cnt ++;
        }
        answer+=(i+1)*2*cnt;//왕복이라 2를 곱하기 & cnt는 가는 횟수
    }
    return answer;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << solution(4,5,{1,0,3,1,2},{0,3,0,4,0});
    return 0;
}