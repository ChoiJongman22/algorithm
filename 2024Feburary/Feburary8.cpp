// 스위치 켜고 끄기

// int main(){
//     int T;
//     cin>>T;
//     vector<int> swc(T,0);
//     for(int i=0;i<T;i++){
//         cin>>swc[i];
//     }
//     int n;
//     cin>>n;
//     for(int i=0;i<n;i++){
//         int gender, num;
//         cin>>gender>>num;
//         if(gender==1){
//             for(int j=num-1;j<T;j+=num){
//                 swc[j]=1-swc[j];
//             }
//         }else{
//             num--;
//             swc[num]=1-swc[num];
//             int left=num-1,right=num+1;
//             while(left>=0 &&right<T &&swc[left]==swc[right]){
//                 swc[left]=1-swc[left];
//                 swc[right]=1-swc[right];
//                 left--;
//                 right++;
//             }
//         }
//     }
//     for(int i=0;i<T;i++){
//         cout<<swc[i]<<" ";
//         if((i+1)%20==0){
//             cout<<"\n";
//         }
//     }
//     return 0;
// }

// 주유소
//  #include <iostream>
//  #include <vector>
//  using namespace std;

// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
//     int N;
//     cin>>N;
//     vector<long long> dis(N-1);
//     for(int i=0;i<N-1;i++){
//         cin>>dis[i];
//     }
//     vector<long long> oil(N);
//     for(int i=0;i<N;i++){
//         cin>>oil[i];
//     }
//     long long total=0;
//     for(int i=0;i<N-1;i++){
//         if(oil[i]<oil[i+1]){
//             oil[i+1]=oil[i];//적으면 앞당기기 와...ㅋ
//         }
//         total+=oil[i]*dis[i];
//     }
//     cout<<total;
//     return 0;

// }

#include <iostream>
#include <vector>
using namespace std;
// 타노스
int main()
{
    string input;
    cin >> input;
    int cnt0 = 0;
    int cnt1 = 0;

    for (auto i : input)
    {
        if (i == '0')
        {
            cnt0 += 1;
        }
        else
        {
            cnt1 += 1;
        }
    }
    int hcnt0 = cnt0 / 2;
    int hcnt1 = cnt1 / 2;
    while (cnt0 != hcnt0)
    {
        int idx = input.rfind('0');
        if (idx != string::npos)
        {
            input.erase(idx, 1); // idx기준으로 하나만 삭제합시다. 안 적으면 모두 삭제할거요!
            cnt0--;
        }
    }
    while (cnt1 != hcnt1)
    {
        int idx = input.find('1');
        // 만약 찾는 문자가 문자열에 존재하지 않으면, string::npos를 반환
        if (idx != string::npos) // 찾는 문자가 문자열에 존재하면
        {
            input.erase(idx, 1);
            cnt1--;
        }
    }
    cout<<input<<"\n";
}
