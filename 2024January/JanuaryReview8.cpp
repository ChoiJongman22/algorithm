#include <iostream>
#include <vector>
#include <stack>
using namespace std;

stack<pair<int,int>> st;
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    int N;
    cin >> N;
    st.push({100000001,0});
    for(int i=1;i<=N;i++){
        int h;
        cin>>h;
        while(st.top().first<h){
            st.pop();
        }
        cout<<st.top().second<<" ";
        st.push({h,i});
    }
    return 0;
}