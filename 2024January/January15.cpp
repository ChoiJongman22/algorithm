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

const int MAX_N = 8;
const int dx[] = {1, -1, 0, 0}; //x축이니까 좌우
const int dy[] = {0, 0, 1, -1}; //y축이니까 상하

int N, M;
vector<vector<int>> lab(MAX_N, vector<int>(MAX_N));
vector<vector<int>> tmp_lab(MAX_N, vector<int>(MAX_N)); // 복사할 lab입니다.

int max_safe_area = 0;                                   //답입니다.

void bfs()
{
    int safe_area = 0;
    queue<pair<int, int>> q; //바이러스가 있는 x,y좌표 pair
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            tmp_lab[i][j] = lab[i][j];
            if (tmp_lab[i][j] == 2)
            {
                q.push({i, j}); //pair로 push시 꼭 중괄호 삽입해야함.
            }
        }
    }
    //bfs는 queue여야함. queue의 top에 있는 부분을 기준으로 너비우선 탐색을 하고 선입선출로 들어온 것 먼저 탐색하는 방법입니다.
    while (!q.empty())
    {
        //따라서, queue가 비어있을 떄까지 계속 진행해야합니다.
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int dir = 0; dir < 4; dir++)
        {
            int nx = x + dx[dir]; //x축을 기준으로 좌 우를 탐색
            int ny = y + dy[dir];

            if (nx >= 0 && nx < N && ny >= 0 && ny < M && tmp_lab[nx][ny] == 0)
            {
                tmp_lab[nx][ny] = 2; //바이러스 전염시키기
                q.push({nx, ny});    //얘 다음 애들도 다 전염되는거임.
            }
        }
    }
    //안전 지역 세기
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (tmp_lab[i][j] == 0)
            {
                safe_area += 1;
            }
        }
    }
    max_safe_area=(max(max_safe_area, safe_area)); //더 많은 안전 지역 계산
}
void print()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cout<<lab[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void build_walls(int cnt)
{
    if (cnt == 3)
    {
        bfs(); //벽을 더이상 세울 수 없으니 탐색하라
        return;
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (lab[i][j] == 0)
            {
                lab[i][j] = 1;  //벽을 세우고
                //print();
                build_walls(cnt+1); //다시 벽을 세우기(재귀적으로 현 상황에서 가능한 모든 경우를 다 생각해보기)
                lab[i][j] = 0;
            }
        }
    }
}

int main()
{   
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            int tmp;
            cin >> tmp;
            lab[i][j] = tmp;
        }
    }
    //입력 완료

    build_walls(0);
    cout<<max_safe_area<<"\n";
}