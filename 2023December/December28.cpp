#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <stack>
#include <unordered_map>
#include <queue>
#include <deque>
#define MAX 500002
using namespace std;

int fibo(int num){
    if(num==0){
        return 0;
    }
    if(num==1){
        return 1;
    }
    return fibo(num-2)+fibo(num-1);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N;
    cin>>N;


    cout<<fibo(N)<<"\n";

}