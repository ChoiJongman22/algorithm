

// 수 이어쓰기
//  #include <iostream>
//  #include <string>
//  using namespace std;

// int main(){
//     string str;
//     cin>>str;

//     int ptr=0, num=0;
//     while(num++<3000){
//         string numstr=to_string(num);
//         for(int i=0;i<numstr.size();i++){
//             if(str[ptr]==numstr[i]){//숫자 내에 현재 위치의 숫자가 있는지를 하나씩 계속 비교합니다.
//                 ptr+=1;//위치를 하나씩 옮겨가며
//             }
//             if(ptr==str.length()){//그리고 숫자의 위치가 결국 더 나가갈 곳이 없다면
//                 cout<<num<<"\n";//그떄의 숫자는 무조건 답이 됩니다.
//                 return 0;
//             }
//         }
//     }
//     return 0;

// }

// 햄버거 분배
//  #include <iostream>
//  #include <string>
//  using namespace std;
//  int main(){
//      int N,K;
//      string loca;
//      cin>>N>>K;
//      cin>>loca;
//      int cnt=0;
//      for(int i=0;i<N;i++){
//          if(loca[i]!='P'){
//              continue;
//          }
//          for(int j=i-K;j<=i+K;j++){//범위를 설정해서 탐색하기, 앞에서 먹는 것 부터가 제일 유리함.
//              if(0<=j && j<N && loca[j]=='H'){
//                  loca[j]='-';//먹었다고 표시하기
//                  cnt+=1;
//                  break;
//              }
//          }
//      }
//      cout<<cnt;
//  }

// 진우의 달 여행
// #include <iostream>
// #include <vector>
// #include <cstring>
// using namespace std;

// vector<vector<int>> space(10, vector<int>(10, 0));
// int DP[10][10][4];
// int N, M;

// int solve(int y, int x, int dir){
//     if(y==N){
//         return 0;
//     }
//     int &ret=DP[y][x][dir];
//     if(ret!=-1)return ret;

//     ret=3000;

//     //y는 항상 증가시킬 거임. 왜냐면 무조건 밑으로 내려가는 거니깐.
//     //왼쪽 방향으로 갈거고 이전 dir은 왼쪽이 아니라면
//     if(x-1>=0 && dir!=0){
//         ret=min(ret, solve(y+1,x-1,0)+space[y][x]);//재귀적으로 현재 y,x에 대한 space값에다가 밑으로 내려가는 방식으로 더하기를 계속함.
//     }
//     if(x+1<M && dir!=2){
//         ret=min(ret,solve(y+1,x+1,2)+space[y][x]);
//     }
//     if(dir!=1){
//         ret=min(ret,solve(y+1,x,1)+space[y][x]);
//     }
//     //재귀가 종료되면 
//     return ret;
// }

// int main(){
//     memset(DP,-1,sizeof(DP));// 배열 초기화
//     cin>>N>>M;
//     for(int i=0;i<N;i++){
//         for(int j=0;j<M;j++){
//             cin>>space[i][j];
//         }
//     }
//     int ans=3000;
//     for(int i=0;i<M;i++){
//         ans=min(ans,solve(0,i,3));
//     }
//     cout<<ans;
// }






//실패한 코드
// void gotomoon(int dir, int n,int m)
// {
//     if (n==N){
//         return;
//     }
//     if(n==0){
//         DP[n][m]=space[n][m];
//         for(int i=0;i<2;i++){
//             gotomoon(i,n+1,m);
//         }
//     }else{
//         if(dir==0 && m>=0 && m+1<M){
//             DP[n+1][m]=min(DP[n][m]+space[n+1][m],DP[n+1][m]);
//             gotomoon(1,n+1,m);
//             DP[n+1][m+1]=min(DP[n][m]+space[n+1][m+1],DP[n+1][m+1]);
//             gotomoon(2,n+1,m+1);

//         }
//         else if(dir==1 && m-1>=0 && m+1<M){
//             DP[n+1][m-1]=min(DP[n][m]+space[n+1][m-1],DP[n+1][m-1]);
//             gotomoon(0,n+1,m-1);
//             DP[n+1][m+1]=min(DP[n][m]+space[n+1][m+1],DP[n+1][m+1]);
//             gotomoon(2,n+1,m+1);

//         }
//         else if(dir==2 && m>=0 && m-1>=0){
//             DP[n+1][m]=min(DP[n][m]+space[n+1][m],DP[n+1][m]);
//             gotomoon(0,n+1,m);
//             DP[n+1][m-1]=min(DP[n][m]+space[n+1][m-1],DP[n+1][m-1]);
//             gotomoon(1,n+1,m-1);

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
//             cin >> space[i][j];
//         }
//     }

//     for (int j = 0; j < M; j++)
//     {
//         gotomoon(0,0,j);
//     }
//     for(int i=0;i<N;i++){
//         for(int j=0;j<M;j++){
//             cout<<DP[i][j]<<" ";
//         }
//         cout<<"\n";
//     }
//     int min=3000;
//     for(int i=0;i<M;i++){
//         if(min>DP[N-1][i]){
//             min=DP[N-1][i];
//         }
//     }
//     cout<<min<<"\n";
// }

//비슷한 단어
#include <iostream>
#include <vector>
using namespace std;
vector<int> S_cnt;
string S;
int N;

vector<int> countAlphabet(string s){
    vector<int> ret(26,0);//알파벳은 26개
    for(auto c:s){
        ret[c-'A']++;
    }
    return ret;
}

bool check(string word){
    vector<int> word_cnt=countAlphabet(word);
    vector<int> diff;
    for(int i=0;i<26;i++){
        if(word_cnt[i]!=S_cnt[i]){
            diff.push_back(word_cnt[i]-S_cnt[i]);
        }
    }
    if(diff.empty()){
        return true;
    }
    if(abs(diff[0])==1 && diff.size()==1){
        return true;
    }
    if(abs(diff[0])==1 && diff.size()==2 && diff[0]+diff[1]==0){
        return true;
    }
    return false;
}

int solution(){
    int ret=0;
    S_cnt=countAlphabet(S);
    for(int i=0;i<N-1;i++){
        //새롭게 입력받으면 되는구나
        string tmp;
        cin>>tmp;
        if(check(tmp)){
            ret+=1;
        }
    }
    return ret;
}

int main(){
    cin>>N;
    cin>>S;
    cout<<solution();
}


