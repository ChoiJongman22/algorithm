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
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int len = 0;

void getBlock(vector<vector<int> > &table, vector<vector<bool> > &visit, vector<vector<int> > &block, int x, int y)
{
    queue<vector<int> > q;
    q.push({x, y});
    visit[x][y] = true;
    while (!q.empty())
    {
        vector<int> curr = q.front();
        int cur_x = curr[0], cur_y = curr[1];
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int x = cur_x + dx[i];
            int y = cur_y + dy[i];

            if (x >= 0 && y >= 0 && x < len && y < len && visited[x][y] == 0 && table[x][y] == 1)
            {
                visit[x][y]=1;
                block.push_back({x,y});
                q.push({x,y});   
            }
        }
    }
}
vector<vector<int>> getBlocks(vector<vector<int>> &table){
    vector<vector<int>> blocks;
    vector<vector<bool>> visit(len, vector<bool>(len));

    for(int i=0;i<len;i++){
        for(int j=0;j<len;j++){
            if(table[i][j]==0 || visit[i][j]==true) continue;
            block.push_back({i,j});
            getBlock(table, visit, block, i,j);
            for(auto &pos: block){
                pos[0]-=i;
                pos[1]-=j;
            }
            blocks.push_back(block);
        }
    }
    return blocks;
}

vector<vector<int>> rotateBlock(vector<vector<int>> &block){
    for(auto &piece :block){
        int tmp=piece[0];
        
    }
}

int solution(vector<vector<int> > game_board, vector<vector<int> > table)
{
    len = game_board.size();
    int answer = -1;
    return answer;
}

int main()
{
}