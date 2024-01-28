#include <iostream>
#include <vector>
using namespace std;
#define MAX -1
int T;
vector<vector<int>> bambu(501, vector<int>(501, 0));
vector<vector<int>> dp(501, vector<int>(501, 0));


int ans = MAX;
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};
int dfs(int start, int end)
{  
    if(dp[start][end]!=0){
        return dp[start][end];
    }
    dp[start][end]=1;
    for (int i = 0; i < 4; i++)
    {
        int ny = start + dy[i];
        int nx = end + dx[i];
        if (ny >= 0 && nx >= 0 && ny < T && nx < T)
        {
            int dif = bambu[ny][nx] - bambu[start][end];
            if (dif > 0)
            {

                dp[start][end]=max(dp[start][end],dfs(ny, nx)+1);
            }
        }
    }
    return dp[start][end];
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        for (int j = 0; j < T; j++)
        {
            cin >> bambu[i][j];
        }
    }
    for (int i = 0; i < T; i++)
    {
        for (int j = 0; j < T; j++)
        {
            ans=max(ans,dfs(i, j));
        }
        
    }
    cout << ans;
}