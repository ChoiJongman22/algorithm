#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <stack>
#include <unordered_map>
#include <queue>
#include <deque>
#include <cmath> //pow함수 선언
#include <limits.h>

#define MAX 20001
using namespace std;
#define INF 987654321
int t;
int dp[501][501]={0,};
int sum[501]={0,};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);    
    cin >> t;
    while(t--) {
        int k;
        cin >> k;
        for(int i=1 ; i<=k ; i++) {
            int a;
            cin >> a;
            sum[i] = sum[i-1] + a; // 1~x 번째 파일까지의 크기 합
            cout<<i<<"번째까지 파일의 합"<<sum[i]<<endl;
        }
        
        for(int i=1 ; i<k ; i++) { // i는 구해야하는 범위를 의미 -> ex. i=1이면 1~2번째 파일 등을 합칠 때를 의미
            for(int x=1 ; x<=k-i ; x++) { //x는 합치는 범위의 시작 부분을 의미 -> i가 범위를 의미하므로 k-i까지만 해주면 k까지 탐색하게 된다.
                int y = x+i;
                dp[x][y] = INT_MAX; // x~y 번째 파일들을 합치는데 필요한 최소 비용
                cout<<"-------------"<<endl;
                cout<<x<<"부터 "<<y<<" 까지의 최소 비용: "<<dp[x][y]<<endl;
                for(int mid = x ; mid<y ; mid++) { // mid는 구해야하는 범위를 두 부분으로 나누는 기준점을 의미
                    cout<<x<<"부터 "<<mid<<"까지의 합"<<dp[x][mid]<<endl;
                    cout<<mid+1<<"부터 "<<y<<"까지의 합"<<dp[mid+1][y]<<endl;
                    cout<<"첫번째부터 "<<y<<"까지의 합"<<sum[y]<<endl;
                    cout<<"첫번째부터 "<<x-1<<"까지의 합"<<sum[x-1]<<endl;
                    cout<<"비교: "<<dp[x][y]<<"와 "<<dp[x][mid] + dp[mid+1][y] + sum[y] - sum[x-1]<<endl;
                    //sum[y]-sum[x-1]은 예를 들어 2~4까지의 최솟값을 구하고 싶으면 먼저 2~2와 3~4의 합 + 전체 합 - 1까지의 합을 해주면 됌.
                    //그니까 이 부분은 3~4의 합에다가 마지막에 2를 더한 합을 다시 더해줘야하니까 전체에서 1까지의 합을 빼서 계산함. 와 천재..
                    cout<<"-------------"<<endl;
                    dp[x][y] = min(dp[x][y], dp[x][mid] + dp[mid+1][y] + sum[y] - sum[x-1]);
                    // dp[n][n]은 0이기 때문에 sum[y] - sum[x-1]로 dp[x][y]를 갱신
                }
            }
        }
        cout << dp[1][k] << "\n";
    }
    return 0;
}