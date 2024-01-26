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
#define INF 10000000

// 거스름돈 기본 그리디
// int main()
// {
//     int coins[] = {500, 100, 50, 10}; // 화폐 단위
//     int n, count = 0;
//     cin >> n; // 거슬러 줘야 할 금액

//     for (int i = 0; i < 4; i++)
//     {
//         count += n / coins[i];
//         cout << "count : " << count << endl;
//         n %= coins[i];
//         cout << "n : " << n << endl;
//     }

//     cout << count; // 사용된 총 화폐 개수
//     return 0;
// }

// 설탕배달

// int main()
//  {
//      ios::sync_with_stdio(0);
//      cin.tie(0);
//      cout.tie(0);
//      int N;
//      cin >> N;
//      int count = 0;
//      while (N >= 0)
//      {
//          if (N % 5 == 0)
//          {
//              count += N / 5; //5로 나누는게 가장 유의미하기때문에
//              cout << count;
//              return 0;
//          }
//          N -= 3;
//          count++;
//      }
//      cout << -1;
//  }

// 동전 0, 생각을 좀 깊게 좀
// int main()
// {
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
//     int N, K;
//     cin >> N >> K;
//     vector<int> vec;
//     for (int i = 0; i < N; i++)
//     {
//         int tmp;
//         cin >> tmp;
//         vec.push_back(tmp);
//     }
//     int count = 0;
//     sort(vec.rbegin(), vec.rend()); //내림차순
//     for (int i = 0; i < N; i++)
//     {
//         while (K >= vec[i])
//         {
//             count += K / vec[i];
//             K %= vec[i];
//         }
//     }
//     cout << count << "\n";
// }

// 잃어버린 괄호

int main()
{
    string a = "";
    cin >> a;
    string num = "";
    int answer=0;
    bool isMinus=false;
    for (int i = 0; i <= a.size(); i++)
    {
        if (a[i] == '-' || a[i] == '+' || i == a.size())
        {
            if (isMinus)
            {
                answer -= stoi(num);
                num="";//초기화 반드시
            }
            else
            {
                answer += stoi(num);
                num="";
            }
        }
        else
        {
            num += a[i];
        }
        if (a[i] == '-')
        {
            isMinus = true;
        }
    }
    cout<<answer<<"\n";
}
