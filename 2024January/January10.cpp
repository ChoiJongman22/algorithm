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

//기본 DFS 구현

//그래프 만들기(인접리스트)
// struct Graph
// {
//     int V;
//     vector<vector<int> > adj;      //인접리스트
//     Graph(int v) : V(v), adj(v){}; //정점수 v로 초기화, 크기가 V인 빈 인 접리스트로 초기화
//     void addEdge(int u, int v)
//     {
//         adj[u].push_back(v); //u->v로 연결된 간선 추가
//     }
// }; // 구조체 선언은 반드시 세미콜론을

// void dfs(Graph &graph, int v, vector<bool> &visited)
// {
//     //처음 매개변수 v는 시작점.
//     visited[v] = true; // 방문한 v
//     cout << v << " ";  // 노드 방문시 출력
//     for (int u : graph.adj[v])
//     {
//         if (!visited[u])
//         {                           // 방문하지 않았다면
//             dfs(graph, u, visited); //재귀 호출
//         }
//     }
// }

// void bfs(Graph &graph, int start)
// {
//     vector<bool> visited(graph.V, false); //방문 여부를 저장
//     queue<int> q;

//     visited[start] = true;
//     q.push(start);
//     while (!q.empty())
//     {
//         int u = q.front();
//         cout << u << " ";
//         q.pop();
//         for (int v : graph.adj[u])
//         {
//             if (!visited[v])
//             {
//                 visited[v] = true;
//                 q.push(v);
//             }
//         }
//     }
// }

// int main()
// {
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);

//     //DFS 실행
//     int V = 3; //노트의 수 0~5 6개
//     Graph graph(V);
//     graph.addEdge(1, 2);
//     graph.addEdge(1, 3);
//     graph.addEdge(1, 4);
//     graph.addEdge(2, 4);
//     graph.addEdge(3, 4);
//     vector<bool> visited(V, false);
//     cout << "DFS 탐색 결과:  ";
//     dfs(graph, 1, visited);

//         return 0;
// }
// void dfs(int start, vector<bool> &visited, vector<vector<int> > &dv)
// {
//     visited[start] = true;
//     cout << start << " ";
//     for (int u : dv[start])
//     {
//         if (!visited[u])
//         {
//             dfs(u, visited, dv);
//         }
//     }
// }

// void bfs(int start, vector<bool> &visited, vector<vector<int>> &dv)
// {
//     queue<int> q;
//     visited[start] = true;
//     q.push(start);

//     while (!q.empty())
//     {
//         int u = q.front();
//         q.pop();
//         cout << u << " ";

//         for (int v : dv[u])
//         {
//             if (!visited[v])
//             {
//                 visited[v] = true;
//                 q.push(v);
//             }
//         }
//     }
// }

// int main()
// {
//     int N, M, V;
//     cin >> N >> M >> V;
//     vector<bool> visited(50000, false);
//     vector<vector<int>> dv(50000, vector<int>());

//     for (int i = 0; i < M; i++)
//     {
//         int n1, n2;
//         cin >> n1 >> n2;
//         dv[n1].push_back(n2);
//         dv[n2].push_back(n1);
//     }

//     for (int i = 1; i <= N; i++) {
//         sort(dv[i].begin(), dv[i].end()); // 정점 번호가 작은 것부터 방문하기 위해 정렬
//     }
//     dfs(V, visited, dv);
//     fill(visited.begin(), visited.end(), false); // visited 배열 초기화

//     cout<<"\n";
//     bfs(V, visited, dv);
//     return 0;
// }

vector<vector<int> > adj(200);//넉넉하게 선언하자.
vector<bool> visited(200, false);
int ans=0;
//바이러스(DFS)
void dfs(int n)
{
    for(int u :adj[n]){
        if (!visited[u]){
            visited[u]=true;
            ans++;
            dfs(u);
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N, M;
    cin>>N>>M;
    for (int i = 0; i < M; i++)
    {
        int n, m;
        cin >> n >> m;
        adj[n].push_back(m);
        adj[m].push_back(n);
    }
    visited[1]=true;
    dfs(1);
    cout<<ans<<endl;
    return 0;
}