#include <iostream>
#include <vector>
#include <queue>
using namespace std;


// vector<int> lotto(13,0);
// vector<int> tmp(13,0);

// int k;
// void dfs(int startIdx, int depth){
//     if(depth==6){
//         for(int i=0;i<depth;i++){
//             cout<<lotto[i]<<" ";
//         }
//         cout<<"\n";
//     }

//     for(int i=startIdx;i<k;i++){
//         lotto[depth]=tmp[i];
//         dfs(i+1,depth+1);
//     }

// }
// int main(){
//     while(true){
//         cin>>k;
//         if(k==0){
//             exit(0);
//         }
//         for(int i=0;i<k;i++){
//             cin>>tmp[i];
//         }
//         dfs(0,0);
//         cout<<"\n";
//     }
// }

// vector<vector<int>> bfsmap(101,vector<int>(101,0));
// vector<vector<int>> visited(101,vector<int>(101,0));
// vector<vector<int>> maze;


// int dy[4]={1,-1,0,0};
// int dx[4]={0,0,1,-1};
// int size1;
// int size2;
// void bfs(int sy,int sx){
//     queue<pair<int,int>> q;
//     q.push({sy,sx});
//     visited[sy][sx]=1;
//     bfsmap[sy][sx]=1;
//     while(!q.empty()){
//         int ny = q.front().first;
//         int nx= q.front().second;
//         q.pop();
//         for(int i=0;i<4;i++){
//             int y=ny+dy[i];
//             int x=nx+dx[i];
//             if(y>=0 && x>=0 && x<size2 && y<size1 && visited[y][x]==0 && maze[y][x]==1){
//                 visited[y][x]=1;
//                 bfsmap[y][x]=bfsmap[ny][nx]+1;
//                 q.push({y,x});
//             }
//         }
//     }
    
// }

// int solution(vector<vector<int> > maps)
// {
//     int answer = 0;
//     size1=maps.size();
//     size2=maps[0].size();
//     maze=maps;
//     bfs(0,0);
//     if(bfsmap[size1-1][size2-1]==0){
//         return -1;
//     }
//     answer=bfsmap[size1-1][size2-1];
//     return answer;
// }

// int main(){
//    cout<< solution({{1, 0, 1, 1, 1}, {1, 0, 1, 0, 1}, {1, 0, 1, 1, 1}, {1, 1, 1, 0, 1}, {0, 0, 0, 0, 1}});
// }


//아이템 줍기

