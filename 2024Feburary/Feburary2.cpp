// #include <iostream>
// #include <vector>
// #include <cmath>
// using namespace std;

// vector<bool> remote(10);//리모컨 고장난지 여부 확인할거야

// //숫자로만 갈 수 있는 지 확인하기
// int check(int n){
//     if(n==0){
//         if(remote[0]){
//             return 0;
//         }else{
//             return 1;
//         }
//         //0번을 누르려고할떄는
//     }
//     int len=0;
//     while(n>0){
//         if(remote[n%10]){
//             return 0;
//         }
//         n=n/10;
//         len+=1;
//     }
//     return len;

// }
// int main(){
//     int N, broke;
//     cin>>N>>broke;

//     for(int i=0;i<broke;i++){
//         int x;
//         cin>> x;
//         remote[x]=true;//고장남
//     }
//     int count=abs(N-100);
//     for(int i=0;i<=1000000;i++){
//         int c=i;
//         int len=check(c);
//         if(len>0){
//             int press=abs(c-N);
//             if(count>press+len){
//                 count=press+len;
//             }
//         }
//     }
//     cout<<count;
//     return 0;
// }

// #include <stack>
// #include <iostream>
// using namespace std;

// int main(){
//     stack<int> s;
//     int T;
//     cin>>T;
//     for(int i=0;i<T;i++){
//         int tmp;
//         cin>>tmp;
//         if(tmp==0 && !s.empty()){
//             s.pop();
//         }
//         else{
//             s.push(tmp);
//         }
//     }
//     int answer=0;

//     //이렇게 하면 스택의 요소가 자꾸 비기 때문에 사이즈가 변한다 절대로 이렇게 하지말자.
//     // for(int i=0;i<s.size();i++){
//     //     cout<<s.top()<<"\n";
//     //     answer+=s.top();
//     //     s.pop();
//     // }
//     while(!s.empty()){
//         answer+=s.top();
//         s.pop();
//     }

//     cout<<answer<<"\n";
// }

//기본에 충실하자 Queue
#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int T;
    cin >> T;
    queue<int> q;
    for (int i = 0; i < T; i++)
    {
        q.push(i+1);
    }
    while (q.size()>1)
    {
        q.pop();
        q.push(q.front());
        q.pop();
    }
    cout<<q.front()<<'\n';
}