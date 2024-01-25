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
#include <utility> // std::pair 헤더
using namespace std;
#define MAX 1000001

const int MAX_TEMP=3050;
const int MAX_N=1010;
const int INF=987654321;

int N, outsideTemp;
int A,B,T1,T2;
int cache[MAX_TEMP][MAX_N];
vector<int> onboards;
int nextTemp(int currTemp){
    int gap=outsideTemp-currTemp;
    if(gap>0){
        return currTemp+1;
    }else if(gap<0){
        return currTemp-1;
    }else{
        return currTemp;
    }
}

int dp(int currTemp, int t){
    if(t==N){
        return 0;
    }
    cout<<"현재 온도는 : "<<currTemp<<endl;
    if(onboards[t]==1 && (currTemp<T1||currTemp>T2)){
        return INF;
    }

    int& ret=cache[currTemp+1050][t];
    if (ret!=-1){
        return ret;
    }
    ret=INF;
    ret=min(ret,B+dp(currTemp,t+1));
    cout<<"첫번쨰 경우: "<<ret<<endl;
    ret=min(ret,A+dp(currTemp-1,t+1));
    cout<<"두번쨰 경우: "<<ret<<endl;
    ret=min(ret,A+dp(currTemp+1,t+1));
    cout<<"세번쨰 경우: "<<ret<<endl;
    ret=min(ret, dp(nextTemp(currTemp),t+1));
    cout<<"네번쨰 경우: "<<ret<<endl;

    return ret;

}

int solution(int temperature, int t1, int t2, int a, int b, vector<int> onboard) {
    int answer = INF;
    outsideTemp=temperature;
    T1=t1;
    T2=t2;
    A=a;
    B=b;
    N=onboard.size();
    onboards=onboard;
    memset(cache,-1,sizeof(cache));
    answer=dp(temperature,0);
    return answer;

}

int main(){
    cout<<solution(28,18,26,10,8,{0,0,1,1,1,1,1});
}