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
#include <utility> // std::pair 헤더
using namespace std;
#define MAX 1000001

//트리의 지름
// struct Node{
//     int index;
//     int dist;
// };
// vector<Node> tree[MAX];
// vector<int> visited(MAX,0);
// int len=-1;
// int maxNode;
// void dfs(int start, int dist){
//     if(visited[start]==1){
//         return;
//     }

//     if(len<dist){
//         len=dist;
//         maxNode=start;
//     } 
//     visited[start]=1;

//     for(int i=0;i<tree[start].size();i++){
//         int nextIndex=tree[start][i].index;
//         int nextDist=tree[start][i].dist;
//         dfs(nextIndex,nextDist+dist);
//     }
// }


// int main(){
//     int V;
//     cin.tie(0);
//     cout.tie(0);
//     ios::sync_with_stdio(0);
//     cin>>V;
//     int fr,to,dist;
//     for(int i=1;i<V+1;i++){
//         cin>>fr;
//         while(true){
//             cin>>to;
//             if(to==-1){
//                 break;
//             }
//             cin>>dist;
//             tree[fr].push_back({to,dist});
//             tree[to].push_back({fr,dist});
//         }
//     }
//     dfs(1,0);
//     for(int i=0;i<V+1;i++){
//         visited[i]=0;
//     }
//     len=-1;
//     dfs(maxNode,0);
//     cout<<len<<"\n";
// }

//DP : 쉬운 계단 수
vector<vector<int>> dp(101,vector<int>(10));
int main(){
    int n;
    cin>>n;
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    for(int i=1;i<=9;i++){
        dp[1][i]=1;//한자리는 모두 한개씩
    }
    for(int i=2;i<=n;i++){
        //2자리부터는 case 분류
        for(int j=0;j<=9;j++){
            if(j==0){
                dp[i][j]=dp[i-1][1];//0이면 전단계에서 1로 끝나는 애랑 똑같아
            }else if(j==9){
                dp[i][j]=dp[i-1][8];//9면 전단계에서 8로 끝나는 애랑 똑같아
            }else{
                dp[i][j]=dp[i-1][j+1]+dp[i-1][j-1];
            }
            dp[i][j]%=1000000000;
        }
    }
    long answer=0;
    for(int i=0;i<=9;i++){
        answer+=dp[n][i];
    }
    cout<<answer%1000000000;
}