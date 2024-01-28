// #include <string>
// #include <vector>
// #include <iostream>
// using namespace std;
// 네트워크
// vector<int> visited;
// void dfs(vector<vector<int>> &computers,int start ){
//     visited[start]=1;
//     for(int i=0;i<computers.size();i++){
//         if(visited[i]==0 && computers[start][i]==1){
//             dfs(computers,i);
//         }
//     }
// }

// int solution(int n, vector<vector<int>> computers) {
//     int answer = 0;
//     visited.resize(n);
//     for(int i=0;i<n;i++){
//         if(visited[i]==0){
//             dfs(computers,i);
//             answer+=1;
//         }
//     }
//     return answer;
// }

// int main(){
//     cout << solution(3,{{1,1,0},{1,1,0},{0,0,1}});
// }

// 여행 경로: 오타 진짜 잘 점검하자^^
//  #include <string>
//  #include <vector>
//  #include <iostream>
//  using namespace std;

// vector<vector<string>> ticket;
// vector<int> visited(100001,0);
// vector<string> answers;
// bool isAnswer=false;
// void dfs(string start, int tckCnt){
//     answers.push_back(start);
//     if(tckCnt==ticket.size()){
//         isAnswer=true;
//     }
//     for(int i=0;i<ticket.size();i++){
//         if(visited[i]==0 && ticket[i][0]==start){
//             visited[i]=1;
//             dfs(ticket[i][1],tckCnt+1);
//             if(isAnswer==false){
//                 //백트래킹
//                 answers.pop_back();
//                 visited[i]=0;
//             }
//         }
//     }
// }

// vector<string> solution(vector<vector<string>> tickets) {
//     vector<string> answer;
//     sort(tickets.begin(),tickets.end());
//     ticket=tickets;
//     dfs("ICN",0);
//     answer=answers;
//     return answer;
// }

// int main(){
//     vector<string> ans=solution({{"ICN","JFK"},{"HND","IAD"},{"JFK","HND"}});
//     for(int i=0;i<ans.size();i++){
//         cout<<ans[i]<<endl;
//     }
// }

// 토마토 복습

// #include <iostream>
// #include <queue>
// #include <algorithm>
// #include <vector>
// #include <string>
// using namespace std;
// vector<vector<int>> tables(1001, vector<int>(1001, 0));
// vector<vector<int>> days(1001, vector<int>(1001, -1));
// int dy[4] = {1, -1, 0, 0};
// int dx[4] = {0, 0, 1, -1};
// int y, x;
// int M, N;
// int mindays = 0;
// void bfs()
// {
//     queue<pair<int, int>> q;
//     for (int i = 0; i < N; i++)
//     {
//         for (int j = 0; j < M; j++)
//         {
//             if (tables[i][j] == 1)
//             {
//                 q.push({i, j});
//                 days[i][j] = 0;
//             }
//         }
//     }
//     while (!q.empty())
//     {
//         int sy = q.front().first;
//         int sx = q.front().second;
//         q.pop();
//         for (int i = 0; i < 4; i++)
//         {
//             int ny = sy + dy[i];
//             int nx = sx + dx[i];
//             if (ny >= 0 && nx >= 0 && ny < N && nx < M && tables[ny][nx] == 0 && days[ny][nx] == -1)
//             {
//                 q.push({ny, nx});
//                 days[ny][nx] = days[sy][sx] + 1;
//                 tables[ny][nx] = 1;
//                 mindays = max(mindays, days[ny][nx]);
//             }
//         }
//     }
// }
// int main()
// {
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
//     cin >> M >> N;
//     for (int i = 0; i < N; i++)
//     {
//         for (int j = 0; j < M; j++)
//         {
//             cin >> tables[i][j];
//         }
//     }
//     bfs();
//     for (int i = 0; i < N; i++)
//     {
//         for (int j = 0; j < M; j++)
//         {
//             if (tables[i][j] == 0 && days[i][j] == -1)
//             {
//                 cout << -1 << "\n";
//                 return 0;
//             }
//         }
//     }
//     cout << mindays << "\n";
//     return 0;
// }

// 안전 영역
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

int N;
int ans = 0;
int safety=0;
vector<vector<int>> graph(101, vector<int>(101, 0));
vector<vector<int>> visited(101, vector<int>(101, 0));
int dy[4]={1,-1,0,0};
int dx[4]={0,0,1,-1};

void bfs(int h, int y, int x)
{
    queue<pair<int,int>> q;
    visited[y][x]=1;
    q.push({y,x});
    while(!q.empty()){
        int sy=q.front().first;
        int sx=q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int ny=sy+dy[i];
            int nx=sx+dx[i];
            if(ny>=0 && nx>=0 && ny<N &&nx<N && visited[ny][nx]==0 &&graph[ny][nx]>h){
                q.push({ny,nx});
                visited[ny][nx]=1;
            }
        }
    }

}

void reset()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            visited[i][j] = 0;
        }
    }
    safety = 0;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    int maxh = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> graph[i][j];
            if (maxh < graph[i][j])
            {
                maxh = graph[i][j];
            }
        }
    }
    for (int i = 0; i <= maxh; i++)
    {
        int safety=0;
        for (int y = 0; y < N; y++)
        {
            for (int x = 0; x < N; x++)
            {
                if (graph[y][x] > i && visited[y][x] == 0)
                {
                    bfs(i, y, x);
                    safety += 1;
                }
            }
        }
        if(ans<safety){
            ans=safety;
        }
        reset();
    }
    cout<<ans;
    return 0;
    
}