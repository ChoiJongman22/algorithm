#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int>> go(19, vector<int>(19));
//왜 틀렸는지 모름
int moving[4][2] = { {0, 1}, {1, 0}, {1, 1},{-1, 1},}; // 아래로, 오른쪽으로, 우상향대각, 우하향대각
int visited[19][19][4][3]={0,};                            // y,x,방향,색깔(4차원 배열을 선언해서라도 내가 원하는 결과를 얻어내기 : dir 내가 고민하던 방향을 이렇게 명시)
int dfs(int y, int x, int dir, int color, int cnt)
{
    if (cnt == 6) {
        return 0;
    }
    visited[y][x][dir][color] = 1;
    int ny = moving[dir][0] + y;
    int nx = moving[dir][1] + x;
    if (ny < 0 || nx < 0 || ny >= 19 || nx >= 19 || go[ny][nx] != color)
    {
        if (cnt == 5 && (y - moving[dir][0] < 0 || x - moving[dir][1] < 0 || 
            y - moving[dir][0] >= 19 || x - moving[dir][1] >= 19 || 
            go[y - moving[dir][0]][x - moving[dir][1]] != color)) {
            return color;
        }
        return 0;
    }
    return dfs(ny, nx, dir, color, cnt + 1);
}
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    for (int i = 0; i < 19; i++)
    {
        for (int j = 0; j < 19; j++)
        {
            cin >> go[i][j];
        }
    }

    for (int i = 0; i < 19; i++)
    {
        for (int j = 0; j < 19; j++)
        {
            if (go[i][j] != 0)
            {
                for (int dir = 0; dir < 4; dir++)
                {
                    if (visited[i][j][dir][go[i][j]] == 1)
                    {
                        continue;
                    }
                    if (dfs(i, j, dir, go[i][j], 1) != 0)
                    {
                        cout << go[i][j] << "\n" << i + 1 << ' ' << j + 1 <<"\n";
                        return 0;
                    }
                }
            }
        }
    }
    cout << 0;
    return 0;
}