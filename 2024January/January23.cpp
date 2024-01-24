#include <string>
#include <vector>
#include <iostream>
using namespace std;
//프로그래머스 섬 연결하기
// struct Node{
//     int start;
//     int end;
//     int cost;
// };

// bool compare(const Node &a, const Node &b){
//     return a.cost<b.cost;
// }

// vector<int> parent;

// int findParent(int x){
//     if(parent[x]==x)return x;
//     cout<<x<<"의 부모는 "<<parent[x]<<"\n";
//     return parent[x]=findParent(parent[x]);//재귀로 부모를 찾아가는 방법임

// }

// int solution(int n, vector<vector<int>> costs) {
//     int answer = 0;
//     vector<Node> edges;

//     for(vector<int> cost:costs){
//         edges.push_back({cost[0],cost[1],cost[2]});//start, end, cost
//     }
//     sort(edges.begin(),edges.end(),compare);
//     for(Node edge: edges){
//         cout << edge.start <<" " <<edge.end<<" "<<edge.cost <<endl;
//         //start, end, cost
//     }
//     parent.resize(n);
//     for(int i=0;i<n;i++){
//         parent[i]=i;
//     }
//     for(Node edge: edges){
//         int start = edge.start;
//         int end=edge.end;
//         int cost=edge.cost;
//         cout<<"start "<<start<<endl;
//         cout<<"end "<<end<<endl;
//         cout<<"cost "<<cost<<endl;
//         int parentstart=findParent(start);
//         int parentend=findParent(end);
//         cout<<parentstart <<" "<<parentend<<"\n";
//         if(parentstart!=parentend){
//             parent[parentstart]=parentend;
//             cout<<cost<<endl;
//             answer+=cost;
//             cout<<"Answer: "<<answer<<endl;
//         }
//     }

//     return answer;
// }

// int main(){
//     solution(4,{{0,1,1},{0,2,2},{1,2,5},{1,3,1},{2,3,8}});
//     return 0;
// }

//구명 보트




int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(),people.end());
    int sum=0;
    int s=0;
    int e=people.size()-1;
    while(s<=e){
        if(people[s]+people[e]<=limit){
            s++;
        }
        e--;
        answer++;
    }
    return answer;
}

int main(){
    cout<<solution({70,50,80,50},100);
}