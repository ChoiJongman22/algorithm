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
// int main()
// {
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
//     int N;
//     cin >> N;
//     vector<int> a;
//     vector<int> b;
//     for (int i = 0; i < N; i++)
//     {
//         int temp;
//         cin >> temp;
//         a.push_back(temp);
//     }
//     sort(a.begin(), a.end());
//     int answer;
//     for (int i = 0; i < N; i++)
//     {
//         answer += a[i] * (N - i);
//     }
//     cout << answer;
// }

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string M;
    int N;
    cin>>M;
    cin>>N;
    for(int i=0;i<N;i++){
        char tmp1;
        int tmp2,tmp3;
        int count=0;
        cin>>tmp1;
        cin>>tmp2;
        cin>>tmp3;
        for(int j=tmp2;j<=tmp3;j++){
            if(M[j]==tmp1){
                count++;
            }
        }
        cout<<count<<"\n";
    }
}
//계속 풀어보기