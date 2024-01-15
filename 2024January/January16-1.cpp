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

//그리디 그냥 큰거 곱하기 작은거 하면 작은거 합나온다. 
int main(){
    int N;
    cin>>N;
    vector<int> a;
    vector<int> b;
    for(int i=0;i<N;i++){
        int tmp;
        cin>>tmp;
        a.push_back(tmp);
    }
    for(int i=0;i<N;i++){
        int tmp;
        cin>>tmp;
        b.push_back(tmp);
    }
    sort(a.begin(),a.end());//오름 차순 정렬
    sort(b.begin(),b.end(),greater<int>());//내림차순 정렬
    int ans=0;
    for(int i=0;i<N;i++){
        ans+=a[i]*b[i];

    }
    cout<<ans<<"\n";
}