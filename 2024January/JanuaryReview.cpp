#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define INF_MAX 9999999
// vector<int> filesum(501, 0);
// vector<vector<int>> dp(501, vector<int>(501, 0));
// 파일 합치기
// int main()
// {
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
//     int T;
//     int t;
//     cin >> T;
//     int file;
//     for (int i = 0; i < T; i++)
//     {
//         cin >> t;
//         for (int j = 1; j < t + 1; j++)
//         {
//             cin >> file;
//             filesum[j] = filesum[j - 1] + file; // 누적합만 구해놓아도 충분하다.
//         }
//         for (int u = 1; u < t; u++)
//         {
//             for (int x = 1; x <= t - u; x++)
//             {
//                 int y = x + u;
//                 dp[x][y] = INF_MAX;
//                 for (int mid = x; mid < y; mid++)
//                 {
//                     dp[x][y] = min(dp[x][y], dp[x][mid] + dp[mid + 1][y] + filesum[y] - filesum[x - 1]);
//                 }
//             }
//         }
//         cout<<dp[1][t]<<"\n";
//     }
// }

// 설탕배달
//  vector<int> sugar(5001,0);

// int main(){
//     int N;
//     cin>>N;
//     sugar[3]=1;
//     sugar[5]=1;
//     for(int i=6;i<=N;i++){
//         if(i%3==0){
//             sugar[i]=sugar[i-3]+1;
//         }
//         if(i%5==0){
//             sugar[i]=sugar[i] ? min(sugar[i] ,sugar[i-5]+1) :sugar[i-5]+1;//sugar[i]가 있으면 최솟값, 아니면 그냥 더하기 1해
//         }
//     }
//     if(sugar[N]==0){
//         cout<<-1;
//         return 0;
//     }
//     cout<<sugar[N]<<endl;
// }

// 부녀회장이 될테야

// int T;
// vector<vector<int>> dp(15,vector<int>(15,0));
// int main(){
//     cin>>T;
//     for(int i=0;i<dp.size();i++){
//         dp[i][1]=1;
//         for(int j=1;j<=dp[i].size();j++){
//             dp[0][j]=j;
//         }
//     }
//     while(T--){
//         int tmp1, tmp2;
//         cin>>tmp1;
//         cin>>tmp2;
//         for(int i=1;i<=tmp1;i++){
//             for(int j=2;j<=tmp2;j++){
//                 dp[i][j]=dp[i-1][j]+dp[i][j-1];
//             }
//         }
//         cout<<dp[tmp1][tmp2]<<"\n";
//     }
// }

// 인구 이동 (BFS)

int N, L, R;
vector<vector<int>> conti(51, vector<int>(51, 0));
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};
vector<vector<int>> visited(51, vector<int>(51, 0));
int sump = 0;
int ans = 0;
bool flag = true; // 연합(퍙균내기)
queue<pair<int, int>> q;
vector<pair<int, int>> q2;
void bfs(int y, int x)
{
    visited[y][x] = 1;
    q.push({y, x});
    q2.push_back({y,x});
    
    sump=conti[y][x];
    while (!q.empty())
    {
        int ny = q.front().first;
        int nx = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int Y = ny + dy[i];
            int X = nx + dx[i];
            if (X >= 0 && Y >= 0 && X < N && Y < N && visited[Y][X] == 0)
            {
                int dif = abs(conti[Y][X] - conti[ny][nx]);
                if (dif >= L && dif <= R)
                {
                    visited[Y][X] = 1;
                    sump += conti[Y][X];
                    q.push({Y, X});
                    q2.push_back({Y, X});
                }
            }
        }
    }
}

void clear()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            visited[i][j] = 0;
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> L >> R;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> conti[i][j];
        }
    }
    while (flag)
    {
        flag = false;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (visited[i][j] == 0)
                {
                    q2.clear();
                    bfs(i, j);
                }
                if (q2.size() >= 2)
                {
                    flag = true;
                    for (int u = 0; u < q2.size(); u++)
                    {
                        conti[q2[u].first][q2[u].second] = sump / q2.size();
                    }
                }
            }
        }

        if (flag)
        {
            ans++;
        }
        clear();
    }
    cout << ans;
}