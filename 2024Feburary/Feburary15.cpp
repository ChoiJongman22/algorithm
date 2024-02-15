#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 10001

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N,D;
    cin>>N>>D;
    vector<int> map(D+1,MAX);
    vector<pair<int,int>> fast[10001];
    int from, to, dis;
    for(int i=0;i<N;i++){
        cin>>from>>to>>dis;
        fast[to].push_back({from,dis});//비교할거 없이 DP로 처음부터 다 더해주는 것으로 생각하면 편하다.
    }

    map[0]=0;
    for(int i=1;i<=D;i++){
        if(fast[i].size()==0){
            map[i]=map[i-1]+1;
        }else{
            for(auto v :fast[i]){
                map[i]=min(map[i],min(map[i-1]+1,map[v.first]+v.second));
            }
        }
    }
    cout<<map[D]<<"\n";

}