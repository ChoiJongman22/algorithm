#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

// vector<int> DP(100001,0);
// int main(){
//     int n,k;
//     cin>>n>>k;
//     vector<int> value(n+1,0);
//     for(int i=1;i<=n;i++){
//         cin>>value[i];
//     }
//     for(int i=1;i<=k;i++){
//         DP[i]=100001;
//     }
//     for(int i=1;i<=n;i++){
//         for(int j=value[i];j<=k;j++){
//             DP[j]=min(DP[j],DP[j-value[i]]+1);
//         }
//     }
//     if(DP[k]==100001){
//         cout<<-1;
//         return 0;
//     }
//     cout<<DP[k];
//     return 0;

// }

vector<string> boards;
vector<int> cnt(2, 0);
int allcnt = 0;

void countox()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (boards[i][j] != '.')
            {
                if (boards[i][j] == 'O')
                {
                    cnt[0] += 1;
                    allcnt += 1;
                }
                else
                {
                    cnt[1] += 1;
                    allcnt += 1;
                }
            }
        }
    }
}

bool winner1(char player){
    for(int i=0;i<3;i++){
        if(boards[i][0]==player && boards[i][0]==boards[i][1] && boards[i][1] &&boards[i][2]){
            return true;
        }
        if(boards[0][i] ==player && boards[0][i]==boards[1][i] && boards[1][i]==boards[2][i]){
            return true;
        }
    }
    if(boards[0][0]==boards[1][1] && boards[1][1]==boards[2][2] && boards[0][0]==player){
        return true;
    }
    if(boards[2][0]==boards[1][1] && boards[1][1]==boards[0][2] && boards[2][0]==player){
        return true;
    }
    return false;
}

bool turncnt()
{
    int x = 0;
    int o = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (boards[i][j] != '.')
            {
                if (boards[i][j] == 'O')
                {
                    o += 1;
                }
                else
                {
                    x += 1;
                }
            }
        }
    }
    if (o - x > 1 || o < x)
    {
        return false;
    }
    return true;
}
int solution(vector<string> board)
{
    int answer = -1;
    boards = board;
    countox();
    if(!turncnt()){
        return 0;
    }
    if(winner1('O') && cnt[0]-cnt[1]!=1){
        return 0;
    }
    if(winner1('X') && cnt[0]-cnt[1]!=0){
        return 0;
    }
    if(winner1('O') && winner1('X')){
        return 0;
    }
    answer=1;
    return answer;
}

int main(){
    cout<<solution({"...",".X.","..."});
}