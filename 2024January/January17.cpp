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


int main(){
    int T;
    cin>> T;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for(int i=0;i<T;i++){
        int C;
        cin>>C;
        vector<int> tmp(4,0);
        vector<int> coins={25,10,5,1};
        for(int j=0;j<coins.size();j++){
            if(C/coins[j]!=0){
                tmp[j]=C/coins[j];
                C=C%coins[j];
                cout<<tmp[j]<< " ";

            }else{
                cout<<tmp[j]<< " ";
            }
        }
        cout<<"\n";
    }

}