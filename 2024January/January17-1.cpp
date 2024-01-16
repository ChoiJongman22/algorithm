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

// int answer = 0;
// //프로그래머스 타겟 넘버
// void getTargetNumber(vector<int> numbers, int target, int sum, int index) {
//     // 재귀는 항상 종료 조건을 명시해야 함.
//     if (numbers.size() == index) {
//         if (target == sum) {
//             answer += 1;
//         }
//         return;
//     }
//     getTargetNumber(numbers, target, sum + numbers[index], index + 1);
//     getTargetNumber(numbers, target, sum - numbers[index], index + 1);
// }
// //순서 지키기
// int solution(vector<int> numbers, int target) {
//     getTargetNumber(numbers, target, 0, 0);
//     return answer;
// }

// int main() {
//     cout << solution({1, 1, 1, 1, 1}, 3) << endl;
//     return 0;
// }

// #include <iostream>
// #include <vector>
// #include <stack>
// using namespace std;
//스택으로 구현하는 방법도 꼭 알아두자.
// int solution(vector<int> numbers, int target)
// {
//     int answer = 0;
//     stack<pair<int, int> > s;
//     s.push({0, 0});

//     while (!s.empty())
//     {
//         int sum = s.top().first;
//         int index = s.top().second;
//         s.pop();

//         if (index == numbers.size())
//         {
//             if (sum == target)
//             {
//                 answer++;
//             }
//         }
//         else
//         {
//             s.push({sum + numbers[index], index + 1});
//             s.push({sum - numbers[index], index + 1});
//         }
//     }

//     return answer;
// }

// int main()
// {
//     cout << solution({1, 1, 1, 1, 1}, 3) << endl;
//     return 0;
// }

int answer = 0;
vector<vector<int> > visited(101, vector<int>(101, 0));
int dx[4] = {1, -1, 0, 0}; //큰 인덱스
int dy[4] = {0, 0, 1, -1}; //작은 인덱스로 생각하자.
queue<pair<int, int> > q;
vector<vector<int> > bfsmap(101, vector<int>(101, 0));

int solution(vector<vector<int> > maps)
{
    int size1 = maps.size();
    int size2 = maps[0].size();
    q.push({0, 0});   //x,y좌표 대입
    bfsmap[0][0] = 1; //시작점이니까
    visited[0][0] = 1;
    // q.push(make_pair(0,0)); //C+11버전에서는 중괄호를 더 선호함

    //bfs시작점입니다.
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = dx[i] + x;
            int ny = dy[i] + y;
            if (nx >= 0 && ny >= 0 && nx < size1 && ny < size2 && visited[nx][ny] == 0 && maps[nx][ny] == 1)
            {
                //범위를 벗어나지 않았거나 ~~ 방문 안했거나 ~~ 경로가 있거나
                visited[nx][ny] = 1;
                q.push({nx, ny});
                bfsmap[nx][ny] = bfsmap[x][y] + 1;
            }
        }
    }
    if (!bfsmap[size1 - 1][size2 - 1])
    {
        answer = -1;
    }
    else
    {
        answer = bfsmap[size1 - 1][size2 - 1];
    }

    return answer;
}

int main()
{
    cout << solution({{1, 0, 1, 1, 1}, {1, 0, 1, 0, 1}, {1, 0, 1, 1, 1}, {1, 1, 1, 0, 1}, {0, 0, 0, 0, 1}});
}