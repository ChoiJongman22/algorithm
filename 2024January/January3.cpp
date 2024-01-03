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
#define MAX 20001
using namespace std;
#define INF 987654321

int v, e;
int start;
int Dist[MAX];
vector<pair<int, int>> Vertex[MAX];

void input() {
    cin >> v >> e >> start;
    for (int i = 0; i < e; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        Vertex[a].push_back(make_pair(b, c));
    }
    for (int i = 1; i <= v; i++) {
        Dist[i] = INF;
    }
}

void solution() {
    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(0, start));
    Dist[start] = 0;
    while (pq.empty() == 0) {
        int cost = -pq.top().first; // 가중치
        int cur = pq.top().second;   // 노드
        cout << "현재 노드: " << start << "에서 부터 " << cur << "까지의 가중치: " << cost << endl;

        pq.pop();
        
        cout << "Priority Queue Contents: ";
        priority_queue<pair<int, int>> temp_pq = pq;  // Create a copy for printing
        while (!temp_pq.empty()) {
            cout << "(" << -temp_pq.top().first << ", " << temp_pq.top().second << ") ";
            temp_pq.pop();
        }
        cout << endl;

        for (int i = 0; i < Vertex[cur].size(); i++) {
            int Next = Vertex[cur][i].first; // 다음노드
            int nCost = Vertex[cur][i].second; // 가중치
            cout<<"지금부터 "<<cur<<"만 따지려구"<<endl;
            cout<<"지금 cost는 "<<cost<<"입니다."<<endl;
            cout <<cur<<"에서 "<<Next<<"로의 가중치" <<nCost << endl;
            cout <<"1에서 "<< Next << "까지의 저장된 거리" << Dist[Next]<< endl;
            cout<<"cost+nCost ="<<cout+nCost<<endl;
            if (Dist[Next] > cost + nCost) {
                Dist[Next] = cost + nCost;
                cout << "1에서 " << Next << "까지의 거리 " << Dist[Next] << "로 갱신" << endl;
                pq.push(make_pair(-Dist[Next], Next));
            }
        }
    }
    for (int i = 1; i <= v; i++) {
        if (Dist[i] == INF)
            cout << "INF" << "\n";
        else
            cout << Dist[i] << "\n";
    }
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    input();
    solution();
    return 0;
}
