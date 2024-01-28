#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;
vector<bool> check(10001,false);//티켓방문 완료.
vector<vector<string>> ticket;
vector<string> answer;
bool isAnswer=false;
void dfs(string start, int tckCnt){
    answer.push_back(start);//시작점은 무조건 push
    if(tckCnt==ticket.size()){
        isAnswer=true;//일종의 탈출 조건(항공권을 다봤다.)
    }
    for(int i=0;i<ticket.size();i++){
        //티켓 수만큼 순회
        if(check[i]) continue;//방문했으면 넘어가기
        if(ticket[i][0]==start){
            check[i]=true;//방문했다 표시
            dfs(ticket[i][1],tckCnt+1);//재귀 시작(항공권 하나 봤음.)
            //백트래킹 명시조건 :항공권이 남았는데 길이 끊겼다면 백트래킹을 해야합니다. 
            if(!isAnswer){
                answer.pop_back();
                check[i]=false;            
            }
        }
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    sort(tickets.begin(),tickets.end());
    ticket=tickets;
    dfs("ICN",0);
    return answer;
}

vector<int> visit;
int answer=0;
void dfs(vector<vector<int>> &computers,int start,int n){
    visit[start]=1;
    for(int i=0;i<computers.size();i++){
        if(visit[i]==0 && computers[start][i]==1){
            dfs(computers,i,n);
        }

    }
}

int solution(int n, vector<vector<int>> computers) {
    visit.resize(n,0);
    for(int i=0;i<n;i++){
        if(visit[i]==0){
            dfs(computers,i,n);
            answer+=1;// dfs를 완료하고 그제서야 하나 추가
        }
    }
    return answer;
}

int main(){
    cout << solution(3,{{1,1,0},{1,1,1},{0,1,1}});
}