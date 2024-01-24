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
#include <utility> // std::pair 헤더
using namespace std;
#define MAX 1000001
// 큰 수 만들기
//  string solution(string number, int k)
//  {
//      string answer = "";
//      int idx = -1;
//      for (int i = 0; i < number.size() - k; i++)
//      {
//          char maxV = ' ';
//          for (int j = idx + 1; j <= k + i; j++)
//          {
//              if (maxV < number[j])
//              {
//                  maxV = number[j];
//                  idx = j;
//              }
//          }
//          answer+=maxV;
//      }

//     return answer;
// }

// int main()
// {
//     cout << solution("1234",2);
// }
//dp 도둑질
// int solution(vector<int> money)
// {
//     int answer = 0;
//     int n = money.size();

//     vector<int> dp(n);

//     dp[0] = money[0];
//     dp[1] = max(money[0], money[1]);

//     for (int i = 2; i < n - 1; i++)
//     {
//         dp[i] = max(dp[i - 1], dp[i - 2] + money[i]);
//     }

//     int max1 = dp[n - 2]; // 마지막 집을 털지 않는 경우

//     dp[0] = 0;
//     dp[1] = money[1];

//     for (int i = 2; i < n; i++)
//     {
//         dp[i] = max(dp[i - 1], dp[i - 2] + money[i]);
//     }

//     int max2 = dp[n - 1]; // 첫 번째 집을 터는 경우

//     answer = max(max1, max2); // 두 경우 중에서 더 큰 값을 선택

//     return answer;
// }

// int main()
// {
//     cout << solution({1, 2, 3, 1, 5});
// }

//dp 정수 삼각형

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    vector<vector<int>> dp(501,vector<int>(501,0));
    dp[0][0]=triangle[0][0];

    for(int i=1;i<triangle.size();i++){
        for(int j=0;j<=i;j++){
            if(j==0){
                dp[i][j]=triangle[i][j]+dp[i-1][0];
            }else if(j==i){
                dp[i][j]=triangle[i][j]+dp[i-1][j-1];

            }else{
                dp[i][j]=max(dp[i-1][j-1],dp[i-1][j])+triangle[i][j];
            }
        }
    }
    for(int i=0;i<triangle.size();i++){
        if(answer<dp[triangle.size()-1][i]){
            answer=dp[triangle.size()-1][i];
        }
    }
    return answer;
}

int main(){
    cout<<solution({{7},{3,8},{8,1,0},{2,7,4,4},{4,5,2,6,5}});
}