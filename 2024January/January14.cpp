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

#define MAX 31
vector<vector<int> > dp(MAX, vector<int>(MAX));

int main()
{
    int testcase;
    int M, N;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> testcase;

    for (int i = 1; i < MAX; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (j == 0)
            {
                dp[i][j] = 1;
            }
            else if (i == j)
            {
                dp[i][j] = 1;
            }
            else
            {
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            }
        }
    }
    for (int i = 0; i < testcase; i++)
    {
        cin >> N >> M;
        cout << dp[M][N] << '\n';
    }
}