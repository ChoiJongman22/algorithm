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

#define MAX 20001
using namespace std;
#define INF 10000000

int dr[4]={-1,0,1,0};
int dc[4]={0,1,0,-1};
int map1[25][25];
int visited[25][25];
int cnt;

vector<int> cntV;
//DFS 문제풀이
int N;

void dfs(int r,int c){
    for(int i=0;i<4;i++){
        int nr=r+dr[i]; //위아래 결정
        int nc=c+dc[i]; //왼/아래 결정
        if(nr>=N || nr<0 ||nc>=N||nc<0) continue; //다음 루프로 건너 뛰세요.왜냐하면 -1 + 0은 -1이기 때문에 집이 없습니다. 즉 0인것만 밑에 집이 있는거니까
        if(visited[nr][nc]==0 && map1[nr][nc]==1){//아직 방문하지 않았고, 집이 있다면
            visited[nr][nc]=1; //방문했고
            cnt+=1;//집 개수 올려주고
            dfs(nr,nc);//다시 재귀적으로. 그래서 파고들자. dfs
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int res=0;
    cin >> N;
    string str;
    for (int i = 0; i < N; i++)
    {
        cin>>str;
        for (int j = 0; j < str.length(); j++)
        {
            visited[i][j]=0;
            if(str[j]=='1'){
                map1[i][j]=1;
            }else{
                map1[i][j]=0;
            }

        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if (map1[i][j] == 1 && visited[i][j] == 0) // 방문하지 않았고, 번지가 있다면
            {
                visited[i][j]=1;//방문했고
                cnt=1;
                dfs(i,j);
                cntV.push_back(cnt);
                res++;
            }
        }
    }

    sort(cntV.begin(),cntV.end());
    cout<<res<<"\n";
    for(int i=0;i<cntV.size();i++){
        cout<<cntV[i]<<"\n";
    }
    return 0;

}

//DP 문제풀이

// vector<vector<int> > home(1003, vector<int>(3));
// vector<int> cost(3);
// int main()
// {
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
//     int testcase;
//     cin >> testcase;

//     for (int i = 1; i <= testcase; i++)
//     {
//         cin >> cost[0] >> cost[1] >> cost[2];
//         home[i][0]=min(home[i-1][1],home[i-1][2])+cost[0];
//         home[i][1]=min(home[i-1][2],home[i-1][0])+cost[1];
//         home[i][2]=min(home[i-1][0],home[i-1][1])+cost[2];
//     }
//     //이렇게 되면 처음부터 다 더한게 된다. 점화식 기억하자. 수학선생님인데..;;
//     cout<<min(min(home[testcase][0],home[testcase][1]),home[testcase][2]);
// }

