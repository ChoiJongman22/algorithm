#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;

// 치즈
//  vector<vector<int>> table(101, vector<int>(101, 0));
//  vector<int> remain(101);
//  bool isAnswer = false;
//  int N, M;
//  int ans = 0;
//  vector<pair<int, int>> melt;
//  int dy[4] = {1, -1, 0, 0};
//  int dx[4] = {0, 0, 1, -1};
//  int cheesecount()
//  {
//      int cheese=0;
//      for (int i = 0; i < N; i++)
//      {
//          for (int j = 0; j < M; j++)
//          {
//              if (table[i][j] == 1)
//              {
//                  cheese += 1;
//              }
//          }
//      }
//      return cheese;
//  }

// void bfs()
// {
//     vector<vector<int>> visited(N,vector<int>(M,0));
//     queue<pair<int, int>> q;
//     q.push({0,0});
//     visited[0][0]=1;
//     while (!q.empty())
//     {
//         int y = q.front().first;
//         int x = q.front().second;
//         q.pop();
//         for (int i = 0; i < 4; i++)
//         {
//             int ny = y + dy[i];
//             int nx = x + dx[i];
//             if (ny >= 0 && nx >= 0 && ny < N && nx < M && visited[ny][nx] == 0)
//             {
//                 if(table[ny][nx]==0){
//                     q.push({ny,nx});
//                 }else{
//                     table[ny][nx]=2;

//                 }
//                 visited[ny][nx]=1;
//             }
//         }
//     }
// }

// int main()
// {
//     cin >> N >> M;
//     for (int i = 0; i < N; i++)
//     {
//         for (int j = 0; j < M; j++)
//         {
//             cin >> table[i][j];
//         }
//     }
//     int currentcheese = cheesecount();
//     remain.push_back(currentcheese);
//     while (currentcheese > 0)//얘가 Keypoint인듯
//     {
//         bfs();
//         currentcheese = 0;
//         for (int i = 0; i < N; i++)
//         {
//             for (int j = 0; j < M; j++)
//             {
//                 if(table[i][j]==2){
//                     table[i][j]=0;
//                 }else if(table[i][j]==1){
//                     currentcheese+=1;
//                 }
//             }
//         }
//         ans+=1;
//         if(currentcheese>0){
//             remain.push_back(currentcheese);
//         }
//     }
//     cout<<ans<<"\n";
//     cout<<remain[remain.size()-1];
//     return 0;
// }

// int solution(int x, int y, int n) {
//     int answer = 0;
//     int DP[1000001]={0}
//     for(int i=0;i<1000001;i++){
//         DP[i]=1000001;
//     }
//     DP[y]=0;
//     for(int i=y;i>x;i--){
//         if(DP[i]!=1000001){
//             if(i%3==0){
//                 DP[i/3]=min(DP[i/3],DP[i]+1);
//             }
//             if(i%2==0){
//                 DP[i/2]=min(DP[i/2],DP[i]+1);
//             }
//             if(i-n>0){
//                 DP[i-n]=min(DP[i-n],DP[i]+1);
//             }
//         }
//     }
//     if(DP[x]==1000001){
//         DP[x]=-1;
//     }
//     answer=DP[x];
//     return answer;
// }

int my_stoi(string s)
{
    int num = 0;
    for (int i = 0; i < 5; i++)
    {
        if (isdigit(s[i]))
        {
            num = num * 10 + s[i] - '0';
        }
    }
    return num;

}

int solution(vector<vector<string>> book_time)
{
    int answer = 0;
    int room[2410]={0,};
    int start = 0;
    int end = 0;
    for (int i = 0; i < book_time.size(); i++)
    {
        start = stoi(book_time[i][0].substr(0, 2)) * 100 + stoi(book_time[i][0].substr(3));
        end = stoi(book_time[i][1].substr(0, 2)) * 100 + stoi(book_time[i][1].substr(3))+10;
        if(end%100>=60){
            end+=40;
        }
        for(int j=start;j<end;j++){
            room[j]+=1;
        }
    }
    for(int i=0;i<2400;i++){
        answer=max(answer, room[i]);
    }
    return answer;
}

int main()
{
    cout << solution({{"15:00", "17:00"}, {"16:40", "18:20"}, {"14:20", "15:20"}, {"14:10", "19:20"}, {"18:20", "21:20"}});
}