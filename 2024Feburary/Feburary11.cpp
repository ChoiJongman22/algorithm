// 가희와 키워드
#include <iostream>
#include <unordered_set>
#include <algorithm>
#include <cstring>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

// int main()
// {
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
//     int N, M;
//     cin >> N >> M;
//     string str = "", tmp = "", k = "";
//     unordered_set<string> st;
//     for (int i = 0; i < N; i++)
//     {
//         cin >> str;
//         st.insert(str);
//     }
//     while (M--)
//     {
//         cin >> tmp;
//         int pos = 0;
//         while (pos < tmp.length())
//         {
//             auto it = tmp.find(',', pos);
//             if (it == tmp.npos)
//             {                        //,가 없는 경우
//                 k = tmp.substr(pos); // 위치 전까지 자르기;
//                 if (st.find(k) != st.end())
//                 { // 발견할 경우
//                     st.erase(k);
//                 }
//                 break;
//             }
//             else
//             {
//                 k = tmp.substr(pos, it - pos);
//                 if (st.find(k) != st.end())
//                 {
//                     st.erase(k);
//                 }
//                 pos = it + 1; // 끝나면 알아서 끝나 마지막인거 확인 안해도돼!
//             }
//         }
//         cout << st.size() << "\n";
//     }
//     return 0;
// }

// int N,M;
// vector<string> words(2000000);
// unordered_map<string, int>visited;
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
//     cin>>N>>M;
//     for(int i=0;i<N;i++){
//         string tmp;
//         cin>>tmp;
//         words[i]=tmp;
//         visited[tmp]=1;
//     }
//     int N1=N;
//     while(M>0){
//         string str;
//         cin>>str;
//         string tmp="";
//         for(int i=0;i<str.size();i++){
//             if(i+1==str.size() || str[i]!=','){
//                 tmp+=str[i];
//             }
//             if(str[i]==',' || i+1==str.size()){
//                 for(int j=0;j<N;j++){
//                     if(words[j]==tmp && visited[tmp]==1){
//                         visited[tmp]=0;
//                         tmp="";
//                         N1--;
//                         break;
//                     }
//                 }
//                 tmp="";
//             }
//         }
//         M--;
//         cout<<N1<<"\n";
//     }
// }

// 에디터

// #include <iostream>
// #include <string>
// #include <stack>
// using namespace std;

// int main(){
//     string str;
//     cin>>str;
//     stack<char> left;
//     stack<char> right;
//     for(int i=0;i<str.size();i++){
//         left.push(str[i]);
//     }
//     int M;
//     cin>>M;
//     while(M--){
//         char cmd;
//         cin>>cmd;
//         if(cmd=='L' && left.empty()==false){
//             right.push(left.top());
//             left.pop();
//         }
//         if(cmd=='D' && right.empty()==false){
//             left.push(right.top());
//             right.pop();
//         }
//         if(cmd=='B' && left.empty()==false){
//             left.pop();
//         }
//         if(cmd=='P'){
//             char tmp;
//             cin>>tmp;
//             left.push(tmp);
//         }
//     }
//     while(!left.empty()){
//         right.push(left.top());
//         left.pop();
//     }
//     while(!right.empty()){
//         cout<<right.top();
//         right.pop();
//     }
//     return 0;
// }

// DFS와 BFS

// int N, M, V;

// void dfs(vector<vector<int>> &graph, vector<bool> &visited, int start)
// {
//     visited[start] = true;
//     cout << start << " ";
//     for (int u : graph[start])
//     {
//         if (visited[u] == false)
//         {
//             dfs(graph, visited, u);
//         }
//     }
// }

// void bfs(vector<vector<int>> &graph, vector<bool> &visited, int start)
// {
//     queue<int> q;
//     q.push(start);
//     visited[start] = true;
//     while (!q.empty())
//     {
//         int x = q.front();
//         q.pop();
//         cout << x << " ";
//         for (int u : graph[x])
//         {
//             if (visited[u] == false)
//             {
//                 visited[u] = true;
//                 q.push(u);
//             }
//         }
//     }
// }

// int main()
// {
//     cin >> N >> M >> V;
//     vector<vector<int>> graph(50000, vector<int>());
//     vector<bool> visited(50000, false);

//     for (int i = 0; i < M; i++)
//     {
//         int tmp1, tmp2;
//         cin >> tmp1 >> tmp2;
//         graph[tmp1].push_back(tmp2);
//         graph[tmp2].push_back(tmp1);
//     }
//     for (int i = 1; i <= N; i++)
//     {
//         sort(graph[i].begin(), graph[i].end());
//     }
//     dfs(graph, visited, V);
//     fill(visited.begin(), visited.end(), false);
//     cout << "\n";
//     bfs(graph, visited, V);
//     return 0;
// }

// 한줄로 서기

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    int N;
    cin >> N;
    stack<int> left;
    stack<int> right;
    vector<int> numbers;
    for (int i = 0; i < N; i++)
    {
        int tmp;
        cin >> tmp;
        numbers.push_back(tmp);
    }
    for (int i = numbers.size() - 1; i >= 0; i--)
    {
        if (right.empty())
        {
            right.push(i + 1);
        }
        else
        {
            while (left.size() < numbers[i])
            {
                left.push(right.top());
                right.pop();
            }
            while (left.size() > numbers[i])
            {
                right.push(left.top());
                left.pop();
            }
            right.push(i + 1);
        }
    }
    while (!left.empty())
    {
        right.push(left.top());
        left.pop();
    }
    while (!right.empty())
    {
        cout << right.top() << " ";
        right.pop();
    }
    return 0;
}
