//1,2,3 더하기 4
#include<iostream>
#include<vector>
using namespace std;
int T;
vector<vector<int>> DP(10001, vector<int>(4,0));
void solution(){
    DP[1][1]=1;
    DP[2][1]=1;
    DP[2][2]=1;
    DP[3][1]=1;
    DP[3][2]=1;
    DP[3][3]=1;
    for(int i=4;i<=10000;i++){
        DP[i][1]=DP[i-1][1];
        DP[i][2]=DP[i-2][2]+DP[i-2][1];
        DP[i][3]=DP[i-3][1]+DP[i-3][2]+DP[i-3][3];
    }
}


int main(){
    cin>>T;
    solution();
    int N;
    for(int i=0;i<T;i++){
        cin>>N;
        cout<<DP[N][1]+DP[N][2]+DP[N][3]<<"\n";

    }
    return 0;
}