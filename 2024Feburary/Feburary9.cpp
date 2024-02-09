// 영단어 암기는 괴로워
//  #include <iostream>
//  #include <vector>
//  #include <map>
//  #include <unordered_map>
//  #include <algorithm>
//  using namespace std;
//  unordered_map<string,int> app;

// bool cmp(pair<string, int> &a, pair<string, int> &b){
//     if(a.second==b.second){
//         if(a.first.length()==b.first.length()){
//             return a.first<b.first;//조건 3 . 길이 비교 후 알바펫순 비교
//         }
//         return a.first.length()>b.first.length();//조건 2. 길이 비교

//     }
//     return a.second>b.second;//조건 1. 출연 빈도 수
// }

// int main(){
//     cin.tie(0);
//     cout.tie(0);
//     ios::sync_with_stdio(0);
//     int n,m;
//     cin>> n >> m;
//     for(int i=0;i<n;i++){
//         string str;
//         cin>>str;
//         if(str.length()>=m){
//             app[str]+=1;
//         }
//     }
//     vector<pair<string,int>> vec(app.begin(),app.end());//map과 pair는 유사함. 이렇게 사용할 수도 있음.
//     sort(vec.begin(),vec.end(),cmp);
//     for(auto p:vec){
//         cout<<p.first<<"\n";
//     }
// }

// 예산
//  #include <iostream>
//  #include <vector>
//  #include <algorithm>
//  using namespace std;

// //Value로 기준을 잡는 이진탐색
// int main(){
//     int N;
//     cin>>N;
//     vector<int> budget(N,0);
//     for(int i=0;i<N;i++){
//         cin>>budget[i];
//     }
//     int M;
//     cin>>M;
//     sort(budget.begin(),budget.end());
//     int start=0;
//     int end=budget[N-1];
//     int result,sum;
//     while(start<=end){
//         sum=0;
//         int mid = (start+end)/2;
//         for(auto i=0;i<N;i++){
//             sum+=min(budget[i],mid);
//         }
//         if(M>=sum){
//             result=mid;
//             start=mid+1;
//         }else{
//             end=mid-1;
//         }
//     }
//     cout<<result<<"\n";

// }

// 블로그
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    int N, X;
    cin >> N >> X;
    vector<int> days(N);
    int maxel = 0;
    int ans = 1;
    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> days[i];
    }
    for (int i = 0; i < X; i++)
    {
        sum += days[i];
    }
    maxel = sum ;
    for (int i = X; i < N; i++)
    {
        sum += days[i] - days[i - X]; // 슬라이딩 윈도우
        if (sum > maxel)
        {
            maxel=sum;
            ans=1;
        }else if (maxel==sum){
            ans++;
        }
    }

    if (maxel == 0)
    {
        cout << "SAD";
        return 0;
    }
    cout << maxel << "\n";
    cout << ans << "\n";
    return 0;
}