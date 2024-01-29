#include <iostream>
#include <vector>
using namespace std;


int main(){
    int n,k;
    cin>>n>>k;
    vector<int> value(n);
    vector<int> DP(k+1);
    for(int i=0;i<n;i++){
        int tmp;
        cin>>tmp;
        value[i]=tmp;
    }
    DP[0]=1;
    for(int i=0;i<n;i++){
        for(int j=value[i];j<=k;j++){
            DP[j]+=DP[j-value[i]];
            cout<<"DP["<<j<<"]"<<DP[j]<<"\n";
        }
    }
    cout<<DP[k]<<"\n";
    return 0;
}