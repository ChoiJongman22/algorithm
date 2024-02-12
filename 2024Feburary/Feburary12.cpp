// N번째 큰수
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// int N;

// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
//     cin>>N;
//     int tmp;
//     priority_queue<int,vector<int>,greater<int>> pq;//최소힙을 사용
//     for(int i=0;i<N*N;i++){
//         cin>>tmp;
//         pq.push(tmp);
//         if(pq.size()>N){
//             pq.pop();
//         }
//     }
//     cout<<pq.top()<<"\n";
// }

// 쉬운 최단 거리
//  int n,m;
//  vector<vector<int>> map(1001,vector<int>(1001,0));
//  vector<vector<int>> ans(1001,vector<int>(1001,0));
//  vector<vector<int>> visited(1001,vector<int>(1001,0));

// pair<int,int> goal;
// int dy[4]={1,-1,0,0};
// int dx[4]={0,0,1,-1};
// void bfs(int y, int x){
//     visited[y][x]=1;
//     queue<pair<int,int>> q;
//     q.push({y,x});
//     while(!q.empty()){
//         int ny=q.front().first;
//         int nx=q.front().second;
//         q.pop();
//         for(int i=0;i<4;i++){
//             int Y=ny+dy[i];
//             int X=nx+dx[i];
//             if(Y==y && X==x){
//                 continue;
//             }
//             if(Y>=0 &&X>=0 &&Y<n &&X<m && map[Y][X]!=0 && ans[Y][X]==0){
//                 visited[Y][X]=1;
//                 ans[Y][X]=ans[ny][nx]+map[Y][X];
//                 q.push({Y,X});
//             }
//         }
//     }
// }
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
//     cin>>n>>m;
//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//             cin>>map[i][j];
//             if(map[i][j]==2){
//                 goal={i,j};
//                 ans[i][j]=0;
//             }
//         }
//     }
//     bfs(goal.first,goal.second);
//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//             if(map[i][j]==0){
//                 cout<<0<<" ";
//             }else{
//                 if(visited[i][j]==1){
//                     cout<<ans[i][j]<<" ";
//                 }else{
//                     cout << -1<<" ";
//                 }
//             }
//         }
//         cout<<endl;
//     }
// }

// 겹치는 건 싫어
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main()
{
    vector<int> sequence;
    unordered_map<int, int> map;
    int N, K;
    cin >> N >> K;
    int tmp;
    for (int i = 0; i < N; i++)
    {
        cin>>tmp;
        sequence.push_back(tmp);
    }
    int start = 0;
    int end = 1;
    int max = 1;
    map[sequence[start]] += 1;
    while (end != N)
    {
        map[sequence[end]] += 1;
        if (map[sequence[end]] > K)
        {
            if (max < end - start)
            {
                max = end - start;
            }
            while (map[sequence[end]] != K)
            {
                map[sequence[start]] -= 1;
                start += 1;
            }
        }
        end++;
    }
    if (max < end - start)
    {
        max = end - start;
    }
    cout << max << "\n";
}
