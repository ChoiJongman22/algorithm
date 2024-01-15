#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 1001; // 최대 노드 수에 맞게 설정

int N, M;
vector<vector<int>> graph(MAX);
vector<int> visited(MAX, 0); // 초기값을 0으로 설정
int ans = 0;

void bfs(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = 1; // 시작 노드를 방문한 것으로 표시

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int i = 0; i < graph[node].size(); i++) {
            int nextNode = graph[node][i];
            if (visited[nextNode] == 0) {
                visited[nextNode] = 1;
                q.push(nextNode);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        graph[tmp1].push_back(tmp2);
        graph[tmp2].push_back(tmp1);
    }

    for (int i = 1; i <= N; i++) {
        if (visited[i] == 0) {
            bfs(i); // 방문하지 않은 노드부터 BFS 탐색
            ans++; //새롭게 연결되는 노드의 개수를 count
        }
    }

    cout << ans << "\n";

    return 0;
}
