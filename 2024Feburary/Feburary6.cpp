// #include <iostream>
// using namespace std;
// #include <vector>
// #include <string>
// vector<string> cookies(1001);
// int ny=0;
// int nx=0;
// void find_heart(int n){
//     for(int i=0;i<n;i++){
//         for(int j=0;j<n;j++){
//             if(cookies[i][j]=='*'){//머리를 찾으면
//                 ny=i+1;//심장은 머리 바로 밑에 있으니까.
//                 nx=j;//심장 위치에서 좌우는 변하지 않도록
//                 return ;
//             }
//         }
//     }
// }
// int main(){
//     int N;
//     cin>>N;
//     cookies.resize(N);
//     for(int i=0;i<N;i++){
//         cin>>cookies[i];
//     }

//     find_heart(N);
//     cout<<nx+1<< " "<<ny+1<<"\n";

//     int len=0;
//     // 오른팔
//     for(int i=nx;i<N;i++){
//         if(cookies[ny][i+1]!='*'){
//             break;
//         }
//         len+=1;
//     }
//     cout<<len<<" ";
//     len=0;

//     // 왼팔
//     for(int i=nx;i>=0;i--){
//         if(cookies[ny][i-1]!='*'){
//             break;
//         }
//         len+=1;
//     }
//     cout<<len<<" ";
//     len=0;

//     //허리
//     int ex,ey;
//     for(int i=ny;i<N;i++){
//         if(cookies[i][nx+1]!='*'){
//             ey=i;
//             ex=nx+1;
//             break;
//         }
//         len+=1;
//     }
//     cout<<len<<" ";
//     len=0;

//     //왼쪽 다리

//     for(int i=ey+1;i<N;i++){
//         for(int j=ex-1;j<N;j++){
//             if(cookies[i][j]!='*'){
//                 break;
//             }
//             len+=1;
//         }
//     }
//     cout<<len<<" ";

//     len=0;

//     //오른쪽 다리
//     for(int i=ey+1;i<N;i++){
//         for(int j=ex+1;j<N;j++){
//             if(cookies[i][j]!='*'){
//                 break;
//             }
//             len+=1;
//         }
//     }
//     cout<<len<<" ";
//     return 0;

// }

#include <iostream>
#include <vector>
using namespace std;

vector<int> number;
#include <algorithm>
int main()
{
    int N, score, P;
    cin >> N >> score >> P;
    if (N == 0)
    {
        cout << 1;
        return 0;
    }
    number.resize(N);

    for (int i = 0; i < N; i++)
    {
        cin >> number[i];
    }
    number.push_back(score);
    sort(number.rbegin(), number.rend());
    int rank = 0;
    int i = 0;
    for (i = 0; i < number.size(); i++)
    {
        rank = i + 1;
        while (i + 1 < number.size() && number[i + 1] == number[i])
        {
            i += 1; //점수가 같거나, 등수가 끝 등수일떄까지
        }
        if (number[i] == score)
        {
            break;
        }
    }
    if (i < P)
    {
        cout << rank;
    }
    else
    {
        cout << -1;
    }
    return 0;
}