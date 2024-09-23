#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;
    vector<int> T(N + 1), P(N + 1), dp(N + 2, 0);  // dp 크기를 N+2로 설정하여 안전하게 처리

    // 상담 기간과 수익 입력
    for (int i = 1; i <= N; i++) {
        cin >> T[i] >> P[i];
    }

    // 역순으로 DP 계산
    for (int i = N; i >= 1; i--) {
        if (i + T[i] - 1 > N) {  // 상담을 진행할 수 없는 경우
            dp[i] = dp[i + 1];
        } else {  // 상담을 진행할 수 있는 경우
            dp[i] = max(dp[i + 1], P[i] + dp[i + T[i]]);
        }
    }

    // 최대 수익 출력
    cout << dp[1] << "\n";

    return 0;
}
