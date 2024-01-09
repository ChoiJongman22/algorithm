#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <stack>
#include <unordered_map>
#include <queue>
#include <deque>
#include <cmath> //pow함수 선언
#include <limits.h>

#define MAX 20001
using namespace std;
#define INF 10000000

// 1로 만들기
// int dp[INF];
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
//     int test;
//     cin>>test;
//     dp[1]=0;
//     for(int i=2;i<=test;i++){
//         dp[i]=dp[i-1]+1;
//         if(i%3==0){
//             dp[i]=min(dp[i],dp[i/3]+1);
//         }
//         if(i%2==0){
//             dp[i]=min(dp[i],dp[i/2]+1);
//         }
//     }
//     cout<<dp[test]<<"\n";
//     return 0;

// }

// 1003번 피보나치 함수
// int zero[41];
// int one[41];
// void fibo(int N){
//     for(int j=2;j<=N;j++){
//         zero[j]=zero[j-1]+zero[j-2];
//         one[j]=one[j-1]+one[j-2];
//     }
// }

// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
//     int testcase;
//     cin>>testcase;
//     one[0]=0;
//     one[1]=1;
//     zero[0]=1;
//     zero[1]=0;
//     for(int i=0;i<testcase;i++){
//         int N;
//         cin>>N;
//         fibo(N);
//         cout<<zero[N]<<" "<<one[N]<<"\n";
//     }
//     return 0;
// }

// int dp[20][20];
// int ans[20][20];

// int main()
// {
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
//     int testcase;
//     cin >> testcase;
//     for (int i = 0; i < testcase; i++)
//     {
//         int n, k;
//         cin >> n >> k;
//         for (int j = 0; j <= n; j++)
//         {
//             for (int u = 1; u <= k; u++)
//             {

//                 if (j == 0)
//                 {
//                     dp[j][u] = u;
//                     ans[j][u] = u;
//                 }
//                 if (u != 1 && j != 0)
//                 {
//                     dp[j][u] = dp[j - 1][u] + dp[j][u - 1];
//                     ans[j][u] += dp[j][u];
//                 }
//             }
//         }
//         cout << ans[n][k] << "\n";
//     }
// }

int dp[20][20];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int testcase;
    cin >> testcase;
    for (int i = 0; i < testcase; i++) {
        int n, k;
        cin >> n >> k;
        for (int j = 0; j <= n; j++) {
            dp[j][1] = 1; // 각 층의 1호는 항상 1명이 살고 있음
        }
        for (int u = 2; u <= k; u++) {
            dp[0][u] = u; // 0층 u호에는 u명이 살고 있음
            for (int j = 1; j <= n; j++) {
                dp[j][u] = dp[j - 1][u] + dp[j][u - 1];
            }
        }
        cout << dp[n][k] << "\n";
    }
    return 0;
}
