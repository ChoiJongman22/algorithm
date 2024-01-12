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

#define MAX 20001
using namespace std;
#define INF 10000000

// vector<vector<int> > bc(52, vector<int>(52));
// vector<vector<int> > visited(52, vector<int>(52));
// //위 아래 좌 우
// int dc[4] = {1, 0, -1, 0};
// int dr[4] = {0, 1, 0, -1};
// int M, N, K;

// void dfs(int n, int m)
// {
//     visited[n][m] = 1;

//     for (int i = 0; i < 4; i++)
//     {
//         int c = dc[i] + n;
//         int r = dr[i] + m;
//         if (c < 0 || c >= N || r < 0 || r >= M)
//         {
//             continue;
//         }
//         if (bc[c][r] == 1 && visited[c][r] != 1)
//         {
//             dfs(c, r);
//         }
//     }
// }
// int main()
// {
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
//     int testcase;
//     cin >> testcase;
//     for (int i = 0; i < testcase; i++)
//     {
//         cin >> M >> N >> K;
//         bc.assign(52, vector<int>(52, 0));
//         visited.assign(52, vector<int>(52, 0));
//         for (int j = 0; j < K; j++)
//         {
//             int tmp1, tmp2;
//             cin >> tmp2 >> tmp1;
//             bc[tmp1][tmp2] = 1; //큰 벡터가 세로열 안에 작은 벡터가 가로열 .... 진짜 개멍청한놈
//         }
//         int cnt = 0;
//         for (int a = 0; a < N; a++)
//         {
//             for (int b = 0; b < M; b++)
//             {
//                 if (bc[a][b] == 1 && visited[a][b] != 1)
//                 {
//                     cnt += 1;
//                     dfs(a, b);
//                 }
//             }
//         }
//         cout << cnt << "\n";
//     }

//     return 0;
// }

vector<int> v(301, 0);
vector<int> ans(301, 0);
int main()
{
    int testcase;
    cin >> testcase;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    for (int i = 1; i <= testcase; i++)
    {
        cin >> v[i];
    }
    ans[1] = v[1];
    ans[2] = v[1] + v[2];
    ans[3] = max(v[1] + v[3], v[2] + v[3]);
    for (int i = 4; i <= testcase; i++)
    {
        ans[i] = max(ans[i - 2] + v[i], ans[i - 3] + v[i - 1]+v[i]); //3개가 더해질 수도 있으니까?
    }
    cout<<ans[testcase]<<"\n";
    return 0;
}
