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
#define MIN -1000000001
#define MAX 1000000001

vector<vector<int> > table(1001, vector<int>(1001, 0));
vector<vector<int> > days(1001, vector<int>(1001, -1));
int mindays = 0;
int dy[4] = {1, -1, 0, 0}; //상하
int dx[4] = {0, 0, 1, -1}; //좌우
int M, N;

void bfs()
{
    queue<pair<int, int> > q;
     for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (table[i][j] == 1)
            {
                q.push({i, j});
                days[i][j] = 0;
            }
        }
    }
    while (!q.empty())
    {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && ny >= 0 && nx < M && ny < N && days[ny][nx] == -1 && table[ny][nx] == 0)
            {
                q.push({ny, nx});
                table[ny][nx] = 1;
                days[ny][nx]=days[y][x]+ 1;
                mindays = max(mindays, days[ny][nx]);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int start, end;
    cin >> M >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> table[i][j];
        }
    }
    bfs();
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (table[i][j] == 0 && days[i][j] == -1)
            {
                cout << -1 << endl;
                return 0;
            }
        }
    }
    cout << mindays<< "\n";
    return 0;
}