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
// int N, M, K;
// vector<vector<int> > table(101, vector<int>(101, 0));
// vector<vector<int> > visited(101, vector<int>(101, 0));
// vector<int> answer;
// int dy[4] = {1, -1, 0, 0};
// int dx[4] = {0, 0, 1, -1};
// void dfs(int y, int x)
// {
//     visited[y][x] = 1; // 방문 처리
//     answer.back()++;
//     for (int i = 0; i < 4; i++)
//     {
//         int ny = y + dy[i];
//         int nx = x + dx[i];
//         if (ny >= 0 && nx >= 0 && ny < M && nx < N && table[ny][nx] != 1 && visited[ny][nx] == 0)
//         {
//             dfs(ny, nx);
//         }
//     }
// }
// int main()
// {
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
//     cin >> M >> N >> K;
//     for (int i = 0; i < K; i++)
//     {
//         int x1, y1, x2, y2;
//         cin>>x1>>y1>>x2>>y2;
//         for (int x = x1; x < x2; x++)
//         {
//             for (int y = y1; y < y2; y++)
//             {
//                 table[y][x]=1;
//             }
//         }
//     }
//     for (int i = 0; i < M; i++)
//     {
//         for (int j = 0; j < N; j++)
//         {
//             if (table[i][j] == 0 && visited[i][j] == 0)
//             {
//                 answer.push_back(0);
//                 dfs(i, j);
//             }
//         }
//     }
//     cout<<answer.size()<<"\n";
//     sort(answer.begin(), answer.end());
//     for(int i=0;i<answer.size();i++){
//         cout<<answer[i]<<"\n";
//     }
// }
vector<vector<int>> c;
vector<int> visited;
int ans = 0;
int bfs(int start, int target)
{
    queue<pair<int, int>> q;
    q.push({start, 0});
    visited[start] = 1;
    while (!q.empty())
    {
        int current = q.front().first;
        int chon = q.front().second;
        q.pop();
        if (current == target)
        {
            return chon;
        }
        for (int i = 0; i < c[current].size(); i++)
        {
            if (c[current][i]!=0 && visited[i] == 0)
            {
                {
                    q.push({i, chon + 1}); // 촌수를 올려서 매개변수로 넘겨주기
                    visited[i] = 1;
                }
            }
        }
    }
}
int main()
{
    int start, target;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T, m;

    cin >> T;
    cin >> start >> target;
    cin >> m;
    c.resize(T + 1, vector<int>(T + 1));
    visited.resize(T + 1, 0);
    for (int i = 0; i < m; i++)
    {
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        c[tmp1][tmp2] = 1;
        c[tmp2][tmp1] = 1;
    }
    cout << bfs(start, target) << "\n";
}
// int n,m;
// int start,target;
// vector<vector<int>> arr(101,vector<int>(101));
// vector<int> visited(101,0);

// void bfs(int k){
//     queue<int> q;
//     q.push(k);
//     while(!q.empty()){
//         k=q.front();
//         q.pop();
//         for(int i=0;i<=n;i++){
//             if(arr[k][i]!=0 && visited[i]==0){
//                 q.push(i);
//                 visited[i]=visited[k]+1;
//             }
//         }
//     }

// }

// int main(){
//     cin>>n;
//     cin>>start>>target;
//     cin>>m;
//     for(int i=0;i<m;i++){
//         int x,y;
//         cin>>x>>y;
//         arr[x][y]=1;
//         arr[y][x]=1;
//     }
//     bfs(start);
//     if(visited[target]==0){
//         visited[target]=-1;
//     }
//     cout<<visited[target];

// }