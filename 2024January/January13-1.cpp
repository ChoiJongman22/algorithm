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

#define MAX 20001
using namespace std;
#define INF 10000000

vector<int> DP(1001,0);
int main(){
    int n;
    cin>>n;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    DP[1]=1;
    DP[2]=3;
    for(int i=3;i<=n;i++){
        DP[i]=(DP[i-1]+2*DP[i-2])%10007;//미리 나누지 않으면 오버플로우 발생 꼭 미리 나누자
    }
    cout<<DP[n]<<"\n";
}