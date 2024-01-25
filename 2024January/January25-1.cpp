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

int solution(vector<vector<int>> targets) {
    int answer = 0;
    int idx=0;
    sort(targets.begin(),targets.end());
    while(idx<targets.size()){
        int end=targets[idx++][1];//여기서는 초기에 0부터 시작함. [0][1]하고 idx+=1합니다. 
        answer++;
        cout<<"end : "<<end<<endl;
        while(idx<targets.size() && targets[idx][0]<end){
            if(targets[idx][1]<end){
                end=targets[idx][1];
                cout<<"end 갱신 : "<<end<<endl;
            }
            idx++;
        }
    }
    return answer;
}

int main(){
    cout<<solution({{4,5},{4,8},{10,14},{11,13},{5,12},{3,7},{1,4}});
}