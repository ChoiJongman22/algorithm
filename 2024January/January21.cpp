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

char rgb1[101][101];
char rgb2[101][101];

int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};
int N;
int ans1, ans2;
vector<vector<int> > visited(101, vector<int>(101, 0));
void bfs(char rgb[101][101], int y, int x)
{
    queue<pair<int, int> > q;
    visited[y][x] = 1;
    q.push({y, x});
    while (!q.empty())
    {
        int ny = q.front().first;
        int nx = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int ry = ny + dy[i];
            int rx = nx + dx[i];
            if (ry >= 0 && rx >= 0 && ry < N && rx < N && visited[ry][rx] == 0 && rgb[ny][nx] == rgb[ry][rx])
            {
                visited[ry][rx] = 1;
                q.push({ry, rx});
            }
        }
    }
}

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        string tmp;
        cin >> tmp;
        for (int j = 0; j < N; j++)
        {
            rgb1[i][j] = tmp[j];
            if (tmp[j] == 'G')
            {
                rgb2[i][j] = 'R';
            }
            else
            {
                rgb2[i][j] = tmp[j];
            }
        }
    }
    ans1 = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (visited[i][j] == 0)
            {
                bfs(rgb1, i, j);
                ans1 += 1;
            }
        }
    }
    cout << ans1 << " ";
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            visited[i][j] = 0;
        }
    }
    ans2 = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (visited[i][j] == 0)
            {
                bfs(rgb2, i, j);//특정지역부터 bfs하는게 맞아
                ans2 += 1;
            }
        }
    }
    cout << ans2;
}