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
using namespace std;
#define INF 10000000
#define MAX 31

//N은 y(상하), M은 x(좌우)
int T;
int safety = 0;
int ans = 0;
vector<vector<int> > safe(101, vector<int>(101, 0));
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};
vector<vector<int> > visited(101, vector<int>(101, 0));
void bfs(int h, int start, int end)
{
    queue<pair<int, int> > q;
    q.push({start, end});
    visited[start][end] = 1;
    while (!q.empty())
    {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int ny = dy[i] + y;
            int nx = dx[i] + x;
            if (ny >= 0 && nx >= 0 && ny < T && nx < T && visited[ny][nx] == 0 && safe[ny][nx] > h)
            {
                visited[ny][nx] = 1;
                q.push({ny, nx});
            }
        }
    }
}
void reset()
{
    for (int i = 0; i < T; i++)
    {
        for (int j = 0; j < T; j++)
        {
            visited[i][j] = 0;
        }
    }
    safety = 0;
}

int main()
{
    cin >> T;
    int maxh = 0;
    for (int i = 0; i < T; i++)
    {
        for (int j = 0; j < T; j++)
        {
            cin >> safe[i][j];
            if (maxh < safe[i][j])
            {
                maxh = safe[i][j];
            }
        }
    }
    //최대 높이를 순회하면서
    for (int i = 0; i <= maxh; i++)//높이가 0일떄도 확인해줘야하는거구나.
    {
        int safety=0;
        for (int y = 0; y < T; y++)
        {
            for (int x = 0; x < T; x++)
            {
                if (safe[y][x] > i && visited[y][x]==0)
                {
                    bfs(i, y, x);
                    safety += 1;
                }
            }
        }
        if (ans < safety)
        {
            ans = safety;
        }
        reset();
    }
    cout << ans;
    return 0;
}
